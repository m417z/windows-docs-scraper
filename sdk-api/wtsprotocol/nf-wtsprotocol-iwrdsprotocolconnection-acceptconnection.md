# IWRdsProtocolConnection::AcceptConnection

## Description

Directs the protocol to continue with the connection request.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

Upon receiving an error, the Remote Desktop Services service will drop the connection.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)