# _WWAN_NETWORK_BLACKLIST_PROVIDER structure

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **WWAN_NETWORK_BLACKLIST_PROVIDER** structure represents a network blacklist provider in a mobile broadband (MBB) modem.

## Members

### `MCC`

As specified by 3GPP, MCC is part of IMSI and specifies the country of the provider.

### `MNC`

As specified by 3GPP, MNC is part of IMSI and specifies the network of the provider.

### `NetworkBlacklistType`

A [**WWAN_NETWORK_BLACKLIST_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_network_blacklist_type) value that specifies for which type of blacklist the MCC/MNC pair is used.

## Remarks

A list of **WWAN_NETWORK_BLACKLIST_PROVIDER** structures follows the **BlacklistProviderList** member of the [**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info) structure.

## See also

[MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations)

[**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info)

[**WWAN_NETWORK_BLACKLIST_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_network_blacklist_type)