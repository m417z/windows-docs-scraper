# IWTSProtocolConnection::AcceptConnection

## Description

[**IWTSProtocolConnection::AcceptConnection** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::AcceptConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-acceptconnection).]

Directs the protocol to continue with the connection request.

## Remarks

During a connection sequence, the Remote Desktop Services service calls this method after it receives a connection request from a client and after it calls the [SendPolicyData](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-sendpolicydata) method.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)