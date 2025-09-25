# INetworkListManager::GetNetworks

## Description

The **GetNetworks** method retrieves the list of networks available on the local machine.

## Parameters

### `Flags` [in]

[NLM_ENUM_NETWORK](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_enum_network) enumeration value that specifies the flags for the network (specifically, connected or not connected).

### `ppEnumNetwork` [out]

Pointer to a pointer that receives an [IEnumNetworks](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-ienumnetworks) interface instance that contains the enumerator for the list of available networks.

## Return value

Returns S_OK if the method succeeds. Otherwise, the method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The pointer passed is **NULL**. |
| **E_UNEXPECTED** | The GUID is invalid. |

## See also

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)