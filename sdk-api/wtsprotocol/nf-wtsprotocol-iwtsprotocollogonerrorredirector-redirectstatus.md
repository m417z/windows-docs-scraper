# IWTSProtocolLogonErrorRedirector::RedirectStatus

## Description

[**IWTSProtocolLogonErrorRedirector::RedirectStatus** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolLogonErrorRedirector::RedirectStatus](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollogonerrorredirector-redirectstatus).]

Queries the protocol regarding how to redirect the client logon status update.

## Parameters

### `pszMessage` [in]

A pointer to a string that contains the logon status message.

### `pResponse` [out]

A pointer to a [WTS_LOGON_ERROR_REDIRECTOR_RESPONSE](https://learn.microsoft.com/windows/win32/api/wtsdefs/ne-wtsdefs-wts_logon_error_redirector_response) enumeration that contains the response. This can be one of the following values.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollogonerrorredirector)