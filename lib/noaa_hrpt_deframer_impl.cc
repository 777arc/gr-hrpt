/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "noaa_hrpt_deframer_impl.h"

namespace gr {
  namespace hrpt {

#define HRPT_SYNC1 0x0284
#define HRPT_SYNC2 0x016F
#define HRPT_SYNC3 0x035C
#define HRPT_SYNC4 0x019D
#define HRPT_SYNC5 0x020F
#define HRPT_SYNC6 0x0095

#define HRPT_MINOR_FRAME_SYNC  0x0A116FD719D83C95LL

#define HRPT_SYNC_WORDS        6
#define HRPT_MINOR_FRAME_WORDS 11090
#define HRPT_BITS_PER_WORD     10

#define ST_IDLE   0
#define ST_SYNCED 1

    noaa_hrpt_deframer::sptr
    noaa_hrpt_deframer::make()
    {
      return gnuradio::get_initial_sptr
	(new noaa_hrpt_deframer_impl());
    }

    noaa_hrpt_deframer_impl::noaa_hrpt_deframer_impl()
      : block("noaa_hrpt_deframer",
		 io_signature::make(1, 1, sizeof(char)),
		 io_signature::make(1, 1, sizeof(short)))
    {
      set_output_multiple(6); // room for writing full sync when received
      d_mid_bit = true;
      d_last_bit = 0;
      enter_idle();
    }

    noaa_hrpt_deframer_impl::~noaa_hrpt_deframer_impl()
    {
    }

    void
    noaa_hrpt_deframer_impl::enter_idle()
    {
      d_state = ST_IDLE;
    }

    void
    noaa_hrpt_deframer_impl::enter_synced()
    {
      d_state = ST_SYNCED;
      d_bit_count = HRPT_BITS_PER_WORD;
      d_word_count = HRPT_MINOR_FRAME_WORDS-HRPT_SYNC_WORDS;
      d_word = 0;
    }

    int
    noaa_hrpt_deframer_impl::general_work(int noutput_items,
				     gr_vector_int &ninput_items,
				     gr_vector_const_void_star &input_items,
				     gr_vector_void_star &output_items)
    {
      int ninputs = ninput_items[0];
      const char *in = (const char *)input_items[0];
      unsigned short *out = (unsigned short *)output_items[0];

      int i = 0, j = 0;
      while(i < ninputs && j < noutput_items) {
	char bit = in[i++];
	char diff = bit^d_last_bit;
	d_last_bit = bit;

	// Wait for transition if not synced, otherwise, alternate bits
	if(d_mid_bit && (diff | (d_state == ST_SYNCED))) {
	  switch(d_state) {
	  case ST_IDLE:
	    d_shifter = (d_shifter << 1) | bit; // MSB transmitted first

	    if((d_shifter & 0x0FFFFFFFFFFFFFFFLL) == HRPT_MINOR_FRAME_SYNC) {
	      out[j++] = HRPT_SYNC1;
	      out[j++] = HRPT_SYNC2;
	      out[j++] = HRPT_SYNC3;
	      out[j++] = HRPT_SYNC4;
	      out[j++] = HRPT_SYNC5;
	      out[j++] = HRPT_SYNC6;
	      enter_synced();
	    }
	    break;

	  case ST_SYNCED:
	    d_word = (d_word << 1) | bit; // MSB transmitted first
	    if(--d_bit_count == 0) {
	      out[j++] = d_word;
	      d_word = 0;
	      d_bit_count = HRPT_BITS_PER_WORD;
	      if(--d_word_count == 0) {
		enter_idle();
	      }
	    }
	    break;

	  default:
	    throw std::runtime_error("noaa_hrpt_deframer_impl: bad state\n");
	  }

	  d_mid_bit = false;
	}
	else {
	  d_mid_bit = true;
	}
      }

      consume_each(i);
      return j;
    }

  } /* namespace hrpt */
} /* namespace gr */
