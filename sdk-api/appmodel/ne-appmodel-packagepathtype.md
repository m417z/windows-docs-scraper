# PackagePathType enumeration

## Description

Indicates the type of folder path to retrieve in a query for the path or other info about a package.

## Constants

### `PackagePathType_Install`

Retrieve the package path in the original install folder for the application.

### `PackagePathType_Mutable`

Retrieve the package path in the mutable install folder for the application, if the application is declared as mutable in the package manifest.

### `PackagePathType_Effective`

Retrieve the package path in the mutable folder if the application is declared as mutable in the package manifest, or in the original install folder if the application is not mutable.

## Remarks

An application has a mutable install folder if it uses the [windows.mutablePackageDirectories extension](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop6-package-extension) in its package manifest. This extension specifies a folder under the %ProgramFiles%\ModifiableWindowsApps path where the contents of the application's install folder are projected so that users can modify the installation files. This feature is currently available only for certain types of desktop PC games that are published by Microsoft and our partners, and it enables these types of games to support mods.

## See also

[GetCurrentPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo2)

[GetCurrentPackagePath2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagepath2)

[GetPackagePathByFullName2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackagepathbyfullname2)

[GetPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo2)

[GetStagedPackagePathByFullName2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getstagedpackagepathbyfullname2)