# INetworkListManager::GetNetwork

## Description

The **GetNetwork** method retrieves a network based on a supplied network ID.

## Parameters

### `gdNetworkId` [in]

GUID that specifies the network ID.

### `ppNetwork` [out]

Pointer to a pointer that receives the [INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork) interface instance for this network.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The pointer passed is **NULL**. |
| **E_UNEXPECTED** | The GUID is invalid. |

## See also

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)