include(CreateCPackCommon)

set(CPACK_GENERATOR "NSIS")

set(QGC_INSTALLER_SOURCE "${CMAKE_BINARY_DIR}/deploy/windows")

set(CPACK_NSIS_INSTALL_ROOT "C:\\\\Program Files")
set(CPACK_NSIS_MUI_ICON "${QGC_INSTALLER_SOURCE}/WindowsQGC.ico")
set(CPACK_NSIS_MUI_UNIICON "${QGC_INSTALLER_SOURCE}/WindowsQGC.ico")
# set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
# set(CPACK_NSIS_MUI_WELCOMEFINISHPAGE_BITMAP "")
# set(CPACK_NSIS_MUI_UNWELCOMEFINISHPAGE_BITMAP "")
# set(CPACK_NSIS_EXTRA_PREINSTALL_COMMANDS "")
# set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "")
# set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "")
# set(CPACK_NSIS_COMPRESSOR "")
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_DISPLAY_NAME "${CMAKE_PROJECT_NAME}")
set(CPACK_NSIS_PACKAGE_NAME "${CMAKE_PROJECT_NAME} x64 ${CMAKE_PROJECT_VERSION}")
# set(CPACK_NSIS_INSTALLED_ICON_NAME "")
set(CPACK_NSIS_HELP_LINK "http://qgroundcontrol.com/#resources")
set(CPACK_NSIS_URL_INFO_ABOUT ${CPACK_PACKAGE_HOMEPAGE_URL})
# set(CPACK_NSIS_CONTACT "")
# set(CPACK_NSIS_<compName>_INSTALL_DIRECTORY "")
# set(CPACK_NSIS_CREATE_ICONS_EXTRA "")
# set(CPACK_NSIS_DELETE_ICONS_EXTRA "")
# set(CPACK_NSIS_EXECUTABLES_DIRECTORY "")
# set(CPACK_NSIS_MUI_FINISHPAGE_RUN "")
# set(CPACK_NSIS_MENU_LINKS "")
# set(CPACK_NSIS_UNINSTALL_NAME "")
# set(CPACK_NSIS_WELCOME_TITLE "")
# set(CPACK_NSIS_WELCOME_TITLE_3LINES "")
# set(CPACK_NSIS_FINISH_TITLE "")
# set(CPACK_NSIS_FINISH_TITLE_3LINES "")
set(CPACK_NSIS_MUI_HEADERIMAGE "${QGC_INSTALLER_SOURCE}/installheader.bmp")
# set(CPACK_NSIS_MANIFEST_DPI_AWARE "")
# set(CPACK_NSIS_BRANDING_TEXT "")
# set(CPACK_NSIS_BRANDING_TEXT_TRIM_POSITION "")
# set(CPACK_NSIS_EXECUTABLE "")
set(CPACK_NSIS_IGNORE_LICENSE_PAGE OFF)
# set(CPACK_NSIS_EXECUTABLE_PRE_ARGUMENTS "")
# set(CPACK_NSIS_EXECUTABLE_POST_ARGUMENTS "")

include(CPack)