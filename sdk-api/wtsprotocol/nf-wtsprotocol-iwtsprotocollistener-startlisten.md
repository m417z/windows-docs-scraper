# IWTSProtocolListener::StartListen

## Description

[**IWTSProtocolListener::StartListen** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolListener::StartListen](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollistener-startlisten).]

 Notifies the protocol to start listening for client connection requests.

## Parameters

### `pCallback` [in]

A pointer to an [IWTSProtocolListenerCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistenercallback) object
implemented by the Remote Desktop Servicesservice. The protocol uses the
**IWTSProtocolListenerCallback** object to notify
the

Remote Desktop Services
service about incoming connection requests. The protocol must add a reference to this object and release it when
[StopListen](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocollistener-stoplisten) is called.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails,
return an **HRESULT** value that indicates the error. For a list of common error codes,
see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **StartListen** method is called when the Remote Desktop Services service starts.

1. The Remote Desktop Services service calls [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create an [IWTSProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolmanager) object.
2. The Remote Desktop Services service calls [CreateListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolmanager-createlistener) on the [IWTSProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolmanager) interface. The protocol creates an [IWTSProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistener) object and passes it back to the Remote Desktop Services service.
3. The Remote Desktop Services service calls **StartListen** on the [IWTSProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistener) object.

## See also

[IWTSProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistener)