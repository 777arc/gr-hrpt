/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "noaa_hrpt_pll_cf_impl.h"
#include <gnuradio/math.h>
#include <gnuradio/sincos.h>

namespace gr
{
namespace hrpt
{

#define M_TWOPI (2 * M_PI)

float phase_wrap(float phase)
{
  while (phase < -M_PI)
    phase += M_TWOPI;
  while (phase > M_PI)
    phase -= M_TWOPI;

  return phase;
}

noaa_hrpt_pll_cf::sptr
noaa_hrpt_pll_cf::make(float alpha, float beta, float max_offset)
{
  return gnuradio::get_initial_sptr(new noaa_hrpt_pll_cf_impl(alpha, beta, max_offset));
}

noaa_hrpt_pll_cf_impl::noaa_hrpt_pll_cf_impl(float alpha, float beta, float max_offset)
    : sync_block("noaa_hrpt_pll_cf",
                 io_signature::make(1, 1, sizeof(gr_complex)),
                 io_signature::make(1, 1, sizeof(float))),
      d_alpha(alpha), d_beta(beta), d_max_offset(max_offset),
      d_phase(0.0), d_freq(0.0)
{
}

noaa_hrpt_pll_cf_impl::~noaa_hrpt_pll_cf_impl()
{
}

int noaa_hrpt_pll_cf_impl::work(int noutput_items,
                                gr_vector_const_void_star &input_items,
                                gr_vector_void_star &output_items)
{
  const gr_complex *in = (const gr_complex *)input_items[0];
  float *out = (float *)output_items[0];

  for (int i = 0; i < noutput_items; i++)
  {

    // Generate and mix out carrier
    float re, im;
    gr::sincosf(d_phase, &im, &re);
    out[i] = (in[i] * gr_complex(re, -im)).imag();

    // Adjust PLL phase/frequency
    float error = phase_wrap(gr::fast_atan2f(in[i].imag(), in[i].real()) - d_phase);
    d_freq = gr::branchless_clip(d_freq + error * d_beta, d_max_offset);
    d_phase = phase_wrap(d_phase + error * d_alpha + d_freq);
  }

  return noutput_items;
}

} /* namespace hrpt */
} /* namespace gr */
