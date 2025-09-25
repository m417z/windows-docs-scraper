# IUPnPServices::get_Item

## Description

The
**Item** property specifies the
[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice) interface for a service, identified by the service ID, in the collection.

## Parameters

### `bstrServiceId` [in]

Specifies a service in the collection.

### `ppService` [out]

Receives a reference to an
[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice) interface for the specified service.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h, or one of the following UPnP-specific return values.

| Return code | Description |
| --- | --- |
| **UPNP_E_DOCUMENT_INVALID** | The service description contained an error. |
| **UPNP_E_EVENT_SUBSCRIPTION_FAILED** | Failed to subscribe to the event source. |

## See also

[IUPnPServices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservices)