# _NDIS_WWAN_SET_SIGNAL_INDICATION structure

## Description

The NDIS_WWAN_SET_SIGNAL_INDICATION structure represents the signal indication of the MB
device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_SIGNAL_INDICATION
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_SIGNAL_INDICATION_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_SIGNAL_INDICATION) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SignalIndication`

A formatted
[WWAN_SET_SIGNAL_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_signal_indication) object that represents the frequency of RSSI interval and RSSI
threshold notifications.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SET_SIGNAL_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_signal_indication)