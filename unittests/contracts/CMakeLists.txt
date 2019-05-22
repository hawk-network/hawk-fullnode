# will be implictly used for any compilation unit if not overrided by SYSTEM_INCLUDE_FOLDERS parameter
# these directories go as -isystem <dir> to avoid warnings from code of third-party libraries

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hawknwk.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/hawknwk.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hawknwk.msig/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/hawknwk.msig/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hawknwk.system/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/hawknwk.system/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hawknwk.token/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/hawknwk.token/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hawknwk.wrap/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/hawknwk.wrap/)
