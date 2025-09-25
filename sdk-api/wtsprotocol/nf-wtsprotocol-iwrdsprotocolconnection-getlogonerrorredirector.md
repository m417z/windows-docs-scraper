# IWRdsProtocolConnection::GetLogonErrorRedirector

## Description

Retrieves an [IWRdsProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollogonerrorredirector) interface that specifies how the protocol should handle client logon errors. The protocol must add a reference to this object before returning, and the Remote Desktop Services service releases the reference when the connection is closed.

## Parameters

### `ppLogonErrorRedir` [out]

Address of a pointer to an [IWRdsProtocolLogonErrorRedirector](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollogonerrorredirector) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

If you do not implement this function, return **E_NOTIMPL** to indicate that logon errors should not be redirected.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)