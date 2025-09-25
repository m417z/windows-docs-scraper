# _NDIS_WWAN_SET_RADIO_STATE structure

## Description

The NDIS_WWAN_SET_RADIO_STATE structure represents the power action to take on the MB device's
radio.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_RADIO_STATE
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_RADIO_STATE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_RADIO_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `RadioAction`

A value from the
[WWAN_RADIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_radio) enumeration that represents the power
action to take on the MB device's radio. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WwanRadioOn | Turn on radio. |
| WwanRadioOff | Turn off radio. |

## Remarks

This parameter allows Windows to turn the radio power on and off. Be aware that this affects only the
**SwRadioState** .

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_RADIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_radio)