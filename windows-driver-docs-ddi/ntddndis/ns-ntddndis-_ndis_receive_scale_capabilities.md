# _NDIS_RECEIVE_SCALE_CAPABILITIES structure

## Description

The **NDIS_RECEIVE_SCALE_CAPABILITIES** structure specifies the [receive side scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2) capabilities of a miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RECEIVE_SCALE_CAPABILITIES** structure. Set the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_RSS_CAPABILITIES**.

For NDIS 6.60 and later, set the
**Revision** member to **NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_3** and the
**Size** member to **NDIS_SIZEOF_RECEIVE_SCALE_CAPABILITIES_REVISION_3**.

For NDIS 6.30 and later, set the
**Revision** member to **NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_2** and the
**Size** member to **NDIS_SIZEOF_RECEIVE_SCALE_CAPABILITIES_REVISION_2**.

For NDIS 6.0, 6.1, and 6.20, set the
**Revision** member to **NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_1** and the
**Size** member to **NDIS_SIZEOF_RECEIVE_SCALE_CAPABILITIES_REVISION_1**.

### `CapabilitiesFlags`

A bitmask of flags that specify the RSS capabilities of the NIC. The
miniport driver can specify the following flags:

| Value | Meaning |
| --- | --- |
| **NDIS_RSS_CAPS_MESSAGE_SIGNALED_INTERRUPTS** | Set this flag if the NIC supports message-signaled interrupts (MSIs). This flag indicates that the NIC can generate a separate interrupt for each CPU after it queues the packets that are assigned to that CPU. |
| **NDIS_RSS_CAPS_CLASSIFICATION_AT_ISR** | Set this flag if the NIC can indicate to the [MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function which target CPUs have queued received packets. |
| **NDIS_RSS_CAPS_USING_MSI_X** | Set this flag if the NIC is using message signaled interrupts (MSIs). This flag is supported in NDIS 6.20 and later. |
| **NDIS_RSS_CAPS_RSS_AVAILABLE_ON_PORTS** | Set this flag if the NIC supports independent RSS configuration of ports. This flag is supported in NDIS 6.30 and later. |
| **NDIS_RSS_CAPS_SUPPORTS_MSI_X** | Set this flag if the NIC supports MSIs. This flag is supported in NDIS 6.30 and later. |
| **NDIS_RSS_CAPS_CLASSIFICATION_AT_DPC** | Set this flag if the miniport driver can detect which target CPUs have queued receive packets from its [MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function. |
| **NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV4** | Set this flag if the NIC can identify an IPv4 packet (with or without options). Also, the NIC supports calculation of the hash value over the IPv4 header fields and TCP header fields. |
| **NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV6** | Set this flag if the NIC can identify an IPv6 packet and compute a hash value over fields in an IPv6 packet. The NIC must be able to compute a hash value over fields in the basic IPv6 header and over fields in the TCP header. Use this flag if the NIC cannot compute a hash value over fields that are located in IPv6 extension headers. |
| **NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV6_EX** | Set this flag if the NIC can identify an IPv6 packet and compute a hash value over fields in an IPv6 packet that contains IPv6 extension headers. The NIC can compute a hash value over fields in the basic IPv6 header, IPv6 extension headers, and TCP header. The NIC must be able to compute hash values over fields in the home address option and the type-2 routing header in the IPv6 extension headers. |
| **NDIS_RSS_CAPS_HASH_TYPE_UDP_IPV4** | Set this flag if the NIC can identify an IPv4 packet, with or without options, and if the NIC supports calculation of the hash value over the IPv4 header fields and UDP header fields. |
| **NDIS_RSS_CAPS_HASH_TYPE_UDP_IPV6** | Set this flag if the NIC can identify an IPv6 packet and compute a hash value over fields in an IPv6 packet. The NIC must be able to compute a hash value over fields in the basic IPv6 header and over fields in the UDP header. Use this flag if the NIC cannot compute a hash value over fields that are located in IPv6 extension headers. |
| **NDIS_RSS_CAPS_HASH_TYPE_UDP_IPV6_EX** | Set this flag if the NIC can identify an IPv6 packet and compute a hash value over fields in an IPv6 packet that contains IPv6 extension headers. The NIC can compute a hash value over fields in the basic IPv6 header, IPv6 extension headers, and the UDP header. The NIC must be able to compute hash values over fields in the home address option and the type-2 routing header in the IPv6 extension headers. |
| **NdisHashFunctionToeplitz** | Set this flag if the NIC supports the toeplitz hash function. If the NIC supports RSS, support for the hash function is mandatory. For more information about hash functions, see [NDIS_RSS_HASH_FUNC_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func). |
| **NdisHashFunctionReserved1** | This flag is reserved for future use. |
| **NdisHashFunctionReserved2** | This flag is reserved for future use. |
| **NdisHashFunctionReserved3** | This flag is reserved for future use. |

### `NumberOfInterruptMessages`

The number of interrupt messages that the NIC supports if the NIC supports MSIs. If the NIC does
not support MSIs but supports line-based interrupts, set this number to 1.

### `NumberOfReceiveQueues`

The number of hardware receive queues that the NIC supports.

### `NumberOfIndirectionTableEntries`

The maximum number of entries that the miniport driver supports in the indirection table. This value must be a power of 2. All NDIS 6.30 and later miniport adapters must support this member, which is required for virtual functions.

## Remarks

Overlying drivers can use the
[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities) OID to query the receive side scaling (RSS) capabilities of a
NIC and its miniport driver.

The miniport driver returns the RSS capabilities in an **NDIS_RECEIVE_SCALE_CAPABILITIES** structure.

For some workloads, a subset of UDP packets could be fragmented due to route changes or the sender not adhering to MTU limitations. In such rare cases, packets of the same flow could be indicated on different processors based on the 4-tuple or 2-tuple hash. Therefore, miniport drivers that advertise **NDIS_RSS_CAPS_HASH_TYPE_UDP_IPV4**, **NDIS_RSS_CAPS_HASH_TYPE_UDP_IPV6**, and **NDIS_RSS_CAPS_HASH_TYPE_UDP_IPV6_EX** should provide a way to disable UDP RSS capabilities via Advanced Properties.

## See also

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RSS_HASH_FUNC_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities)

[Receive Side Scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2)