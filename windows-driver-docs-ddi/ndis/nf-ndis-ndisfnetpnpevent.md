# NdisFNetPnPEvent function

## Description

A filter driver can call the
**NdisFNetPnPEvent** function to forward a network Plug and Play (PnP) or Power Management event to
overlying drivers.

## Parameters

### `NdisFilterHandle`

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetPnPEventNotification`

A pointer to a
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure, which describes the network PnP event or Power Management
event being forwarded by the filter driver.

## Return value

**NdisFNetPnPEvent** can return either of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The overlying driver succeeded in processing the PnP event. |
| **NDIS_STATUS_FAILURE** | The overlying driver failed the PnP event. |

## Remarks

NDIS calls a filter driver's
[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event) function to notify
the filter driver of network PnP and Power Management events.

Filter drivers can forward these notifications to overlying drivers. To forward a request, call the
**NdisFNetPnPEvent** function from
*FilterNetPnPEvent*.

**Note** NDIS drivers must not call
**NdisFNetPnPEvent** from within the context of the
[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)