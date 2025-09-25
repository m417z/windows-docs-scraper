# IWTSProtocolLogonErrorRedirector::OnBeginPainting

## Description

[**IWTSProtocolLogonErrorRedirector::OnBeginPainting** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolLogonErrorRedirector::OnBeginPainting](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollogonerrorredirector-onbeginpainting).]

Notifies the protocol that the logon user interface is ready to begin painting.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollogonerrorredirector)