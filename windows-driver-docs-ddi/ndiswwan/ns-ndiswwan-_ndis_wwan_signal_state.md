# _NDIS_WWAN_SIGNAL_STATE structure

## Description

The NDIS_WWAN_SIGNAL_STATE structure represents the signal state of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SIGNAL_STATE structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | Windows 10, version 1903 and later miniport drivers set this to NDIS_WWAN_SIGNAL_STATE_REVISION_3. Earlier miniport driver versions set this to NDIS_WWAN_SIGNAL_STATE_REVISION_1. |
| Size | sizeof(NDIS_WWAN_SIGNAL_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the signal state operation.

### `SignalState`

A formatted
[WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state) object that represents
the signal state of the MB device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state)