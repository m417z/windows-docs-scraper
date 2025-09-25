# IWRdsProtocolLogonErrorRedirector::RedirectMessage

## Description

Queries the protocol regarding how to redirect the logon message.

## Parameters

### `pszCaption` [in]

A pointer to a string that contains the message box caption.

### `pszMessage` [in]

A pointer to a string that contains the logon message.

### `uType` [in]

An integer that contains the message box type. For more information, see the [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) function.

### `pResponse` [out]

A pointer to a [WRDS_LOGON_ERROR_REDIRECTOR_RESPONSE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wts_logon_error_redirector_response) enumeration that specifies to the Remote Desktop Services service the preferred response for redirecting the logon message.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollogonerrorredirector)