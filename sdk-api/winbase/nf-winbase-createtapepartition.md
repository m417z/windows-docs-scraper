# CreateTapePartition function

## Description

The
**CreateTapePartition** function reformats a tape.

## Parameters

### `hDevice` [in]

Handle to the device where the new partition is to be created. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwPartitionMethod` [in]

Type of partition to create. To determine what type of partitions your device supports, see the documentation for your hardware. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_FIXED_PARTITIONS**<br><br>0L | Partitions the tape based on the device's default definition of partitions. The *dwCount* and *dwSize* parameters are ignored. |
| **TAPE_INITIATOR_PARTITIONS**<br><br>2L | Partitions the tape into the number and size of partitions specified by *dwCount* and *dwSize*, respectively, except for the last partition. The size of the last partition is the remainder of the tape. |
| **TAPE_SELECT_PARTITIONS**<br><br>1L | Partitions the tape into the number of partitions specified by *dwCount*. The *dwSize* parameter is ignored. The size of the partitions is determined by the device's default partition size. For more specific information, see the documentation for your tape device. |

### `dwCount` [in]

Number of partitions to create. The
[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function provides the maximum number of partitions a tape can support.

### `dwSize` [in]

Size of each partition, in megabytes. This value is ignored if the *dwPartitionMethod* parameter is **TAPE_SELECT_PARTITIONS**.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, it can return one of the following error codes.

| Error | Description |
| --- | --- |
| **ERROR_BEGINNING_OF_MEDIA**<br><br>1102L | An attempt to access data before the beginning-of-medium marker failed. |
| **ERROR_BUS_RESET**<br><br>1111L | A reset condition was detected on the bus. |
| **ERROR_END_OF_MEDIA**<br><br>1100L | The end-of-tape marker was reached during an operation. |
| **ERROR_FILEMARK_DETECTED**<br><br>1101L | A filemark was reached during an operation. |
| **ERROR_SETMARK_DETECTED**<br><br>1103L | A setmark was reached during an operation. |
| **ERROR_NO_DATA_DETECTED**<br><br>1104L | The end-of-data marker was reached during an operation. |
| **ERROR_PARTITION_FAILURE**<br><br>1105L | The tape could not be partitioned. |
| **ERROR_INVALID_BLOCK_LENGTH**<br><br>1106L | The block size is incorrect on a new tape in a multivolume partition. |
| **ERROR_DEVICE_NOT_PARTITIONED**<br><br>1107L | The partition information could not be found when a tape was being loaded. |
| **ERROR_MEDIA_CHANGED**<br><br>1110L | The tape that was in the drive has been replaced or removed. |
| **ERROR_NO_MEDIA_IN_DRIVE**<br><br>1112L | There is no media in the drive. |
| **ERROR_NOT_SUPPORTED**<br><br>50L | The tape driver does not support a requested function. |
| **ERROR_UNABLE_TO_LOCK_MEDIA**<br><br>1108L | An attempt to lock the ejection mechanism failed. |
| **ERROR_UNABLE_TO_UNLOAD_MEDIA**<br><br>1109L | An attempt to unload the tape failed. |
| **ERROR_WRITE_PROTECT**<br><br>19L | The media is write protected. |

## Remarks

Creating partitions reformats the tape. All previous information recorded on the tape is destroyed.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)