# _DEBUG_GET_TEXT_COMPLETIONS_OUT structure

## Description

Defines information about text completions to get.

## Members

### `Flags`

Flags. Valid flag values include the following:

| Value | Meaning |
| --- | --- |
| **DEBUG_GET_TEXT_COMPLETIONS_IS_DOT_COMMAND**<br><br>0x00000001 | Is dot command. Dot commands begin with a period (.). |
| **DEBUG_GET_TEXT_COMPLETIONS_IS_EXTENSION_COMMAND**<br><br>0x00000002 | Is extension command. |
| **DEBUG_GET_TEXT_COMPLETIONS_IS_SYMBOL**<br><br>0x00000004 | Is symbol. |

### `ReplaceIndex`

The index of the replace location.

### `MatchCount`

Count value of matches.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.