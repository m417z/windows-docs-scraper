# MsiEnumComponentsW function

## Description

The
**MsiEnumComponents** function enumerates the installed components for all products. This function retrieves one component code each time it is called.

## Parameters

### `iComponentIndex` [in]

Specifies the index of the component to retrieve. This parameter should be zero for the first call to the
**MsiEnumComponents** function and then incremented for subsequent calls. Because components are not ordered, any new component has an arbitrary index. This means that the function can return components in any order.

### `lpComponentBuf` [out]

Pointer to a buffer that receives the component code. This buffer must be 39 characters long. The first 38 characters are for the
[GUID](https://learn.microsoft.com/windows/desktop/Msi/guid), and the last character is for the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no components to return. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system does not have enough memory to complete the operation. Available with Windows Server 2003. |
| **ERROR_SUCCESS** | A value was enumerated. |

## Remarks

To enumerate components, an application should initially call the
**MsiEnumComponents** function with the *iComponentIndex* parameter set to zero. The application should then increment the *iComponentIndex* parameter and call
**MsiEnumComponents** until there are no more components (that is, until the function returns ERROR_NO_MORE_ITEMS).

When making multiple calls to
**MsiEnumComponents** to enumerate all of the product's components, each call should be made from the same thread.

> [!NOTE]
> The msi.h header defines MsiEnumComponents as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)