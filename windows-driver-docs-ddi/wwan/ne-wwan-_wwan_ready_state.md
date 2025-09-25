# _WWAN_READY_STATE enumeration

## Description

The WWAN_READY_STATE enumeration lists the different device ready-states that are supported by the MB
device.

## Constants

### `WwanReadyStateOff`

The device firmware stack is OFF or has not yet completed its initialization.

### `WwanReadyStateInitialized`

The device is ready to turn on and register with the provider.

### `WwanReadyStateSimNotInserted`

The SIM card is not inserted into the device.

### `WwanReadyStateBadSim`

The SIM card inserted into the device is invalid.

### `WwanReadyStateFailure`

A general device failure has occurred.

### `WwanReadyStateNotActivated`

The subscription is not activated.

### `WwanReadyStateDeviceLocked`

The device is locked and requires PIN1 or PUK1 to unlock.

Note that if a device is locked because it requires a PIN type other than PIN1 or PUK1 (for example,
a network personalization PIN), miniport drivers should report
**WwanReadyStateInitialized**. Though miniport drivers should return WWAN_STATUS_PIN_REQUIRED for OID
requests which are blocked because of PIN. Subsequent OID_WWAN_PIN
*query* requests should return the PIN type needed to unlock the device.

### `WwanReadyStateNoEsimProfile`

### `WwanReadyStateMax`

## Remarks

For devices that use a SIM card, this enumeration indicates if the SIM card has been initialized and
is ready for access.

## See also

[WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ready_info)