/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HRPT_NOAA_HRPT_DEFRAMER_H
#define INCLUDED_HRPT_NOAA_HRPT_DEFRAMER_H

#include <hrpt/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace hrpt {

    /*!
     * \brief <+description of block+>
     * \ingroup hrpt
     *
     */
    class HRPT_API noaa_hrpt_deframer : virtual public block
    {
     public:
      typedef std::shared_ptr<noaa_hrpt_deframer> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of hrpt::noaa_hrpt_deframer.
       *
       * To avoid accidental use of raw pointers, hrpt::noaa_hrpt_deframer's
       * constructor is in a private implementation
       * class. hrpt::noaa_hrpt_deframer::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace hrpt
} // namespace gr

#endif /* INCLUDED_HRPT_NOAA_HRPT_DEFRAMER_H */

