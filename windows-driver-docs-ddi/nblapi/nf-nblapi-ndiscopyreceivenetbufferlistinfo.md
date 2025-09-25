# NdisCopyReceiveNetBufferListInfo function

## Description

Intermediate drivers call the
**NdisCopyReceiveNetBufferListInfo** function to copy the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information in a received
**NET_BUFFER_LIST** structure.

## Parameters

### `DestNetBufferList` [in]

A pointer to the destination [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

### `SrcNetBufferList` [in]

A pointer to the source [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

When an intermediate driver or filter driver gets receive indications from an underlying driver, it
can, for example, clone the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure or allocate a new
structure to propagate the request to overlying drivers. The driver should use
**NdisCopyReceiveNetBufferListInfo** to copy the **NET_BUFFER_LIST** information, including private NDIS
information, to the new structure.

To copy the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information on the send path, use the
[NdisCopySendNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscopysendnetbufferlistinfo) function.

The following [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) items are copied in a call to **NdisCopyReceiveNetBufferListInfo**:

| Copied Item | Starting Windows Version |
| --- | --- |
| TcpIpChecksumNetBufferListInfo | Windows Vista |
| IPsecOffloadV1NetBufferListInfo | Windows Vista |
| TcpReceiveNoPush | Windows Vista |
| Ieee8021QNetBufferListInfo | Windows Vista |
| MediaSpecificInformation | Windows Vista |
| NetBufferListFrameType | Windows Vista |
| NetBufferListHashValue | Windows Vista |
| NetBufferListHashInfo | Windows Vista |
| IPsecOffloadV2TunnelNetBufferListInfo | Windows Vista with Service Pack 1 (SP1) |
| IPsecOffloadV2HeaderNetBufferListInfo | Windows Vista with SP1 |
| VirtualSubnetInfo | Windows 8 (AMD64 only) |
| NetBufferListFilteringInfo | Windows 8 |

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST Structure](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-structure)

[NdisCopySendNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscopysendnetbufferlistinfo)