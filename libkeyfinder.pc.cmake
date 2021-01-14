prefix=@CMAKE_INSTALL_PREFIX@
includedir=${prefix}/include
libdir=${prefix}/@CMAKE_INSTALL_LIBDIR@

Name: libKeyFinder
Description: libKeyFinder can be used to estimate the musical key of digital audio
Version: @CMAKE_PROJECT_VERSION@
URL: https://github.com/ibsh/libKeyFinder
Libs: -L${libdir} -lkeyfinder
Cflags: -I${includedir}
