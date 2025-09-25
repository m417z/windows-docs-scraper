# IUPnPService::get_LastTransportStatus

## Description

For queries related to evented variables, the
**LastTransportStatus** property specifies the HTTP status of the last
[IUPnPService::InvokeAction](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-invokeaction) operation. For queries related to non-evented variables, the
**LastTransportStatus** property specifies the last
[IUPnPService::QueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-querystatevariable) operation, if the caller invoked a query for a non-evented variable.

## Parameters

### `plValue` [out]

Receives a reference to the status. If *plValue* is the HTTP status 200, the operation was successful.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)