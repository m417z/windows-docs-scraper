# UdecxWdfDeviceAddUsbDeviceEmulation function

## Description

Initializes a framework device object to support operations related to a host controller and a virtual USB device attached to the controller.

## Parameters

### `WdfDevice`

A handle to the framework device object that the client driver retrieved in the previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config` [in]

 A pointer to a [UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config) structure that the client driver initialized by calling [UDECX_WDF_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecx_wdf_device_config_init).

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

The UDE client driver for the emulated host controller and the USB device must call this method after the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call.

During this call, the client driver-supplied event callback implementations are also registered. Supply function pointers to those functions by call setting appropriate members of [UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config).

The method makes the framework device object capable of performing operations related to a controller and its root hub, such as handling various queues required to process IOCTL requests sent to the attached USB device.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)