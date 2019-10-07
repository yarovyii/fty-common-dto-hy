################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

if (NOT MSVC)
    include(FindPkgConfig)
    pkg_check_modules(PC_LOG4CPLUS "log4cplus")
    if (PC_LOG4CPLUS_FOUND)
        # add CFLAGS from pkg-config file, e.g. draft api.
        add_definitions(${PC_LOG4CPLUS_CFLAGS} ${PC_LOG4CPLUS_CFLAGS_OTHER})
        # some libraries install the headers is a subdirectory of the include dir
        # returned by pkg-config, so use a wildcard match to improve chances of finding
        # headers and SOs.
        set(PC_LOG4CPLUS_INCLUDE_HINTS ${PC_LOG4CPLUS_INCLUDE_DIRS} ${PC_LOG4CPLUS_INCLUDE_DIRS}/*)
        set(PC_LOG4CPLUS_LIBRARY_HINTS ${PC_LOG4CPLUS_LIBRARY_DIRS} ${PC_LOG4CPLUS_LIBRARY_DIRS}/*)
    endif(PC_LOG4CPLUS_FOUND)
endif (NOT MSVC)

find_path (
    LOG4CPLUS_INCLUDE_DIRS
    NAMES log4cplus/logger.h
    HINTS ${PC_LOG4CPLUS_INCLUDE_HINTS}
)

find_library (
    LOG4CPLUS_LIBRARIES
    NAMES log4cplus
    HINTS ${PC_LOG4CPLUS_LIBRARY_HINTS}
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
    LOG4CPLUS
    REQUIRED_VARS LOG4CPLUS_LIBRARIES LOG4CPLUS_INCLUDE_DIRS
)
mark_as_advanced(
    LOG4CPLUS_FOUND
    LOG4CPLUS_LIBRARIES LOG4CPLUS_INCLUDE_DIRS
)

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
