# INetwork::GetNetworkId

## Description

The **GetNetworkId** method returns the unique identifier of a network.

## Parameters

### `pgdGuidNetworkId` [out]

Pointer to a GUID that specifies the network ID.

## Return value

Returns S_OK if the method succeeds.

## Remarks

The caller is responsible for allocating the buffer pointed to by *pgdGuidNetworkId*. This buffer must be large enough to hold a GUID.

Calling **GetNetworkId** will return S_OK even if the network requested has been deleted.

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)