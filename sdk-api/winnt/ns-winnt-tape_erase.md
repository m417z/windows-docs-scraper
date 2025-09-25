# TAPE_ERASE structure

## Description

The
**TAPE_ERASE** structure describes the partition to be erased.

## Members

### `Type`

Tape erasure type. This member must have one of the following values:

| Value | Meaning |
| --- | --- |
| **TAPE_ERASE_LONG**<br><br>1L | Erases the entire partition. |
| **TAPE_ERASE_SHORT**<br><br>0L | Erases only the partition's header block. |

### `Immediate`

If this member is **TRUE**, return as soon as the erase operation begins. Otherwise, return when the operation has been completed.