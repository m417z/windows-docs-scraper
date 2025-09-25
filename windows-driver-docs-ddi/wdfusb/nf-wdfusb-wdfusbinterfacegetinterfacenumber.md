# WdfUsbInterfaceGetInterfaceNumber function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetInterfaceNumber** method returns the interface number of a specified USB interface object.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

## Return value

**WdfUsbInterfaceGetInterfaceNumber** returns the interface number.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about interface numbers, see the USB specification.

For more information about the **WdfUsbInterfaceGetInterfaceNumber** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the interface number of a specified USB interface object.

```cpp
BYTE interfaceNumber;

interfaceNumber = WdfUsbInterfaceGetInterfaceNumber(UsbInterface);
```

## See also

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)