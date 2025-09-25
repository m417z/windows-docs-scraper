# WdfUsbTargetPipeWdmGetPipeHandle function

## Description

[Applies to KMDF only]

The **WdfUsbTargetPipeWdmGetPipeHandle** method returns the USBD_PIPE_HANDLE-typed handle that is associated with a specified framework pipe object.

## Parameters

### `UsbPipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

## Return value

**WdfUsbTargetPipeWdmGetPipeHandle** returns a USBD_PIPE_HANDLE-typed handle.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A framework-based driver needs to obtain a USBD_PIPE_HANDLE-typed handle only if it creates a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) that requires a pipe handle.

The driver can call the **WdfUsbTargetPipeWdmGetPipeHandle** method after it has called [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig). The USBD_PIPE_HANDLE-typed handle that **WdfUsbTargetPipeWdmGetPipeHandle** returns is valid until the driver calls **WdfUsbTargetDeviceSelectConfig** again, the driver calls [WdfUsbInterfaceSelectSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfaceselectsetting), or the framework pipe object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework pipe object, and if the object is deleted before the driver calls **WdfUsbTargetDeviceSelectConfig** again or calls **WdfUsbInterfaceSelectSetting**, the handle is valid until the object's *EvtCleanupCallback* function returns.

For more information about the **WdfUsbTargetPipeWdmGetPipeHandle** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example obtains the USBD_PIPE_HANDLE-typed handle for a specified pipe.

```cpp
USBD_PIPE_HANDLE  usbdPipeHandle;

usbdPipeHandle = WdfUsbTargetPipeWdmGetPipeHandle(UsbPipe);
```

## See also

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)