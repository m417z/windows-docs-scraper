# IWRdsProtocolConnection::GetClientMonitorData

## Description

Retrieves the number of monitors and the primary monitor number on the client.

## Parameters

### `pNumMonitors` [out]

A pointer to a **UINT** variable to receive the number of monitors counted.

### `pPrimaryMonitor` [out]

A pointer to a **UINT** variable to receive the number of the primary monitor on the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)