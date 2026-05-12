qt_add_library(CustomUIModule STATIC)

set_source_files_properties(AppSettings/CustomAppSettings.qml PROPERTIES QT_RESOURCE_ALIAS CustomAppSettings.qml)
set_source_files_properties(AppSettings/CustomGeneralSettings.qml PROPERTIES QT_RESOURCE_ALIAS CustomGeneralSettings.qml)
set_source_files_properties(AppSettings/CustomSettingsPagesModel.qml PROPERTIES QT_RESOURCE_ALIAS CustomSettingsPagesModel.qml)

qt_add_qml_module(CustomUIModule
    URI Custom.AppSettings
    VERSION 1.0
    RESOURCE_PREFIX /qml
    QML_FILES
        AppSettings/CustomAppSettings.qml
        AppSettings/CustomGeneralSettings.qml
        AppSettings/CustomSettingsPagesModel.qml
        AppSettings/SettingsPage.qml
    NO_PLUGIN
)
