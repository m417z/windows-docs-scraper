# IDiscRecorder2::AcquireExclusiveAccess

## Description

Acquires exclusive access to the device.

## Parameters

### `force` [in]

Set to VARIANT_TRUE to gain exclusive access to the volume whether the file system volume can or cannot be dismounted. If VARIANT_FALSE, this method gains exclusive access only when there is no file system mounted on the volume.

### `__MIDL__IDiscRecorder20000` [in]

String that contains the friendly name of the client application requesting exclusive access. Cannot be **NULL** or a zero-length string. The string must conform to the restrictions for the IOCTL_CDROM_EXCLUSIVE_ACCESS control code found in the DDK.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_ACCESS_DENIED** | The device is currently being used by another application.<br><br>Value: 0x80070005 |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_IMAPI_RECORDER_COMMAND_TIMEOUT** | The device failed to accept the command within the timeout period. This may be caused by the device having entered an inconsistent state, or the timeout value for the command may need to be increased.<br><br>Value: 0xC0AA020D |
| **HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE)** | The specified handle is invalid.<br><br>Value: 6 |
| **HRESULT_FROM_WIN32(ERROR_DEV_NOT_EXIST)** | The specified network resource or device is no longer available.<br><br>Value: 55 |
| **E_IMAPI_RECORDER_LOCKED** | The device associated with this recorder during the last operation has been exclusively locked, causing this operation to fail.<br><br>Value: 0xC0AA0210 |

## Remarks

You should not have to call this method to acquire the lock yourself because the write operations, such as [IDiscFormat2Data::Write](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-write), acquires the lock for you.

Each recorder has a lock count. The first call to a recorder locks the device for exclusive access. Applications can use the **AcquireExclusiveAccess** method multiple times to apply multiple locks on a device. Each call increments the lock count by one.

When unlocking a recorder, the lock count must reach zero to free the device for other clients. Calling the [IDiscRecorder2::ReleaseExclusiveAccess](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-releaseexclusiveaccess) method decrements the lock count by one.

An equal number of calls to the **AcquireExclusiveAccess** and [ReleaseExclusiveAccess](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-releaseexclusiveaccess) methods are needed to free a device. Should the application exit unexpectedly or crash while holding the exclusive access, the CDROM.SYS driver will automatically release these exclusive locks.

If the device is already locked, you can call [IDiscRecorder2::get_ExclusiveAccessOwner](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_exclusiveaccessowner) to retrieve the name of the client application that currently has exclusive access.

## See also

[IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2)

[IDiscRecorder2::ReleaseExclusiveAccess](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-releaseexclusiveaccess)

[IDiscRecorder2::get_ExclusiveAccessOwner](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_exclusiveaccessowner)