# IWTSProtocolConnection::Close

## Description

[**IWTSProtocolConnection::Close** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::Close](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-close).]

Closes a connection after the session is disconnected.

## Remarks

 The protocol should perform whatever cleanup is necessary to close the connection and delete the [IWTSProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnectioncallback) object.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)