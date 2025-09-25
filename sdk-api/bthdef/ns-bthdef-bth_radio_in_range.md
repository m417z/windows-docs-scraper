# BTH_RADIO_IN_RANGE structure

## Description

The **BTH_RADIO_IN_RANGE** structure stores data about Bluetooth devices within communication range.

## Members

### `deviceInfo`

Current set of attributes associated with the remote device, in the form of a [BTH_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/bthdef/ns-bthdef-bth_device_info) structure.

### `previousDeviceFlags`

Previous flags for the **flags** member of the [BTH_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/bthdef/ns-bthdef-bth_device_info) structure pointed to by the **deviceInfo** member. Used to determine which attributes associated with the remote device have changed.

## See also

[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/bthdef/ns-bthdef-bth_device_info)

[Bluetooth and WM_DEVICECHANGE
Messages](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wm-devicechange-messages)