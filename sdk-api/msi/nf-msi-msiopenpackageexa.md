# MsiOpenPackageExA function

## Description

The
**MsiOpenPackageEx** function opens a package to use with functions that access the product database. The
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle) function must be called with the handle when the handle is no longer needed.

**Note** Initialize COM on the same thread before calling the [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), **MsiOpenPackageEx**, or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta) function.

## Parameters

### `szPackagePath` [in]

The path to the package.

### `dwOptions` [in]

The bit flags to indicate whether or not to ignore the computer state. Pass in 0 (zero) to use
[MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea) behavior.

| Constant | Meaning |
| --- | --- |
| **MSIOPENPACKAGEFLAGS_IGNOREMACHINESTATE**<br><br>1 | Ignore the computer state when creating the product handle. |

### `hProduct` [out]

A pointer to a variable that receives the product handle.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration information is corrupt. |
| **ERROR_INSTALL_FAILURE** | The product could not be opened. |
| **ERROR_INSTALL_REMOTE_PROHIBITED** | Windows Installer does not permit installation from a remote desktop connection. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_SUCCESS** | The function completes successfully. |

If this function fails, it may return a system error code. For more information, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

To create a restricted product handle that is independent of the current machine state and incapable of changing the current machine state, use
**MsiOpenPackageEx** with MSIOPENPACKAGEFLAGS_IGNOREMACHINESTATE set in *dwOptions*.

Note that if *dwOptions* is MSIOPENPACKAGEFLAGS_IGNOREMACHINESTATE or 1,
**MsiOpenPackageEx** ignores the current machine state when creating the product handle. If the value of *dwOptions* is 0,
**MsiOpenPackageEx** is the same as
[MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea) and creates a product handle that is dependent upon whether the package specified by *szPackagePath* is already installed on the computer.

The restricted handle created by using
**MsiOpenPackageEx** with MSIOPENPACKAGEFLAGS_IGNOREMACHINESTATE only permits execution of dialogs, a subset of the standard actions, and custom actions that set properties (
[Custom Action Type 35](https://learn.microsoft.com/windows/desktop/Msi/custom-action-type-35),
[Custom Action Type 51](https://learn.microsoft.com/windows/desktop/Msi/custom-action-type-51), and
[Custom Action Type 19](https://learn.microsoft.com/windows/desktop/Msi/custom-action-type-19)). The restricted handle prevents the use of custom actions that run
[Dynamic-Link Libraries](https://learn.microsoft.com/windows/desktop/Msi/dynamic-link-libraries),
[Executable Files](https://learn.microsoft.com/windows/desktop/Msi/executable-files) or
[Scripts](https://learn.microsoft.com/windows/desktop/Msi/scripts).

You can call
[MsiDoAction](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidoactiona) on the following standard actions using the restricted handle. All other actions return ERROR_FUNCTION_NOT_CALLED if called with the restricted handle.

* [ADMIN](https://learn.microsoft.com/windows/desktop/Msi/admin-action)
* [ADVERTISE](https://learn.microsoft.com/windows/desktop/Msi/advertise-action)
* [INSTALL](https://learn.microsoft.com/windows/desktop/Msi/install-action)
* [SEQUENCE](https://learn.microsoft.com/windows/desktop/Msi/sequence-action)
* [AppSearch action](https://learn.microsoft.com/windows/desktop/Msi/appsearch-action)
* [CCPSearch](https://learn.microsoft.com/windows/desktop/Msi/ccpsearch-action)
* [CostFinalize](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action)
* [CostInitialize](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action)
* [FileCost](https://learn.microsoft.com/windows/desktop/Msi/filecost-action)
* [FindRelatedProducts](https://learn.microsoft.com/windows/desktop/Msi/findrelatedproducts-action)
* [IsolateComponents action](https://learn.microsoft.com/windows/desktop/Msi/isolatecomponents-action)
* [LaunchConditions](https://learn.microsoft.com/windows/desktop/Msi/launchconditions-action)
* [MigrateFeatureStates](https://learn.microsoft.com/windows/desktop/Msi/migratefeaturestates-action)
* [ResolveSource](https://learn.microsoft.com/windows/desktop/Msi/resolvesource-action)
* [RMCCPSearch](https://learn.microsoft.com/windows/desktop/Msi/rmccpsearch-action)
* [ValidateProductID](https://learn.microsoft.com/windows/desktop/Msi/validateproductid-action)

The
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle) function must be called when the handle is not needed.

> [!NOTE]
> The msi.h header defines MsiOpenPackageEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).