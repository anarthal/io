/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_IO_OSTREAM_JOINER_HPP
#define BOOST_IO_OSTREAM_JOINER_HPP

#if defined(BOOST_USE_MODULES) && !defined(BOOST_IO_INTERFACE_UNIT)
#ifndef BOOST_IN_MODULE_PURVIEW
import boost.io;
#endif
#else

#include <boost/config.hpp>
#include <boost/io/detail/config.hpp>
#include <boost/config/std/ostream.hpp>
#include <boost/config/std/string.hpp>
#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/config/std/type_traits.hpp>
#endif
#include <boost/config/std/utility.hpp>
#endif

namespace boost {
namespace io {
namespace detail {

#if !defined(BOOST_NO_CXX11_ADDRESSOF)
template<class T>
inline T*
osj_address(T& o)
{
    return std::addressof(o);
}
#else
template<class T>
inline T*
osj_address(T& obj)
{
    return &obj;
}
#endif

} /* detail */

BOOST_IO_MODULE_EXPORT
template<class Delim, class Char = char,
    class Traits = std::char_traits<Char> >
class ostream_joiner {
public:
    typedef Char char_type;
    typedef Traits traits_type;
    typedef std::basic_ostream<Char, Traits> ostream_type;
    typedef std::output_iterator_tag iterator_category;
    typedef void value_type;
    typedef void difference_type;
    typedef void pointer;
    typedef void reference;

    ostream_joiner(ostream_type& output, const Delim& delim)
        : output_(detail::osj_address(output))
        , delim_(delim)
        , first_(true) { }

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
    ostream_joiner(ostream_type& output, Delim&& delim)
        : output_(detail::osj_address(output))
        , delim_(std::move(delim))
        , first_(true) { }
#endif

    template<class T>
    ostream_joiner& operator=(const T& value) {
        if (!first_) {
            *output_ << delim_;
        }
        first_ = false;
        *output_ << value;
        return *this;
    }

    ostream_joiner& operator*() BOOST_NOEXCEPT {
        return *this;
    }

    ostream_joiner& operator++() BOOST_NOEXCEPT {
        return *this;
    }

    ostream_joiner& operator++(int) BOOST_NOEXCEPT {
        return *this;
    }

private:
    ostream_type* output_;
    Delim delim_;
    bool first_;
};

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
BOOST_IO_MODULE_EXPORT
template<class Char, class Traits, class Delim>
inline ostream_joiner<typename std::decay<Delim>::type, Char, Traits>
make_ostream_joiner(std::basic_ostream<Char, Traits>& output, Delim&& delim)
{
    return ostream_joiner<typename std::decay<Delim>::type, Char,
        Traits>(output, std::forward<Delim>(delim));
}
#else
BOOST_IO_MODULE_EXPORT
template<class Char, class Traits, class Delim>
inline ostream_joiner<Delim, Char, Traits>
make_ostream_joiner(std::basic_ostream<Char, Traits>& output,
    const Delim& delim)
{
    return ostream_joiner<Delim, Char, Traits>(output, delim);
}
#endif

} /* io */
} /* boost */

#endif // #if defined(BOOST_USE_MODULES) ...

#endif
