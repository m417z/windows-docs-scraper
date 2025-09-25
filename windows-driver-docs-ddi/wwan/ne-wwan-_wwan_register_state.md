# _WWAN_REGISTER_STATE enumeration

## Description

The WWAN_REGISTER_STATE enumeration lists the different provider network registration states that are
supported by the MB device.

## Constants

### `WwanRegisterStateUnknown`

The current registration state is unknown. The miniport driver may specify this state on a failure
to set an appropriate
*WwanRegisterActionXxx*.

### `WwanRegisterStateDeregistered`

The device is not registered and is not searching for network providers.

### `WwanRegisterStateSearching`

The device is searching for a network provider.

### `WwanRegisterStateHome`

The device is using the home network provider.

### `WwanRegisterStateRoaming`

The device is using a network provider that supports roaming.

### `WwanRegisterStatePartner`

The device is using a roaming network partner.

### `WwanRegisterStateDenied`

Registration of the device on visible networks has been denied. However, emergency voice calls may
still be made. This value applies only to voice connections, and not to data connections.

### `WwanRegisterStateMax`

The total number of supported registration states.

## Remarks

The current registration state is typically reflected in the device's user interface.

The
**WwanRegisterStatePartner** value indicates that the device is roaming on a preferred partner network,
whereas
**WwanRegisterStateRoaming** value indicates that the device is just roaming. If the partner
characterization of the roaming state is not available, the miniport driver should report
**WwanRegisterStateRoaming**.

## See also

[WWAN_REGISTRATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_registration_state)