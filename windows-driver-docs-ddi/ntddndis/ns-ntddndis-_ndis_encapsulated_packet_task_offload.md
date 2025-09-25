# _NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD structure

## Description

The **NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD** structure contains the offload support state for Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload (NVGRE-TO). This structure is used in the **EncapsulatedPacketTaskOffloadGre** member of the [NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure.

## Members

### `TransmitChecksumOffloadSupported`

Task offload settings for transmit checksum.

### `ReceiveChecksumOffloadSupported`

Task offload settings for receive checksum.

### `LsoV2Supported`

Task offload settings for large send offload version 2 (LSOv2).

### `RssSupported`

Task offload settings for receive side scaling (RSS).

### `VmqSupported`

Task offload settings for virtual machine queue (VMQ).

### `UsoSupported`

Task offload settings for UDP segmentation offload (USO).

### `Reserved`

Reserved for system use.

### `MaxHeaderSizeSupported`

This member should be set to the maximum header size from the beginning of the packet to the beginning of the inner TCP or UDP payload (the last byte of TCP or UDP inner header) that the NIC must support for all of these task offloads. The protocol driver is expected to not offload processing of a packet whose combined encapsulation headers exceed this size.

**Note**: 256 bytes is a good default value that should cover all possible cases.

## Remarks

In the initial capability advertisement and in [NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) and [NDIS_STATUS_TASK_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-hardware-capabilities) status indications, the **TransmitChecksumOffloadSupported**, **ReceiveChecksumOffloadSupported**, **LsoV2Supported**, **RssSupported**, **VmqSupported**, and **UsoSupported** members can be set to a bitwise OR of the following flags:

Term | Description
--- | ---
NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_NOT_SUPPORTED | Specifies that the miniport adapter does not support the corresponding task offload feature that the member specifies.
NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_INNER_IPV4 | Specifies that the miniport adapter supports the corresponding task offload feature that the member specifies where the inner IP header of an encapsulated packet is IPv4.
NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_OUTER_IPV4 | Specifies that the miniport adapter supports the corresponding task offload feature that the member specifies where the outer IP header of an encapsulated packet is IPv4.
NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_INNER_IPV6 | Specifies that the miniport adapter supports the corresponding task offload feature that the member specifies where the inner IP header of an encapsulated packet is IPv6.
NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_OUTER_IPV6 | Specifies that the miniport adapter supports the corresponding task offload feature that the member specifies where the outer IP header of an encapsulated packet is IPv6.

As an example, if a miniport adapter and driver only support an IPv6 header as outer IP header but not as inner IP header, it will set **TransmitChecksumOffloadSupported**, **ReceiveChecksumOffloadSupported**, **LsoV2Supported**, **RssSupported**, **VmqSupported**, and **UsoSupported** to the value of the bitwise OR of NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_INNER_IPV4, NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_OUTER_IPV4 and NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_OUTER_IPV6.

Regarding IP options and TCP options, the following assumption was made for encapsulated packets:

- If the NIC specifies **IpOptions** and **TcpOptions** support in normal checksum offload and LSOv2 advertisement, it must support the option processing for encapsulated packets if [Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload](https://learn.microsoft.com/windows-hardware/drivers/network/network-virtualization-using-generic-routing-encapsulation--nvgre--task-offload) is supported. This means it will support both inner and outer IP options and TCP options inside the encapsulated packets. There is no separate capability advertisement for these specific to only NVGRE Task Offload.

It is possible for a protocol driver to offload "mixed mode" packets which means packets in which the inner and outer IP header versions are different. For example, a packet could have outer IP header as IPv6 and the inner IP header as IPv4.

## See also

- [NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

- [Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload](https://learn.microsoft.com/windows-hardware/drivers/network/network-virtualization-using-generic-routing-encapsulation--nvgre--task-offload)