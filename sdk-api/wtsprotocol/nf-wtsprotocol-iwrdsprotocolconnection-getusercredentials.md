# IWRdsProtocolConnection::GetUserCredentials

## Description

Returns user credentials.

## Parameters

### `pUserCreds` [out]

A pointer to a [WRDS_USER_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_user_credential) structure that contains the credentials. Currently, only the user name, password, and domain are supported. The user name and password are plaintext.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If your protocol returns an **HRESULT** error code, or the user provides incorrect credentials, WinLogon will display a logon screen to request credentials. If your protocol returns **S_OK**, the credentials will be passed to WinLogon to log on the user.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)