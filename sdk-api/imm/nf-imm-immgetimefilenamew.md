# ImmGetIMEFileNameW function

## Description

Retrieves the file name of the IME associated with the specified input locale.

## Parameters

### `HKL` [in]

Input locale identifier.

### `lpszFileName` [out, optional]

Pointer to a buffer in which the function retrieves the file name. This parameter contains **NULL** when *uBufLen* is set to **NULL**.

### `uBufLen` [in]

Size, in bytes, of the output buffer. The application specifies 0 if the function is to return the buffer size needed to receive the file name, not including the terminating null character. For Unicode, *uBufLen* specifies the size in Unicode characters, not including the terminating null character.

## Return value

Returns the number of bytes in the file name copied to the output buffer. If the application sets *uBufLen* to 0, the function returns the size of the buffer required for the file name. In either case, the terminating null character is not included.

For Unicode, the function returns the number of Unicode characters copied into the output buffer, not including the Unicode terminating null character.

## Remarks

In the registry, the operating system stores the file name as the "IME name value" in the registry key HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Keyboard Layouts\HKL.

> [!NOTE]
> The imm.h header defines ImmGetIMEFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)