# _TAPE_PREPARE structure (minitape.h)

## Description

The TAPE_PREPARE structure is used in conjunction with the [IOCTL_TAPE_PREPARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_prepare) request to load or unload tape, reset the tape's tension, lock or unlock the ejection mechanism, or format the tape.

## Members

### `Operation`

Indicates the type of operation to perform. This member can be one of the following:

| Operation | Meaning |
| --- | --- |
| TAPE_LOAD | Loads the tape and moves the tape to the beginning. |
| TAPE_UNLOAD | Moves the tape to the beginning for removal from the device. After a successful unload operation, the device returns errors to applications that attempt to access the tape, until the tape is loaded again. |
| TAPE_TENSION | Adjusts the tension by moving the tape to the end of the tape and back to the beginning. This option is not supported by all devices. This value is ignored if it is not supported. |
| TAPE_LOCK | Locks the tape ejection mechanism, so that the tape is not ejected accidentally. |
| TAPE_UNLOCK | Unlocks the tape ejection mechanism. |
| TAPE_FORMAT | Performs a low-level format of the tape. Not all devices support this feature. This value is ignored if it is not supported. |

### `Immediate`

When set to **TRUE**, indicates that the target device should return status immediately. When set to **FALSE**, indicates that the device should return status after the operation is complete.

## See also

[IOCTL_TAPE_PREPARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_prepare)

[TapeMiniPrepare](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)