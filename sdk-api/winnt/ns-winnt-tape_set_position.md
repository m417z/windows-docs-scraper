# TAPE_SET_POSITION structure

## Description

The
**TAPE_SET_POSITION** structure describes how and where to position the tape.

## Members

### `Method`

Type of positioning. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_ABSOLUTE_BLOCK**<br><br>1L | Moves the tape to the device-specific block address specified by the **Offset** member. The **Partition** member is ignored. |
| **TAPE_LOGICAL_BLOCK**<br><br>2L | Moves the tape to the block address specified by **Offset** in the partition specified by **Partition**. |
| **TAPE_REWIND**<br><br>0L | Moves the tape to the beginning of the current partition. The **Partition** and **Offset** members are ignored. |
| **TAPE_SPACE_END_OF_DATA**<br><br>4L | Moves the tape to the end of the data on the partition specified by **Partition**. |
| **TAPE_SPACE_FILEMARKS**<br><br>6L | Moves the tape forward (or backward) the number of filemarks specified by **Offset** in the current partition. The **Partition** member is ignored. |
| **TAPE_SPACE_RELATIVE_BLOCKS**<br><br>5L | Moves the tape forward (or backward) the number of blocks specified by **Offset** in the current partition. The **Partition** member is ignored. |
| **TAPE_SPACE_SEQUENTIAL_FMKS**<br><br>7L | Moves the tape forward (or backward) to the first occurrence of n filemarks in the current partition, where n is the number specified by **Offset**. The **Partition** parameter is ignored. |
| **TAPE_SPACE_SEQUENTIAL_SMKS**<br><br>9L | Moves the tape forward (or backward) to the first occurrence of n setmarks in the current partition, where n is the number specified by **Offset**. The **Partition** member is ignored. |
| **TAPE_SPACE_SETMARKS**<br><br>8L | Moves the tape forward (or backward) the number of setmarks specified by **Offset** in the current partition. The **Partition** member is ignored. |

### `Partition`

Partition to position within. If this member is zero, the current partition is assumed.

### `Offset`

Block address or count for the position operation specified by the **Method** member.

### `Immediate`

If this member is **TRUE**, return as soon as the operation begins. Otherwise, return after the operation has completed.

## Remarks

If the positioning is relative, a positive offset moves the tape forward (toward the end of the tape) and a negative offset moves the tape backward (toward the beginning of the tape).