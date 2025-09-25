# WlanSetSecuritySettings function

## Description

The [WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist) function sets the security settings for a configurable object.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `SecurableObject` [in]

A [WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object) value that specifies the object to which the security settings will be applied.

### `strModifiedSDDL` [in]

A security descriptor string that specifies the new security settings for the object. This string must be NULL-terminated. For more information, see the Remarks section.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *strModifiedSDDL* is **NULL**.<br>* *SecurableObject* is set to a value greater than or equal to **WLAN_SECURABLE_OBJECT_COUNT** (12). |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |

## Remarks

A successful call to the **WlanSetSecuritySettings** function overrides the default permissions associated with an object. For more information about default permissions, see [Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions).

The following describes the procedure for creating a security descriptor object and parsing it as a string.

1. Call [InitializeSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor) to create a security descriptor in memory.
2. Call [SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner) to set the owner information for the security descriptor.
3. Call [InitializeAcl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializeacl) to create a discretionary access control list (DACL) in memory.
4. Call [AddAccessAllowedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedace) or [AddAccessDeniedAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedace) to add access control entries (ACEs) to the DACL. Set the *AccessMask* parameter to one of the following bitwise OR combinations as appropriate:
   * WLAN_READ_ACCESS
   * WLAN_READ_ACCESS | WLAN_EXECUTE_ACCESS
   * WLAN_READ_ACCESS | WLAN_EXECUTE_ACCESS | WLAN_WRITE_ACCESS
5. Call [SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl) to add the DACL to the security descriptor.
6. Call [ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora) to convert the descriptor to string.

The string returned by [ConvertSecurityDescriptorToStringSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsecuritydescriptortostringsecuritydescriptora) can then be used as the *strModifiedSDDL* parameter value when calling **WlanSetSecuritySettings**.

## See also

[Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions)

[WlanGetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetsecuritysettings)