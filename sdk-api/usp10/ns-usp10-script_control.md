# SCRIPT_CONTROL structure

## Description

Contains script control flags for several Uniscribe functions, for example, [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize).

## Members

### `uDefaultLanguage`

Primary [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the language to use when Unicode values are ambiguous. This value is used in numeric processing to select digit shape when the **fDigitSubstitute** member of [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) is set.

### `fContextDigits`

Value indicating how national digits are selected. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Choose national digits according to the nearest previous strong text. |
| **FALSE** | Choose national digits according to the value of the **uDefaultLanguage** member. |

### `fInvertPreBoundDir`

Value indicating if the initial context is set to the opposite of the base embedding level, or to the base embedding level itself. Possible values are defined in the following table. The application sets this member to indicate that text at the start of the string defaults to being laid out as if it follows a strong left-to-right character if the base [embedding level](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) is 0, and as if it follows a strong right-to-left character if the base embedding level is 1. This member is used for [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) legacy support.

| Value | Meaning |
| --- | --- |
| **TRUE** | Change the initial context to the opposite of the base embedding level. |
| **FALSE** | Set the initial context to the base embedding level. |

### `fInvertPostBoundDir`

Value indicating if the final context is set to the opposite of the base embedding level, or to the base embedding level itself. Possible values are defined in the following table. The application sets this member to indicate that text at the end of the string defaults to being laid out as if it precedes strong text of the same direction as the base embedding level. It is used for [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) legacy support.

| Value | Meaning |
| --- | --- |
| **TRUE** | Change the final context to the opposite of the base embedding level. |
| **FALSE** | Set the final context to the base embedding level. |

### `fLinkStringBefore`

Value indicating if the shaping engine shapes the first character of the string as if it joins with a previous character. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Shape the first character by linking with a previous character. |
| **FALSE** | Do not shape the first character by linking with a previous character. |

### `fLinkStringAfter`

Value indicating if the shaping engine shapes the last character of the string as if it is joined to a subsequent character. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Shape the last character by linking with a subsequent character. |
| **FALSE** | Do not shape the last character by linking with a subsequent character. |

### `fNeutralOverride`

Value indicating the treatment of all neutral characters in the string. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Set neutral items to a strong direction, that is, right-to-left or left-to-right, depending on the current embedding level. This setting effectively locks the items in place, and reordering occurs only between neutrals. |
| **FALSE** | Do not set neutral items to a strong direction. |

### `fNumericOverride`

Value indicating the treatment of all numeric characters in the string. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Set numeric characters to a strong direction, that is, right-to-left or left-to-right, depending on the current embedding level. This setting effectively locks the items in place, and reordering occurs only between numeric characters. |
| **FALSE** | Do not set numeric characters to a strong direction. |

### `fLegacyBidiClass`

Value indicating the handling for plus and minus characters by the shaping engine. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Treat the plus and minus characters as for legacy bidirectional classes in pre-Windows XP operating systems. In this case, the characters are treated as neutral characters, that is, with no implied direction, and the slash character is treated as a common separator. |
| **FALSE** | Treat the plus and minus characters as for Windows XP and later. In this case, the characters are treated as European separators. |

### `fMergeNeutralItems`

Value specifying if the shaping engine should merge neutral characters into strong items when possible. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Merge neutral characters into strong items. |
| **FALSE** | Do not merge neutral characters into strong items. |

### `fUseStandardBidi`

Value specifying if the shaping engine should use the standard bidirectional matching pair algorithm. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Skip the matching pair algorithm. |
| **FALSE** | Use the matching pair algorithm. |

### `fReserved`

Reserved; always initialize to 0.

## See also

[Digit Shapes](https://learn.microsoft.com/windows/desktop/Intl/digit-shapes)

[SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)