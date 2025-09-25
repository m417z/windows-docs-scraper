# _UCX_USBDEVICE_CHARACTERISTIC structure

## Description

Stores the characteristics of a device.

## Members

### `Size`

Size of this structure.

### `CharacteristicType`

A [UCX_USBDEVICE_CHARACTERISTIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ne-ucxusbdevice-_ucx_usbdevice_characteristic_type)-type value that indicates the type of device characteristic.

### `PathDelay`

A [UCX_USBDEVICE_CHARACTERISTIC_PATH_DELAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_characteristic_path_delay)-typed value that indicates the path delay values for the endpoint.

## See also

[EVT_UCX_USBDEVICE_GET_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_get_characteristic)