# MsiEnumComponentQualifiersW function

## Description

The
**MsiEnumComponentQualifiers** function enumerates the advertised qualifiers for the given component. This function retrieves one qualifier each time it is called.

## Parameters

### `szComponent` [in]

Specifies component whose qualifiers are to be enumerated.

### `iIndex` [in]

Specifies the index of the qualifier to retrieve. This parameter should be zero for the first call to the
**MsiEnumComponentQualifiers** function and then incremented for subsequent calls. Because qualifiers are not ordered, any new qualifier has an arbitrary index. This means that the function can return qualifiers in any order.

### `lpQualifierBuf` [out]

Pointer to a buffer that receives the qualifier code.

### `pcchQualifierBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpQualifierBuf* parameter. On input, this size should include the terminating null character. On return, the value does not include the null character.

### `lpApplicationDataBuf` [out]

Pointer to a buffer that receives the application registered data for the qualifier. This parameter can be null.

### `pcchApplicationDataBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpApplicationDataBuf* parameter. On input, this size should include the terminating null character. On return, the value does not include the null character. This parameter can be null only if the *lpApplicationDataBuf*  parameter is null.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |
| **ERROR_NO_MORE_ITEMS** | There are no qualifiers to return. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system does not have enough memory to complete the operation. Available with Windows Server 2003. |
| **ERROR_SUCCESS** | A value was enumerated. |
| **ERROR_UNKNOWN_COMPONENT** | The specified component is unknown. |

## Remarks

To enumerate qualifiers, an application should initially call the
**MsiEnumComponentQualifiers** function with the *iIndex*  parameter set to zero. The application should then increment the  *iIndex*  parameter and call
**MsiEnumComponentQualifiers** until there are no more qualifiers (that is, until the function returns ERROR_NO_MORE_ITEMS).

When
**MsiEnumComponentQualifiers** returns, the *pcchQualifierBuf* parameter contains the length of the qualifier string stored in the buffer. The count returned does not include the terminating null character. If the buffer is not big enough,
**MsiEnumComponentQualifiers** returns ERROR_MORE_DATA, and this parameter contains the size of the string, in characters, without counting the null character. The same mechanism applies to *pcchDescriptionBuf*.

When making multiple calls to
**MsiEnumComponentQualifiers** to enumerate all of the component's advertised qualifiers, each call should be made from the same thread.

> [!NOTE]
> The msi.h header defines MsiEnumComponentQualifiers as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)