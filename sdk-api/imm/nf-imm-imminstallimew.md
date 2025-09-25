# ImmInstallIMEW function

## Description

Installs an IME.

## Parameters

### `lpszIMEFileName` [in]

Pointer to a null-terminated string that specifies the full path of the IME.

### `lpszLayoutText` [in]

Pointer to a null-terminated string that specifies the name of the IME and the associated layout text.

## Return value

Returns the input locale identifier for the IME.

## Remarks

This function is intended to be used by IME setup applications only.

> [!NOTE]
> The imm.h header defines ImmInstallIME as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)