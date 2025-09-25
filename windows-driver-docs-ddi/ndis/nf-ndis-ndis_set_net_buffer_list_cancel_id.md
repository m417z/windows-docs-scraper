# NDIS_SET_NET_BUFFER_LIST_CANCEL_ID macro

## Description

The **NDIS_SET_NET_BUFFER_LIST_CANCEL_ID** macro marks a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure with a cancellation identifier that a driver can later use to cancel the pending transmission of the associated data.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_CancelId`

A ULONG value that is a cancellation identifier for the **NET_BUFFER_LIST** structure.

## Remarks

An NDIS driver can call the **NDIS_SET_NET_BUFFER_LIST_CANCEL_ID** macro for each [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that it passes to lower-level drivers for transmission. The **NDIS_SET_NET_BUFFER_LIST_CANCEL_ID** macro marks the specified NET_BUFFER_LIST structure with a cancellation identifier. Drivers must call the [**NdisGeneratePartialCancelId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgeneratepartialcancelid) function to obtain a value that the driver must use as the high-order byte of a cancellation identifier.

To cancel send requests, filter drivers call the [**NdisFCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcancelsendnetbufferlists) function. Other drivers call the [**NdisCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists) function.

Drivers can call the [**NDIS_GET_NET_BUFFER_LIST_CANCEL_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_get_net_buffer_list_cancel_id) macro to retrieve a cancellation identifier from a **NET_BUFFER_LIST** structure.

## See also

[**NdisCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscancelsendnetbufferlists)

[**NdisFCancelSendNetBufferLists**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfcancelsendnetbufferlists)

[**NdisGeneratePartialCancelId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgeneratepartialcancelid)

[**NDIS_GET_NET_BUFFER_LIST_CANCEL_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndis_get_net_buffer_list_cancel_id)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)