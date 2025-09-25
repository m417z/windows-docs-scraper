# IDiscFormat2Erase::put_ClientName

## Description

Sets the friendly name of the client.

## Parameters

### `value` [in]

Name of the client application.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## Remarks

The name is used when the write operation requests exclusive access to the device. The [IDiscRecorder2::get_ExclusiveAccessOwner](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_exclusiveaccessowner) property contains the name of the client that has the lock.

Because any application with read/write access to the CDROM device during the erase operation can use the IOCTL_CDROM_EXCLUSIVE_ACCESS (query) control code (see the Microsoft Windows Driver Development Kit (DDK)) to access the name, it is important that the name identify the program that is using this interface to erase to the media. The name is restricted to the same character set as required by the IOCTL_CDROM_EXCLUSIVE_ACCESS control code.

## See also

[IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase)

[IDiscFormat2Erase::get_ClientName](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-get_clientname)