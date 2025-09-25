# SetTapePosition function

## Description

The
**SetTapePosition** function sets the tape position on the specified device.

## Parameters

### `hDevice` [in]

Handle to the device on which to set the tape position. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwPositionMethod` [in]

Type of positioning to perform. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_ABSOLUTE_BLOCK**<br><br>1L | Moves the tape to the device-specific block address specified by the *dwOffsetLow* and *dwOffsetHigh* parameters. The *dwPartition* parameter is ignored. |
| **TAPE_LOGICAL_BLOCK**<br><br>2L | Moves the tape to the block address specified by *dwOffsetLow* and *dwOffsetHigh* in the partition specified by *dwPartition*. |
| **TAPE_REWIND**<br><br>0L | Moves the tape to the beginning of the current partition. The *dwPartition*, *dwOffsetLow*, and *dwOffsetHigh* parameters are ignored. |
| **TAPE_SPACE_END_OF_DATA**<br><br>4L | Moves the tape to the end of the data on the partition specified by *dwPartition*. |
| **TAPE_SPACE_FILEMARKS**<br><br>6L | Moves the tape forward (or backward) the number of filemarks specified by *dwOffsetLow* and *dwOffsetHigh* in the current partition. The *dwPartition* parameter is ignored. |
| **TAPE_SPACE_RELATIVE_BLOCKS**<br><br>5L | Moves the tape forward (or backward) the number of blocks specified by *dwOffsetLow* and *dwOffsetHigh* in the current partition. The *dwPartition* parameter is ignored. |
| **TAPE_SPACE_SEQUENTIAL_FMKS**<br><br>7L | Moves the tape forward (or backward) to the first occurrence of n filemarks in the current partition, where n is the number specified by *dwOffsetLow* and *dwOffsetHigh*. The *dwPartition* parameter is ignored. |
| **TAPE_SPACE_SEQUENTIAL_SMKS**<br><br>9L | Moves the tape forward (or backward) to the first occurrence of n setmarks in the current partition, where n is the number specified by *dwOffsetLow* and *dwOffsetHigh*. The *dwPartition* parameter is ignored. |
| **TAPE_SPACE_SETMARKS**<br><br>8L | Moves the tape forward (or backward) the number of setmarks specified by *dwOffsetLow* and *dwOffsetHigh* in the current partition. The *dwPartition* parameter is ignored. |

### `dwPartition` [in]

Partition to position within. If *dwPartition* is zero, the current partition is used. Partitions are numbered logically from 1 through n, where 1 is the first partition on the tape and n is the last.

### `dwOffsetLow` [in]

Low-order bits of the block address or count for the position operation specified by the *dwPositionMethod* parameter.

### `dwOffsetHigh` [in]

High-order bits of the block address or count for the position operation specified by the *dwPositionMethod* parameter. If the high-order bits are not required, this parameter should be zero.

### `bImmediate` [in]

Indicates whether to return as soon as the move operation begins. If this parameter is **TRUE**, the function returns immediately; if **FALSE**, the function does not return until the move operation has been completed.

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

If the offset specified by *dwOffsetLow* and *dwOffsetHigh* specifies the number of blocks, filemarks, or setmarks to move, a positive offset moves the tape forward to the end of the last block, filemark, or setmark. A negative offset moves the tape backward to the beginning of the last block, filemark, or setmark. If the offset is zero, the tape does not move.

To obtain information about the status, capabilities, and capacities of tape drives and media, call the
[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)

[GetTapePosition](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeposition)