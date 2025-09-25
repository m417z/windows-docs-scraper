# _NDIS_OFFLOAD structure

## Description

The **NDIS_OFFLOAD** structure specifies several computational [tasks that can be offloaded to the network adapter](https://learn.microsoft.com/windows-hardware/drivers/network/task-offload).

## Members

### `Header`

The [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_OFFLOAD** structure. Set the **Type** member of the structure that **Header** specifies to NDIS_OBJECT_TYPE_OFFLOAD.

Set the **Revision** and **Size** members of the [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure as follows:

- For NDIS 6.83 and later drivers:
  - Set **Revision** to NDIS_OFFLOAD_REVISION_6 (NDIS 6.83).
  - Set **Size** to NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_6.
- For NDIS 6.70 and later drivers:
  - Set **Revision** to NDIS_OFFLOAD_REVISION_5 (NDIS 6.70).
  - Set **Size** to NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_5.
- For NDIS 6.50 and later drivers:
  - Set **Revision** to NDIS_OFFLOAD_REVISION_4 (NDIS 6.50).
  - Set **Size** to NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_4.
- For NDIS 6.30 and later drivers:
  - Set **Revision** to NDIS_OFFLOAD_REVISION_3 (NDIS 6.30).
  - Set **Size** to NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_3.
- For NDIS 6.1 and 6.20 drivers:
  - Set **Revision** to NDIS_OFFLOAD_REVISION_2 (NDIS 6.1).
  - Set **Size** to NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_2.
- For NDIS 6.0 drivers:
  - Set **Revision** to NDIS_OFFLOAD_REVISION_1 (NDIS 6.0).
  - Set **Size** to NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_1.

### `Checksum`

Checksum offload information in an [**NDIS_TCP_IP_CHECKSUM_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_ip_checksum_offload) structure.

### `LsoV1`

Large send offload version 1 (LSOV1) information in an [**NDIS_TCP_LARGE_SEND_OFFLOAD_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_large_send_offload_v1) structure.

### `IPsecV1`

Internet protocol security (IPsec) offload information in an [**NDIS_IPSEC_OFFLOAD_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v1) structure.

### `LsoV2`

Large send offload version 2 (LSOV2) offload information in an [**NDIS_TCP_LARGE_SEND_OFFLOAD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_large_send_offload_v2) structure.

### `Flags`

A bitwise OR of flags that specify properties that the network adapter supports. The following flags are defined.

| Value | Meaning |
|-------|---------|
| **IPSEC_OFFLOAD_V2_AND_TCP_CHECKSUM_COEXISTENCE** <br> 0x00000002 | The network adapter supports IPsecV2 and TCP checksums. |
| **IPSEC_OFFLOAD_V2_AND_UDP_CHECKSUM_COEXISTENCE** <br> 0x00000004 | The network adapter supports IPsecV2 and UDP checksums. |

### `IPsecV2`

Internet protocol security (IPsec) offload version 2 information in an [**NDIS_IPSEC_OFFLOAD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v2) structure.

### `Rsc`

[Receive Segment Coalescing (RSC)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-segment-coalescing--rsc-) offload information in an [**NDIS_TCP_RECV_SEG_COALESCE_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_recv_seg_coalesce_offload) structure.

### `EncapsulatedPacketTaskOffloadGre`

[Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload](https://learn.microsoft.com/windows-hardware/drivers/network/network-virtualization-using-generic-routing-encapsulation--nvgre--task-offload) information in an [NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_encapsulated_packet_task_offload) structure. This member should only be set by miniport drivers that support task offloads for NVGRE-formatted packets.

**Note**: This member is available only in NDIS 6.30 and later.

### `EncapsulatedPacketTaskOffloadVxlan`

VXLAN encapsulated packet task offload information in an [**NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_encapsulated_packet_task_offload_v2) structure. This member should only be set by miniport drivers that support task offloads for VXLAN-formatted packets. VXLAN is similar to NVGRE, but with a different protocol.

**Note**: This member is available only in NDIS 6.50 and later.

### `EncapsulationTypes`

The enabled encapsulation types for encapsulated packet task offload.

**Note**: This member is available only in NDIS 6.50 and later.

### `Rfc6877Xlat`

464XLAT hardware offload information in an [**NDIS_RFC6877_464XLAT_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rfc6877_464xlat_offload) structure.

**Note**: This member is available only in NDIS 6.70 and later.

### `UdpSegmentation`

UDP Segmentation Offload (USO) hardware offload information in an [**NDIS_UDP_SEGMENTATION_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_udp_segmentation_offload) structure.

**Note**: This member is available only in NDIS 6.83 and later.

### `UdpRsc`

UDP Receive Segment Coalescing Offload (URO) hardware offload information in an [**NDIS_UDP_RSC_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbluro/ns-nbluro-ndis_udp_rsc_offload) structure.

**Note**: This member is available only in NDIS 6.89 and later.

## Remarks

The **NDIS_OFFLOAD** structure is used in the following places:
- The **DefaultOffloadConfiguration** member of the [**NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes) structure
- The **DefaultOffloadConfiguration** member of the [**NDIS_BIND_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_bind_parameters) structure
- The **DefaultOffloadConfiguration** member of the [**NDIS_FILTER_ATTACH_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_filter_attach_parameters) structure
- The **InformationBuffer** member of the [**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/oidrequest/ns-oidrequest-ndis_oid_request) structure (which is used in the [OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config) OID request)
- The **StatusBuffer** member of the [NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config) status indication

## See also

[Determining the RSC Capabilities of a Network Adapter](https://learn.microsoft.com/windows-hardware/drivers/network/determining-the-rsc-capabilities-of-a-network-adapter)

[**NDIS_BIND_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_bind_parameters)

[**NDIS_FILTER_ATTACH_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_filter_attach_parameters)

[**NDIS_IPSEC_OFFLOAD_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v1)

[**NDIS_IPSEC_OFFLOAD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_ipsec_offload_v2)

[**NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/objectheader/ns-objectheader-ndis_object_header)

[**NDIS_OID_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/oidrequest/ns-oidrequest-ndis_oid_request)

[**NDIS_STATUS_INDICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndis/ns-ndis-_ndis_status_indication)

[**NDIS_STATUS_TASK_OFFLOAD_CURRENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-task-offload-current-config)

[**NDIS_TCP_IP_CHECKSUM_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_ip_checksum_offload)

[**NDIS_TCP_LARGE_SEND_OFFLOAD_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_large_send_offload_v1)

[**NDIS_TCP_LARGE_SEND_OFFLOAD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_tcp_large_send_offload_v2)

[Network Virtualization using Generic Routing Encapsulation (NVGRE) Task Offload](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddndis/ns-ntddndis-_ndis_encapsulated_packet_task_offload)

[OID_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-offload-encapsulation)

[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config)

[OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities)

[TCP/IP Task Offload](https://learn.microsoft.com/windows-hardware/drivers/network/task-offload)

[UDP Segmentation Offload (USO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-segmentation-offload-uso-)