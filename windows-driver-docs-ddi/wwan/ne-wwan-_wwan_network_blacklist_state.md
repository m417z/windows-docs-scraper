# _WWAN_NETWORK_BLACKLIST_STATE enumeration

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **WWAN_NETWORK_BLACKLIST_STATE** enumeration describes possible states of a modem's two different blacklists, the SIM provider blacklist and the network provider blacklist.

## Constants

### `WwanNetworkBlacklistStateNotActuated`

Both blacklist conditions are not met.

### `WwanNetworkBlacklistSIMProviderActuated`

The inserted SIM is blacklisted because its provider ID matches the blacklist for SIM provider IDs.

### `WwanNetworkBlacklistNetworkProviderActuated`

Available networks are blacklisted because their provider IDs are all in the blacklist for network provider IDs.

### `WwanNetworkBlacklistStateMaximum`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info) structure.

## See also

[MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations)

[**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info)