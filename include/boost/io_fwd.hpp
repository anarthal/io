/*
Copyright 2002 Daryle Walker

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_IO_FWD_HPP
#define BOOST_IO_FWD_HPP

#if defined(BOOST_USE_MODULES) && !defined(BOOST_IO_INTERFACE_UNIT)
#ifndef BOOST_IN_MODULE_PURVIEW
import boost.io;
#endif
#else

#include <boost/config/std/iosfwd.hpp>

#include <boost/io/detail/config.hpp>

namespace boost {
namespace io {

BOOST_IO_MODULE_EXPORT class ios_flags_saver;
BOOST_IO_MODULE_EXPORT class ios_precision_saver;
BOOST_IO_MODULE_EXPORT class ios_width_saver;
BOOST_IO_MODULE_EXPORT class ios_base_all_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_iostate_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_exception_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_tie_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_rdbuf_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_fill_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_locale_saver;

BOOST_IO_MODULE_EXPORT template<class Ch, class Tr = std::char_traits<Ch> >
class basic_ios_all_saver;

BOOST_IO_MODULE_EXPORT typedef basic_ios_iostate_saver<char>      ios_iostate_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_iostate_saver<wchar_t>   wios_iostate_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_exception_saver<char>    ios_exception_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_exception_saver<wchar_t> wios_exception_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_tie_saver<char>          ios_tie_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_tie_saver<wchar_t>       wios_tie_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_rdbuf_saver<char>        ios_rdbuf_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_rdbuf_saver<wchar_t>     wios_rdbuf_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_fill_saver<char>         ios_fill_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_fill_saver<wchar_t>      wios_fill_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_locale_saver<char>       ios_locale_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_locale_saver<wchar_t>    wios_locale_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_all_saver<char>          ios_all_saver;
BOOST_IO_MODULE_EXPORT typedef basic_ios_all_saver<wchar_t>       wios_all_saver;

BOOST_IO_MODULE_EXPORT class ios_iword_saver;
BOOST_IO_MODULE_EXPORT class ios_pword_saver;
BOOST_IO_MODULE_EXPORT class ios_all_word_saver;

} /* io */
} /* boost */

#endif // #if defined(BOOST_USE_MODULES) ...

#endif
