# NET_BUFFER_LIST_DUP_ACK_COUNT macro

## Description

The **NET_BUFFER_LIST_DUP_ACK_COUNT** is a macro that NDIS drivers use to get and set the number of coalesced segments in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_DUP_ACK_COUNT** returns the **DupAckCount** member of the [**NDIS_RSC_NBL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblrsc/ns-nblrsc-ndis_rsc_nbl_info) union that is associated with the **TcpRecvSegCoalesceInfo** identifier. The information is retrieved from the **NetBufferListInfo** member of the indicated [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

This macro uses the [NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_info) macro to access the **TcpRecvSegCoalesceInfo** information.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NDIS_RSC_NBL_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblrsc/ns-nblrsc-ndis_rsc_nbl_info)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_info)