# GetTapePosition function

## Description

The
**GetTapePosition** function retrieves the current address of the tape, in logical or absolute blocks.

## Parameters

### `hDevice` [in]

Handle to the device on which to get the tape position. This handle is created by using
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `dwPositionType` [in]

Type of address to obtain. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_ABSOLUTE_POSITION**<br><br>0L | The *lpdwOffsetLow* and *lpdwOffsetHigh* parameters receive the device-specific block address. The *dwPartition* parameter receives zero. |
| **TAPE_LOGICAL_POSITION**<br><br>1L | The *lpdwOffsetLow* and *lpdwOffsetHigh* parameters receive the logical block address. The *dwPartition* parameter receives the logical tape partition. |

### `lpdwPartition` [out]

Pointer to a variable that receives the number of the current tape partition. Partitions are numbered logically from 1 through n, where 1 is the first partition on the tape and n is the last. When a device-specific block address is retrieved, or if the device supports only one partition, this parameter receives zero.

### `lpdwOffsetLow` [out]

Pointer to a variable that receives the low-order bits of the current tape position.

### `lpdwOffsetHigh` [out]

Pointer to a variable that receives the high-order bits of the current tape position. This parameter can be **NULL** if the high-order bits are not required.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, it can return one of the following error codes.

| Error code | Description |
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

A logical block address is relative to a partition. The first logical block address on each partition is zero.

Call the
[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function to obtain information about the status, capabilities, and capacities of tape drives and media.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)

[SetTapePosition](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-settapeposition)