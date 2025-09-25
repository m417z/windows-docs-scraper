# _NDIS_WWAN_NETWORK_BLACKLIST structure

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **NDIS_WWAN_NETWORK_BLACKLIST** structure describes a mobile broadband (MBB) device's list of network blacklist providers.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_NETWORK_BLACKLIST** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_NETWORK_BLACKLIST_REVISION_1 |
| Size | sizeof(NDIS_WWAN_NETWORK_BLACKLIST) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_BUSY | The operation failed because the device was busy. In the absence of any explicit information from the function to clear this condition, the host can use subsequent actions by the function (e.g. notifications or command completions) as a hint to retry the failed operation. |
| WWAN_STATUS_FAILURE | The operation failed. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |

### `NetworkBlacklistInfo`

A formatted [**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info) structure that contains a list of network blacklist providers for the modem.

## Remarks

This structure is used in the [NDIS_STATUS_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-network-blacklist) status notification in response to a previous [OID_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-blacklist) Query or Set request.

## See also

[MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations)

[OID_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-blacklist)

[NDIS_STATUS_WWAN_NETWORK_BLACKLIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-network-blacklist)

[**WWAN_NETWORK_BLACKLIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_info)