CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

IF( WIN32 )
#	SET( FLTK_PATCH PATCH_COMMAND patch -p1 --binary < ${CMAKE_SOURCE_DIR}/foo.patch )
#	SET( FLTK_PATCH PATCH_COMMAND ${CMAKE_COMMAND} -E copy_if_different
#		"${CMAKE_CURRENT_SOURCE_DIR}/FLTK_JPEG_CMakeLists.txt"
#		"<SOURCE_DIR>/jpeg/CMakeLists.txt" )
    SET( FLTK_AUX_OPTION -DHAVE_STRINGS_H=0 -DHAVE_DLFCN_H=0 -DHAVE_DIRENT_H=0 )
ELSE()
#	SET( FLTK_PATCH PATCH_COMMAND patch -p1 < ${CMAKE_SOURCE_DIR}/foo.patch )
    SET( FLTK_AUX_OPTION )
ENDIF()

#    ${FLTK_PATCH}

ExternalProject_Add( FLTK

	URL ${CMAKE_SOURCE_DIR}/fltk-47ba6632b1be.zip
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
		-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
		-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
		-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
		-DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
		-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
		-DFLTK_BUILD_TEST:BOOL=OFF
		-DOPTION_USE_SYSTEM_LIBJPEG:BOOL=OFF
		-DOPTION_USE_SYSTEM_ZLIB:BOOL=OFF
		-DOPTION_USE_SYSTEM_LIBPNG:BOOL=OFF
		${FLTK_AUX_OPTION}
)
ExternalProject_Get_Property( FLTK INSTALL_DIR )
SET( FLTK_INSTALL_DIR ${INSTALL_DIR} )

IF( APPLE )
	ExternalProject_Add_Step( FLTK PostInstall
		COMMAND ${CMAKE_COMMAND} -E make_directory ${INSTALL_DIR}/FLTK
		COMMAND ${CMAKE_COMMAND} -E rename ${INSTALL_DIR}/FLTK.framework ${INSTALL_DIR}/FLTK/.framework
		DEPENDEES install
	)
ENDIF()
