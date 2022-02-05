/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HRPT_NOAA_HRPT_PLL_CF_IMPL_H
#define INCLUDED_HRPT_NOAA_HRPT_PLL_CF_IMPL_H

#include <hrpt/noaa_hrpt_pll_cf.h>

namespace gr {
  namespace hrpt {

    class noaa_hrpt_pll_cf_impl : public noaa_hrpt_pll_cf
    {
     private:
      float d_alpha;		// 1st order loop constant
      float d_beta;			// 2nd order loop constant
      float d_max_offset;		// Maximum frequency offset, radians/sample
      float d_phase;		// Instantaneous carrier phase
      float d_freq;			// Instantaneous carrier frequency, radians/sample

     public:
      noaa_hrpt_pll_cf_impl(float alpha, float beta, float max_offset);
      ~noaa_hrpt_pll_cf_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
      void set_alpha(float alpha) { d_alpha = alpha; }
      void set_beta(float beta) { d_beta = beta; }
      void set_max_offset(float max_offset) { d_max_offset = max_offset; }
    };

  } // namespace hrpt
} // namespace gr

#endif /* INCLUDED_HRPT_NOAA_HRPT_PLL_CF_IMPL_H */

