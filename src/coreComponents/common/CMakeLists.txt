#
# Specify all headers
#
set( common_headers
     ${CMAKE_BINARY_DIR}/include/common/GeosxConfig.hpp
     BufferAllocator.hpp
     DataLayouts.hpp
     DataTypes.hpp
     FieldSpecificationOps.hpp
     Format.hpp
     GEOS_RAJA_Interface.hpp
     GeosxMacros.hpp
     Logger.hpp
     MpiWrapper.hpp
     Path.hpp
     Span.hpp
     Stopwatch.hpp
     Timer.hpp
     Tensor.hpp
     TimingMacros.hpp
     TypeDispatch.hpp
     initializeEnvironment.hpp
     LifoStorage.hpp
     LifoStorageCommon.hpp
     LifoStorageHost.hpp
     FixedSizeDeque.hpp
     FixedSizeDequeWithMutexes.hpp
     MultiMutexesLock.hpp
     PhysicsConstants.hpp
     Units.hpp
   )

if ( ENABLE_CUDA )
  list( APPEND common_headers LifoStorageCuda.hpp )
endif( )

#
# Specify all sources
#
set( common_sources
     BufferAllocator.cpp
     DataTypes.cpp
     Logger.cpp
     MpiWrapper.cpp
     Path.cpp
     initializeEnvironment.cpp
   )

set( dependencyList ${parallelDeps} lvarray pugixml::pugixml RAJA chai conduit::conduit fmt::fmt )

if ( ENABLE_MKL )
  set( dependencyList ${dependencyList} mkl )
endif()

if( ENABLE_CALIPER )
  set( dependencyList ${dependencyList} caliper )
endif()

if( ENABLE_CALIPER )
  set( dependencyList ${dependencyList} caliper )

  if (TARGET adiak::adiak)
    set( dependencyList ${dependencyList} adiak::adiak )
  endif()

  if (TARGET adiak)
    set( dependencyList ${dependencyList} adiak )
  endif()
endif()

blt_add_library( NAME       common
                 SOURCES    ${common_sources}
                 HEADERS    ${common_headers}
                 DEPENDS_ON ${dependencyList}
                 OBJECT     ${GEOSX_BUILD_OBJ_LIBS}
               )

target_include_directories( common PUBLIC ${CMAKE_BINARY_DIR}/include )
target_include_directories( common PUBLIC ${CMAKE_SOURCE_DIR}/coreComponents )

geosx_add_code_checks(PREFIX common )

if( GEOS_ENABLE_TESTS )
  add_subdirectory( unitTests )
endif()
