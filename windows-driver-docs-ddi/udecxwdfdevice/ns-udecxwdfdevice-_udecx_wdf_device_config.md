# _UDECX_WDF_DEVICE_CONFIG structure

## Description

Contains pointers to event callback functions implemented by the UDE client driver for a USB host controller. Initialize this structure by calling [UDECX_WDF_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecx_wdf_device_config_init).

## Members

### `Size`

The size of this structure.

### `NumberOfUsb20Ports`

The number of USB 2.0 ports on the root hub of the emulated host controller.

### `NumberOfUsb30Ports`

The number of USB 3.0 ports on the root hub of the emulated host controller.

### `EvtUdecxWdfDeviceQueryUsbCapability`

A pointer to an [EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nc-udecxwdfdevice-evt_udecx_wdf_device_query_usb_capability) callback function.

### `ResetAction`

A [UDECX_WDF_DEVICE_RESET_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ne-udecxwdfdevice-_udecx_wdf_device_reset_action)-type value that indicates the reset action: each attached device or the host controller.

### `EvtUdecxWdfDeviceReset`

A pointer to an [EVT_UDECX_WDF_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nc-udecxwdfdevice-evt_udecx_wdf_device_reset) callback function.

## See also

[UDECX_WDF_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecx_wdf_device_config_init)

[UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation)