# _HIDP_UNKNOWN_TOKEN structure

## Description

The HIDP_UNKNOWN_TOKEN structure contains information about a global item that the HID parser did not recognize.

## Members

### `Token`

Specifies the one-byte prefix of a global item.

### `Reserved`

Reserved for internal system use.

### `BitField`

Specifies the data part of the global item.

## Remarks

HIDP_UNKNOWN_TOKEN is designed to be used with the [HIDP_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_extended_attributes) structure. [HidP_GetExtendedAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getextendedattributes) returns a HIDP_EXTENDED_ATTRIBUTES structure, which contains a variable length array of **HIDP_UNKNOWN_TOKEN** structures.

## See also

[HIDP_EXTENDED_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_extended_attributes)

[HidP_GetExtendedAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getextendedattributes)