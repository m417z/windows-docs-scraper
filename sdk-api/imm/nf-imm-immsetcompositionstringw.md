# ImmSetCompositionStringW function

## Description

Sets the characters, attributes, and clauses of the composition and reading strings.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `dwIndex` [in]

Type of information to set. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **SCS_SETSTR** | Set the composition string, the reading string, or both. At least one of the *lpComp* and *lpRead* parameters must indicate a valid string. If either string is too long, the IME truncates it. |
| **SCS_CHANGEATTR** | Set attributes for the composition string, the reading string, or both. At least one of the *lpComp* and *lpRead* parameters must indicate a valid attribute array. |
| **SCS_CHANGECLAUSE** | Set the clause information for the composition string, the reading string, or both. At least one of the *lpComp* and *lpRead* parameters must point to a valid clause information array. |
| **SCS_SETRECONVERTSTRING** | **Windows Me/98, Windows 2000, Windows XP:** Ask IME to reconvert the string using a specified [RECONVERTSTRING](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-reconvertstring) structure. |
| **SCS_QUERYRECONVERTSTRING** | **Windows Me/98, Windows 2000, Windows XP:** Ask IME to adjust the [RECONVERTSTRING](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-reconvertstring) structure. Then the application can pass the adjusted structure into this function using SCS_SETRECONVERTSTRING. IME does not generate any [WM_IME_COMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-composition) messages. |

### `lpComp` [in, optional]

Pointer to a buffer containing the information to set for the composition string, as specified by the value of *dwIndex*.

### `dwCompLen` [in]

Size, in bytes, of the information buffer for the composition string, even if SCS_SETSTR is specified and the buffer contains a Unicode string.

### `lpRead` [in, optional]

Pointer to a buffer containing the information to set for the reading string, as specified by the value of *dwIndex*. The application can set this parameter to **NULL**.

### `dwReadLen` [in]

Size, in bytes, of the information buffer for the reading string, even if SCS_SETSTR is specified and the buffer contains a Unicode string.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

The application can set *lpComp*, *lpRead*, or both. If the application does not specify a value for *lpComp*, it must set this parameter to **NULL** and set *dwCompLen* to 0.

When the application is changing attributes, all characters in a clause must have the same attribute. Converted characters must have the attribute ATTR_CONVERTED or ATTR_TARGET_CONVERTED. Unconverted characters must have the attribute ATTR_INPUT or ATTR_TARGET_NOTCONVERTED.

When the application is changing clause information, it can change only the target clause, just affecting one boundary at a time. The target clause has the attribute ATTR_TARGET_CONVERTED or ATTR_TARGET_NOTCONVERTED.

For additional information about attributes (ATTR_* values), see [Composition String](https://learn.microsoft.com/windows/desktop/Intl/composition-string).

When the IME completes the changes, it sends a [WM_IME_COMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-composition) message to the application to notify it of the changes.

**Windows Me/98, Windows 2000, Windows XP:** The SCS_*CONVERTSTRING values are used for reconversion. They can only be used for an IME that has the SCS_CAP_SETRECONVERTSTRING property. The application uses these values as follows:

1. Call **ImmSetCompositionString** with SCS_QUERYRECONVERTSTRING, so that IME adjusts the [RECONVERTSTRING](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-reconvertstring) structure for the reconversion.
2. Call **ImmSetCompositionString** with SCS_SETRECONVERTSTRING, so that IME generates a new composition string. After this, *lpComp* and *lpRead* indicate a [RECONVERTSTRING](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-reconvertstring) structure that contains the updated composition and reading string. Use the value of *lpRead* only when the selected IME has SCS_CAP_MAKEREAD set.

> [!NOTE]
> The imm.h header defines ImmSetCompositionString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

[RECONVERTSTRING](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-reconvertstring)

[WM_IME_COMPOSITION](https://learn.microsoft.com/windows/desktop/Intl/wm-ime-composition)