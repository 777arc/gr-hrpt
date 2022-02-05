/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HRPT_NOAA_HRPT_DEFRAMER_IMPL_H
#define INCLUDED_HRPT_NOAA_HRPT_DEFRAMER_IMPL_H

#include <hrpt/noaa_hrpt_deframer.h>

namespace gr {
  namespace hrpt {

    class noaa_hrpt_deframer_impl : public noaa_hrpt_deframer
    {
     private:
      unsigned int       d_state;
      bool               d_mid_bit;
      unsigned char      d_last_bit;
      unsigned int       d_bit_count;
      unsigned int       d_word_count;
      unsigned long long d_shifter;     // 60 bit sync word
      unsigned short     d_word;        // 10 bit HRPT word

      void enter_idle();
      void enter_synced();

     public:
      noaa_hrpt_deframer_impl();
      ~noaa_hrpt_deframer_impl();

      // Where all the action really happens
      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items
      );
    };

  } // namespace hrpt
} // namespace gr

#endif /* INCLUDED_HRPT_NOAA_HRPT_DEFRAMER_IMPL_H */

