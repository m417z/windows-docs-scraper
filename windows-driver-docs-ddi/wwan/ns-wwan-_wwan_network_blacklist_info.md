# _WWAN_NETWORK_BLACKLIST_INFO structure

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **WWAN_NETWORK_BLACKLIST_INFO** structure contains a list of network blacklist providers for a mobile broadband (MBB) modem.

## Members

### `BlacklistState`

A [**WWAN_NETWORK_BLACKLIST_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_network_blacklist_state) value that indicates whether any of the blacklist conditions are met that result in the modem not registering with the network.

### `BlacklistProviderList`

A [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) structure that represents a list of network blacklists. The **ElementType** member in the **WWAN_LIST_HEADER** should be set to **WwanStructNetworkBlacklistProvider**. The **ElementCount** member in the **WWAN_LIST_HEADER** should be set to the number of [**WWAN_NETWORK_BLACKLIST_PROVIDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_provider) structures that follow the **WWAN_LIST_HEADER** structure.

## Remarks

This structure is used in the [**NDIS_WWAN_SET_NETWORK_BLACKLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_network_blacklist) structure and the [**NDIS_WWAN_NETWORK_BLACKLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_network_blacklist) structure.

## See also

[MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations)

[OID_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-blacklist)

[**NDIS_WWAN_SET_NETWORK_BLACKLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_network_blacklist)

[**NDIS_WWAN_NETWORK_BLACKLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_network_blacklist)

[**WWAN_NETWORK_BLACKLIST_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_network_blacklist_state)

[**WWAN_NETWORK_BLACKLIST_PROVIDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_provider)

[**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)