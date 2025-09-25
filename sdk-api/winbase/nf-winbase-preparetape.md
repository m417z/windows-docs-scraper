# PrepareTape function

## Description

The
**PrepareTape** function prepares the tape to be accessed or removed.

## Parameters

### `hDevice` [in]

Handle to the device preparing the tape. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwOperation` [in]

Tape device preparation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_FORMAT**<br><br>5L | Performs a low-level format of the tape. Currently, only the QIC117 device supports this feature. |
| **TAPE_LOAD**<br><br>0L | Loads the tape and moves the tape to the beginning. |
| **TAPE_LOCK**<br><br>3L | Locks the tape ejection mechanism so that the tape is not ejected accidentally. |
| **TAPE_TENSION**<br><br>2L | Adjusts the tension by moving the tape to the end of the tape and back to the beginning. This option is not supported by all devices. This value is ignored if it is not supported. |
| **TAPE_UNLOAD**<br><br>1L | Moves the tape to the beginning for removal from the device. After a successful unload operation, the device returns errors to applications that attempt to access the tape, until the tape is loaded again. |
| **TAPE_UNLOCK**<br><br>4L | Unlocks the tape ejection mechanism. |

### `bImmediate` [in]

If this parameter is **TRUE**, the function returns immediately. If it is **FALSE**, the function does not return until the operation has been completed.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, it can return one of the following error codes.

| Error | Description |
| --- | --- |
| **ERROR_BEGINNING_OF_MEDIA**<br><br>1102L | An attempt to access data before the beginning-of-medium marker failed. |
| **ERROR_BUS_RESET**<br><br>1111L | A reset condition was detected on the bus. |
| **ERROR_DEVICE_NOT_PARTITIONED**<br><br>1107L | The partition information could not be found when a tape was being loaded. |
| **ERROR_END_OF_MEDIA**<br><br>1100L | The end-of-tape marker was reached during an operation. |
| **ERROR_FILEMARK_DETECTED**<br><br>1101L | A filemark was reached during an operation. |
| **ERROR_INVALID_BLOCK_LENGTH**<br><br>1106L | The block size is incorrect on a new tape in a multivolume partition. |
| **ERROR_MEDIA_CHANGED**<br><br>1110L | The tape that was in the drive has been replaced or removed. |
| **ERROR_NO_DATA_DETECTED**<br><br>1104L | The end-of-data marker was reached during an operation. |
| **ERROR_NO_MEDIA_IN_DRIVE**<br><br>1112L | There is no media in the drive. |
| **ERROR_NOT_SUPPORTED**<br><br>50L | The tape driver does not support a requested function. |
| **ERROR_PARTITION_FAILURE**<br><br>1105L | The tape could not be partitioned. |
| **ERROR_SETMARK_DETECTED**<br><br>1103L | A setmark was reached during an operation. |
| **ERROR_UNABLE_TO_LOCK_MEDIA**<br><br>1108L | An attempt to lock the ejection mechanism failed. |
| **ERROR_UNABLE_TO_UNLOAD_MEDIA**<br><br>1109L | An attempt to unload the tape failed. |
| **ERROR_WRITE_PROTECT**<br><br>19L | The media is write protected. |

## Remarks

Some tape devices do not support certain tape operations. See your tape device documentation and use the
[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function to determine your tape device's capabilities.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)