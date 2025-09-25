# TAPE_GET_POSITION structure

## Description

The
**TAPE_GET_POSITION** structure describes the position of the tape.

## Members

### `Type`

Type of position. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_ABSOLUTE_POSITION**<br><br>0L | The position specified by the **Offset** member is an absolute number of blocks from the beginning of the partition specified by the **Partition** member. |
| **TAPE_LOGICAL_POSITION**<br><br>1L | The position specified by the **Offset** member is relative to the current position in the partition specified by **Partition**. |

### `Partition`

Partition to position within. If this member is zero, the current partition is assumed.

### `Offset`

Block address.