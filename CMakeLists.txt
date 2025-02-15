cmake_minimum_required(VERSION 3.10)
project(app C)

set(CMAKE_C_COMPILER  "clang")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_INCLUDE_DIR "/opt/homebrew/Cellar/raylib/5.5/include")
set(RAYLIB_LIB_DIR "/opt/homebrew/Cellar/raylib/5.5/lib")

# Habilitar la opción de compilación de tests (pero desactivada por defecto)
#option(BUILD_TESTS "Build unit tests" OFF)

# Si BUILD_TESTS está activado, agregar la carpeta de tests
#if(BUILD_TESTS)
#    enable_testing()
#    add_subdirectory(tests)
#endif()


include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIB_DIR})

# Definir directorios de inclusión
include_directories(include)

# Buscar archivos fuente
file(GLOB SOURCES "src/*.c")

add_executable(app ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib m pthread dl)

# Opciones de compilación
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    -std=c99 \
    -Wall \
    -Werror \
    -Wconversion \
    -Wdouble-promotion \
    -Wno-unused-parameter \
    -Wno-unused-function \
    -Wno-sign-conversion")

# Configuración específica para Debug
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -fsanitize=address -fsanitize=undefined")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g3 -fsanitize=address -fsanitize=undefined")
endif()



