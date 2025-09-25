# MsiOpenProductW function

## Description

The
**MsiOpenProduct** function opens a product for use with the functions that access the product database. The
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle) function must be called with the handle when the handle is no longer needed.

**Note** Initialize COM on the same thread before calling the [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or **MsiOpenProduct** function.

## Parameters

### `szProduct` [in]

Specifies the product code of the product to be opened.

### `hProduct` [out]

Pointer to a variable that receives the product handle.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration information is corrupt. |
| **ERROR_INSTALL_FAILURE** | The product could not be opened. |
| **ERROR_INSTALL_SOURCE_ABSENT** | The source was unavailable. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product code was unrecognized. |

## See also

[Product Query Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

## Remarks

> [!NOTE]
> The msi.h header defines MsiOpenProduct as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).