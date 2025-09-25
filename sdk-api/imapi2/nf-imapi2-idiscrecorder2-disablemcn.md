# IDiscRecorder2::DisableMcn

## Description

Disables Media Change Notification (MCN) for the device.

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

MCN is the CD-ROM device driver's method of detecting media change and state changes in the CD-ROM device. For example, when you change the media in a CD-ROM device, a MCN message is sent to trigger media features, such as Autoplay. To disable the features, call this method.

To enable notifications, call the [IDiscRecorder2::EnableMcn](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-enablemcn) method. If the application crashes or closes unexpectedly, then MCN is automatically re-enabled by the driver.

Note that DisableMcn increments a reference count each time it is called. The [EnableMcn](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-enablemcn) method decrements the count. The device is enabled when the reference count is zero.

## See also

[IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2)

[IDiscRecorder2::EnableMcn](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-enablemcn)