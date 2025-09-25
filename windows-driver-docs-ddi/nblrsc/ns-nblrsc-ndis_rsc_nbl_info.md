# _NDIS_RSC_NBL_INFO structure

## Description

The **NDIS_RSC_NBL_INFO** union specifies receive segment coalescing (RSC) counter information that is associated with a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Info`

A member in the union that is contained in **NDIS_RSC_NBL_INFO**. Drivers use **Info** to access RSC information. **Info** is a structure with the following members:

### `Info.CoalescedSegCount`

The number of coalesced segments in the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. For non-RSC packets this member must be set to zero.
Drivers can access this member with the [NET_BUFFER_LIST_COALESCED_SEG_COUNT](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-coalesced-seg-count)
macro.

**Note** The **RscTcpTimestampDelta** information and the **DupAckCount** member should be non-zero only if **CoalescedSegCount** is not zero.
See the remarks section for more information about **RscTcpTimestampDelta**.

### `Info.DupAckCount`

The number of duplicate ACKs that were encountered while forming the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. **DupAckCount** should be non-zero only if **CoalescedSegCount** is not zero.
Drivers can access this member with the [NET_BUFFER_LIST_DUP_ACK_COUNT](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-dup-ack-count)
macro.

### `Value`

A member in the union that is contained in **NDIS_RSC_NBL_INFO**. Drivers use **Value** to access the RSC information as a single **PVOID**.

## Remarks

To access receive segment coalescing (RSC) counter information that is associated with a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure, an NDIS driver calls the [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro and specifies the **TcpRecvSegCoalesceInfo** information type which is in an **NDIS_RSC_NBL_INFO** union.

To access RSC timestamp information that is associated with a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure, an NDIS driver calls the [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro and specifies the **RscTcpTimestampDelta** information type which is a single **ULONG** value.

**Note** The **RscTcpTimestampDelta** information and the **DupAckCount** member of **NDIS_RSC_NBL_INFO** should be nonzero only if **CoalescedSegCount** is not zero.

The **RscTcpTimestampDelta** information might be set for coalesced segments that are using the TCP timestamp option. **RscTcpTimestampDelta** information should contain the delta between the earliest and the latest TCP timestamp values in the sequence of coalesced segments. The miniport driver can provide a 16-bit value for **RscTcpTimestampDelta**.

The [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure of a single coalesced unit (SCU) is not different from the standard **NET_BUFFER_LIST** structure that is indicated on the receive path without RSC. The SCU resembles an IP jumbogram packet that came from the wire. Therefore, every indicated SCU must have one [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure for each **NET_BUFFER_LIST**.

The [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) can be an MDL chain and the MDL can have a total size that exceeds the normal maximum transmission unit (MTU) but must be limited by the maximum legal IP datagram length, see RFC791 section 3.1.

Also, the additional [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information can be provided for an SCU.
NDIS performs the **NET_BUFFER_LIST** and [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) validation. The host TCPIP stack performs packet checks including IP and TCP header validation.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_COALESCED_SEG_COUNT](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-coalesced-seg-count)

[NET_BUFFER_LIST_DUP_ACK_COUNT](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-dup-ack-count)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)