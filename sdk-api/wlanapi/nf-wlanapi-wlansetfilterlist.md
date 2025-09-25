# WlanSetFilterList function

## Description

The **WlanSetFilterList** function sets the permit/deny list.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `wlanFilterListType` [in]

A [WLAN_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_filter_list_type) value that specifies the type of filter list. The value must be either **wlan_filter_list_type_user_permit** or **wlan_filter_list_type_user_deny**. Group policy-defined lists cannot be set using this function.

### `pNetworkList` [in, optional]

Pointer to a [DOT11_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network_list) structure that contains the list of networks to permit or deny. The **dwIndex** member of the structure must have a value less than the value of the **dwNumberOfItems** member of the structure; otherwise, an access violation may occur.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to set the filter list. <br><br>When called with *wlanFilterListType* set to **wlan_filter_list_type_user_permit**, [WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist) retrieves the discretionary access control list (DACL) stored with the **wlan_secure_permit_list** object. When called with *wlanFilterListType* set to **wlan_filter_list_type_user_deny**, **WlanSetFilterList** retrieves the DACL stored with the **wlan_secure_deny_list** object. In either of these cases, if the DACL does not contain an access control entry (ACE) that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread, then **WlanSetFilterList** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The group policy permit and deny lists take precedence over the user's permit and deny lists. That means access to a network on the user's permit list will be denied if the network appears on the group policy deny list. Similarly, access to a network on the user's deny list will be permitted if the network appears on the group policy permit list. Networks that are not on a user list or a group policy list will be permitted.

Denied networks cannot be connected by means of auto config and will not be included on the visible networks list. New user permit and deny lists overwrite previous versions of the user lists.

To clear a filter list, set the *pNetworkList* parameter to **NULL**, or pass a pointer to a [DOT11_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network_list) structure that has the **dwNumberOfItems** member set to 0.

To add all SSIDs to a filter list, pass a pointer to a [DOT11_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network_list) structure with an associated [DOT11_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network) structure that has the **uSSIDLength** member of its [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure set to 0.

To add all BSS types to a filter list, pass a pointer to a [DOT11_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network_list) with an associated [DOT11_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network) structure that has its **dot11BssType** member set to **dot11_BSS_type_any**.

The **netsh wlan add filter** and **netsh wlan delete filter** commands provide similar functionality at the command line. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

## See also

[WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist)