# IWTSProtocolConnection::NotifySessionId

## Description

[**IWTSProtocolConnection::NotifySessionId** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::NotifySessionId](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-notifysessionid).]

Sends the ID of the new session to the protocol.

## Parameters

### `SessionId` [in]

A pointer to a [WTS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that contains a connection GUID and the associated session ID.

## Remarks

This is an event notification and you should return immediately from this method. To avoid a possible deadlock, you should not make any function or method calls that will directly or indirectly result in a Remote Desktop Services API being called. If you need to make any outbound call, you should start a new thread and make the outbound call from the new thread.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)