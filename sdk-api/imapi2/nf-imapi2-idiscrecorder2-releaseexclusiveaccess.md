# IDiscRecorder2::ReleaseExclusiveAccess

## Description

Releases exclusive access to the device.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_IMAPI_RECORDER_COMMAND_TIMEOUT** | The device failed to accept the command within the timeout period. This may be caused by the device having entered an inconsistent state, or the timeout value for the command may need to be increased.<br><br>Value: 0xC0AA020D |
| **HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE)** | The specified handle is invalid.<br><br>Value: 6 |
| **HRESULT_FROM_WIN32(ERROR_DEV_NOT_EXIST)** | The specified network resource or device is no longer available.<br><br>Value: 55 |
| **E_IMAPI_RECORDER_LOCKED** | The device associated with this recorder during the last operation has been exclusively locked, causing this operation to failed.<br><br>Value: 0xC0AA0210 |

## Remarks

Each recorder has a lock count. The first call to a recorder locks the device for exclusive access. Applications can use the [IDiscRecorder2::AcquireExclusiveAccess](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-acquireexclusiveaccess) method multiple times to apply multiple locks on a device. Each call increments the lock count by one.

When unlocking a recorder, the lock count must reach zero to free the device for other clients. Calling the **ReleaseExclusiveAccess** method decrements the lock count by one.

An equal number of calls to the [AcquireExclusiveAccess](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-acquireexclusiveaccess) and **ReleaseExclusiveAccess** methods are needed to free a device. When the lock count reaches zero, recording device is free; the last lock has been removed.

## See also

[IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2)

[IDiscRecorder2::AcquireExclusiveAccess](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-acquireexclusiveaccess)

[IDiscRecorder2::get_ExclusiveAccessOwner](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_exclusiveaccessowner)