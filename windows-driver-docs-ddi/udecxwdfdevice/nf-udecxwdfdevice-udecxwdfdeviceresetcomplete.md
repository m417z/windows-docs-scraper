# UdecxWdfDeviceResetComplete function

## Description

Informs the USB device emulation class extension (UdeCx) that the reset operation on the specified controller has competed.

## Parameters

### `UdeWdfDevice`

A handle to a framework device object that represents the controller that has been reset. The client driver initialized this object in the previous call to [**UdecxWdfDeviceAddUsbDeviceEmulation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

## Remarks

When the class extension calls the [EVT_UDECX_WDF_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nc-udecxwdfdevice-evt_udecx_wdf_device_reset) callback function, that call is asynchronous. The client driver must call **UdecxWdfDeviceResetComplete** to notify the class extension when the reset operation is complete with appropriate status information.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_WDF_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nc-udecxwdfdevice-evt_udecx_wdf_device_reset)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)