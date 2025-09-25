# NdisFDevicePnPEventNotify function

## Description

A filter driver can call the
**NdisFDevicePnPEventNotify** function to forward a device Plug and Play (PnP) or Power Management event
to underlying drivers.

## Parameters

### `NdisFilterHandle` [in]

The NDIS handle that identifies this filter module. NDIS passed the handle to the filter driver in
a call to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetDevicePnPEvent` [in]

A pointer to a
[NET_DEVICE_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_device_pnp_event) structure that
describes a device Plug and Play event.

## Remarks

NDIS calls a filter driver's
[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify) function to notify the filter driver of device PnP and Power Management
events that affect an underlying device object.

Filter drivers can forward these notifications to underlying drivers. To forward a request, call the
**NdisFDevicePnPEventNotify** function before returning from the
*FilterDevicePnPEventNotify* function.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify)

[NET_DEVICE_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_device_pnp_event)