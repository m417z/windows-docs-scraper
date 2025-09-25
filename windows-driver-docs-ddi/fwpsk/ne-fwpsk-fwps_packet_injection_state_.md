# FWPS_PACKET_INJECTION_STATE_ enumeration

## Description

The FWPS_PACKET_INJECTION_STATE enumeration type specifies the injection state of a network buffer
list.

## Constants

### `FWPS_PACKET_NOT_INJECTED`

The packet was not injected by any of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions). A
packet that originated from the TCP/IP stack will be at this state.

### `FWPS_PACKET_INJECTED_BY_SELF`

The packet was injected using an injection handle passed by a call to one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions).

### `FWPS_PACKET_INJECTED_BY_OTHER`

The packet was injected using an injection handle other than one passed by a call
to one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions).

### `FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF`

The packet was injected by using an injection handle passed by a call to one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions), but
the packet was later cloned and reinjected by an additional call to a packet injection function,
possibly using a different injection handle.

### `FWPS_PACKET_INJECTION_STATE_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.