# _WWAN_NETWORK_BLACKLIST_TYPE enumeration

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **WWAN_NETWORK_BLACKLIST_TYPE** enumeration specifies which of a mobile broadband (MBB) modem's two network blacklists is used for an MCC/MNC pair.

## Constants

### `WwanNetworkBlacklistTypeSIM`

The MCC/MNC pair is used for the SIM provider blacklist.

### `WwanNetworkBlacklistTypeNetwork`

The MCC/MNC pair is used for the network provider blacklist.

### `WwanNetworkBlacklistTypeMaximum`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_NETWORK_BLACKLIST_PROVIDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_provider) structure.

## See also

[MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations)

[**WWAN_NETWORK_BLACKLIST_PROVIDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_provider)