# WdfUsbTargetDeviceGetNumInterfaces function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceGetNumInterfaces** method returns the number of USB device interfaces that are supported by a specified USB device.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## Return value

**WdfUsbTargetDeviceGetNumInterfaces** returns the number of USB interfaces that the device supports.

A bug check occurs if a driver-supplied object handle is invalid.

## Remarks

For more information about the **WdfUsbTargetDeviceGetNumInterfaces** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the number of USB device interfaces that a specified USB device supports.

```cpp
UCHAR numInterfaces;

numInterfaces = WdfUsbTargetDeviceGetNumInterfaces(UsbDevice);
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)