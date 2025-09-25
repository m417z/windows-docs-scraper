# _WWAN_PACKET_SERVICE_STATE enumeration

## Description

The WWAN_PACKET_SERVICE_STATE enumeration lists the different packet service attachment states that
are supported by the MB device.

## Constants

### `WwanPacketServiceStateUnknown`

Packet service state is unknown. The miniport driver should specify this state on a failure to set
the MB packet service state.

### `WwanPacketServiceStateAttaching`

Packet service attach action is in progress.

### `WwanPacketServiceStateAttached`

Packet service is attached.

### `WwanPacketServiceStateDetaching`

Packet service detach action is in progress.

### `WwanPacketServiceStateDetached`

Packet service is detached.

## Remarks

The packet service attach or detach state is typically reflected in the device's user interface.

## See also

[WWAN_PACKET_SERVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_packet_service)