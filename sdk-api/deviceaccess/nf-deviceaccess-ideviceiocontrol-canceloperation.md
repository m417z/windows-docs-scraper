# IDeviceIoControl::CancelOperation

## Description

The **CancelOperation** method attempts to cancel a previously issued call by using the [DeviceIoControlAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-ideviceiocontrol-deviceiocontrolasync) method.

## Parameters

### `cancelContext` [in]

The cancel context that a previous call to [DeviceIoControlAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-ideviceiocontrol-deviceiocontrolasync) returned.

## Return value

This method supports standard return values, in addition to these:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was still outstanding, and cancellation was attempted. |
| **ERROR_NOT_FOUND** | The operation was no longer outstanding. |

## Remarks

Regardless of whether cancellation is successful, the result of the operation is available in the callback that's provided to the asynchronous call.

## See also

[IDeviceIoControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-ideviceiocontrol)