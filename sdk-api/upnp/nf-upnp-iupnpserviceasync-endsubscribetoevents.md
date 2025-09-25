# IUPnPServiceAsync::EndSubscribeToEvents

## Description

The **EndSubscribeToEvents** method retrieves the results of a previous [BeginSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginsubscribetoevents) operation.

## Parameters

### `ullRequestID` [in]

A 64-bit **ULONG** value that corresponds to the [BeginSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginsubscribetoevents) operation requested prior to this call.

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_ERROR** | The device received the request, but returned an error. |
| **UPNP_E_DEVICE_TIMEOUT** | The device has not responded within the 30 second time-out period. |
| **UPNP_E_PROTOCOL_ERROR** | The query did not complete due to problems at the UPnP protocol level. |
| **UPNP_E_TRANSPORT_ERROR** | The remote operation failed due to an HTTP problem. To retrieve the HTTP error code, use [IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus). |

**Note** Some values can indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

## See also

[BeginSubscribeToEvents](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginsubscribetoevents)

[IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus)

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)