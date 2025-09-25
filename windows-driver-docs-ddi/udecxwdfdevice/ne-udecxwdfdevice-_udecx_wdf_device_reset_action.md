# _UDECX_WDF_DEVICE_RESET_ACTION enumeration

## Description

Defines values that indicate the types of reset operation supported by an emulated USB host controller.

## Constants

### `UdecxWdfDeviceResetActionResetEachUsbDevice`

Each device that is attached to the controller is reset.

### `UdecxWdfDeviceResetActionResetWdfDevice`

The emulated host controller is reset.

## See also

[EVT_UDECX_WDF_DEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nc-udecxwdfdevice-evt_udecx_wdf_device_reset)

[UDECX_WDF_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ns-udecxwdfdevice-_udecx_wdf_device_config)