# ImmUnregisterWordA function

## Description

Removes a register string from the dictionary of the IME associated with the specified input locale.

## Parameters

### `HKL` [in]

Input locale identifier.

### `lpszReading` [in]

Pointer to a null-terminated reading string associated with the string to remove.

### `DWORD` [in]

Style of the register string. This parameter can have any of the following values.

| Value | Meaning |
| --- | --- |
| **IME_REGWORD_STYLE_EUDC** | The string is in the end-user-defined character (EUDC) range. |
| **Any value from IME_REGWORD_STYLE_USER_FIRST to IME_REGWORD_STYLE_USER_LAST** | The string is in a private style maintained by the specified IME. |

### `lpszUnregister` [in]

Pointer to a null-terminated string specifying the register string to remove.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

## Remarks

> [!NOTE]
> The imm.h header defines ImmUnregisterWord as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).