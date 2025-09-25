# _BTH_LOCAL_RADIO_INFO structure

## Description

The BTH_LOCAL_RADIO_INFO structure contains information about the local Bluetooth system and
radio.

## Members

### `localInfo`

A
[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info) structure that contains
information about the local radio.

### `flags`

A flag that indicates the state of the local radio. Both flags can be set at the same time.
Possible values include:

LOCAL_RADIO_DISCOVERABLE

LOCAL_RADIO_CONNECTABLE

### `hciRevision`

The minor version of the host controller interface (HCI).

### `hciVersion`

The major version of the HCI.

### `radioInfo`

A
[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info) structure that contains
information about the local radio device.

## Remarks

The
[IOCTL_BTH_GET_LOCAL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_get_local_info) call's
output buffer contains the information about the local Bluetooth system and radio.

## See also

[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info)

[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info)

[IOCTL_BTH_GET_LOCAL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_get_local_info)