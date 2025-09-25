# _WWAN_PIN_DESC structure

## Description

The WWAN_PIN_DESC structure represents the description or current status for a Personal
Identification Number (PIN).

## Members

### `PinMode`

The current status of the PIN.

### `PinFormat`

The format of the PIN. This member is ignored if the
**PinMode** is
**WwanPinModeNotSupported**.

### `PinLengthMin`

The minimum number of characters in the PIN. Miniport drivers should not specify a value that is
greater than WWAN_PIN_LEN (12). Miniport drivers should specify WWAN_PIN_LENGTH_UNKNOWN, if the PIN
length is not available.

### `PinLengthMax`

The maximum number of characters in the PIN. Miniport drivers should not specify a value that is
greater than WWAN_PIN_LEN (12). Miniport drivers should specify WWAN_PIN_LENGTH_UNKNOWN, if the PIN
length is not available.

## See also

[WWAN_PIN_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_format)

[WWAN_PIN_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_list)

[WWAN_PIN_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_mode)