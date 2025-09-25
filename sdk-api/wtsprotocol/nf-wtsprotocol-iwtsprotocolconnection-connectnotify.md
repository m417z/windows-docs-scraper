# IWTSProtocolConnection::ConnectNotify

## Description

[**IWTSProtocolConnection::ConnectNotify** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::ConnectNotify](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-connectnotify).]

Signals that the session has been initialized.

## Parameters

### `SessionId` [in]

An integer that contains the session ID associated with the client.

## Remarks

This is an event notification and you should return immediately from this method. To avoid a possible deadlock, you should not make any function or method calls that will directly or indirectly result in a Remote Desktop Services API being called. If you need to make any outbound call, you should start a new thread and make the outbound call from the new thread.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)