/* -*- c++ -*- */
/*
 * Copyright 2022 gr-hrpt author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HRPT_NOAA_HRPT_DECODER_H
#define INCLUDED_HRPT_NOAA_HRPT_DECODER_H

#include <hrpt/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace hrpt {

    /*!
     * \brief <+description of block+>
     * \ingroup hrpt
     *
     */
    class HRPT_API noaa_hrpt_decoder : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<noaa_hrpt_decoder> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of hrpt::noaa_hrpt_decoder.
       *
       * To avoid accidental use of raw pointers, hrpt::noaa_hrpt_decoder's
       * constructor is in a private implementation
       * class. hrpt::noaa_hrpt_decoder::make is the public interface for
       * creating new instances.
       */
      static sptr make(bool verbose, bool output_files);
    };

  } // namespace hrpt
} // namespace gr

#endif /* INCLUDED_HRPT_NOAA_HRPT_DECODER_H */

