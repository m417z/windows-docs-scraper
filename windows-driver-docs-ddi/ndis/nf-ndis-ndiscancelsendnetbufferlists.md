# NdisCancelSendNetBufferLists function

## Description

Protocol drivers call the
**NdisCancelSendNetBufferLists** function to cancel the transmission of network data.

## Parameters

### `NdisBindingHandle` [in]

The handle returned by the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function that
identifies the miniport driver or virtual miniport to which the cancellation applies.

### `CancelId` [in]

The cancellation identifier. This identifier specifies the network data for which transmission is
being canceled.

## Remarks

A protocol driver maps IRPs that it receives from higher-level software to NDIS network data. A list
of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures describes the
network data that the protocol driver sends to lower-level drivers for transmission. If an IRP is
canceled, a protocol driver can call the
**NdisCancelSendNetBufferLists** function to cancel the pending transmission of the corresponding NDIS
network data.

Call the
[NDIS_SET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id) macro for each NET_BUFFER_LIST structure that is passed to
lower-level drivers for transmission. The NDIS_SET_NET_BUFFER_LIST_CANCEL_ID macro marks the specified
packet with a cancellation identifier.

**NdisCancelSendNetBufferLists** cancels the transmission of all data that is marked with the specified
cancellation identifier and is associated with the specified miniport driver. The binding handle that is
specified in the
*NdisBindingHandle* parameter identifies the miniport driver.

The
**NdisCancelSendNetBufferLists** function cancels network data transmissions on a single binding. To
cancel network data transmissions on more than one binding, a protocol driver must call the
**NdisCancelSendNetBufferLists** function once for each binding.

The protocol driver must ensure that the handle that the
*NdisBindingHandle* parameter specifies remains valid for the duration of the call to
**NdisCancelSendNetBufferLists**. That is, the protocol driver must not call the
[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex) function to close
the binding before
**NdisCancelSendNetBufferLists** returns.

There is no guarantee that calling
**NdisCancelSendNetBufferLists** will cancel the pending transmission of all network data with the
specified cancellation identifier. For example, if the next-lower driver to which the protocol driver is
bound does not provide a
[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send) function, a call
to
**NdisCancelSendNetBufferLists** does nothing.

In all cases, NDIS returns network data that was submitted for transmission to the originating
protocol driver's
[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete) function. NDIS returns canceled send data with a completion
status of NDIS_STATUS_SEND_ABORTED. The delay between calling
**NdisCancelSendNetBufferLists** and the return of the canceled NET_BUFFER_LIST structures can vary and
therefore cannot be exactly specified.

## See also

[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send)

[NDIS_SET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisCloseAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapterex)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_send_net_buffer_lists_complete)