# _HIDP_EXTENDED_ATTRIBUTES structure

## Description

The HIDP_EXTENDED_ATTRIBUTES structure contains information about the global items specified for a HID control that the HID parser did not recognize.

## Members

### `NumGlobalUnknowns`

Specifies the number of [HIDP_UNKNOWN_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_unknown_token) structures in the list specified by **Data**.

### `Reserved`

Reserved for internal system use only.

### `GlobalUnknowns`

Reserved for internal system use only.

### `Data`

Specifies the memory location where [HidP_GetExtendedAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getextendedattributes) returns a variable length array of [HIDP_UNKNOWN_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_unknown_token) structures.

## Remarks

The HIDP_EXTENDED_ATTRIBUTES structure is designed to be used with **HidP_GetExtendedAttributes**.

## See also

[HIDP_UNKNOWN_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_unknown_token)

[HidP_GetExtendedAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getextendedattributes)