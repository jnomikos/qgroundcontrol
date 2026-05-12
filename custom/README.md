# Custom Build Template

This is a template to get you started fast on QGroundControl. This current template is based on Stable_v5.0.

This custom build template provides a foundation for creating a branded version of QGroundControl tailored to your organization's needs. It includes placeholders and examples for customization points that you can modify to match your branding and requirements.

## Instructions

### 1. Replace Logos with Client Logos

Update the application icons and logos throughout the build to match your client's branding:

- **macOS Icon**: Replace the icon in `custom/res/icons/` with your client's logo
- **Windows Icon**: Update `custom/deploy/windows/WindowsQGC.ico` with your branded icon
- **AppImage Icon**: Replace `custom/res/icons/custom_qgroundcontrol.png` with your logo
- **Splash Screen & UI Assets**: Update any logo files in `custom/res/` directories

### 2. Replace Colors with Client Colors

Customize the color palette to match your client's brand guidelines:

- Modify QML style definitions in `custom/src/` for primary, secondary, and accent colors
- Update any custom stylesheets and theme files
- Ensure contrast and accessibility standards are maintained
- Test the color scheme across all UI components

### 3. Change Custom-QGroundControl App Name

Update the application name throughout the codebase:

- Primary location: `custom/cmake/CustomOverrides.cmake` - Update `QGC_APP_NAME` variable
- Android package name: Update `QGC_ANDROID_PACKAGE_NAME` in the same file
- Update any references in `custom/src/` source code
- Verify the new name appears correctly in all build outputs and installer packaging

### 4. Update GitHub Workflows

Change all "QGroundControl" references to your new app name in CI/CD pipelines:

- Update workflow files in `.github/workflows/` directory
- Modify artifact names and release descriptions
- Update badge URLs and references in workflow YAML files
- Ensure build, test, and deployment scripts reference the correct application name

## Getting Started

1. Review the existing custom build structure in the `custom/` directory
2. Follow the instructions above in order
3. Test the build locally before deploying
4. Refer to the [QGC Dev Guide](https://dev.qgroundcontrol.com/en/custom_build/custom_build.html) for more detailed customization options
