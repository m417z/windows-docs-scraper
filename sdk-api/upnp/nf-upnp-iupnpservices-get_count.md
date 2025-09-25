# IUPnPServices::get_Count

## Description

The
**Count** property specifies the number of services in the collection.

## Parameters

### `plCount` [out]

Receives a reference to the number of services in the collection.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h, or one of the following UPnP-specific return values.

| Return code | Description |
| --- | --- |
| **UPNP_E_DOCUMENT_INVALID** | The service description contained an error. |
| **UPNP_E_EVENT_SUBSCRIPTION_FAILED** | Failed to subscribe to the event source. |

## See also

[IUPnPServices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservices)