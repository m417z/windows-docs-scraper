# MsiOpenPackageA function

## Description

The
**MsiOpenPackage** function opens a package to use with the functions that access the product database. The
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle) function must be called with the handle when the handle is not needed.

**Note** Initialize COM on the same thread before calling the **MsiOpenPackage**, [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta) function.

## Parameters

### `szPackagePath` [in]

The path to the package.

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

MsiOpenPackage can accept an opened database handle in the form "#nnnn", where nnnn is the database handle in string form, i.e. #123, instead of a path to the package. This is intended for development tasks such as running validation actions, or for use with database management tools.

> [!NOTE]
> The msi.h header defines MsiOpenPackage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Product Query Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)