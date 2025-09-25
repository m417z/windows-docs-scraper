# IWRdsProtocolConnection::LogonNotify

## Description

Called when the user has logged on to the session.

## Parameters

### `hClientToken` [in]

A handle that represents the user token.

### `wszUserName` [in]

A pointer to a null-terminated string that contains the user name.

### `wszDomainName` [in]

A pointer to a null-terminated string that contains the user's domain name.

### `SessionId` [in]

A pointer to a [WRDS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that uniquely identifies the session.

### `pWRdsConnectionSettings` [in, out]

A pointer to a [WRDS_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_connection_settings) structure that contains connection settings for the session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an event notification and you should return immediately from this method. To avoid a possible deadlock, you should not make any function or method calls that will directly or indirectly result in a Remote Desktop Services API being called. If you need to make any outbound call, you should start a new thread and make the outbound call from the new thread.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)