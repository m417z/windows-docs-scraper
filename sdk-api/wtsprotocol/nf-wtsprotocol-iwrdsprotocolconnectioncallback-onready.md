# IWRdsProtocolConnectionCallback::OnReady

## Description

Requests that the Remote Desktop Services service continue the connection process for that client.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The protocol must call this method after the Remote Desktop Services service calls [GetLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getlogonerrorredirector). The Remote Desktop Services service will not call [AcceptConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-acceptconnection) to continue the connection process until **OnReady** has been called.

## See also

[IWRdsProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnectioncallback)