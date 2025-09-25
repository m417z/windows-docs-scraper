# INetworkListManager::GetNetworkConnection

## Description

The **GetNetworkConnection** method retrieves a network based on a supplied Network Connection ID.

## Parameters

### `gdNetworkConnectionId` [in]

A **GUID** that specifies the Network Connection ID.

### `ppNetworkConnection` [out, retval]

Pointer to a pointer to the [INetworkConnection](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnection) object associated with the supplied *gdNetworkConnectionId*.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The network associated with the specified network connection ID was not found. |
| **E_POINTER** | The pointer passed is **NULL**. |
| **E_UNEXPECTED** | The specified GUID is invalid. |

## Remarks

This method can return **S_FALSE** if a network connection associated with the specified ID has been removed.
For example, it is possible for a client to receive a [INetworkConnectionEvents::NetworkConnectionConnectivityChanged](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworkconnectionevents-networkconnectionconnectivitychanged) event along with a network connection ID, but find that the network connection has been disconnected or even replaced by the time **INetworkListManager::GetNetworkConnection** is called with the provided ID.

## See also

[INetworkConnection](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnection)

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)