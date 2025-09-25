# _NDIS_WWAN_SET_PIN_EX structure

## Description

The NDIS_WWAN_SET_PIN_EX structure represents what PIN action to take on the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_PIN_EX structure. The MB
Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_PIN_REVISION_2 |
| Size | sizeof(NDIS_WWAN_SET_PIN_EX) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PinAction`

A formatted [**WWAN_PIN_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action) object that represents an action to perform with a Personal Identification Number (PIN).

## See also

[WWAN_PIN_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action)