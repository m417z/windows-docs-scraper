# WLAN_BSS_LIST structure

## Description

The **WLAN_BSS_LIST** structure contains a list of basic service set (BSS) entries.

## Members

### `dwTotalSize`

The total size of this structure, in bytes.

### `dwNumberOfItems`

The number of items in the **wlanBssEntries** member.

### `wlanBssEntries`

An array of [WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry) structures that contains information about a BSS.

## Remarks

The [WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist) function retrieves the BSS list of the wireless network or networks on a given interface and returns this information in a **WLAN_BSS_LIST** structure.

The **WLAN_BSS_LIST** structure may contain padding for alignment between the **dwTotalSize** member, the **dwNumberOfItems** member, and the first [WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry) array entry in the **wlanBssEntries** member. Padding for alignment may also be present between the **WLAN_BSS_ENTRY** array entries in the **wlanBssEntries** member. Any access to a **WLAN_BSS_ENTRY** array entry should assume padding may exist.

When the wireless LAN interface is also operating as a Wireless Hosted Network , the BSS list will contain an entry for the BSS created for the Wireless Hosted Network.

Since the information is returned by the access point for an infrastructure BSS network or by the network peer for an independent BSS network (ad hoc network), the information returned should not be trusted. The **ulIeOffset** and **ulIeSize** members in the [WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry) structure should be used to determine the maximum size of the information element data blob in the **WLAN_BSS_ENTRY** structure, not the data in the information element data blob.

## See also

[WLAN_AVAILABLE_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network)

[WLAN_AVAILABLE_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network_list)

[WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry)

[WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist)

[WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist)