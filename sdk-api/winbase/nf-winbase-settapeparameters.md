# SetTapeParameters function

## Description

The
**SetTapeParameters** function either specifies the block size of a tape or configures the tape device.

## Parameters

### `hDevice` [in]

Handle to the device for which to set configuration information. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwOperation` [in]

Type of information to set. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **SET_TAPE_DRIVE_INFORMATION**<br><br>1L | Sets the device-specific information specified by *lpTapeInformation*. |
| **SET_TAPE_MEDIA_INFORMATION**<br><br>0L | Sets the tape-specific information specified by the *lpTapeInformation* parameter. |

### `lpTapeInformation` [in]

Pointer to a structure that contains the information to set. If the *dwOperation* parameter is SET_TAPE_MEDIA_INFORMATION, *lpTapeInformation* points to a
[TAPE_SET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_set_media_parameters) structure.

If *dwOperation* is SET_TAPE_DRIVE_INFORMATION, *lpTapeInformation* points to a
[TAPE_SET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_set_drive_parameters) structure.

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

## See also

[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters)

[TAPE_SET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_set_drive_parameters)

[TAPE_SET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_set_media_parameters)