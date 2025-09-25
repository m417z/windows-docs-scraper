# _L2CAP_DISCONNECT_REASON enumeration

## Description

The L2CAP_DISCONNECT_REASON enumeration type gives the reason an L2CAP channel has been
disconnected.

## Constants

### `HciDisconnect`

The value specifies for the profile driver that the Bluetooth driver stack has received a
disconnect notification from the host controller interface (HCI) layer.

### `L2capDisconnectRequest`

This value specifies for the profile driver that a disconnect request has been received from a
remote device.

### `RadioPoweredDown`

This value specifies for the profile driver that the local radio has been turned off.

### `HardwareRemoval`

This value specifies for the profile driver that the local radio has been physically
removed.

## Remarks

A value from this enumeration is used as the
**Reason** member of the
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structure.

Hardware limitations may prevent the Bluetooth driver stack from distinguishing between
**RadioPoweredDown** and
**HardwareRemoval** events.

Currently,
*HciDisconnect* and
*L2capDisconnectRequest* are the only values the Bluetooth driver stack passes to the
[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback).

## See also

[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters)