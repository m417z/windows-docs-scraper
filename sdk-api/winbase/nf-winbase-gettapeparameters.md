# GetTapeParameters function

## Description

The
**GetTapeParameters** function retrieves information that describes the tape or the tape drive.

## Parameters

### `hDevice` [in]

Handle to the device about which information is sought. This handle is created by using the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwOperation` [in]

Type of information requested. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **GET_TAPE_DRIVE_INFORMATION**<br><br>1 | Retrieves information about the tape device. |
| **GET_TAPE_MEDIA_INFORMATION**<br><br>0 | Retrieves information about the tape in the tape device. |

### `lpdwSize` [out]

Pointer to a variable that receives the size, in bytes, of the buffer specified by the *lpTapeInformation* parameter. If the buffer is too small, this parameter receives the required size.

### `lpTapeInformation` [out]

Pointer to a structure that contains the requested information. If the *dwOperation* parameter is **GET_TAPE_MEDIA_INFORMATION**, *lpTapeInformation* points to a
[TAPE_GET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_get_media_parameters) structure.

If *dwOperation* is **GET_TAPE_DRIVE_INFORMATION**, *lpTapeInformation* points to a
[TAPE_GET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_get_drive_parameters) structure.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

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

The block size range values (maximum and minimum) returned by the
**GetTapeParameters** function called with the *dwOperation* parameter set to the **GET_TAPE_DRIVE_INFORMATION** value will indicate system limits, not drive limits. However, it is the tape drive device and the media present in the drive that determine the true block size limits. Thus, an application may not be able to set all the block sizes mentioned in the range obtained by specifying **GET_TAPE_DRIVE_INFORMATION** in *dwOperation*.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[SetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-settapeparameters)

[TAPE_GET_DRIVE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_get_drive_parameters)

[TAPE_GET_MEDIA_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-tape_get_media_parameters)