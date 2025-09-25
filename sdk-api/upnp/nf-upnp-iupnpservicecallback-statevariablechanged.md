# IUPnPServiceCallback::StateVariableChanged

## Description

The
**StateVariableChanged** method is invoked when a state variable has changed.

## Parameters

### `pus` [in]

Reference to an
[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice) object that specifies the service about which the UPnP framework is sending the notification.

### `pcwszStateVarName` [in]

Reference to a string that specifies the name of the state variable that has changed.

### `vaValue` [in]

Specifies the new value. The type of the data returned depends on the data type of the state variable for which the notification is sent.

## Return value

The application should return S_OK.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)

[IUPnPService::AddCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservice-addcallback)

[IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback)