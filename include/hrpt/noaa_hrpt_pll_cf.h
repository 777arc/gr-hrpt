/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HRPT_NOAA_HRPT_PLL_CF_H
#define INCLUDED_HRPT_NOAA_HRPT_PLL_CF_H

#include <hrpt/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace hrpt {

    /*!
     * \brief <+description of block+>
     * \ingroup hrpt
     *
     */
    class HRPT_API noaa_hrpt_pll_cf : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<noaa_hrpt_pll_cf> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of hrpt::noaa_hrpt_pll_cf.
       *
       * To avoid accidental use of raw pointers, hrpt::noaa_hrpt_pll_cf's
       * constructor is in a private implementation
       * class. hrpt::noaa_hrpt_pll_cf::make is the public interface for
       * creating new instances.
       */
      static sptr make(float alpha, float beta, float max_offset);
      
      virtual void set_alpha(float alpha) = 0;
      virtual void set_beta(float beta) = 0;
      virtual void set_max_offset(float max_offset) = 0;
    };

  } // namespace hrpt
} // namespace gr

#endif /* INCLUDED_HRPT_NOAA_HRPT_PLL_CF_H */

