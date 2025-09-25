# INetworkConnectionCost::GetCost

## Description

The **GetCost** method retrieves the network cost associated with a connection.

## Parameters

### `pCost` [out]

A DWORD value that represents the network cost of the connection. The lowest 16 bits represent the cost level and the highest 16 bits represent the cost flags. Possible values are defined by the [NLM_CONNECTION_COST](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_cost) enumeration.

## Return value

Returns S_OK on success. Otherwise an HRESULT error code is returned. Possible values include:

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pCost* is NULL |
| **HRESULT_FROM_WIN32(ERROR_NO_NETWORK)** | Network connectivity is currently unavailable. |

## See also

[INetworkConnectionCost](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnectioncost)