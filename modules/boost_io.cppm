// Copyright 2026 Ruben Perez
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

module;

#include <boost/config.hpp>
#include <boost/config/disable_module_warnings.hpp>

export module boost.io;
import std;

#define BOOST_IO_INTERFACE_UNIT
#define BOOST_IN_MODULE_PURVIEW

#include <boost/io_fwd.hpp>
#include <boost/io/ios_state.hpp>
#include <boost/io/nullstream.hpp>
#include <boost/io/ostream_joiner.hpp>
#include <boost/io/ostream_put.hpp>
#include <boost/io/quoted.hpp>
