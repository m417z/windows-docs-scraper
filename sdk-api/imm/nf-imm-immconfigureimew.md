# ImmConfigureIMEW function

## Description

Displays the configuration dialog box for the IME of the specified input locale identifier.

## Parameters

### `HKL` [in]

Input locale identifier of an IME.

### `HWND` [in]

Handle to the parent window for the dialog box.

### `DWORD` [in]

Flags specifying the type of dialog box to display. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **IME_CONFIG_GENERAL** | Display general-purpose configuration dialog box. |
| **IME_CONFIG_REGISTERWORD** | Display register word dialog box. |
| **IME_CONFIG_SELECTDICTIONARY** | Display dictionary selection dialog box. |

### `LPVOID` [in]

Pointer to supplemental data. If *dwMode* is set to IME_CONFIG_REGISTERWORD, this parameter must indicate a [REGISTERWORD](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-registerworda) structure. If *dwMode* is not IME_CONFIG_REGISTERWORD, this parameter is ignored.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

[REGISTERWORD](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-registerworda)

## Remarks

> [!NOTE]
> The imm.h header defines ImmConfigureIME as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).