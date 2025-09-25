# WdfUsbTargetDeviceWdmGetConfigurationHandle function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceWdmGetConfigurationHandle** method returns the USBD_CONFIGURATION_HANDLE-typed handle that is associated with the current configuration of a specified USB device.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

## Return value

If the driver has selected a configuration for the device, **WdfUsbTargetDeviceWdmGetConfigurationHandle** returns the device's USBD_CONFIGURATION_HANDLE-typed handle. Otherwise, the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A framework-based driver needs to obtain a USBD_CONFIGURATION_HANDLE-typed handle only if it creates a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) that contains a [_URB_SELECT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_interface) structure.

The driver can call **WdfUsbTargetDeviceWdmGetConfigurationHandle** after it has called [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig). The USBD_CONFIGURATION_HANDLE-typed handle that **WdfUsbTargetDeviceWdmGetConfigurationHandle** returns is valid until the driver calls **WdfUsbTargetDeviceSelectConfig** again or the USB device object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the USB device object, and if the object is deleted before the driver calls **WdfUsbTargetDeviceSelectConfig** again, the handle is valid until the object's *EvtCleanupCallback* function returns.

For more information about the **WdfUsbTargetDeviceWdmGetConfigurationHandle** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains a handle to the current configuration of a specified USB device.

```cpp
USBD_CONFIGURATION_HANDLE deviceConfigHdl;

deviceConfigHdl = WdfUsbTargetDeviceWdmGetConfigurationHandle(UsbDevice);
```

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)

[_URB_SELECT_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_select_interface)