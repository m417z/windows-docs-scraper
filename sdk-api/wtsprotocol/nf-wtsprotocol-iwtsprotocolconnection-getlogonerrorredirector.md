# IWTSProtocolConnection::GetLogonErrorRedirector

## Description

[**IWTSProtocolConnection::GetLogonErrorRedirector** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::GetLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getlogonerrorredirector).]

Retrieves an [IWTSProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollogonerrorredirector) interface that specifies how the protocol should handle client logon errors. The protocol must add a reference to this object before returning, and the Remote Desktop Services service releases the reference when the connection is closed.

## Parameters

### `ppLogonErrorRedir` [out]

Address of a pointer to an [IWTSProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollogonerrorredirector) interface.

## Remarks

The [IWTSProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollogonerrorredirector) interface is implemented by the protocol to receive status and error messages from the Remote Desktop Services service.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)