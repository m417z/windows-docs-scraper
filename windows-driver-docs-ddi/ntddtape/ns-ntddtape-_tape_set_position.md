# _TAPE_SET_POSITION structure (ntddtape.h)

## Description

The TAPE_SET_POSITION structure is used in conjunction with the [IOCTL_TAPE_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_position) request to move the current position on the tape to the specified partition and offset.

## Members

### `Method`

Indicates the type of positioning to perform. This member must have one of the following values:

#### TAPE_REWIND

Positions the tape at the beginning of the partition indicated in **Partition** if the media is partitioned, and to the beginning of the media if the media is not partitioned. If the media is not partitioned, **Partition** must be set to zero. The **Offset** member is ignored.

#### TAPE_ABSOLUTE_BLOCK

Positions the tape at the absolute block address located at the offset from the beginning specified by **Offset**. The value in the **Partition** member is ignored.

#### TAPE_LOGICAL_BLOCK

Positions the tape to the logical block address specified by **Offset**, relative to the beginning of the partition indicated in **Partition**. If the media is not partitioned, **Partition** must be set to zero.

#### TAPE_PSEUDO_LOGICAL_BLOCK

Positions the tape to the pseudological block address specified by **Offset**, relative to the beginning of the partition indicated in **Partition**. If the media is not partitioned, **Partition** must be to zero.

#### TAPE_SPACE_END_OF_DATA

Positions the tape at the end of the partition indicated in **Partition**, or if the media is not partitioned, at the end of the tape. The **Offset** member is ignored.

#### TAPE_SPACE_RELATIVE_BLOCKS

Starting from the current position, positions the tape immediately after the number of blocks specified by **Offset**. The **Partition** member is ignored.

#### TAPE_SPACE_FILEMARKS

Starting from the current position, positions the tape immediately after the number of filemarks specified by **Offset**. The **Partition** member is ignored.

#### TAPE_SPACE_SEQUENTIAL_FMKS

Starting from the current position, positions the tape immediately after the next occurrence, if any, of the number of consecutive filemarks specified by **Offset**. The **Partition** member is ignored.

#### TAPE_SPACE_SETMARKS

Starting from the current position, positions the tape immediately after the number of setmarks specified by **Offset**. The **Partition** member is ignored.

#### TAPE_SPACE_SEQUENTIAL_SMKS

Starting from the current position, positions the tape immediately after the next occurrence, if any, of the number of consecutive setmarks specified by **Offset**. The **Partition** member is ignored.

### `Partition`

Indicates the partition in which to set the tape's position. This member must have one of the following values:

NOT_PARTITIONED (or zero)

DATA_PARTITION

DIRECTORY_PARTITION

If the media is not partitioned, this member is zero.

### `Offset`

Specifies an offset whose type depends on the value in **Method**. If the specified method positions the tape to a block address, **Offset** specifies the byte offset into the specified partition. If the specified method is to skip blocks, filemarks, or setmarks, **Offset** specifies the number to skip. If **Offset** is zero, the tape is positioned at the beginning of the partition.

### `Immediate`

When set to **TRUE**, indicates that the target device should return status immediately. When set to **FALSE**, indicates that the device should return status after the operation is complete.

##### - Method.TAPE_ABSOLUTE_BLOCK

Positions the tape at the absolute block address located at the offset from the beginning specified by **Offset**. The value in the **Partition** member is ignored.

##### - Method.TAPE_LOGICAL_BLOCK

Positions the tape to the logical block address specified by **Offset**, relative to the beginning of the partition indicated in **Partition**. If the media is not partitioned, **Partition** must be set to zero.

##### - Method.TAPE_PSEUDO_LOGICAL_BLOCK

Positions the tape to the pseudological block address specified by **Offset**, relative to the beginning of the partition indicated in **Partition**. If the media is not partitioned, **Partition** must be to zero.

##### - Method.TAPE_REWIND

Positions the tape at the beginning of the partition indicated in **Partition** if the media is partitioned, and to the beginning of the media if the media is not partitioned. If the media is not partitioned, **Partition** must be set to zero. The **Offset** member is ignored.

##### - Method.TAPE_SPACE_END_OF_DATA

Positions the tape at the end of the partition indicated in **Partition**, or if the media is not partitioned, at the end of the tape. The **Offset** member is ignored.

##### - Method.TAPE_SPACE_FILEMARKS

Starting from the current position, positions the tape immediately after the number of filemarks specified by **Offset**. The **Partition** member is ignored.

##### - Method.TAPE_SPACE_RELATIVE_BLOCKS

Starting from the current position, positions the tape immediately after the number of blocks specified by **Offset**. The **Partition** member is ignored.

##### - Method.TAPE_SPACE_SEQUENTIAL_FMKS

Starting from the current position, positions the tape immediately after the next occurrence, if any, of the number of consecutive filemarks specified by **Offset**. The **Partition** member is ignored.

##### - Method.TAPE_SPACE_SEQUENTIAL_SMKS

Starting from the current position, positions the tape immediately after the next occurrence, if any, of the number of consecutive setmarks specified by **Offset**. The **Partition** member is ignored.

##### - Method.TAPE_SPACE_SETMARKS

Starting from the current position, positions the tape immediately after the number of setmarks specified by **Offset**. The **Partition** member is ignored.

## Remarks

Note that a drive or a tape may not support all **Method** values.

Partitions are numbered logically from 1 to N. However, a partition number does not imply a physical position on the tape. For example, partition number one might not be at the beginning of the media.

When the offset specifies a number of blocks, filemarks, or setmarks to position over, a positive value N in the offset causes forward positioning over N blocks, filemarks, or setmarks, halting on the end-of-partition or end-of-tape side of the block, filemark, or setmark. A zero value in the offset causes no change of position. A negative value N in the offset causes reverse positioning, toward the beginning of the partition or the tape media, over N blocks, filemarks, or setmarks, halting on the beginning-of-partition side of a block, filemark, or setmark.

## See also

[IOCTL_TAPE_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_set_position)

[TapeMiniSetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)