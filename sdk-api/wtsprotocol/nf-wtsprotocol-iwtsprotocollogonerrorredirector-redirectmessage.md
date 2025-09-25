# IWTSProtocolLogonErrorRedirector::RedirectMessage

## Description

[**IWTSProtocolLogonErrorRedirector::RedirectMessage** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolLogonErrorRedirector::RedirectMessage](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollogonerrorredirector-redirectmessage).]

Queries the protocol regarding how to redirect the logon message.

## Parameters

### `pszCaption` [in]

A pointer to a string that contains the message box caption.

### `pszMessage` [in]

A pointer to a string that contains the logon message.

### `uType` [in]

An integer that contains the message box type. For more information, see the **MessageBox** function.

### `pResponse` [out]

A pointer to a [WTS_LOGON_ERROR_REDIRECTOR_RESPONSE](https://learn.microsoft.com/windows/win32/api/wtsdefs/ne-wtsdefs-wts_logon_error_redirector_response) enumeration that specifies to the Remote Desktop Services service the preferred response for redirecting the logon message.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollogonerrorredirector)