# MsiApplyPatchW function

## Description

For each product listed by the patch package as eligible to receive the patch, the
**MsiApplyPatch** function invokes an installation and sets the
[PATCH](https://learn.microsoft.com/windows/desktop/Msi/patch) property to the path of the patch package.

## Parameters

### `szPatchPackage` [in]

A null-terminated string specifying the full path to the patch package.

### `szInstallPackage` [in]

If *eInstallType* is set to INSTALLTYPE_NETWORK_IMAGE, this parameter is a null-terminated string that specifies a path to the product that is to be patched. The installer applies the patch to every eligible product listed in the patch package if *szInstallPackage* is set to null and *eInstallType* is set to INSTALLTYPE_DEFAULT.

If *eInstallType* is INSTALLTYPE_SINGLE_INSTANCE, the installer applies the patch to the product specified by *szInstallPackage*. In this case, other eligible products listed in the patch package are ignored and the *szInstallPackage* parameter contains the null-terminated string representing the product code of the instance to patch. This type of installation requires the installer running Windows Server 2003 or Windows XP.

### `eInstallType` [in]

This parameter specifies the type of installation to patch.

| Type of installation | Meaning |
| --- | --- |
| **INSTALLTYPE_NETWORK_IMAGE** | Specifies an administrative installation. In this case, *szInstallPackage* must be set to a package path. A value of 1 for INSTALLTYPE_NETWORK_IMAGE sets this for an administrative installation. |
| **INSTALLTYPE_DEFAULT** | Searches system for products to patch. In this case, *szInstallPackage* must be 0. |
| **INSTALLTYPE_SINGLE_INSTANCE** | Patch the product specified by *szInstallPackage*. *szInstallPackage* is the product code of the instance to patch. This type of installation requires the installer running Windows Server 2003 or Windows XP with SP1. For more information see, [Installing Multiple Instances of Products and Patches](https://learn.microsoft.com/windows/desktop/Msi/installing-multiple-instances-of-products-and-patches). |

### `szCommandLine` [in]

A null-terminated string that specifies command line property settings. See About
[Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties) and
[Setting Public Property Values on the Command Line](https://learn.microsoft.com/windows/desktop/Msi/setting-public-property-values-on-the-command-line). See the Remarks section.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_PATCH_PACKAGE_OPEN_FAILED** | Patch package could not be opened. |
| **ERROR_PATCH_PACKAGE_INVALID** | The patch package is invalid. |
| **ERROR_PATCH_PACKAGE_UNSUPPORTED** | The patch package is unsupported. |
| **An error relating to an action** | See [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An initialization error occurred. |

## Remarks

Because the list delimiter for transforms, sources, and patches is a semicolon, this character should not be used for file names or paths.

**Note**

You must set the [REINSTALL](https://learn.microsoft.com/windows/desktop/Msi/reinstall) property on the command line when applying a [small update](https://learn.microsoft.com/windows/desktop/Msi/small-updates) or [minor upgrade](https://learn.microsoft.com/windows/desktop/Msi/minor-upgrades) patch. Without this property, the patch is registered on the system but cannot update files. For patches that do not use a [Custom Action Type 51](https://learn.microsoft.com/windows/desktop/Msi/custom-action-type-51) to automatically set the **REINSTALL** and [REINSTALLMODE](https://learn.microsoft.com/windows/desktop/Msi/reinstallmode) properties, the **REINSTALL** property must be explicitly set with the *szCommandLine* parameter. Set the **REINSTALL** property to list the features affected by the patch, or use a practical default setting of "REINSTALL=ALL". The default value of the **REINSTALLMODE** property is "omus". Beginning with Windows Installer version 3.0, the **REINSTALL** property is configured by the installer and does not need to be set on the command line.

> [!NOTE]
> The msi.h header defines MsiApplyPatch as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes)

[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)