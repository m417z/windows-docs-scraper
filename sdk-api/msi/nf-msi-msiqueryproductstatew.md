# MsiQueryProductStateW function

## Description

The
**MsiQueryProductState** function returns the installed state for a product.

## Parameters

### `szProduct` [in]

Specifies the product code that identifies the product to be queried.

## Return value

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ABSENT** | The product is installed for a different user. |
| **INSTALLSTATE_ADVERTISED** | The product is advertised but not installed. |
| **INSTALLSTATE_DEFAULT** | The product is installed for the current user. |
| **INSTALLSTATE_INVALIDARG** | An invalid parameter was passed to the function. |
| **INSTALLSTATE_UNKNOWN** | The product is neither advertised or installed. |

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

## Remarks

> [!NOTE]
> The msi.h header defines MsiQueryProductState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).