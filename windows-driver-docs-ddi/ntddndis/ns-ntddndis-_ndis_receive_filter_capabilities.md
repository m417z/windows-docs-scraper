# _NDIS_RECEIVE_FILTER_CAPABILITIES structure

## Description

The **NDIS_RECEIVE_FILTER_CAPABILITIES** structure specifies the receive filtering capabilities of a
network adapter.

NDIS receive filters are used in the following NDIS interfaces:

* [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing). For more information about how to use receive filters in this interface, see [Managing Packet Coalescing Receive Filters](https://learn.microsoft.com/windows-hardware/drivers/network/managing-packet-coalescing-receive-filters).
* [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-). For more information about how to use receive filters in this interface, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).
* [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture). For more information about how to use receive filters in this interface, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_FILTER_CAPABILITIES** structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT.

To indicate the version of the **NDIS_RECEIVE_FILTER_CAPABILITIES** structure, the driver sets the
**Revision** member to one of the following values:

#### NDIS_RECEIVE_FILTER_CAPABILITIES_REVISION_2

Added
various members for NDIS 6.30 and later.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_CAPABILITIES_REVISION_2.

#### NDIS_RECEIVE_FILTER_CAPABILITIES_REVISION_1

Original version for NDIS 6.20.

The driver sets the
**Size** member to NDIS_SIZEOF_RECEIVE_FILTER_CAPABILITIES_REVISION_1.

### `Flags`

A bitwise OR of flags. This member is reserved for NDIS.

### `EnabledFilterTypes`

A bitwise OR of flags that specify the types of receive filters that are enabled. The
following filter type flag is valid.

#### NDIS_RECEIVE_FILTER_VMQ_FILTERS_ENABLED

Specifies that VMQ filters are enabled.

**Note** The miniport driver should set this flag if the miniport driver is enabled to use the SR-IOV interface.

#### NDIS_RECEIVE_FILTER_PACKET_COALESCING_FILTERS_ENABLED

Specifies that NDIS packet coalescing receive filters are enabled.

### `EnabledQueueTypes`

A bitwise OR of flags that specify the types of receive queues that are enabled. The
following queue type flag is valid.

#### NDIS_RECEIVE_FILTER_VM_QUEUES_ENABLED

Specifies that virtual machine (VM) queues are enabled. VM queues are used when the miniport driver is enabled to use the VMQ interface.

**Note** The miniport driver must not set this flag if the miniport driver is enabled to only use the SR-IOV interface. For more information on how these interfaces are enabled, see [Handling SR-IOV, VMQ, and RSS Standardized INF Keywords](https://learn.microsoft.com/windows-hardware/drivers/network/handling-sr-iov--vmq--and-rss-standardized-inf-keywords).

### `NumQueues`

The number of VM queues that the network adapter supports.

**Note** If the miniport driver is enabled to use the SR-IOV interface, it must set this member to zero. When use of the SR-IOV interface is enabled, NDIS uses virtual ports (VPorts) for receive and transmit queues instead of VM queues.

### `SupportedQueueProperties`

A bitwise OR of flags that specify the VM queue properties that the network adapter supports. The
following flags are defined:

#### NDIS_RECEIVE_FILTER_MSI_X_SUPPORTED

The network adapter uses MSI-X for receive queue interrupt generation. This flag is mandatory for miniport drivers that support the VMQ or SR-IOV interface.

#### NDIS_RECEIVE_FILTER_VM_QUEUE_SUPPORTED

The network adapter provides the minimum requirements to support VM queue packet filtering.

The miniport driver must set this flag if it is enabled to use the VMQ or SR-IOV interface.

For more information about VMQ requirements for VM queue packet filtering, see [Setting and Clearing VMQ Filters](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-vmq-filters).

For more information about SR-IOV requirements for VM queue packet filtering, see [Setting a Receive Filter on a Virtual Port](https://learn.microsoft.com/windows-hardware/drivers/network/setting-a-receive-filter-on-a-virtual-port).

#### NDIS_RECEIVE_FILTER_LOOKAHEAD_SPLIT_SUPPORTED

The network adapter supports VM queues that split an incoming received packet at the lookahead
offset. This offset is equal to or greater than the requested lookahead size. The network adapter uses DMA to transfer the lookahead
and post-lookahead data to separate shared memory segments.

**Note** Starting with NDIS 6.30, splitting packet data into separate lookahead buffers is no longer supported. Miniport drivers that support this version of NDIS must not set this flag.

#### NDIS_RECEIVE_FILTER_DYNAMIC_PROCESSOR_AFFINITY_CHANGE_SUPPORTED

The network adapter supports the ability to dynamically change one of the following processor affinity attributes:

* The processor affinity of a VM queue in the VMQ interface. The processor affinity is changed through an OID set request of [OID_RECEIVE_FILTER_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-parameters).
* The processor affinity of a nondefault virtual port (VPort), which was created in the SR-IOV interface and is attached to the PCI Express (PCIe) physical function (PF) of the network adapter. The processor affinity is changed through an OID set request of [OID_NIC_SWITCH_VPORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-vport-parameters).

**Note** This flag is supported in NDIS 6.30 and later. Miniport drivers that support the VMQ or SR-IOV interface must set this flag.

#### NDIS_RECEIVE_FILTER_INTERRUPT_VECTOR_COALESCING_SUPPORTED

The network adapter supports interrupt coalescing for received packets on any of the following:

* Multiple VM queues in the VMQ interface.
* Multiple VPorts that are attached to the PF in the SR-IOV interface.

If this flag is set, the network adapter must coalesce receive interrupts for VM queues or VPorts that have the same processor affinity.

**Note** This flag is supported in NDIS 6.30 and later. Miniport drivers that support the VMQ or SR-IOV interface must set this flag.

#### NDIS_RECEIVE_FILTER_IMPLAT_MIN_OF_QUEUES_MODE

Indicates that the number of VM queues available is the minimum number of queues available from any member of a Load Balancing Failover (LBFO) team. This flag applies to LBFO filters only. This flag is not set for miniports.

#### NDIS_RECEIVE_FILTER_IMPLAT_SUM_OF_QUEUES_MODE

Indicates that the number of VM queues available is the sum of all the queues available from every member of an LBFO team. This flag applies to LBFO filters only. This flag is not set for miniports.

#### NDIS_RECEIVE_FILTER_PACKET_COALESCING_SUPPORTED_ON_DEFAULT_QUEUE

The network adapter supports NDIS packet coalescing. Packet coalescing is only supported on the default receive queue of the network adapter. This receive queue has an identifier of NDIS_DEFAULT_RECEIVE_QUEUE_ID.

**Note** This flag is supported in NDIS 6.30 and later.

### `SupportedFilterTests`

A bitwise OR of flags that specify the test operations that a miniport
driver supports. The following flags are defined:

#### NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_EQUAL_SUPPORTED

The network adapter supports testing the selected header field to determine whether it is equal to a
given value.

**Note** If the miniport driver supports the VMQ or SR-IOV interfaces, it must set this flag.

#### NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_MASK_EQUAL_SUPPORTED

The network adapter supports masking (that is, a bitwise AND) of the selected header field to
determine whether the result is equal to a specified value.

#### NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_NOT_EQUAL_SUPPORTED

The network adapter supports testing the selected header field to determine whether it is not equal to a
specified value.

**Note** This flag is supported in NDIS 6.30 and later.

### `SupportedHeaders`

A bitwise OR of flags that specify the types of network packet headers that
a miniport driver can inspect. The following flags are defined:

#### NDIS_RECEIVE_FILTER_MAC_HEADER_SUPPORTED

The network adapter can inspect the media access control (MAC) header of a network packet. The **SupportedMacHeaderFields** member defines the various fields from the MAC header that can be inspected.

#### NDIS_RECEIVE_FILTER_ARP_HEADER_SUPPORTED

The network adapter can inspect the Address Resolution Protocol (ARP) header of a network packet. The **SupportedArpHeaderFields** member defines the various fields from the ARP header that can be inspected.

**Note** This flag is supported in NDIS 6.30 and later.

#### NDIS_RECEIVE_FILTER_IPV4_HEADER_SUPPORTED

The network adapter can inspect the IP version 4 (IPv4) header of a network packet. The **SupportedIPv4HeaderFields** member defines the various fields from the IPv4 header that can be inspected.

**Note** This flag is supported in NDIS 6.30 and later.

#### NDIS_RECEIVE_FILTER_IPV6_HEADER_SUPPORTED

The network adapter can inspect the IP version 6 (IPv6) header of a network packet. The **SupportedIPv6HeaderFields** member defines the various fields from the IPv6 header that can be inspected.

**Note** This flag is supported in NDIS 6.30 and later.

#### NDIS_RECEIVE_FILTER_UDP_HEADER_SUPPORTED

The network adapter can inspect the User Datagram Protocol
(UDP) header of a network packet. The **SupportedIPv6HeaderFields** member defines the various fields from the UDP header that can be inspected.

**Note** This flag is supported in NDIS 6.30 and later.

### `SupportedMacHeaderFields`

A bitwise OR of flags that specify the types of MAC header fields that a
miniport driver can inspect. The following flags are defined:

#### NDIS_RECEIVE_FILTER_MAC_HEADER_DEST_ADDR_SUPPORTED

The network adapter supports inspecting and filtering that are based on the destination MAC
address in the MAC header.

**Note** Starting with NDIS 6.30, miniport drivers that support the VMQ or SR-IOV interface must set this flag.

#### NDIS_RECEIVE_FILTER_MAC_HEADER_SOURCE_ADDR_SUPPORTED

The network adapter supports inspecting and filtering that are based on the source MAC address
in the MAC header.

#### NDIS_RECEIVE_FILTER_MAC_HEADER_PROTOCOL_SUPPORTED

The network adapter supports inspecting and filtering that are based on the EtherType identifier
in the MAC header. For example, the EtherType identifier for IPv4 packets is 0x0800.

#### NDIS_RECEIVE_FILTER_MAC_HEADER_VLAN_ID_SUPPORTED

The network adapter supports inspecting and filtering that are based on the VLAN identifier in
the MAC header.

**Note** Starting with NDIS 6.30, this flag is optional. If the miniport driver does not set this flag, the network adapter should inspect and filter the specified MAC address fields. If a VLAN tag is present in the received packet, the network adapter must remove it from the packet data. The miniport driver must put the VLAN tag in an [NDIS_NET_BUFFER_LIST_8021Q_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_8021q_info) structure that is associated with the packet's [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

#### NDIS_RECEIVE_FILTER_MAC_HEADER_PRIORITY_SUPPORTED

The network adapter supports inspecting and filtering that are based on the priority tag in the
MAC header.

#### NDIS_RECEIVE_FILTER_MAC_HEADER_PACKET_TYPE_SUPPORTED

The network adapter supports inspecting and filtering that are based on the packet type field of the IEEE 802.2 subnetwork access protocol (SNAP) header in an 802.3 MAC header.

**Note** This flag is supported in NDIS 6.30 and later.

### `MaxMacHeaderFilters`

The maximum number of MAC header filters that the miniport driver
supports.

### `MaxQueueGroups`

This member is reserved for NDIS.

### `MaxQueuesPerQueueGroup`

This member is reserved for NDIS.

### `MinLookaheadSplitSize`

The minimum size, in bytes, that the network adapter supports for lookahead
packet buffers.

**Note** Starting with NDIS 6.30, splitting packet data into separate lookahead buffers is no longer supported. Miniport drivers that support this version of NDIS must set this member to zero.

### `MaxLookaheadSplitSize`

The maximum size, in bytes, that the network adapter supports for lookahead
packet buffers.

**Note** Starting with NDIS 6.30, splitting packet data into separate lookahead buffers is no longer supported. Miniport drivers that support this version of NDIS must set this member to zero.

### `SupportedARPHeaderFields`

A bitwise OR of flags that specify the types of ARP header fields that a
miniport driver can inspect. The following flags are defined:

#### NDIS_RECEIVE_FILTER_ARP_HEADER_OPERATION_SUPPORTED

The network adapter supports receive filtering on the ARP operation field.

#### NDIS_RECEIVE_FILTER_ARP_HEADER_SPA_SUPPORTED

The network adapter supports receive filtering on the ARP source protocol address (SPA) field.

#### NDIS_RECEIVE_FILTER_ARP_HEADER_TPA_SUPPORTED

The network adapter supports receive filtering on the ARP target protocol address (TPA) field.

### `SupportedIPv4HeaderFields`

A bitwise OR of flags that specify the types of IPv4 header fields that a
miniport driver can inspect. The following flags are defined:

#### NDIS_RECEIVE_FILTER_IPV4_HEADER_PROTOCOL_SUPPORTED

The network adapter supports receive filtering on the IPv4 protocol field.

### `SupportedIPv6HeaderFields`

A bitwise OR of flags that specify the types of IPv6 header fields that a
miniport driver can inspect. The following flags are defined:

#### NDIS_RECEIVE_FILTER_IPV6_HEADER_PROTOCOL_SUPPORTED

The network adapter supports receive filtering on the IPv6 protocol field.

### `SupportedUdpHeaderFields`

A bitwise OR of flags that specify the types of IPv6 header fields that a
miniport driver can inspect. The following flags are defined:

#### NDIS_RECEIVE_FILTER_UDP_HEADER_DEST_PORT_SUPPORTED

The network adapter supports receive filtering on the UDP destination port field.

**Note** If the received UDP packet contains IPv4 options or IPv6 extension headers, the network adapter can automatically drop the received packet and treat it as if it failed the UDP filter test.

### `MaxFieldTestsPerPacketCoalescingFilter`

The maximum number of tests on packet header fields that can be specified for a single packet coalescing filter. For more information about packet coalescing, see [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing).

**Note** Network adapters that support packet coalescing must support five or more packet header fields that can be specified for a single packet coalescing filter. If the adapter does not support packet coalescing, the miniport driver must set this value to zero.

### `MaxPacketCoalescingFilters`

The maximum number of packet coalescing receive filters that are supported by the network adapter.

**Note** Network adapters that support packet coalescing must support ten or more packet coalescing filters. If the adapter does not support packet coalescing, the miniport driver must set this value to zero.

### `NdisReserved`

Reserved. Set to 0.

## Remarks

The **NDIS_RECEIVE_FILTER_CAPABILITIES** structure is used in the
**ReceiveFilterCapabilities** member of the
[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes),
[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters), and
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structures and the
return result of the
[OID_RECEIVE_FILTER_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-hardware-capabilities) OID query.

Many of the members and flag settings of the **NDIS_RECEIVE_FILTER_CAPABILITIES** structure are valid only if the miniport driver is enabled to use the VMQ or SR-IOV interface. The miniport driver is enabled to use these interfaces through standardized INF keywords. For more information, see [Handling SR-IOV, VMQ, and RSS Standardized INF Keywords](https://learn.microsoft.com/windows-hardware/drivers/network/handling-sr-iov--vmq--and-rss-standardized-inf-keywords).

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info)

[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters)

[OID_RECEIVE_FILTER_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-hardware-capabilities)