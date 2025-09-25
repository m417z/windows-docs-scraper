# IWTSProtocolConnection::DisconnectNotify

## Description

[**IWTSProtocolConnection::DisconnectNotify** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::DisconnectNotify](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-disconnectnotify).]

Notifies the protocol that the session has been disconnected.

## Remarks

This is an event notification and you should return immediately from this method. To avoid a possible deadlock, you should not make any function or method calls that will directly or indirectly result in a Remote Desktop Services API being called. If you need to make any outbound call, you should start a new thread and make the outbound call from the new thread.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)