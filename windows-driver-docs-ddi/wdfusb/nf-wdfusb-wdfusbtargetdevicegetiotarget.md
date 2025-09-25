# WdfUsbTargetDeviceGetIoTarget function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceGetIoTarget** method returns a handle to the I/O target object that is associated with a specified USB device.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## Return value

The **WdfUsbTargetDeviceGetIoTarget** method returns a handle to an I/O target object.

A bug check occurs if a driver-supplied object handle is invalid.

## Remarks

For more information about the **WdfUsbTargetDeviceGetIoTarget** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example creates a request object and verifies that the framework can send a request to the I/O target object that is associated with a specified USB device.

```cpp
status = WdfRequestCreate(
                          &attributes,
                          WdfUsbTargetDeviceGetIoTarget(deviceContext->UsbTargetDevice),
                          &request
                          );
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetPipeGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipegetiotarget)