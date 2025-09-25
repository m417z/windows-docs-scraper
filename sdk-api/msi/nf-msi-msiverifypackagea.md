# MsiVerifyPackageA function

## Description

The
**MsiVerifyPackage** function verifies that the given file is an installation package.

## Parameters

### `szPackagePath` [in]

Specifies the path and file name of the package.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INSTALL_PACKAGE_INVALID** | The file is not a valid package. |
| **ERROR_INSTALL_PACKAGE_OPEN_FAILED** | The file could not be opened. |
| **ERROR_INVALID_PARAMETER** | The parameter is not valid. |
| **ERROR_SUCCESS** | The file is a package. |

## Remarks

> [!NOTE]
> The msi.h header defines MsiVerifyPackage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).