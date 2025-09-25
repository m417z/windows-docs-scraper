# IWRdsProtocolConnection::PreDisconnect

## Description

Notifies the protocol that the session is about to be disconnected.

## Parameters

### `DisconnectReason` [in]

A numeric value that indicates the reason for the disconnection.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is an event notification and you should return immediately from this method. To avoid a possible deadlock, you should not make any function or method calls that will directly or indirectly result in a Remote Desktop Services API being called. If you need to make any outbound call, you should start a new thread and make the outbound call from the new thread.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)