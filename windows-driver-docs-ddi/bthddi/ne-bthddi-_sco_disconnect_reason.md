# _SCO_DISCONNECT_REASON enumeration

## Description

The SCO_DISCONNECT_REASON enumeration type gives the reason an SCO channel has been
disconnected.

## Constants

### `ScoHciDisconnect`

This value specifies to the profile driver that the Bluetooth driver stack has received a
disconnect notification from the host controller interface (HCI) layer.

### `ScoDisconnectRequest`

This value specifies to the profile driver that a disconnect request has been received from the
remote device.

### `ScoRadioPoweredDown`

This value specifies to the profile driver that the local radio has been turned off.

### `ScoHardwareRemoval`

This value specifies to the profile driver that the local radio has been physically
removed.

## Remarks

A value from this enumeration is used as the
**Reason** member of the
[SCO_INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_sco_indication_parameters) structure.

Hardware limitations may prevent the Bluetooth driver stack from distinguishing between
**ScoRadioPoweredDown** and
**ScoHardwareRemoval** events.

Currently,
*ScoHciDisconnect* is the only value the Bluetooth driver stack passes to the
[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback).

## See also

[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback)

[SCO_INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_sco_indication_parameters)