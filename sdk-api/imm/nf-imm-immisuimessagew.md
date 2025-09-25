# ImmIsUIMessageW function

## Description

Checks for messages intended for the IME window and sends those messages to the window.

## Parameters

### `HWND` [in]

Handle to a window belonging to the IME window class.

### `UINT` [in]

Message to check.

### `WPARAM` [in]

Message-specific parameter.

### `LPARAM` [in]

Message-specific parameter.

## Return value

Returns a nonzero value if the message is processed by the IME window, or 0 otherwise.

## Remarks

An application typically uses this function to display a composition string or candidate list specified by the IME. If *hWndIME* is **NULL**, the function determines if the message is a user interface message.

**Windows Me/98:** This function has only an ANSI version. To receive Unicode characters from a Unicode-based IME, the application should use [ImmGetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immgetcompositionstringa).

> [!NOTE]
> The imm.h header defines ImmIsUIMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ImmGetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immgetcompositionstringa)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)