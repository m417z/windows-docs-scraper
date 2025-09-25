## Description

The **PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK** type is a pointer to a function that you define in your application. The function is called whenever there's a change in the network aggregate connectivity level and cost hints.

Register your callback with a call to [NotifyNetworkConnectivityHintChange](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-notifynetworkconnectivityhintchange).

## Parameters

### `CallerContext` [in]

The user-specific caller context.

### `ConnectivityHint` [in]

A value of type [NL_NETWORK_CONNECTIVITY_HINT](https://learn.microsoft.com/windows/win32/api/nldef/ns-nldef-nl_network_connectivity_hint) representing the aggregate connectivity level and cost hints.

## Remarks

## See also

[NotifyNetworkConnectivityHintChange](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-notifynetworkconnectivityhintchange)