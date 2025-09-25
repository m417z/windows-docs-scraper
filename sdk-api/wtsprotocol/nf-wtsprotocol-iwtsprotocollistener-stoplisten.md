# IWTSProtocolListener::StopListen

## Description

[**IWTSProtocolListener::StopListen** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolListener::StopListen](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollistener-stoplisten).]

Notifies the protocol to stop listening for client connection requests.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolListener](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollistener)