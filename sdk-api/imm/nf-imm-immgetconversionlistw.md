# ImmGetConversionListW function

## Description

Retrieves the conversion result list of characters or words without generating any IME-related messages.

## Parameters

### `HKL` [in]

Input locale identifier.

### `HIMC` [in]

Handle to the input context.

### `lpSrc` [in]

Pointer to a null-terminated character string specifying the source of the list.

### `lpDst` [out]

Pointer to a [CANDIDATELIST](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidatelist) structure in which the function retrieves the list.

### `dwBufLen` [in]

Size, in bytes, of the output buffer. The application sets this parameter to 0 if the function is to return the buffer size required for the complete conversion result list.

### `uFlag` [in]

Action flag. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **GCL_CONVERSION** | Source string is the reading string. The function copies the result string to the destination buffer. |
| **GCL_REVERSECONVERSION** | Source string is the result string. The function copies the reading string to the destination buffer. |
| **GCL_REVERSE_LENGTH** | Source string is the result string. The function returns the size, in bytes, of the reading string created if GCL_REVERSECONVERSION is specified. |

## Return value

Returns the number of bytes copied to the output buffer. If the application sets the *dwBufLen* parameter to 0, the function returns the size, in bytes, of the required output buffer.

## See also

[CANDIDATELIST](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidatelist)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

## Remarks

> [!NOTE]
> The imm.h header defines ImmGetConversionList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).