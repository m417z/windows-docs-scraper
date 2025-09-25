# MsiGetProductCodeW function

## Description

The
**MsiGetProductCode** function returns the product code of an application by using the component code of an installed or advertised component of the application. During initialization, an application must determine under which product code it has been installed or advertised.

## Parameters

### `szComponent` [in]

This parameter specifies the component code of a component that has been installed by the application. This will be typically the component code of the component containing the executable file of the application.

### `lpBuf39` [out]

Pointer to a buffer that receives the product code. This buffer must be 39 characters long. The first 38 characters are for the GUID, and the last character is for the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INSTALL_FAILURE** | The product code could not be determined. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_COMPONENT** | The specified component is unknown. |

## Remarks

During initialization, an application must determine the product code under which it was installed. An application can be part of different products in different installations. For example, an application can be part of a suite of applications, or it can be installed by itself.

> [!NOTE]
> The msi.h header defines MsiGetProductCode as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Application-Only Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)