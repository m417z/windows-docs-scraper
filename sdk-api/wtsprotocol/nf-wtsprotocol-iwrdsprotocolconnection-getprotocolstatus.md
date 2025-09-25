# IWRdsProtocolConnection::GetProtocolStatus

## Description

Retrieves information about the protocol status.

## Parameters

### `pProtocolStatus` [out]

A pointer to a [WRDS_PROTOCOL_STATUS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_protocol_status) structure that receives counter, signal, and cache information for the protocol.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)