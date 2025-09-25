# IUPnPServiceCallback::ServiceInstanceDied

## Description

The
**ServiceInstanceDied** method is invoked when a service is no longer sending events.

## Parameters

### `pus` [in]

Reference to an
[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice) object that specifies the service about which the UPnP framework is sending the notification.

## Return value

The application should return S_OK.

## Remarks

The UPnP framework invokes this method either when a service has notified the UPnP framework that it is no longer sending events or when the UPnP framework has failed to maintain its connection to a service.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)

[IUPnPService::AddCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-addcallback)

[IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback)