# WdfUsbTargetDeviceCyclePortSynchronously function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceCyclePortSynchronously** method power-cycles the USB port to which a specified device is attached.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## Return value

**WdfUsbTargetDeviceCyclePortSynchronously** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was invalid. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Power-cycling a port causes the device to be surprise-removed and re-enumerated. A driver might request a power cycle after it has loaded firmware into a device.

Before the framework cycles the I/O target's USB port, it cancels all I/O requests that remain in the I/O target's queue. The driver must not send additional I/O requests to the I/O target until **WdfUsbTargetDeviceCyclePortSynchronously** returns.

The driver must call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) before it calls **WdfUsbTargetDeviceCyclePortSynchronously**.

For more information about the **WdfUsbTargetDeviceCyclePortSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example power-cycles a specified device's USB port.

```cpp
NTSTATUS status;

status = WdfUsbTargetDeviceCyclePortSynchronously(UsbDevice);
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)