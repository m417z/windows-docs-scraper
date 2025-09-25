# WdfUsbTargetDeviceResetPortSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceResetPortSynchronously** method resets the USB port that is associated with the specified USB device.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## Return value

**WdfUsbTargetDeviceResetPortSynchronously** returns the USB I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was invalid. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfUsbTargetDeviceResetPortSynchronously** method resets the USB port by sending an [IOCTL_INTERNAL_USB_RESET_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_reset_port) request.

Before the framework resets the I/O target's USB port, it cancels all I/O requests that remain in the I/O target's queue. The driver must not send additional I/O requests to the I/O target until **WdfUsbTargetDeviceResetPortSynchronously** returns.

The driver must call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) before it calls **WdfUsbTargetDeviceResetPortSynchronously**. After **WdfUsbTargetDeviceResetPortSynchronously** returns, the driver can call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart).

After a successful reset operation, the bus driver reselects the configuration and any alternate interface settings that the device had before the reset operation occurred.

For more information about the **WdfUsbTargetDeviceResetPortSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example resets a specified device's USB port.

```cpp
NTSTATUS status;

status = WdfUsbTargetDeviceResetPortSynchronously(UsbDevice);
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)