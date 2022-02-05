/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HRPT_NOAA_HRPT_DECODER_IMPL_H
#define INCLUDED_HRPT_NOAA_HRPT_DECODER_IMPL_H

#include <hrpt/noaa_hrpt_decoder.h>

namespace gr {
  namespace hrpt {

    class noaa_hrpt_decoder_impl : public noaa_hrpt_decoder
    {
     private:
      // Configuration
      bool d_verbose;
      bool d_output_files;

      // Frame-level state
      unsigned short d_current_word;
      unsigned int   d_word_num;
      int            d_frames_seen;

      // Minor frame number
      int d_current_mfnum;
      int d_expected_mfnum;
      int d_seq_errs;

      // Spacecraft address
      int d_address;

      // Minor frame timestamp
      int d_day_of_year;
      int d_milliseconds;
      int d_last_time;

      void process_mfnum();
      void process_address();
      void process_day_of_year();
      void process_milli1();
      void process_milli2();
      void process_milli3();

     public:
      noaa_hrpt_decoder_impl(bool verbose, bool output_files);
      ~noaa_hrpt_decoder_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace hrpt
} // namespace gr

#endif /* INCLUDED_HRPT_NOAA_HRPT_DECODER_IMPL_H */

