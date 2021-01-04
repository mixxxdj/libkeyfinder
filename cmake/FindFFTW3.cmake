#[=======================================================================[.rst:
FindFFTW3
--------

Finds the FFTW3 library.

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``FFTW3::fftw3``
  The FFTW3 library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``FFTW3_FOUND``
  True if the system has the FFTW3 library.
``FFTW3_INCLUDE_DIRS``
  Include directories needed to use FFTW3.
``FFTW3_LIBRARIES``
  Libraries needed to link to FFTW3.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``FFTW3_INCLUDE_DIR``
  The directory containing ``fftw3.h``.
``FFTW3_LIBRARY``
  The path to the FFTW3 library.

#]=======================================================================]

find_path(FFTW3_INCLUDE_DIR
  NAMES fftw3.h
  DOC "FFTW3 include directory")
mark_as_advanced(FFTW3_INCLUDE_DIR)

find_library(FFTW3_LIBRARY
  NAMES fftw fftw3 fftw-3.3
  DOC "FFTW3 library"
)
mark_as_advanced(FFTW3_LIBRARY)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  FFTW3
  DEFAULT_MSG
  FFTW3_LIBRARY
  FFTW3_INCLUDE_DIR
)

if(FFTW3_FOUND)
  set(FFTW3_LIBRARIES "${FFTW3_LIBRARY}")
  set(FFTW3_INCLUDE_DIRS "${FFTW3_INCLUDE_DIR}")

  if(NOT TARGET FFTW3::fftw3)
    add_library(FFTW3::fftw3 UNKNOWN IMPORTED)
    set_target_properties(FFTW3::fftw3
      PROPERTIES
        IMPORTED_LOCATION "${FFTW3_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${FFTW3_INCLUDE_DIR}"
    )
  endif()
endif()
