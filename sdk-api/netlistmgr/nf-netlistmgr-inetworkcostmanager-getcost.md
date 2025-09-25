# INetworkCostManager::GetCost

## Description

The **GetCost** method retrieves the current cost of either a machine-wide internet connection, or the first-hop of routing to a specific destination on a connection. If *destIPaddr* is NULL, this method instead returns the cost of the network used for machine-wide Internet connectivity.

## Parameters

### `pCost` [out]

A DWORD value that indicates the cost of the connection. The lowest 16 bits represent the cost level, and the highest 16 bits represent the flags. Possible values are defined by the [NLM_CONNECTION_COST](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_cost) enumeration.

### `pDestIPAddr` [in]

An [NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr) structure containing the destination IPv4/IPv6 address. If NULL, this method will instead return the cost associated with the preferred connection used for machine Internet connectivity.

## Return value

Returns S_OK on success, otherwise an HRESULT error code is returned.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pCost* is NULL |
| **E_PENDING** | Currently determining the interface used to route to the destination |
| **E_INVALIDARG** | The destination IPv4/IPv6 address specified by *destIPAddr* is invalid. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The request is not supported. This error is returned if either an IPv4 or IPv6 stack is not present on the local computer but either an IPv4 or IPv6 address was specified by *destIPAddr*. |
| **HRESULT_FROM_WIN32(ERROR_NO_NETWORK)** | Network connectivity is currently unavailable. |

## See also

[INetworkCostManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkcostmanager)

[NLM_SOCKADDR](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_sockaddr)