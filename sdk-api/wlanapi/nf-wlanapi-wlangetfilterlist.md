# WlanGetFilterList function

## Description

The **WlanGetFilterList** function retrieves a group policy or user permission list.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `wlanFilterListType` [in]

A [WLAN_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_filter_list_type) value that specifies the type of filter list. All user defined and group policy filter lists can be queried.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `ppNetworkList` [out]

Pointer to a [DOT11_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network_list) structure that contains the list of permitted or denied networks.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to get the filter list. <br><br>When called with *wlanFilterListType* set to **wlan_filter_list_type_user_permit**, [WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist) retrieves the discretionary access control list (DACL) stored with the **wlan_secure_permit_list** object. When called with *wlanFilterListType* set to **wlan_filter_list_type_user_deny**, **WlanGetFilterList** retrieves the DACL stored with the **wlan_secure_deny_list** object. In either of these cases, if the DACL does not contain an access control entry (ACE) that grants WLAN_READ_ACCESS permission to the access token of the calling thread, then **WlanGetFilterList** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *ppNetworkList* is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

User permission lists can be set by calling [WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist).

## See also

[DOT11_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network_list)

[WLAN_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_filter_list_type)

[WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist)