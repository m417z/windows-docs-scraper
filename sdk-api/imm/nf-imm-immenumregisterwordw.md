# ImmEnumRegisterWordW function

## Description

Enumerates the register strings having the specified reading string, style, and register string.

## Parameters

### `HKL` [in]

Input locale identifier.

### `REGISTERWORDENUMPROCW`

TBD

### `lpszReading` [in, optional]

Pointer to the reading string to enumerate. The application sets this parameter to **NULL** if the function is to enumerate all available reading strings that match the *dwStyle* and *lpszRegister* settings.

### `DWORD` [in]

Style to enumerate. The application specifies 0 if the function is to enumerate all available styles that match the *lpszReading* and *lpszRegister* settings.

### `lpszRegister` [in, optional]

Pointer to the register string to enumerate. The application sets this parameter to **NULL** if the function is to enumerate all register strings that match the *lpszReading* and *dwStyle* settings.

### `LPVOID` [in]

Pointer to application-supplied data. The function passes this data to the callback function.

#### - REGISTERWORDENUMPROCA [in]

Pointer to the callback function. For more information, see [EnumRegisterWordProc](https://learn.microsoft.com/windows/desktop/api/imm/nc-imm-registerwordenumproca).

## Return value

Returns the last value returned by the callback function, with the meaning defined by the application. The function returns 0 if it cannot enumerate the register strings.

## Remarks

If *dwStyle* is set to 0 and both *lpszReading* and *lpszRegister* are set to **NULL**, this function enumerates all register strings in the IME dictionary.

> [!NOTE]
> The imm.h header defines ImmEnumRegisterWord as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumRegisterWordProc](https://learn.microsoft.com/windows/desktop/api/imm/nc-imm-registerwordenumproca)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)