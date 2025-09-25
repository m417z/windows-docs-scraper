# SCRIPT_LOGATTR structure

## Description

Contains attributes of logical characters that are useful when editing and formatting text.

## Members

### `fSoftBreak`

Value indicating if breaking the line in front of the character, called a "soft break", is valid. Possible values are defined in the following table. This member is set on the first character of Southeast Asian words.

| Value | Meaning |
| --- | --- |
| **TRUE** | A soft break is valid. |
| **FALSE** | A soft break is not valid. |

### `fWhiteSpace`

Value indicating if the character is one of the many Unicode characters classified as breakable white space. Possible values are defined in the following table. Breakable white space can break a word. All white space is breakable except nonbreaking space (NBSP) and zero-width nonbreaking space (ZWNBSP).

| Value | Meaning |
| --- | --- |
| **TRUE** | The character is breakable white space. |
| **FALSE** | The character is not breakable white space. |

### `fCharStop`

Value indicating if the character is a valid position for showing the caret upon a character movement keyboard action. Possible values are defined in the following table. This member is set for most characters, but not on code points inside Indian and Southeast Asian character clusters. This member can be used to implement LEFT ARROW and RIGHT ARROW operations in editors.

| Value | Meaning |
| --- | --- |
| **TRUE** | The character is a valid position for showing the caret upon a character movement keyboard action. |
| **FALSE** | The character is not a valid position for showing the caret upon a character movement keyboard action. |

### `fWordStop`

Value indicating the valid position for showing the caret upon a word movement keyboard action, such as CTRL+LEFT ARROW and CTRL+RIGHT ARROW. Possible values are defined in the following table. This member can be used to implement the CTRL+LEFT ARROW and CTRL+RIGHT ARROW operations in editors.

| Value | Meaning |
| --- | --- |
| **TRUE** | The character is a valid position for showing the caret upon a word movement keyboard action. |
| **FALSE** | The character is not a valid position for showing the caret upon a word movement keyboard action. |

### `fInvalid`

Value used to mark characters that form an invalid or undisplayable combination. Possible values are defined in the following table. A script that can set this member has the **fInvalidLogAttr** member set in its [SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties) structure.

| Value | Meaning |
| --- | --- |
| **TRUE** | The character forms an invalid or undisplayable combination. |
| **FALSE** | The character does not form an invalid or undisplayable combination. |

### `fReserved`

Reserved.

## See also

[SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties)

[ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)