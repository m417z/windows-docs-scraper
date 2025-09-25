# NdisCopySendNetBufferListInfo function

## Description

Intermediate drivers call the
**NdisCopySendNetBufferListInfo** function to copy the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information in a transmit
**NET_BUFFER_LIST** structure.

## Parameters

### `DestNetBufferList` [in]

A pointer to the destination [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

### `SrcNetBufferList` [in]

A pointer to the source [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

When an intermediate driver or filter driver receives a transmit request from an overlying driver, it
can, for example, clone the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure or allocate a new
structure to propagate the request to underlying drivers. The driver should use
**NdisCopySendNetBufferListInfo** to copy the **NET_BUFFER_LIST** information, including private NDIS
information, to the new structure.

To copy the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) information on the receive path, use the
[NdisCopyReceiveNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscopyreceivenetbufferlistinfo) function.

The following [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) items are copied in a call to **NdisCopySendNetBufferListInfo**:

| Copied Item | Starting Windows Version |
| --- | --- |
| TcpIpChecksumNetBufferListInfo | Windows Vista |
| IPsecOffloadV1NetBufferListInfo | Windows Vista |
| TcpLargeSendNetBufferListInfo | Windows Vista |
| Ieee8021QNetBufferListInfo | Windows Vista |
| MediaSpecificInformation | Windows Vista |
| NetBufferListCancelId | Windows Vista |
| NetBufferListProtocolId | Windows Vista |
| IPsecOffloadV2TunnelNetBufferListInfo | Windows Vista with Service Pack 1 (SP1) |
| IPsecOffloadV2HeaderNetBufferListInfo | Windows Vista with SP1 |
| VirtualSubnetInfo | Windows 8 (AMD64 only) |
| NetBufferListFilteringInfo | Windows 8 |

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST Structure](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-structure)

[NdisCopyReceiveNetBufferListInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscopyreceivenetbufferlistinfo)