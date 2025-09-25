# WdfUsbInterfaceGetNumEndpoints function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetNumEndpoints** method returns the number of endpoints that are associated with a specified alternate setting of a specified USB interface.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

### `SettingIndex` [in]

An index value that identifies an alternate setting for the interface. For more information about alternate settings, see the USB specification.

## Return value

If the specified index is valid, **WdfUsbInterfaceGetNumEndpoints** returns the number of endpoints that are associated with the specified interface's alternate setting. Otherwise, the method returns zero.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbInterfaceGetNumEndpoints** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the number of endpoints for alternate setting 0 of a specified USB interface.

```cpp
BYTE  numEndpoints;
numEndpoints = WdfUsbInterfaceGetNumEndpoints(
                                              UsbInterface,
                                              0
                                              );
```

## See also

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)