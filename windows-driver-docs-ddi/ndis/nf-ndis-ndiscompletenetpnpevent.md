# NdisCompleteNetPnPEvent function

## Description

Protocol drivers call the
**NdisCompleteNetPnPEvent** function to complete a response to a Plug and Play or Power Management event
for which the caller's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function returned
NDIS_STATUS_PENDING.

## Parameters

### `NdisBindingHandle` [in]

The handle that NDIS provided at the
*NdisBindingHandle* parameter of the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. The handle
identifies the binding between the caller and the underlying miniport adapter.

### `NetPnPEventNotification`

A pointer to a
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure that NDIS passed to the caller's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.

### `Status` [in]

The protocol driver's response to the pending Plug and Play or Power Management event
notification. To succeed such an event, specify NDIS_STATUS_SUCCESS. For information about other status
values, see the return values of the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.

## Remarks

When a protocol driver returns NDIS_STATUS_PENDING from its
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function, it
must eventually call
**NdisCompleteNetPnPEvent** to indicate its response to the given Plug and Play or Power Management
notification.

## See also

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)