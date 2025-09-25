# WdfUsbTargetDeviceGetInterface function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceGetInterface** method returns a handle to the framework USB interface object that is associated with a specified interface index.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `InterfaceIndex` [in]

A zero-based index value that specifies a USB interface object in the current configuration. This index value might not be the same as the interface number that the USB specification defines.

## Return value

**WdfUsbTargetDeviceGetInterface** returns a handle to a USB interface object. If the *InterfaceIndex* value is invalid, this method returns **NULL**.

A bug check occurs if a driver-supplied object handle is invalid.

## Remarks

For more information about the **WdfUsbTargetDeviceGetInterface** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains a handle to the first USB interface object that the framework has created for a USB device. The example then obtains the number of endpoints that are associated with the interface object.

```cpp
WDFUSBINTERFACE  UsbInterface;
BYTE  numEndpoints;

UsbInterface = WdfUsbTargetDeviceGetInterface(
                                              deviceContext->UsbTargetDevice,
                                              0
                                              );
numEndpoints = WdfUsbInterfaceGetNumEndpoints(
                                              UsbInterface,
                                              0
                                              );
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)