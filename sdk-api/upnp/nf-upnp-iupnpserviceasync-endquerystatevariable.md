# IUPnPServiceAsync::EndQueryStateVariable

## Description

The **EndQueryStateVariable** method retrieves the results of a previous [BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable) operation and retrieves the resultant service-specific state variable value.

## Parameters

### `ullRequestID` [in]

Pointer to a 64-bit **ULONG** value that corresponds to the [BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable) operation initiated prior to this call.

### `pValue` [out, retval]

On input, contains an empty array. On output, receives a reference to the value of the variable specified in [BeginQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-beginquerystatevariable) by *bstrVariableName*. The type of the data returned depends on the state variable for which the query was invoked.

**Note** Clear this parameter with [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

## Return value

Returns **S_OK** on success. Otherwise, the method returns a COM error code defined in **WinError.h** or one of the following values:

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_ERROR** | The state variable is not evented and the remote query returned an error code. This is not a transport error; the device received the request, but it returned an error. |
| **UPNP_E_INVALID_VARIABLE** | The requested state variable does not exist. |
| **UPNP_E_DEVICE_TIMEOUT** | The device has not responded within the 30 second time-out period. |
| **UPNP_E_INVALID_ARGUMENTS** | One or more of the arguments passed with *vInActionArgs* is invalid. |
| **UPNP_E_PROTOCOL_ERROR** | The query did not complete because of problems at the UPnP protocol level. |
| **UPNP_E_TRANSPORT_ERROR** | The state variable is not evented and the remote query for the value failed because of an HTTP problem. To retrieve the HTTP error code, use [IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus). |
| **UPNP_E_VARIABLE_VALUE_UNKNOWN** | The state variable is evented, but the UPnP software cannot return a value because it is still waiting for an event notification. |

**Note** Some values can indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

## See also

[IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus)

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceAsync::EndQueryStateVariable](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpserviceasync-endquerystatevariable)