# _WWAN_PIN_FORMAT enumeration

## Description

The WWAN_PIN_FORMAT enumeration lists the different Personal Identification Number (PIN) formats that
are supported by the MB device.

## Constants

### `WwanPinFormatUnknown`

The format of PIN is not specified.

### `WwanPinFormatNumeric`

The format of the PIN allows only the numerical characters 0 through 9.

### `WwanPinFormatAlphaNumeric`

The format of the PIN allows alphanumeric characters a through z (lowercase), A through Z
(uppercase), 0 through 9 (numeric), the asterisk symbol (*), and the pound symbol (#).

### `WwanPinFormatMax`

The total number of supported PIN formats.

## See also

[WWAN_PIN_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_desc)