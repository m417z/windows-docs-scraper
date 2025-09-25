# _DEBUG_GET_TEXT_COMPLETIONS_IN structure

## Description

Defines information about text completions to get.

## Members

### `Flags`

Flags. Valid flag values include the following:

| Value | Meaning |
| --- | --- |
| **DEBUG_GET_TEXT_COMPLETIONS_NO_DOT_COMMANDS**<br><br>0x00000001 | Do not include dot commands. Dot commands begin with a period (.). |
| **DEBUG_GET_TEXT_COMPLETIONS_NO_EXTENSION_COMMANDS**<br><br>0x00000002 | Do not include extension commands. |
| **DEBUG_GET_TEXT_COMPLETIONS_NO_SYMBOLS**<br><br>0x00000004 | Do not include completions with symbols. |

### `MatchCountLimit`

The limit of matches.

### `Reserved`

Reserved.