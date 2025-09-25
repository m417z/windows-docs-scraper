# _NEIGHBOR_OFFLOAD_STATE_CONST structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The NEIGHBOR_OFFLOAD_STATE_CONST structure contains the constant variables of a neighbor state
object.

## Members

### `Header`

An
[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header) structure. NDIS
sets the
**Length** member of
**Header** to the size, in bytes, of the NEIGHBOR_OFFLOAD_STATE_CONST structure. The
**RecognizedOptions** member of
**Header** is reserved.

### `DlSourceAddress`

When non-**NULL**, a 32-byte source MAC address. The offload target must support software-configurable
MAC addresses and it must set the source MAC address of all packets that it sends on the offloaded
connection to
**DlSourceAddress** .

When **NULL**, the offload target ignores this parameter and sets the source MAC address to the value
that was configured for the network interface.

If the network interface has one or more multicast addresses enabled, the offloaded connection must
allow receive traffic to arrive on either the configured MAC address or the multicast addresses. The
configured MAC address is either
**DlSourceAddress** or, if
**DlSourceAddress** is zero, the MAC address for the network interface.

### `VlanId`

An unsigned 12-bit binary number that identifies the virtual LAN (VLAN) to which a packet belongs.
The
**VlanId** ID pertains only to packets that are sent or received using the neighbor state object.

When **NULL**, the offload target should use any VLAN IDs that have been configured for its network
interface. The offload target's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
reads such VLAN IDs from the registry.

## Remarks

For a description of how an offload target uses the
**VlanId** member, see
[802.1Q
and 802.1p Processing on an Offloaded TCP Connection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_tcp_offload_state_cached).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NEIGHBOR_OFFLOAD_STATE_CACHED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_cached)

[NEIGHBOR_OFFLOAD_STATE_DELEGATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_neighbor_offload_state_delegated)

[OFFLOAD_STATE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_offload_state_header)