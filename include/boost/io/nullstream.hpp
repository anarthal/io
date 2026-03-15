/*
Copyright 2021-2022 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_IO_NULLSTREAM_HPP
#define BOOST_IO_NULLSTREAM_HPP

#if defined(BOOST_USE_MODULES) && !defined(BOOST_IO_INTERFACE_UNIT)
#ifndef BOOST_IN_MODULE_PURVIEW
import boost.io;
#endif
#else

#include <boost/config.hpp>
#include <boost/io/detail/config.hpp>
#include <boost/config/std/ostream.hpp>
#include <boost/config/std/streambuf.hpp>

namespace boost {
namespace io {

BOOST_IO_MODULE_EXPORT
template<class CharT, class Traits = std::char_traits<CharT> >
class basic_nullbuf
    : public std::basic_streambuf<CharT, Traits> {
protected:
    typename Traits::int_type overflow(typename Traits::int_type c)
        BOOST_OVERRIDE {
        return Traits::not_eof(c);
    }

    std::streamsize xsputn(const CharT*, std::streamsize n) BOOST_OVERRIDE {
        return n;
    }
};

namespace detail {

template<class CharT, class Traits>
class nullbuf {
public:
    boost::io::basic_nullbuf<CharT, Traits>* buf() {
        return &buf_;
    }

private:
    boost::io::basic_nullbuf<CharT, Traits> buf_;
};

} /* detail */

BOOST_IO_MODULE_EXPORT
template<class CharT, class Traits = std::char_traits<CharT> >
class basic_onullstream
    : detail::nullbuf<CharT, Traits>
    , public std::basic_ostream<CharT, Traits> {
public:
    basic_onullstream()
        : std::basic_ostream<CharT, Traits>(detail::nullbuf<CharT,
             Traits>::buf()) { }
};

BOOST_IO_MODULE_EXPORT typedef basic_onullstream<char> onullstream;
BOOST_IO_MODULE_EXPORT typedef basic_onullstream<wchar_t> wonullstream;

} /* io */
} /* boost */

#endif // #if defined(BOOST_USE_MODULES) ...

#endif
