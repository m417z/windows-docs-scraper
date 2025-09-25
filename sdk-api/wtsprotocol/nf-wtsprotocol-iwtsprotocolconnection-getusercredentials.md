# IWTSProtocolConnection::GetUserCredentials

## Description

[**IWTSProtocolConnection::GetUserCredentials** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::GetUserCredentials](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getusercredentials).]

Returns user credentials.

## Parameters

### `pUserCreds` [out]

A pointer to a [WTS_USER_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_user_credential) structure that contains the credentials. Currently, only the user name, password, and domain are supported. The user name and password are plaintext.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If your protocol returns an **HRESULT** error code, or the user provides incorrect credentials, WinLogon will display a logon screen to request credentials. If your protocol returns **S_OK**, the credentials will be passed to WinLogon to log on the user.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)