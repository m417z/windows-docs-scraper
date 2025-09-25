# ImmGetDescriptionW function

## Description

Copies the description of the IME to the specified buffer.

## Parameters

### `HKL` [in]

Input locale identifier.

### `lpszDescription` [out, optional]

Pointer to a buffer in which the function retrieves the null-terminated string describing the IME.

### `uBufLen` [in]

Size, in characters, of the output buffer. The application sets this parameter to 0 if the function is to return the buffer size needed for the complete description, excluding the terminating null character.

**Windows NT, Windows 2000, Windows XP:** The size of the buffer is in Unicode characters, each consisting of two bytes. If the parameter is set to 0, the function returns the size of the buffer required in Unicode characters, excluding the Unicode terminating null character.

## Return value

Returns the number of characters copied to the output buffer. If the application sets the *uBufLen* parameter to 0, the function returns the size of the buffer required to receive the description. Neither value includes the terminating null character. For Unicode, the function returns the number of Unicode characters, not including the Unicode terminating null character.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

## Remarks

> [!NOTE]
> The immdev.h header defines ImmGetDescription as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).