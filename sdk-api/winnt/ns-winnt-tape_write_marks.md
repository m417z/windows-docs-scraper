# TAPE_WRITE_MARKS structure

## Description

The
**TAPE_WRITE_MARKS** structure describes the type and number of tapemarks to write.

## Members

### `Type`

Type of tapemark to write. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_FILEMARKS** | Writes filemarks. |
| **TAPE_LONG_FILEMARKS**<br><br>3L | Writes long filemarks. |
| **TAPE_SETMARKS**<br><br>0L | Writes setmarks. |
| **TAPE_SHORT_FILEMARKS**<br><br>2L | Writes short filemarks. |

### `Count`

Number of tapemarks to write.

### `Immediate`

If this member is **TRUE**, return as soon as the operation begins. Otherwise, return after the operation has completed.