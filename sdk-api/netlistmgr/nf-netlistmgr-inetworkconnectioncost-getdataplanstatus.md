# INetworkConnectionCost::GetDataPlanStatus

## Description

The **GetDataPlanStatus** method retrieves the status of the data plan associated with a connection.

## Parameters

### `pDataPlanStatus` [out]

Pointer to an [NLM_DATAPLAN_STATUS](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_dataplan_status) structure that describes the status of the data plan associated with the connection. The caller supplies the memory of this structure.

## Return value

Returns S_OK on success. Otherwise, an HRESULT error code is returned. Possible values include:

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pDataPlanStatus* is NULL. |
| **HRESULT_FROM_WIN32(ERROR_NO_NETWORK)** | Network connectivity is currently unavailable. |

## See also

[INetworkConnectionCost](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnectioncost)