# WdfUsbInterfaceGetNumSettings function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetNumSettings** method returns the number of alternate settings that a specified USB interface supports.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

## Return value

**WdfUsbInterfaceGetNumSettings** returns the number of alternate settings that the specified USB interface supports.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfUsbInterfaceGetNumSettings** after it has called [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

For more information about the **WdfUsbInterfaceGetNumSettings** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the number of alternate settings that are available for a specified USB interface.

```cpp
BYTE altSettings;

altSettings = WdfUsbInterfaceGetNumSettings(UsbInterface);
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)