# IWTSProtocolConnectionCallback::OnReady

## Description

[**IWTSProtocolConnectionCallback::OnReady** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnectionCallback::OnReady](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnectioncallback-onready).]

Requests that the Remote Desktop Services service continue the connection process for that client.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The protocol must call this method after the Remote Desktop Services service calls [SendPolicyData](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-sendpolicydata). The Remote Desktop Services service will not call [AcceptConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-acceptconnection) to continue the connection process until **OnReady** has been called.

## See also

[IWTSProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnectioncallback)