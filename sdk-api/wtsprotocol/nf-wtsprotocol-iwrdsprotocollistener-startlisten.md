# IWRdsProtocolListener::StartListen

## Description

Notifies the protocol to start listening for client connection requests.

## Parameters

### `pCallback` [in]

A pointer to an [IWRdsProtocolListenerCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollistenercallback) object
implemented by the Remote Desktop Servicesservice. The protocol uses the
**IWRdsProtocolListenerCallback** object to notify
the

Remote Desktop Services
service about incoming connection requests. The protocol must add a reference to this object and release it when
[StopListen](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollistener-stoplisten) is called.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails,
return an **HRESULT** value that indicates the error. For a list of common error codes,
see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **StartListen** method is called when the Remote Desktop Services service starts.

1. The Remote Desktop Services service calls [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create an [IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager) object.
2. The Remote Desktop Services service calls [CreateListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-createlistener) on the [IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager) interface. The protocol creates an [IWRdsProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollistener) object and passes it back to the Remote Desktop Services service.
3. The Remote Desktop Services service calls **StartListen** on the [IWRdsProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollistener) object.

## See also

[IWRdsProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollistener)