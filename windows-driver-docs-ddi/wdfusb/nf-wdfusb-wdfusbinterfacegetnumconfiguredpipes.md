# WdfUsbInterfaceGetNumConfiguredPipes function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetNumConfiguredPipes** method returns the number of pipes that are configured for a specified USB device interface.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

## Return value

**WdfUsbInterfaceGetNumConfiguredPipes** returns the number of pipes that are configured for the specified interface.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfUsbInterfaceGetNumConfiguredPipes** after it has called [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig).

For more information about the **WdfUsbInterfaceGetNumConfiguredPipes** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the number of pipes that are configured for a specified USB interface.

```cpp
BYTE pipeCount;

pipeCount = WdfUsbInterfaceGetNumConfiguredPipes(UsbInterface);
```

## See also

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)