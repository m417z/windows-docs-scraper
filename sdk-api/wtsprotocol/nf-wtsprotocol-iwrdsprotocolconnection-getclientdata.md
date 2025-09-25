# IWRdsProtocolConnection::GetClientData

## Description

Requests client settings from the protocol.

## Parameters

### `pClientData` [out]

A pointer to a [WRDS_CLIENT_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_client_data) structure that contains the client settings.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

Upon receiving an error, the Remote Desktop Services service will drop the connection.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)