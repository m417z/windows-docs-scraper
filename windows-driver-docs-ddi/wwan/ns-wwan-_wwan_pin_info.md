# _WWAN_PIN_INFO structure

## Description

The WWAN_PIN_INFO structure represents PIN type and PIN-entry state of Personal Identification Number
(PIN) information required by the MB device.

## Members

### `PinType`

The type of PIN required to unlock the information stored on the device.

### `PinState`

The state of PIN-entry required to unlock the device.

This value indicates whether the device requires a PIN to be entered or not.

### `AttemptsRemaining`

The number of attempts that remain for any pin-related operations such as enter, enable, disable,
and change.

## See also

[NDIS_WWAN_PIN_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_pin_info)

[WWAN_PIN_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_state)

[WWAN_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_type)