# WlanSetProfileList function

## Description

The **WlanSetProfileList** function sets the preference order of profiles for a given interface.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `dwItems` [in]

The number of profiles in the *strProfileNames* parameter.

### `strProfileNames` [in]

The names of the profiles in the desired order. Profile names are case-sensitive. This string must be NULL-terminated.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The supplied names must match the profile names derived automatically from the SSID of the network. For infrastructure network profiles, the SSID must be supplied for the profile name. For ad hoc network profiles, the supplied name must be the SSID of the ad hoc network followed by `-adhoc`.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to change the profile list. <br><br>Before [WlanSetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilelist) performs an operation that changes the relative order of all-user profiles in the profile list or moves an all-user profile to a lower position in the profile list, **WlanSetProfileList** retrieves the discretionary access control list (DACL) stored with the **wlan_secure_all_user_profiles_order** object. If the DACL does not contain an access control entry (ACE) that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread, then **WlanSetProfileList** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *hClientHandle* is **NULL** or invalid.<br>* *pInterfaceGuid* is **NULL**.<br>* *dwItems* is 0.<br>* *strProfileNames* is **NULL**.<br>* The same profile name appears more than once in *strProfileNames*.<br>* *pReserved* is not **NULL**. |
| **ERROR_NOT_FOUND** | *strProfileNames* contains the name of a profile that is not present in the profile store. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanSetProfileList** function sets the preference order of wireless LAN profiles for a given wireless interface.

The profiles in the list must be a one-to-one match with the current profiles returned by the [WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist) function. The position of group policy profiles cannot be changed.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanSetProfileList** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter has been removed from the system (a USB wireless adapter that has been removed, for example).

## See also

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)