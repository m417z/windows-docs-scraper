# WLAN_SECURABLE_OBJECT enumeration

## Description

The **WLAN_SECURABLE_OBJECT** enumerated type defines the [securable objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects) used by [Native Wifi Functions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-functions).

These objects can be secured using [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings). The current permissions associated with these objects can be retrieved using [WlanGetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetsecuritysettings). For more information about the use of securable objects, see [How DACLs Control Access to an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object).

## Constants

### `wlan_secure_permit_list:0`

The permissions for modifying the permit list for user profiles.

The [discretionary access control lists (DACL)](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists) associated with this securable object is retrieved when either [WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist) or [WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist) is called with *wlanFilterListType* set to **wlan_filter_list_type_user_permit**. For the **WlanGetFilterList** call to succeed, the DACL must contain an [access control entry (ACE)](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-entries) that grants WLAN_READ_ACCESS permission to the [access token](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-tokens) of the calling thread. For the **WlanSetFilterList** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_deny_list`

The permissions for modifying the deny list for user profiles. The auto config service will not establish a connection to a network on the deny list.

The DACL associated with this securable object is retrieved when either [WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist) or [WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist) is called with *wlanFilterListType* set to **wlan_filter_list_type_user_deny**. For the **WlanGetFilterList** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetFilterList** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_ac_enabled`

The permissions for enabling the auto config service.

The DACL associated with this securable object is retrieved when either [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) or [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) is called with *OpCode* set to **wlan_intf_opcode_autoconf_enabled**. For the **WlanQueryInterface** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetInterface** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_bc_scan_enabled`

The permissions for enabling background scans.

The DACL associated with this securable object is retrieved when either [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) or [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) is called with *OpCode* set to **wlan_intf_opcode_background_scan_enabled**. For the **WlanQueryInterface** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetInterface** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_bss_type`

The permissions for altering the basic service set type.

The DACL associated with this securable object is retrieved when either [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) or [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) is called with *OpCode* set to **wlan_intf_opcode_bss_type**. For the **WlanQueryInterface** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetInterface** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_show_denied`

 The permissions for modifying whether networks on the deny list appear in the available networks list.

The DACL associated with this securable object is retrieved when either [WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter) or [WlanSetAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetautoconfigparameter) is called with *OpCode* set to **wlan_autoconf_opcode_show_denied_networks**. For the **WlanQueryAutoConfigParameter** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetAutoConfigParameter** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_interface_properties`

The permissions for changing interface properties.

This is the generic securable object used by [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) or [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) when another more specific securable object is not used. Its DACL is retrieved whenever **WlanQueryInterface** or **WlanSetInterface** is access token of the calling thread and the *OpCode* is set to a value other than **wlan_intf_opcode_autoconf_enabled**, **wlan_intf_opcode_background_scan_enabled**, **wlan_intf_opcode_media_streaming_mode**, **wlan_intf_opcode_bss_type**, or **wlan_intf_opcode_current_operation_mode**. The DACL is also not retrieved when *OpCode* is set to **wlan_intf_opcode_radio_state** and the caller is the console user.

For the [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_ihv_control`

The permissions for using the [WlanIhvControl](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanihvcontrol) function for independent hardware vendor (IHV) control of WLAN drivers or services.

The DACL associated with this securable object is retrieved when [WlanIhvControl](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanihvcontrol) is called. For the call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_all_user_profiles_order`

The permissions for modifying the order of all-user profiles.

The DACL associated with this securable object is retrieved before [WlanSetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilelist) or [WlanSetProfilePosition](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileposition) performs an operation that changes the relative order of all-user profiles in the profile list or moves an all-user profile to a lower position in the profile list. For either call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_add_new_all_user_profiles`

The permissions for adding new all-user profiles.

**Note** The security descriptor associated with this object is applied to new all-user profiles created.

The DACL associated with this securable object is retrieved when [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) is called with *dwFlags* set to 0. For the call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_add_new_per_user_profiles`

The permissions for adding new per-user profiles.

The DACL associated with this securable object is retrieved when [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) is called with *dwFlags* set to WLAN_PROFILE_USER. For the call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_media_streaming_mode_enabled`

The permissions for setting or querying the media streaming mode.

The DACL associated with this securable object is retrieved when either [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) or [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) is called with *OpCode* set to **wlan_intf_opcode_media_streaming_mode**. For the **WlanQueryInterface** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetInterface** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_current_operation_mode`

The permissions for setting or querying the operation mode of the wireless interface.

The DACL associated with this securable object is retrieved when either [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) or [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) is called with *OpCode* set to **wlan_intf_opcode_current_operation_mode**. For the **WlanQueryInterface** call to succeed, the DACL must contain an ACE that grants WLAN_READ_ACCESS permission to the access token of the calling thread. For the **WlanSetInterface** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread.

### `wlan_secure_get_plaintext_key`

The permissions for retrieving the plain text key from a wireless profile.

 The DACL associated with this securable object is retrieved when the [WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile) function is called with the **WLAN_PROFILE_GET_PLAINTEXT_KEY** flag set in the value pointed to by the *pdwFlags* parameter on input. For the **WlanGetProfile** call to succeed, the DACL must contain an ACE that grants **WLAN_READ_ACCESS** permission to the access token of the calling thread. By default, the permissions for retrieving the plain text key is allowed only to the members of the Administrators group on a local computer.

**Windows 7:** This value is an extension to native wireless APIs added on Windows 7 and later.

### `wlan_secure_hosted_network_elevated_access`

The permissions that have elevated access to call the privileged Hosted Network functions.

The DACL associated with this securable object is retrieved when the [WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty) function is called with the *OpCode* parameter set to **wlan_hosted_network_opcode_enable**. For the **WlanHostedNetworkSetProperty** call to succeed, the DACL must contain an ACE that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread. By default, the permission to set the wireless Hosted Network property to **wlan_hosted_network_opcode_enable** is allowed only to the members of the Administrators group on a local computer.

 The DACL associated with this securable object is retrieved when the [WlanHostedNetworkForceStart](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestart) function is called. For the **WlanHostedNetworkForceStart** call to succeed, the DACL must contain an ACE that grants **WLAN_WRITE_ACCESS** permission to the access token of the calling thread. By default, the permission to force start the wireless Hosted Network is allowed only to the members of the Administrators group on a local computer.

**Windows 7:** This value is an extension to native wireless APIs added on Windows 7 and later.

### `wlan_secure_virtual_station_extensibility`

**Windows 7:** This value is an extension to native wireless APIs added on Windows 7 and later.

### `wlan_secure_wfd_elevated_access`

This value is reserved for internal use by the Wi-Fi Direct service.

**Windows 8:** This value is an extension to native wireless APIs added on Windows 8 and later.

### `WLAN_SECURABLE_OBJECT_COUNT`

## Remarks

These objects can be secured using [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings). The current permissions associated with these objects can be retrieved using [WlanGetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetsecuritysettings). For more information about the use of securable objects, see [How DACLs Control Access to an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) and [Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions).

## See also

[How DACLs Control Access to an Object](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)

[Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions)

[WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanHostedNetworkForceStart](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestart)

[WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty)

[WlanIhvControl](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanihvcontrol)

[WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter)

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)

[WlanSetAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetautoconfigparameter)

[WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist)

**WlanSetInterface**

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilelist)

[WlanSetProfilePosition](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileposition)