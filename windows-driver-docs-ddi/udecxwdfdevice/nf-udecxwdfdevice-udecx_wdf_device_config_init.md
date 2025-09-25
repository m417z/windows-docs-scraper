# UDECX_WDF_DEVICE_CONFIG_INIT function

## Description

Initializes a [UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config) structure.

## Parameters

### `Config` [out]

A pointer to a [UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config) structure to initialize.

### `EvtUdecxWdfDeviceQueryUsbCapability` [in]

A pointer to an [EVT_UDECX_WDF_DEVICE_QUERY_USB_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nc-udecxwdfdevice-evt_udecx_wdf_device_query_usb_capability) callback function.

## See also

[UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config)

[UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation)