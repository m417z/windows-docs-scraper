# MsiGetProductPropertyW function

## Description

The
**MsiGetProductProperty** function retrieves product properties. These properties are in the product database.

## Parameters

### `hProduct` [in]

Handle to the product obtained from
[MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szProperty` [in]

Specifies the property to retrieve. This is case-sensitive.

### `lpValueBuf` [out]

Pointer to a buffer that receives the property value. The value is truncated and null-terminated if *lpValueBuf* is too small. This parameter can be null.

### `pcchValueBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpValueBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpValueBuf* is null, *pcchValueBuf* can be null.

## Return value

The
**MsiGetProductProperty** function return the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_INVALID_HANDLE** | An invalid handle was passed to the function. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the entire property value. |
| **ERROR_SUCCESS** | The function completed successfully. |

## Remarks

When the
**MsiGetProductProperty** function returns, the *pcchValueBuf* parameter contains the length of the string stored in the buffer. The count returned does not include the terminating null character. If the buffer is not big enough,
**MsiGetProductProperty** returns ERROR_MORE_DATA, and
**MsiGetProductProperty** contains the size of the string, in characters, without counting the null character.

> [!NOTE]
> The msi.h header defines MsiGetProductProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Product Query Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)