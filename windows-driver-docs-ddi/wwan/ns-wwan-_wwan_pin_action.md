# _WWAN_PIN_ACTION structure

## Description

The WWAN_PIN_ACTION structure represents actions to perform with a Personal Identification Number
(PIN).

## Members

### `PinType`

The type of the PIN on which to perform the action.

### `PinOperation`

The action to perform with the PIN. For more information, see [WWAN_PIN_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_operation).

### `Pin`

A NULL-terminated string that represents the PIN value to perform the action with, or the PIN
value required to enable/disable PIN settings. This member is a numeric value and applies for all values of
**PinOperation** .

### `NewPin`

A NULL-terminated string that represents the new PIN value to set when
**PinOperation** is
**WwanPinOperationChange** or
**WwanPinOperationEnter**, for
**PinType****WwanPinTypePuk1** or
**WwanPinTypePuk2**. This member is a numeric value.

### `RequestPinOperationPrompt`

A BOOLEAN value that indicates whether to display a prompt to request the PIN operation.

## Remarks

When
**PinType** is
**WwanPinTypePuk1** or
**WwanPinTypePuk2**,
**Pin** represents the corresponding PUK key.

When
**PinType** is
**WwanPinTypePuk1** or
**WwanPinTypePuk2, WwanPinOperationEnter** is the only supported value for
**PinOperation** .

## See also

[NDIS_WWAN_SET_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_pin)

[WWAN_PIN_OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_operation)

[WWAN_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_type)