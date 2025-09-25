# NdisFCancelSendNetBufferLists function

## Description

Filter drivers call the
**NdisFCancelSendNetBufferLists** function to cancel the transmission of network data.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `CancelId` [in]

The cancellation identifier. This identifier specifies the network data for the transmission that
is being canceled.

## Remarks

A filter driver can cancel the send requests that it originates or pass on the cancellation requests
from overlying drivers. To cancel a send request from an overlying driver, NDIS calls the filter drivers
[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists) function.

A filter driver can call the
[NDIS_SET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id) macro to mark NET_BUFFER_LIST structures that it originates and
passes down to lower-level drivers for transmission. The NDIS_SET_NET_BUFFER_LIST_CANCEL_ID macro marks
the specified packet with a cancellation identifier.

**NdisFCancelSendNetBufferLists** cancels the transmission of all data that is marked with the
specified cancellation identifier.

NDIS returns canceled send data that the filter driver originated to the
[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete) function. The completion status of canceled requests is
NDIS_STATUS_SEND_ABORTED.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterCancelSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_cancel_send_net_buffer_lists)

[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete)

[NDIS_SET_NET_BUFFER_LIST_CANCEL_ID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-set-net-buffer-list-cancel-id)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)