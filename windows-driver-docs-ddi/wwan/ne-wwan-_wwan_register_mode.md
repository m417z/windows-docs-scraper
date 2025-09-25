# _WWAN_REGISTER_MODE enumeration

## Description

The WWAN_REGISTER_MODE enumeration lists the different network selection modes which defines the way
the device should select a network while registering.

## Constants

### `WwanRegisterModeUnknown`

It is not specified how the device registers with network providers.

### `WwanRegisterModeAutomatic`

Device automatically selects a network on which it should register.

### `WwanRegisterModeManual`

Device registers to a pre-selected (manually selected) network.

### `WwanRegisterModeMax`

The total number of supported registration modes.

## Remarks

**WwanRegisterModeAutomatic** and
**WwanRegisterModeManual** are the only acceptable values. Miniport drivers can return
**WwanRegisterModeManual** in cases where it is not able to get this value from device.

## See also

[WWAN_REGISTRATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_registration_state)