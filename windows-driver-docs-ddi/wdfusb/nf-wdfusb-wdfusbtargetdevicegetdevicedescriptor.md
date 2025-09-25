# WdfUsbTargetDeviceGetDeviceDescriptor function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceGetDeviceDescriptor** method retrieves the USB device descriptor for the USB device that is associated with a specified framework USB device object.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `UsbDeviceDescriptor` [out]

A pointer to a caller-allocated [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) structure that receives the USB device descriptor.

## Remarks

A bug check occurs if a driver-supplied object handle is invalid.

For more information about the **WdfUsbTargetDeviceGetDeviceDescriptor** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the USB device descriptor for a device. The example stores the descriptor in driver-defined context space.

```cpp
PMY_DEVICE_CONTEXT  myDeviceContext;

myDeviceContext = GetDeviceContext(device);

WdfUsbTargetDeviceGetDeviceDescriptor(
                                      myDeviceContext->UsbTargetDevice,
                                      &myDeviceContext->UsbDeviceDescr
                                      );
```

## See also

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)