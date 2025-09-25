# NDIS_GET_NET_BUFFER_LIST_CANCEL_ID macro

## Description

The **NDIS_GET_NET_BUFFER_LIST_CANCEL_ID** macro gets the cancellation identifier from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NDIS_GET_NET_BUFFER_LIST_CANCEL_ID** returns a ULONG value that is a cancellation identifier for the [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

To cancel send requests, filter drivers call the [**NdisFCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcancelsendnetbufferlists) function. Other NDIS drivers call the [**NdisCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists) function.

Drivers can call the [**NDIS_SET_NET_BUFFER_LIST_CANCEL_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_set_net_buffer_list_cancel_id) macro to set a cancellation identifier in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[**NdisCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists)

[**NdisFCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcancelsendnetbufferlists)

[**NDIS_SET_NET_BUFFER_LIST_CANCEL_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_set_net_buffer_list_cancel_id)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)