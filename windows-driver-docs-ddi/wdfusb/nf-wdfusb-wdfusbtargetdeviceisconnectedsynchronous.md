# WdfUsbTargetDeviceIsConnectedSynchronous function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceIsConnectedSynchronous** method determines if the specified USB device is connected.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## Return value

**WdfUsbTargetDeviceIsConnectedSynchronous** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was invalid. |
| **STATUS_DEVICE_NOT_CONNECTED or STATUS_DEVICE_DOES_NOT_EXIST** | The device was not connected. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetDeviceIsConnectedSynchronous** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example determines if a specified USB device is connected.

```cpp
NTSTATUS status;

status = WdfUsbTargetDeviceIsConnectedSynchronous(UsbDevice);
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)