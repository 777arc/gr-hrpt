# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT hrpt_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT hrpt_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND hrpt_python_files
    noaa_hrpt_decoder_python.cc
    noaa_hrpt_deframer_python.cc
    noaa_hrpt_pll_cf_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(hrpt 
   ../..
   gr::hrpt
   "${hrpt_python_files}")

install(TARGETS hrpt_python DESTINATION ${GR_PYTHON_DIR}/hrpt COMPONENT pythonapi)
