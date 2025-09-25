# WlanSetProfilePosition function

## Description

The **WlanSetProfilePosition** function sets the position of a single, specified profile in the preference list.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `strProfileName` [in]

The name of the profile. Profile names are case-sensitive. This string must be NULL-terminated.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The supplied name must match the profile name derived automatically from the SSID of the network. For an infrastructure network profile, the SSID must be supplied for the profile name. For an ad hoc network profile, the supplied name must be the SSID of the ad hoc network followed by `-adhoc`.

### `dwPosition` [in]

Indicates the position in the preference list that the profile should be shifted to. 0 (zero) corresponds to the first profile in the list that is returned by the [WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist) function.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to change the profile position. <br><br>Before [WlanSetProfilePosition](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileposition) performs an operation that changes the relative order of all-user profiles in the profile list or moves an all-user profile to a lower position in the profile list, **WlanSetProfilePosition** retrieves the discretionary access control list (DACL) stored with the **wlan_secure_all_user_profiles_order** object. If the DACL does not contain an access control entry (ACE) that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread, then **WlanSetProfilePosition** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *pInterfaceGuid* is **NULL**, *strProfileName* is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The position of group policy profiles cannot be changed.

By default, only a user logged on as a member of the Administrators group can change the position of an all-user profile. Call [WlanGetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetsecuritysettings) to determine the actual user rights required to change the position of an all-user profile.

To set the profile position at the command line, use the **netsh wlan set profileorder** command. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Ad hoc profiles appear after the infrastructure profiles in the profile list. If you try to position an ad hoc profile before an infrastructure profile using **WlanSetProfilePosition**, the **WlanSetProfilePosition** call will succeed but the Wireless Zero Configuration service will reorder the profile list such that the ad hoc profile is positioned after all infrastructure network profiles.

Guest profiles, profiles with Wireless Provisioning Service (WPS) authentication, and profiles with Wi-Fi Protected Access-None (WPA-None) authentication are not supported. Any such profile that appears in the preferred profile list has a fixed position in the profile list. That means its position cannot be changed using **WlanSetProfilePosition** and that its position is not affected by position changes of other profiles.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanSetProfilePosition** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter has been removed from the system (a USB wireless adapter that has been removed, for example).

## See also

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilelist)