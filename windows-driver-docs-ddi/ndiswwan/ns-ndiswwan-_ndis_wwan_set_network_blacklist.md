# _NDIS_WWAN_SET_NETWORK_BLACKLIST structure

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **NDIS_WWAN_SET_NETWORK_BLACKLIST** structure describes a list of network blacklist providers that a mobile broadband (MBB) device should use to overwrite any existing blacklist providers in the modem.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_NETWORK_BLACKLIST** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_NETWORK_BLACKLIST_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_NETWORK_BLACKLIST) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetNetworkBlacklist`

A formatted [**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info) structure that contains the new list of network blacklist providers for the modem.

## Remarks

This structure is used in an [OID_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-blacklist) Set request.

After completing the Set request, the modem should return an [NDIS_STATUS_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-network-blacklist) status notification as a response to inform the OS of the updated network blacklists.

## See also

[MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations)

[OID_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-blacklist)

[NDIS_STATUS_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-network-blacklist)

[**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info)