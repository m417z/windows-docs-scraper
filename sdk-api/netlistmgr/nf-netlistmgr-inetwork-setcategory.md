# INetwork::SetCategory

## Description

The **SetCategory** method sets the category of a network. Changes made take effect immediately. Callers of this API must be members of the Administrators group.

## Parameters

### `NewCategory` [in]

Pointer to a [NLM_NETWORK_CATEGORY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_network_category) enumeration value that specifies the new category of the network.

## Return value

Returns S_OK if the method succeeds.

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)