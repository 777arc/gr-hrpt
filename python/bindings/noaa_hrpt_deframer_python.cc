/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(noaa_hrpt_deframer.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(2916af3e8d94bb1b52540c4900fd20ab)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <hrpt/noaa_hrpt_deframer.h>
// pydoc.h is automatically generated in the build directory
#include <noaa_hrpt_deframer_pydoc.h>

void bind_noaa_hrpt_deframer(py::module& m)
{

    using noaa_hrpt_deframer    = ::gr::hrpt::noaa_hrpt_deframer;


    py::class_<noaa_hrpt_deframer, gr::block, gr::basic_block,
        std::shared_ptr<noaa_hrpt_deframer>>(m, "noaa_hrpt_deframer", D(noaa_hrpt_deframer))

        .def(py::init(&noaa_hrpt_deframer::make),
           D(noaa_hrpt_deframer,make)
        )
        



        ;




}








