# WriteTapemark function

## Description

The
**WriteTapemark** function writes a specified number of filemarks, setmarks, short filemarks, or long filemarks to a tape device. These tapemarks divide a tape partition into smaller areas.

## Parameters

### `hDevice` [in]

Handle to the device on which to write tapemarks. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwTapemarkType` [in]

Type of tapemarks to write. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_FILEMARKS**<br><br>1L | Writes the number of filemarks specified by the *dwTapemarkCount* parameter. |
| **TAPE_LONG_FILEMARKS**<br><br>3L | Writes the number of long filemarks specified by *dwTapemarkCount*. |
| **TAPE_SETMARKS**<br><br>0L | Writes the number of setmarks specified by *dwTapemarkCount*. |
| **TAPE_SHORT_FILEMARKS**<br><br>2L | Writes the number of short filemarks specified by *dwTapemarkCount*. |

### `dwTapemarkCount` [in]

Number of tapemarks to write.

### `bImmediate` [in]

If this parameter is **TRUE**, the function returns immediately; if it is **FALSE**, the function does not return until the operation has been completed.

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

Filemarks, setmarks, short filemarks, and long filemarks are special recorded elements that denote the linear organization of the tape. None of these marks contain user data. Filemarks are the most general marks; setmarks provide a hierarchy not available with filemarks.

A short filemark contains a short erase gap that cannot be overwritten unless the write operation is performed from the beginning of the partition or from an earlier long filemark.

A long filemark contains a long erase gap that allows an application to position the tape at the beginning of the filemark and to overwrite the filemark and the erase gap.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)