## Description

Indicates the type of folder path to retrieve in a query for the path or other info about a package.

## Constants

### `PackagePathType_Install`

Retrieve the package's install path.

### `PackagePathType_Mutable`

If the package has a [Mutable location](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop8-mutablepackagedirectories), then retrieve the package's Mutable path.

### `PackagePathType_Effective`

Specifies that the package path should be retrieved according to the following logic:

* If the package has a User-External location, then return that path.
* Otherwise, if the package has a Machine-External location, then return that path.
* Otherwise, if the package has a [Mutable location](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop8-mutablepackagedirectories), then return the Mutable path. Also see [Create a directory in any location based on packaged app directory](https://learn.microsoft.com/windows/msix/manage/create-directory).
* Otherwise, return the package's Install path.

### `PackagePathType_MachineExternal`

Specifies that the package path should be retrieved according to the following logic:

* If the package has a Machine-External location, then return that path.
* Otherwise, return an error.

### `PackagePathType_UserExternal`

Specifies that the package path should be retrieved according to the following logic:

* If the package has a User-External location, then return that path.
* Otherwise, return an error.

### `PackagePathType_EffectiveExternal`

Specifies that the package path should be retrieved according to the following logic:

* If the package has a User-External location, then return that path.
* Otherwise, if the package has a Machine-External location, then return that path.
* Otherwise, return an error.

## Remarks

An application has a mutable install folder if it uses the [windows.mutablePackageDirectories extension](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop8-mutablepackagedirectories) in its package manifest. This extension specifies a folder under the %ProgramFiles%\ModifiableWindowsApps path where the contents of the application's install folder are projected so that users can modify the installation files.

> [!IMPORTANT]
> This feature requires the **modifiableApp** [restricted capability](https://learn.microsoft.com/windows/uwp/packaging/app-capability-declarations). Microsoft Store policy requires packages with that capability to be certain types of desktop PC games that are published by Microsoft and its partners.

A package always has an Install location. A package can also have a Mutable, Machine External and/or User External location.

The concept of "effective" is the location that has the highest precedence for the package/user.

## See also

* [GetCurrentPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo2)
* [GetCurrentPackagePath2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackagepath2)
* [GetPackagePathByFullName2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackagepathbyfullname2)
* [GetPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo2)
* [GetStagedPackagePathByFullName2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getstagedpackagepathbyfullname2)
* [desktop6:MutablePackageDirectories](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop6-mutablepackagedirectories)
* [desktop8:MutablePackageDirectories](https://learn.microsoft.com/uwp/schemas/appxpackage/uapmanifestschema/element-desktop8-mutablepackagedirectories)
* [Package.MutableLocation property](https://learn.microsoft.com/uwp/api/windows.applicationmodel.package.mutablelocation)
* [Package.MutablePath property](https://learn.microsoft.com/uwp/api/windows.applicationmodel.package.mutablepath)