# _PD_BUFFER structure

## Description

This structure represents a PacketDirect (PD) packet, or a portion of a PD packet in a queue.

## Members

### `NextPDBuffer`

A pointer to the next **PD_BUFFER** structure in the queue.

### `NextPartialPDBuffer`

A pointer to the next partial **PD_BUFFER** structure in the queue.

### `PDClientReserved`

Reserved for system use. Do not use.

### `PDClientContext`

The client and the provider are not allowed to modify this field. If a client has allocated the **PD_BUFFER** with a non-zero value for ClientContextSize, then the PDClientContext refers to a buffer size of ClientContextSize. Otherwise, this field is NULL.

### `DataBufferVirtualAddress`

This field represents the address that hosts and software can use to access/modify the packet contents. The actual packet data is always at DataBufferVirtualAddress+DataStart. The provider and the platform never modify the value of this field after the **PD_BUFFER** initialization.

### `DataBufferDmaLogicalAddress`

This field represents the logical memory location used for storing the packet data. The provider
must use for DMA. The actual packet data is always at
DataBufferDmaLogicalAddress+DataStart. The provider and the
platform must never modify the value of this field after the **PD_BUFFER**
initialization.

### `DataBufferSize`

This is the total size of the allocated data buffer. The provider and the platform must never modify the value of this field
after the **PD_BUFFER** initialization. This data type is **ULONG** instead of
**USHORT** because of large send offload.

### `PDClientContextSize`

When this value is non-zero, it is the size of the buffer pointed to by PDClientContext.
The value of this field must only be modified by the platform. The platform does not change the value of this field after the **PD_BUFFER** allocation.

### `Attributes`

The attributes must never be modified by the provider. The table below lists attributes that this **PD_BUFFER** structure can have.

| Attribute | Description |
| --- | --- |
| PD_BUFFER_ATTR_BUILT_IN_DATA_BUFFER | A **PD_BUFFER** allocated with its own accompanying data buffer will have this attribute set. The **PD_BUFFER** attributes must never be modified by clients or providers. |

### `Flags`

The following table lists flags that this **PD_BUFFER** structure can have.

| Flag | Description |
| --- | --- |
| PD_BUFFER_FLAG_PARTIAL_PACKET_HEAD | Indicates that this buffer is the head of partial packets. |

### `DataStart`

This field denotes where the packet starts relative to the original starting address of the allocated data buffer. The provider must never modify this field. The provider adds this value to the
DataBufferDmaLogicalAddress value to derive the actual
target DMA address for packet reception/transmission. For example, the
target DMA address value in the hardware receive/transmit descriptor
must be set to DataBufferDmaLogicalAddress+DataStart when a **PD_BUFFER**
is posted to a receive/transmit queue.

### `DataLength`

The length of the packet or partial packet data.

### `MetaDataV0`

### `MetaDataV0.RxFilterContext`

The provider sets this to the filter context value obtained
from the matched filter that steered the packet to the receive
queue. Filter context values are specified by the clients
when configuring filters.

### `MetaDataV0.GftFlowEntryId`

If one of the RxGftExceptionPacket or RxGftCopyPacket or RxGftSamplePacket bits are set, the RxFilterContext value is
overwritten with a GFT flow entry Id value.

### `MetaDataV0.RxHashValue`

The hash value computed for the incoming packet
that is steered to the receive queue using RSS.

### `MetaDataV0.RxIPHeaderChecksumSucceeded`

A common RX offload field that indicates if the IP header checksum succeeded.

### `MetaDataV0.RxTCPChecksumSucceeded`

A common RX offload field that indicates if the TCP checksum succeeded.

### `MetaDataV0.RxUDPChecksumSucceeded`

A common RX offload field that indicates if the UDP checksum succeeded.

### `MetaDataV0.RxIPHeaderChecksumFailed`

A common RX offload field that indicates if the IP header checksum failed.

### `MetaDataV0.RxTCPChecksumFailed`

A common RX offload field that indicates if the TCP checksum failed.

### `MetaDataV0.RxUDPChecksumFailed`

A common RX offload field that indicates if the UDP checksum failed.

### `MetaDataV0.RxHashComputed`

A common RX offload field that indicates if the hash is computed.

### `MetaDataV0.RxHashWithL4PortNumbers`

A common RX offload field that indicates the hash is computed with L4 port numbers.

### `MetaDataV0.RxGftDirectionIngress`

### `MetaDataV0.RxGftExceptionPacket`

A common RX offload field that indicates this is a GFT exception packet.

### `MetaDataV0.RxGftCopyPacket`

A common RX offload field that indicates this is a GFT copy packet.

### `MetaDataV0.RxGftSamplePacket`

A common RX offload field that indicates this is a GFT sample packet.

### `MetaDataV0.RxReserved1`

Reserved.

### `MetaDataV0.RxCoalescedSegCount`

A common RX offload field that contains the amount of coalesced segments.

### `MetaDataV0.RxRscTcpTimestampDelta`

A common RX offload field that contains RSC and TCP timestamp difference.

### `MetaDataV0.RxOffloads`

RX offloads for this buffer.

### `MetaDataV0.TxIsIPv4`

A common TX offload field that indicates this packet is IPv4.

### `MetaDataV0.TxIsIPv6`

A common TX offload field that indicates this packet is IPv6.

### `MetaDataV0.TxTransportHeaderOffset`

A common TX offload field that contains the packet's header offset.

### `MetaDataV0.TxMSS`

A common TX offload field that contains the maximum segment size of this packet.

### `MetaDataV0.TxComputeIPHeaderChecksum`

A common TX offload field that indicates the IP header checksum is computed.

### `MetaDataV0.TxComputeTCPChecksum`

A common TX offload field that indicates the TCP checksum is computed.

### `MetaDataV0.TxComputeUDPChecksum`

A common TX offload field that indicates the UDP checksum is computed.

### `MetaDataV0.TxIsEncapsulatedPacket`

A common TX offload field that indicates the packet is encapsulated.

### `MetaDataV0.TxInnerPacketOffsetsValid`

A common TX offload field that indicates the inner packet offsets are valid.

### `MetaDataV0.TxReserved1`

Reserved.

### `MetaDataV0.TxInnerFrameOffset`

A common TX offload field that contains the inner frame offset.

### `MetaDataV0.TxInnerIpHeaderRelativeOffset`

A common TX offload field that contains the inner IP header relative offset.

### `MetaDataV0.TxInnerIsIPv6`

A common TX offload field that indicates the inner packet is IPv6.

### `MetaDataV0.TxInnerTcpOptionsPresent`

A common TX offload field that indicates the inner TCP options are present.

### `MetaDataV0.TxOffloads`

TX offloads for this buffer.

### `MetaDataV0.VirtualSubnetInfo`

The virtual subnet information.

### `MetaDataV0.Ieee8021qInfo`

The IEEE 802.1Q information.

### `MetaDataV0.GftSourceVPortId`

The GFT source virtual port ID.

### `MetaDataV0.Reserved`

Reserved for system use.

### `MetaDataV0.ProviderScratch`

A scratch field that the PD provider can use for its own purposes while the PD_BUFFER is sitting in the provider queue (in other words, posted by the client but not yet drained back by the client). Once the PD_BUFFER is drained by the client, there is no guarantee that the contents of this field will be preserved.

## Remarks

If an L2 packet is represented by multiple **PD_BUFFER** structures, the first **PD_BUFFER**
must have the PD_BUFFER_ATTR_BUILT_IN_DATA_BUFFER flag set and the
NextPartialPDBuffer field must point to the partial **PD_BUFFER** structures that
constitute the whole packet. Each of the partial **PD_BUFFER** structures must point to the next partial **PD_BUFFER** by using the NextPartialPDBuffer as opposed to the NextPDBuffer field. The NextPDBuffer field must be NULL in all partial **PD_BUFFER** structures except
for the head buffer. All partial PD_BUFFER structures except for the head buffer must
have the PD_BUFFER_ATTR_BUILT_IN_DATA_BUFFER flag cleared. The last partial
**PD_BUFFER** must have it's NextPartialPDBuffer field set to NULL. The total
length of the L2 packet is the sum of DataLength fields from each partial
**PD_BUFFER**. The head **PD_BUFFER** must contain up to and including the IP transport (TCP, UDP, SCTP, etc) header. In the case of encapsulation or double-encapsulation,
the inner-most IP transport header must be contained in the head **PD_BUFFER**.

When posting **PD_BUFFER** structures to receive queues, DataLength is ignored by
the provider (For more information see the ReceiveDataLength description in the [NDIS_PD_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue_parameters) structure).
When draining completed **PD_BUFFER** structures from receive queues,
the provider stores the length of the received packet in the DataLength field. The length does not include FCS or any stripped 801Q
headers.
When posting **PD_BUFFER** structures to transmit queues, DataLength denotes the length
of the packet to be sent. When draining completed **PD_BUFFER** structures from
transmit queues, the provider leaves the DataLength field unmodified.