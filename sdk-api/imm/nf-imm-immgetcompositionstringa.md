# ImmGetCompositionStringA function

## Description

Retrieves information about the composition string.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `DWORD` [in]

Index of the information to retrieve, which is one of the values specified in [IME Composition String Values](https://learn.microsoft.com/windows/desktop/Intl/ime-composition-string-values). For each value except GCS_CURSORPOS and GCS_DELTASTART, the function copies the requested information to the output buffer. The function returns the cursor and delta position values in the low 16 bits of the return value.

### `lpBuf` [out, optional]

Pointer to a buffer in which the function retrieves the composition string information.

### `dwBufLen` [in]

Size, in bytes, of the output buffer, even if the output is a Unicode string. The application sets this parameter to 0 if the function is to return the size of the required output buffer.

## Return value

Returns the number of bytes copied to the output buffer. If *dwBufLen* is set to 0, the function returns the buffer size, in bytes, required to receive all requested information, excluding the terminating null character. The return value is always the size, in bytes, even if the requested data is a Unicode string.

This function returns one of the following negative error codes if it does not succeed:

* IMM_ERROR_NODATA. Composition data is not ready in the input context.
* IMM_ERROR_GENERAL. General error detected by IME.

## Remarks

An application calls this function in response to the [WM_IME_COMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-composition) or [WM_IME_STARTCOMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-startcomposition) message. The IMM removes the information when the application calls the [ImmReleaseContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immreleasecontext) function.

**Note** You must write code to handle both full-width Hiragana and half-width Katakana if your application is used with the Soft Input Panel (SIP).

> [!NOTE]
> The imm.h header defines ImmGetCompositionString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ImmReleaseContext](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immreleasecontext)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

[WM_IME_COMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-composition)

[WM_IME_STARTCOMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-startcomposition)