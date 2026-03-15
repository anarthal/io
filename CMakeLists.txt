# Copyright 2018 Mike Dev
# Distributed under the Boost Software License, Version 1.0.
# (http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.5...3.20)

project(boost_io VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

if (BOOST_USE_MODULES)
  add_library(boost_io STATIC)
  target_sources(boost_io PUBLIC FILE_SET CXX_MODULES BASE_DIRS modules FILES modules/boost_io.cppm)
  set(__scope PUBLIC)

  target_compile_features(boost_io PUBLIC cxx_std_23)
  set_target_properties(boost_io PROPERTIES CXX_MODULE_STD ON)
  target_compile_definitions(boost_io PUBLIC BOOST_USE_MODULES)
else()
  add_library(boost_io INTERFACE)
  set(__scope INTERFACE)
endif()

add_library(Boost::io ALIAS boost_io)

target_include_directories(boost_io ${__scope} include)

target_link_libraries(boost_io
  ${__scope}
    Boost::config
)
