# _TAPE_WRITE_MARKS structure (minitape.h)

## Description

The TAPE_WRITE_MARKS structure is used in conjunction with an [IOCTL_TAPE_WRITE_MARKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_write_marks) request to write a setmark, a filemark, a short filemark, or a long filemark to tape.

## Members

### `Type`

Indicates the type of mark to write. This member can have one of the following values:

| Type | Meaning |
| --- | --- |
| TAPE_SETMARKS | Writes the number of setmarks specified by **Count**. |
| TAPE_FILEMARKS | Writes the number of filemarks specified by the **Count** parameter. |
| TAPE_SHORT_FILEMARKS | Writes the number of short filemarks specified by **Count**. |
| TAPE_LONG_FILEMARKS | Writes the number of long filemarks specified by **Count**. |

### `Count`

Indicates the number of marks to write.

### `Immediate`

When set to **TRUE**, indicates that the target device should return status immediately. When set to **FALSE**, indicates that the device should return status after the operation is complete.

## See also

[IOCTL_TAPE_WRITE_MARKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_write_marks)

[TapeMiniWriteMarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)