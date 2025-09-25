# INetwork::GetCategory

## Description

The **GetCategory** method returns the category of a network.

## Parameters

### `pCategory` [out]

Pointer to a [NLM_NETWORK_CATEGORY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_network_category) enumeration value that specifies the category information for the network.

## Return value

Returns S_OK if the method succeeds.

## Remarks

The private or public network categories must never be used to assume which Windows Firewall ports are open, as the user can change the default settings of these categories. Instead, Windows Firewall APIs should be called to ensure the ports that the required ports are open.

## See also

[INetwork](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetwork)

[NLM_NETWORK_CATEGORY](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_network_category)