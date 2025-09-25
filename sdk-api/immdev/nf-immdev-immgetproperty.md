# ImmGetProperty function

## Description

Retrieves the property and capabilities of the IME associated with the specified input locale.

## Parameters

### `HKL` [in]

Input locale identifier.

### `DWORD` [in]

Type of property information to retrieve. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **IGP_CONVERSION** | Conversion capabilities. |
| **IGP_GETIMEVERSION** | System version number for which the specified IME was created. |
| **IGP_PROPERTY** | Property information. |
| **IGP_SELECT** | Selection inheritance capabilities. |
| **IGP_SENTENCE** | Sentence mode capabilities. |
| **IGP_SETCOMPSTR** | Composition string capabilities. |
| **IGP_UI** | User interface capabilities. |

## Return value

Returns the property or capability value, depending on the value of the *dwIndex* parameter. If *dwIndex* is set to IGP_PROPERTY, the function returns one or more of the following values:

| Value | Meaning |
| --- | --- |
| IME_PROP_AT_CARET | If set, conversion window is at the caret position. If clear, the window is near the caret position. |
| IME_PROP_SPECIAL_UI | If set, the IME has a nonstandard user interface. The application should not draw in the IME window. |
| IME_PROP_CANDLIST_START_FROM_1 | If set, strings in the candidate list are numbered starting at 1. If clear, strings start at 0. |
| IME_PROP_UNICODE | If set, the IME is viewed as a Unicode IME. The operating system and the IME communicate through the Unicode IME interface. If clear, the IME uses the ANSI interface to communicate with the operating system. |
| IME_PROP_COMPLETE_ON_UNSELECT | If set, the IME completes the composition string when the IME is deactivated. If clear, the IME cancels the composition string when the IME is deactivated, for example, from a keyboard layout change. |
| IME_PROP_ACCEPT_WIDE_VKEY | If set, the IME processes the injected Unicode that came from the [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) function by using VK_PACKET. If clear, the IME might not process the injected Unicode, and might send the injected Unicode to the application directly. |

If *dwIndex* is set to IGP_UI, the function returns one or more of the following values:

| Value | Meaning |
| --- | --- |
| UI_CAP_2700 | Support text escapement values of 0 or 2700. For more information, see the **lfEscapement** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. |
| UI_CAP_ROT90 | Support text escapement values of 0, 900, 1800, or 2700. For more information, see **lfEscapement**. |
| UI_CAP_ROTANY | Support any text escapement value. For more information, see **lfEscapement**. |

If *dwIndex* is set to IGP_SETCOMPSTR, the function returns one or more of the following values:

| Value | Meaning |
| --- | --- |
| SCS_CAP_COMPSTR | Create the composition string by calling the [ImmSetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immsetcompositionstringa) function with the SCS_SETSTR value. |
| SCS_CAP_MAKEREAD | Create the reading string from corresponding composition string when using the [ImmSetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immsetcompositionstringa) function with SCS_SETSTR and without setting *lpRead*. |
| SCS_CAP_SETRECONVERTSTRING: | This IME can support reconversion. Use [ImmSetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immsetcompositionstringa) to do reconversion. |

If *dwIndex* is set to IGP_SELECT, the function returns one or more of the following values:

| Value | Meaning |
| --- | --- |
| SELECT_CAP_CONVMODE | Inherit conversion mode when a new IME is selected. |
| SELECT_CAP_SENTENCE | Inherit sentence mode when a new IME is selected. |

If *dwIndex* is set to IGP_GETIMEVERSION, the function returns one or more of the following values:

| Value | Meaning |
| --- | --- |
| IMEVER_0310 | The IME was created for Windows 3.1. |
| IMEVER_0400 | The IME was created for Windows Me/98/95. |

## See also

[ImmSetCompositionString](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immsetcompositionstringa)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)