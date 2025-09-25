# NDIS_INTERFACE_INFORMATION structure

## Description

The NDIS_INTERFACE_INFORMATION structure provides information about a network interface for the
[OID_GEN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-interface-info) OID.

## Members

### `ifOperStatus`

The operational status of the interface. This status is the same as the value that the
[OID_GEN_OPERATIONAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-operational-status) OID
returns.

### `ifOperStatusFlags`

The operational status flags of the interface. This field is reserved for the NDIS proxy interface
provider. Other interface providers should set this member to zero.

### `MediaConnectState`

The
[NET_IF_MEDIA_CONNECT_STATE](https://learn.microsoft.com/windows/desktop/api/ifdef/ne-ifdef-net_if_media_connect_state) connection state type.

### `MediaDuplexState`

The media duplex state of the interface. This state is the same as the value that the
[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state) OID
returns.

### `ifMtu`

The maximum transmission unit (MTU) of the interface. This MTU is the same as the value that the
[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size) OID
returns.

### `ifPromiscuousMode`

A Boolean value that is **TRUE** if the interface is in promiscuous mode or **FALSE** if it is not. This
value is the same as the value that
[OID_GEN_PROMISCUOUS_MODE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-promiscuous-mode) OID query
returns.

### `ifDeviceWakeUpEnable`

A Boolean value that is **TRUE** if the interface supports wake-on-LAN capability and the capability is enabled, or **FALSE** if it does
not.

### `XmitLinkSpeed`

The transmit link speed, in bytes per second, of the interface. This speed is the same as the
value that an
[OID_GEN_XMIT_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-xmit-link-speed) OID query
returns.

### `RcvLinkSpeed`

The receive link speed, in bytes per second, of the interface. This speed is the same as the value
that an
[OID_GEN_RCV_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rcv-link-speed) OID query
returns.

### `ifLastChange`

The time that the interface entered its current operational state. This time is the same as the
value that an
[OID_GEN_LAST_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-last-change) OID query
returns.

### `ifCounterDiscontinuityTime`

The time of the last discontinuity of the interface's counters. This time is the same as the value
that an
[OID_GEN_DISCONTINUITY_TIME](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-discontinuity-time) OID
query returns.

### `ifInUnknownProtos`

The number of packets that were received through the interface and that were discarded because of
an unknown or unsupported protocol. This number is the same as the value that an
[OID_GEN_UNKNOWN_PROTOS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-unknown-protos) OID query
returns.

### `ifInDiscards`

The number of inbound packets that were discarded even though no errors had been detected to
prevent them from being deliverable to a higher-layer protocol. This number is the same as the value
that an
[OID_GEN_RCV_DISCARDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rcv-discards) OID query
returns.

### `ifInErrors`

The number of inbound packets that contained errors that prevented them from being deliverable to
a higher layer protocol. This number is the same as the value that an
[OID_GEN_RCV_ERROR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rcv-error) OID query returns.

### `ifHCInOctets`

The total number of bytes that are received on this interface. This number is the same as the
value that an
[OID_GEN_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-bytes-rcv) OID returns.

### `ifHCInUcastPkts`

The number of directed packets that are received without errors on the interface. This number is
the same as the value that an
[OID_GEN_DIRECTED_FRAMES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-frames-rcv) OID
query returns.

### `ifHCInMulticastPkts`

The number of multicast/functional packets that are received without errors on the interface. This
number is the same as the value that an
[OID_GEN_MULTICAST_FRAMES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-frames-rcv) OID
query returns.

### `ifHCInBroadcastPkts`

The number of broadcast packets that are received without errors on the interface. This number is
the same as the value that an
[OID_GEN_BROADCAST_FRAMES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-frames-rcv) OID
query returns.

### `ifHCOutOctets`

The number of bytes that are transmitted without errors on the interface. This number is the same
as the value that an
[OID_GEN_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-bytes-xmit) OID query
returns.

### `ifHCOutUcastPkts`

The number of directed packets that are transmitted without errors on the interface. This number
is the same as the value that an
[OID_GEN_DIRECTED_FRAMES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-frames-xmit) OID
query returns.

### `ifHCOutMulticastPkts`

The number of multicast/functional packets that are transmitted without errors on the interface.
This number is the same as the value that an
[OID_GEN_MULTICAST_FRAMES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-frames-xmit) OID query returns.

### `ifHCOutBroadcastPkts`

The number of broadcast packets that are transmitted without errors on the interface. This number
is the same as the value that an
[OID_GEN_BROADCAST_FRAMES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-frames-xmit) OID query returns.

### `ifOutErrors`

The number of packets that the interface fails to transmit. This number is the same as the value
that an
[OID_GEN_XMIT_ERROR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-xmit-error) OID query
returns.

### `ifOutDiscards`

The number of packets that the interface discards. This number is the same as the value that an
[OID_GEN_XMIT_DISCARDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-xmit-discards) OID query
returns.

### `ifHCInUcastOctets`

The number of bytes in directed packets that are received without errors. This count is the same
value that
[OID_GEN_DIRECTED_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-bytes-rcv) returns.

### `ifHCInMulticastOctets`

The number of bytes in multicast/functional packets that are received without errors. This count
is the same value that
[OID_GEN_MULTICAST_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-bytes-rcv) returns.

### `ifHCInBroadcastOctets`

The number of bytes in broadcast packets that are received without errors. This count is the same
value that
[OID_GEN_BROADCAST_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-bytes-rcv) returns.

### `ifHCOutUcastOctets`

The number of bytes in directed packets that are transmitted without errors. This count is the
same value that
[OID_GEN_DIRECTED_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-bytes-xmit) returns.

### `ifHCOutMulticastOctets`

The number of bytes in multicast/functional packets that are transmitted without errors. This
count is the same value that
[OID_GEN_MULTICAST_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-bytes-xmit) returns.

### `ifHCOutBroadcastOctets`

The number of bytes in broadcast packets that are transmitted without errors. This count is the
same value that
[OID_GEN_BROADCAST_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-bytes-xmit) returns.

### `CompartmentId`

The compartment that the interface belongs to, if the interface provider can provide the ID of the
compartment to which the interface belongs. Otherwise, it should return
NET_IF_COMPARTMENT_ID_UNSPECIFIED. If the interface provider returns NET_IF_COMPARTMENT_ID_UNSPECIFIED
for the compartment ID, NDIS will return the right compartment ID for this interface.

### `SupportedStatistics`

The supported statistics. For more information, see the
**SupportedStatistics** member of the
[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_miniport_adapter_general_attributes) structure.

## Remarks

NDIS interface providers populate an NDIS_INTERFACE_INFORMATION structure in response to a query of
the
[OID_GEN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-interface-info) OID. This
structure contains information that changes during the lifetime of the interface.

To register as an interface provider, an NDIS driver calls the
[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndisifregisterprovider) function.

## See also

[Introduction to Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/introduction-to-network-drivers)

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_miniport_adapter_general_attributes)

[NET_IF_MEDIA_CONNECT_STATE](https://learn.microsoft.com/windows/desktop/api/ifdef/ne-ifdef-net_if_media_connect_state)

[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/nf-ndis-ndisifregisterprovider)

[OID_GEN_BROADCAST_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-bytes-rcv)

[OID_GEN_BROADCAST_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-bytes-xmit)

[OID_GEN_BROADCAST_FRAMES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-frames-rcv)

[OID_GEN_BROADCAST_FRAMES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-broadcast-frames-xmit)

[OID_GEN_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-bytes-rcv)

[OID_GEN_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-bytes-xmit)

[OID_GEN_DIRECTED_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-bytes-rcv)

[OID_GEN_DIRECTED_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-bytes-xmit)

[OID_GEN_DIRECTED_FRAMES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-frames-rcv)

[OID_GEN_DIRECTED_FRAMES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-directed-frames-xmit)

[OID_GEN_DISCONTINUITY_TIME](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-discontinuity-time)

[OID_GEN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-interface-info)

[OID_GEN_LAST_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-last-change)

[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size)

[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex)

[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state)

[OID_GEN_MULTICAST_BYTES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-bytes-rcv)

[OID_GEN_MULTICAST_BYTES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-bytes-xmit)

[OID_GEN_MULTICAST_FRAMES_RCV](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-frames-rcv)

[OID_GEN_MULTICAST_FRAMES_XMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-multicast-frames-xmit)

[OID_GEN_OPERATIONAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-operational-status)

[OID_GEN_PROMISCUOUS_MODE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-promiscuous-mode)

[OID_GEN_RCV_DISCARDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rcv-discards)

[OID_GEN_RCV_ERROR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rcv-error)

[OID_GEN_RCV_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rcv-link-speed)

[OID_GEN_UNKNOWN_PROTOS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-unknown-protos)

[OID_GEN_XMIT_DISCARDS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-xmit-discards)

[OID_GEN_XMIT_ERROR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-xmit-error)

[OID_GEN_XMIT_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-xmit-link-speed)