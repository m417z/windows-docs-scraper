# IWTSProtocolConnection::LogonNotify

## Description

[**IWTSProtocolConnection::LogonNotify** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::LogonNotify](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-logonnotify).]

Specifies that the user has logged on to the session.

## Parameters

### `hClientToken` [in]

A pointer to a user token handle.

### `wszUserName` [in]

A pointer to a string that contains the user name.

### `wszDomainName` [in]

A pointer to a string that contains the domain name for the user.

### `SessionId` [in]

A pointer to a [WTS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that contains the session ID associated with the user.

## Remarks

The Remote Desktop Services service also calls this method when the state of the session has changed.

This is an event notification and you should return immediately from this method. To avoid a possible deadlock, you should not make any function or method calls that will directly or indirectly result in a [Remote Desktop Services API](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-api-functions) being called. If you need to make any outbound call, you should start a new thread and make the outbound call from the new thread.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)