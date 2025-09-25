# EVT_UDECX_WDF_DEVICE_RESET callback function

## Description

The UDE client driver's implementation to reset the emulated host controller or the devices attached to it.

## Parameters

### `UdecxWdfDevice` [in]

A handle to a framework device object that represents the controller. The client driver initialized this object in the previous call to [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

## Remarks

The USB device emulation class extension (UdeCx) invokes this callback function to notify the client driver that it must handle a reset request including resetting all downstream devices attached to the emulated host controller.
This call is asynchronous. The client driver signals completion with status information by calling [UdecxWdfDeviceResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceresetcomplete).
If the client specified **UdeWdfDeviceResetActionResetEachUsbDevice** in [UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config) (during the [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation) call), this callback is never used. Instead, each connected attached device receives an *EVT_UDECX_WDF_DEVICE_RESET* callback.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)