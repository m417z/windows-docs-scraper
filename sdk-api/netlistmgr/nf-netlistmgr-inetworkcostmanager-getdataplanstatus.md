# INetworkCostManager::GetDataPlanStatus

## Description

The **GetDataPlanStatus** retrieves the data plan status for either a machine-wide internet connection , or the first-hop of routing to a specific destination on a connection. If an IPv4/IPv6 address is not specified, this method returns the data plan status of the connection used for machine-wide Internet connectivity.

## Parameters

### `pDataPlanStatus` [out]

Pointer to an [NLM_DATAPLAN_STATUS](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_dataplan_status) structure that describes the data plan status associated with a connection used to route to a destination. If *destIPAddr* specifies a tunnel address, the first available data plan status in the interface stack is returned.

### `pDestIPAddr` [in]

An [NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr) structure containing the destination IPv4/IPv6 or tunnel address. If NULL, this method returns the cost associated with the preferred connection used for machine Internet connectivity.

## Return value

Returns S_OK on success, otherwise an HRESULT error code is returned.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pDataPlanStatus* is NULL. |
| **E_PENDING** | Determining the interface used to route to the destination |
| **E_INVALIDARG** | The destination address specified by *destIPAddr* is invalid. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The request is not supported. This error is returned if either an IPv4 or IPv6 stack is not present on the local computer but either an IPv4 or IPv6 address was specified by *destIPAddr*. |
| **HRESULT_FROM_WIN32(ERROR_NO_NETWORK)** | Network connectivity is currently unavailable. |

## See also

[INetworkCostManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkcostmanager)

[NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr)