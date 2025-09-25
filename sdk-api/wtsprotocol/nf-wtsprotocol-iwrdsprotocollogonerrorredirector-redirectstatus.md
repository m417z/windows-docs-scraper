# IWRdsProtocolLogonErrorRedirector::RedirectStatus

## Description

Queries the protocol regarding how to redirect the client logon status update.

## Parameters

### `pszMessage` [in]

A pointer to a string that contains the logon status message.

### `pResponse` [out]

A pointer to a [WRDS_LOGON_ERROR_REDIRECTOR_RESPONSE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wts_logon_error_redirector_response) enumeration that contains the response.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollogonerrorredirector)