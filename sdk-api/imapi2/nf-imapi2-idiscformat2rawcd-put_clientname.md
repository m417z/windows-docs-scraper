# IDiscFormat2RawCD::put_ClientName

## Description

Sets the friendly name of the client.

## Parameters

### `value` [in]

Name of the client application. Cannot be **NULL** or an empty string.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_IMAPI_DF2RAW_CLIENT_NAME_IS_NOT_VALID** | The client name is not valid.<br><br>Value: 0xC0AA0604 |
| **E_IMAPI_DF2RAW_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0600 |
| **E_IMAPI_DF2RAW_MEDIA_IS_PREPARED** | The requested operation is not valid when media has been "prepared" but not released.<br><br>Value: 0xC0AA0603 |

## Remarks

The name is used when the write operation requests exclusive access to the device. The [IDiscRecorder2::get_ExclusiveAccessOwner](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_exclusiveaccessowner) property contains the name of the client that has the lock.

Because any application with read/write access to the CDROM device during the write operation can use the IOCTL_CDROM_EXCLUSIVE_ACCESS (query) control code (see the Microsoft Windows Driver Development Kit (DDK)) to access the name, it is important that the name identify the program that is using this interface to write to the media. The name is restricted to the same character set as required by the IOCTL_CDROM_EXCLUSIVE_ACCESS control code.

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

[IDiscFormat2RawCD::get_ClientName](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_clientname)