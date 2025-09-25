# _WWAN_REGISTER_ACTION enumeration

## Description

The WWAN_REGISTER_ACTION enumeration lists the different provider network registration actions that
are supported by the MB device.

## Constants

### `WwanRegisterActionAutomatic`

Automatically register with provider and then packet-attach, if required.

### `WwanRegisterActionManual`

Manually register with provider and then packet-attach, if required.

### `WwanRegisterActionMax`

The total number of supported registration actions.

## See also

[WWAN_SET_REGISTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_register_state)