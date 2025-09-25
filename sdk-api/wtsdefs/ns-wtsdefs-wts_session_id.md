# WTS_SESSION_ID structure

## Description

Contains a **GUID** that uniquely identifies a session.

## Members

### `SessionUniqueGuid`

A GUID that specifies the client connection.

### `SessionId`

An integer that specifies the session associated with the client connection.

## Remarks

This structure is used in the following methods:

* [AuthenticateClientToSession](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-authenticateclienttosession)
* [LogonNotify](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-logonnotify)
* [NotifySessionId](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-notifysessionid)

## See also

[AuthenticateClientToSession](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-authenticateclienttosession)

[LogonNotify](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-logonnotify)

[NotifySessionId](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-notifysessionid)

[Remote Desktop Protocol Provider Structures](https://learn.microsoft.com/windows/desktop/TermServ/custom-remote-protocol-structures)