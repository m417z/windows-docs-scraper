# WlanSetProfile function

## Description

The **WlanSetProfile** function sets the content of a specific profile.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `dwFlags` [in]

The flags to set on the profile.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** *dwFlags* must be 0. Per-user profiles are not supported.

| Value | Meaning |
| --- | --- |
| 0 | The profile is an all-user profile. |
| **WLAN_PROFILE_GROUP_POLICY**<br><br>0x00000001 | The profile is a group policy profile. |
| **WLAN_PROFILE_USER**<br><br>0x00000002 | The profile is a per-user profile. |

### `strProfileXml` [in]

Contains the XML representation of the profile. The [WLANProfile](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-profileschema-wlanprofile-element) element is the root profile element. To view sample profiles, see [Wireless Profile Samples](https://learn.microsoft.com/windows/desktop/NativeWiFi/wireless-profile-samples). There is no predefined maximum string length.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The supplied profile must meet the compatibility criteria described in [Wireless Profile Compatibility](https://learn.microsoft.com/windows/desktop/NativeWiFi/wireless-profile-compatibility).

### `strAllUserProfileSecurity` [in, optional]

Sets the security descriptor string on the all-user profile. For more information about profile permissions, see the Remarks section.

If *dwFlags* is set to WLAN_PROFILE_USER, this parameter is ignored.

If this parameter is set to **NULL** for a new all-user profile, the security descriptor associated with the wlan_secure_add_new_all_user_profiles object is used. If the security descriptor has not been modified by a [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings) call, all users have default permissions on a new all-user profile. Call [WlanGetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetsecuritysettings) to get the default permissions associated with the wlan_secure_add_new_all_user_profiles object.

If this parameter is set to **NULL** for an existing all-user profile, the permissions of the profile are not changed.

If this parameter is not **NULL** for an all-user profile, the security descriptor string associated with the profile is created or modified after the security descriptor object is created and parsed as a string.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** This parameter must be **NULL**.

### `bOverwrite` [in]

Specifies whether this profile is overwriting an existing profile. If this parameter is **FALSE** and the profile already exists, the existing profile will not be overwritten and an error will be returned.

### `pReserved` [in]

Reserved for future use. Must be set to **NULL**.

### `pdwReasonCode` [out]

A [WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code) value that indicates why the profile is not valid.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to set the profile. <br><br>When called with *dwFlags* set to 0 - that is, when setting an all-user profile - [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) retrieves the discretionary access control list (DACL) stored with the **wlan_secure_add_new_all_user_profiles** object. When called with *dwFlags* set to **WLAN_PROFILE_USER** - that is, when setting a per-user profile - **WlanSetProfile** retrieves the discretionary access control list (DACL) stored with the **wlan_secure_add_new_per_user_profiles** object. In either case, if the DACL does not contain an access control entry (ACE) that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread, then **WlanSetProfile** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_ALREADY_EXISTS** | *strProfileXml* specifies a network that already exists. Typically, this return value is used when *bOverwrite* is **FALSE**; however, if *bOverwrite* is **TRUE** and *dwFlags* specifies a different profile type than the one used by the existing profile, then the existing profile will not be overwritten and **ERROR_ALREADY_EXISTS** will be returned. |
| **ERROR_BAD_PROFILE** | The profile specified by *strProfileXml* is not valid. If this value is returned, *pdwReasonCode* specifies the reason the profile is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *hClientHandle* is **NULL** or invalid.<br>* *pInterfaceGuid* is **NULL**.<br>* *pReserved* is not **NULL**.<br>* *strProfileXml* is **NULL**. [ConfigBlob](https://learn.microsoft.com/windows/desktop/eaphost/eaphostconfigschema-configblob-eaphostconfig-element). If the profile must have an empty **ConfigBlob**, use `<ConfigBlob>00</ConfigBlob>` in the profile.* *pdwReasonCode* is **NULL**.<br>* *dwFlags* is not set to one of the specified values.<br>* *dwFlags* is set to WLAN_PROFILE_GROUP_POLICY and *bOverwrite* is set to **FALSE**. |
| **ERROR_NO_MATCH** | The interface does not support one or more of the capabilities specified in the profile. For example, if a profile specifies the use of WPA2 when the NIC only supports WPA, then this error code is returned. Also, if a profile specifies the use of FIPS mode when the NIC does not support FIPS mode, then this error code is returned. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanSetProfile** function can be used to add a new wireless LAN profile or replace an existing wireless LAN profile.

A new profile is added at the top of the list after the group policy profiles. A profile's position in the list is not changed if an existing profile is overwritten.**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:**

Ad hoc profiles appear after the infrastructure profiles in the profile list. If you create a new ad hoc profile, it is placed at the top of the ad hoc list, after the group policy and infrastructure profiles.

802.1X guest profiles, Wireless Provisioning Service (WPS) profiles, and profiles with Wi-Fi Protected Access-None (WPA-None) authentication are not supported. That means such a profile cannot be created, deleted, enumerated, or accessed using Native Wifi functions. Any such profile already in the preferred profile list will remain in the list, and its position in the list relative to other profiles is fixed unless the position of the other profiles change.

You can call **WlanSetProfile** on a profile that contains a plaintext key (that is, a profile with the [protected](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#protected) element present and set to **FALSE**). Before the profile is saved in the profile store, the key material is automatically encrypted. When the profile is subsequently retrieved from the profile store by calling [WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile), the encrypted key material is returned.**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The key material is never encrypted.

All-user profiles have three associated permissions: read, write, and execute. If a user has read access, the user can view profile permissions. If a user has execute access, the user has read access and the user can also connect to and disconnect from a network using the profile. If a user has write access, the user has execute access and the user can also modify and delete permissions associated with a profile.

The following describes the procedure for creating a security descriptor object and parsing it as a string.

1. Call [InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor) to create a security descriptor in memory.
2. Call [SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner).
3. Call [InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl) to create a discretionary access control list (DACL) in memory.
4. Call [AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace) or [AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace) to add access control entries (ACEs) to the DACL. Set the *AccessMask* parameter to one of the following as appropriate:
   * WLAN_READ_ACCESS
   * WLAN_EXECUTE_ACCESS
   * WLAN_WRITE_ACCESS
5. Call [SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl) to add the DACL to the security descriptor.
6. Call [ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora) to convert the descriptor to string.

The string returned by [ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora) can then be used as the *strAllUserProfileSecurity* parameter value when calling **WlanSetProfile**.

For every wireless LAN profile used by the Native Wifi AutoConfig service, Windows maintains the concept of custom user data. This custom user data is initially non-existent, but can be set by calling the [WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata) function. The custom user data gets reset to empty any time the profile is modified by calling the **WlanSetProfile** function. Once custom user data has been set, this data can be accessed using the [WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata) function.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanSetProfile** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter has been removed from the system (a USB wireless adapter that has been removed, for example).

The **netsh wlan add profile** command provides similar functionality at the command line. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

## See also

[ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora)

[InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl)

[InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor)

[Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions)

[SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)

[WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata)

[WlanSetProfileEapUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapuserdata)

[WlanSetProfileEapXmlUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapxmluserdata)