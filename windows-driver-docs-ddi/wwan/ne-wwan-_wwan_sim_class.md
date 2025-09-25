# _WWAN_SIM_CLASS enumeration

## Description

The WWAN_SIM_CLASS enumeration lists the different types of Subscriber Identity Modules (SIMs) that
are supported by the MB device.

## Constants

### `WwanSimClassUnknown`

The device supports an unknown class of SIM.

### `WwanSimClassSimLogical`

The device supports a logical or embedded SIM.

### `WwanSimClassSimRemovable`

The device supports a removable SIM.

### `WwanSimClassSimRemote`

The device supports a remote SIM that is not physically attached to MB device. For example, a
tethered cellular telephone modem.

### `WwanSimClassMax`

The total number of supported SIM classes.

## See also

[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)