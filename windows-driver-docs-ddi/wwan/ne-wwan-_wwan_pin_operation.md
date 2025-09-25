# _WWAN_PIN_OPERATION enumeration

## Description

The WWAN_PIN_OPERATION enumeration lists the different Personal Identification Number (PIN)
operations that are supported by the MB device.

## Constants

### `WwanPinOperationEnter`

Enter the specified PIN into the device.

### `WwanPinOperationEnable`

Enable the specified PIN.

### `WwanPinOperationDisable`

Disable the specified PIN.

### `WwanPinOperationChange`

Change the specified PIN.

### `WwanPinOperationMax`

The total number of supported PIN operations.

## Remarks

If a PIN disable operation for a given PIN type is tried when that PIN type is locked, miniport
drivers can either fail the request with WWAN_STATUS_PIN_REQUIRED or they can successfully complete the
request. If miniport drivers complete the request successfully, the disable operation should also unlock
the PIN.

## See also

[WWAN_PIN_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action)