## Description

Defines the possible reasons that data is discarded by one of the network layers.

## Constants

### `IpDiscardBadSourceAddress`

The outgoing packet's source address is a multicast address, a broadcast address, or an IPv6 address that contains an embedded IPv4 loopback or unspecified address.

### `IpDiscardNotLocallyDestined`

The received packet's destination address doesn't exist on the system, and no appropriate forwarding interface exists.

### `IpDiscardProtocolUnreachable`

There's either no transport protocol handler for the received packet or the transport protocol handler refused to process the packet.

### `IpDiscardPortUnreachable`

There's no application that is receiving packets on the received packet's destination port.

### `IpDiscardBadLength`

A length field specified within the received packet is inconsistent with the packet's length.

### `IpDiscardMalformedHeader`

The received packet contains a recognized extension header or option whose contents are invalid.

### `IpDiscardNoRoute`

The received packet can't be forwarded to its destination address because the system's routing table doesn't contain a route to that destination.

### `IpDiscardBeyondScope`

The received packet can't be forwarded because the packet's incoming and outgoing network interfaces have different zone indexes for the packet's zone level.

### `IpDiscardInspectionDrop`

The packet was dropped during inspection due to failing security checks or protocol compliance issues.

### `IpDiscardTooManyDecapsulations`

The received packet cannot be forwarded to its destination address because there are too many decapsulations.

### `IpDiscardAdministrativelyProhibited`

The packet was discarded due to administrative policies prohibiting its transmission or receipt.

### `IpDiscardBadChecksum`

The packet was discarded because its checksum was incorrect, indicating potential data corruption.

### `IpDiscardFirstFragmentIncomplete`

The first fragment of the packet was incomplete, leading to the discard of the entire packet.

### `IpDiscardHeaderNotContiguous`

The packet's header wasn't contiguous in memory, causing it to be discarded.

### `IpDiscardHeaderNotAligned`

The packet header wasn't properly aligned, leading to its discard due to formatting issues.

### `IpDiscardReceivePathMax`

The packet was discarded as it exceeded the maximum length allowed on the receive path.

### `IpDiscardHopLimitExceeded`

The received packet's hop limit or time-to-live limit has been exceeded.

### `IpDiscardAddressUnreachable`

The outgoing packet can't be sent to the packet's destination address either because the destination doesn't exist or packets aren't allowed to be sent to that destination.

### `IpDiscardRscPacket`

The outgoing packet can't be sent because it is a receive-side coalesced (RSC) packet.

### `IpDiscardSourceViolation`

The packet was discarded because it violated source address validation checks.

### `IpDiscardForwardPathMax`

The packet exceeded the maximum path length for forwarding and was discarded.

### `IpDiscardArbitrationUnhandled`

The packet was discarded because it required arbitration that wasn't handled.

### `IpDiscardInspectionAbsorb`

The outgoing packet cannot be sent because WFP took ownership of the packet.

### `IpDiscardDontFragmentMtuExceeded`

The packet was discarded because it exceeded the MTU size and had the Don't Fragment bit set.

### `IpDiscardBufferLengthExceeded`

The packet was discarded because it exceeded the buffer length limitations.

### `IpDiscardAddressResolutionTimeout`

The packet was discarded due to a timeout in address resolution.

### `IpDiscardAddressResolutionFailure`

The packet was discarded because address resolution failed.

### `IpDiscardIpsecFailure`

The packet was discarded due to an IPsec processing failure.

### `IpDiscardExtensionHeadersFailure`

The packet was discarded because of a failure related to processing IPv6 extension headers.

### `IpDiscardAllocationFailure`

The packet was discarded due to a failure in allocating necessary resources.

### `IpDiscardIpsnpiClientDrop`

The packet was discarded by an IPSNPI client due to unspecified reasons.

### `IpDiscardUnsupportedOffload`

The packet was discarded because it required an unsupported offload operation.

### `IpDiscardRoutingFailure`

The packet was discarded due to a failure in routing.

### `IpDiscardAncillaryDataFailure`

The packet was discarded because of a failure related to ancillary data processing.

### `IpDiscardRawDataFailure`

The packet was discarded due to a failure in processing raw data.

### `IpDiscardSessionStateFailure`

The packet was discarded because of a failure related to session state management.

### `IpDiscardIpsnpiAllocationFailure`

The packet was discarded due to an allocation failure within the IPSNPI subsystem.

### `IpDiscardIpsnpiModifiedButNotForwarded`

The packet was modified by IPSNPI but not forwarded, leading to its discard.

### `IpDiscardIpsnpiNoNextHop`

The packet was discarded because no next hop could be determined in the IPSNPI subsystem.

### `IpDiscardIpsnpiNoCompartment`

The packet was discarded due to a missing compartment in the IPSNPI subsystem.

### `IpDiscardIpsnpiNoInterface`

The packet was discarded because no interface was found in the IPSNPI subsystem.

### `IpDiscardIpsnpiNoSubInterface`

The packet was discarded due to the absence of a sub-interface in the IPSNPI subsystem.

### `IpDiscardIpsnpiInterfaceDisabled`

The packet was discarded because the interface in the IPSNPI subsystem was disabled.

### `IpDiscardIpsnpiSegmentationFailed`

The packet was discarded due to a failure in segmentation within the IPSNPI subsystem.

### `IpDiscardIpsnpiNoEthernetHeader`

The packet was discarded because it lacked an Ethernet header in the IPSNPI subsystem.

### `IpDiscardIpsnpiUnexpectedFragment`

The packet was discarded because it was an unexpected fragment in the IPSNPI subsystem.

### `IpDiscardIpsnpiUnsupportedInterfaceType`

The packet was discarded due to an unsupported interface type in the IPSNPI subsystem.

### `IpDiscardIpsnpiInvalidLsoInfo`

The packet was discarded because of invalid Large Send Offload (LSO) information in the IPSNPI subsystem.

### `IpDiscardIpsnpiInvalidUsoInfo`

The packet was discarded due to invalid UDP Segmentation Offload (USO) information in the IPSNPI subsystem.

### `IpDiscardInternalError`

The packet was discarded due to an internal error within the system.

### `IpDiscardAdministrativelyConfigured`

The packet was discarded due to an administrative configuration that prevented its processing.

### `IpDiscardBadOption`

The packet was discarded because it contained a bad option or an option that couldn't be processed.

### `IpDiscardLoopbackDisallowed`

The packet was discarded because loopback was disallowed for its type or destination.

### `IpDiscardSmallerScope`

The packet was discarded because its scope was smaller than required for successful delivery.

### `IpDiscardQueueFull`

The packet was discarded because the processing queue was full.

### `IpDiscardInterfaceDisabled`

The packet was discarded because the interface it arrived on was disabled.

### `IpDiscardNlClientDiscard`

The packet was discarded by a Netlink client due to unspecified reasons.

### `IpDiscardIpsnpiUroSegmentSizeExceedsMtu`

The packet was discarded because the segment size for UDP RSC Offload (URO) exceeded the MTU in the IPSNPI subsystem.

### `IpDiscardSwUsoFailure`

The packet was discarded due to a UDP Segmentation Offload (USO) failure.

### `IpDiscardMax`

The maximum value for enumeration.

## Remarks

## See also