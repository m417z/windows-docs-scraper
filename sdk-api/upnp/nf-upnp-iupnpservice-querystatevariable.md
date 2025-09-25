# IUPnPService::QueryStateVariable

## Description

The
**QueryStateVariable** method returns the value of the specified service's state variable.

## Parameters

### `bstrVariableName` [in]

Specifies the state variable for which to return a value.

### `pValue` [out]

Receives a reference to the value of the variable specified by *bstrVariableName*. The type of the data returned depends on the state variable for which the query was invoked.

To free this parameter, use [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns either one of the COM error codes defined in WinError.h or one of the UPnP-specific return values listed in the following table. Some of these values indicate that an error was received from a UPnP-certified device. For more information, see [Device Error Codes](https://learn.microsoft.com/windows/desktop/UPnP/device-error-codes).

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_ERROR** | The variable is not evented and the remote query returned an error code. This is not a transport error; the device received the request, but it returned an error. |
| **UPNP_E_DEVICE_TIMEOUT** | The device has not responded within the 30 second time-out period. |
| **UPNP_E_INVALID_VARIABLE** | The variable does not exist. |
| **UPNP_E_PROTOCOL_ERROR** | The query did not complete because of problems at the UPnP protocol level. |
| **UPNP_E_TRANSPORT_ERROR** | The variable is not evented and the remote query for the value failed because of an HTTP problem. To retrieve the HTTP error code, use [IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus). |
| **UPNP_E_VARIABLE_VALUE_UNKNOWN** | The variable is evented, but the UPnP software cannot return a value because it is still waiting for an event notification. |

## Remarks

The UPnP Forum discourages use of this method. If possible, use a service-specific action, if one has been provided.

This method retrieves the values of evented variables from the service object's local cache. The cache contains the value for each variable indicated in the last event notification. This method retrieves the values of non-evented variables by sending a remote query to the device.

If an application invokes this method for an evented state variable, between the time a service first initializes itself and the time it processes its first event, **UPNP_E_VARIABLE_VALUE_UNKNOWN** is returned.

If an application invokes this method for a service that does not use events, and the HTTP request fails, **UPNP_E_TRANSPORT_ERROR** is returned. To view the status, use
[IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus).

**Note** The time.tz variable can contain incorrect timezone information on the control point. For example, you can have a device and a control point running in the same timezone, -7.00. When the control point queries a time.tz variable for the current time, the device returns a datestructure with the timezone value set to -8.00 instead of -7.00.

To work around this issue, use the dataTime.tz variable type instead time.tz on the control point.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)

[IUPnPService::LastTransportStatus](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-get_lasttransportstatus)