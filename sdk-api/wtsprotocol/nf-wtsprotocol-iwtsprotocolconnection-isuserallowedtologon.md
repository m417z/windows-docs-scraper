# IWTSProtocolConnection::IsUserAllowedToLogon

## Description

[**IWTSProtocolConnection::IsUserAllowedToLogon** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::IsUserAllowedToLogon](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-isuserallowedtologon).]

Determines whether a user is allowed to log on to a session.

## Parameters

### `SessionId` [in]

An integer that contains the session ID associated with the user.

### `UserToken` [in]

A pointer to the user token handle.

### `pDomainName` [in]

A pointer to a string that contains the domain name for the user.

### `pUserName` [in]

A pointer to a string that contains the user name.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)