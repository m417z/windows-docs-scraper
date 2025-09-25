# IWRdsProtocolConnection::IsUserAllowedToLogon

## Description

Determines from the protocol whether a user is allowed to log on to a session.

## Parameters

### `SessionId` [in]

The session identifier.

### `UserToken` [in]

A handle that represents the user token.

### `pDomainName` [in]

A pointer to a null-terminated string that contains the user's domain name.

### `pUserName` [in]

A pointer to a null-terminated string that contains the user name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)