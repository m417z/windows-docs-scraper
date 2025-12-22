# WlanGetSecuritySettings function

## Description

The **WlanGetSecuritySettings** function gets the security settings associated with a configurable object.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `SecurableObject` [in]

A [WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object) value that specifies the object to which the security settings apply.

### `pValueType` [out, optional]

A pointer to a [WLAN_OPCODE_VALUE_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_opcode_value_type-r1) value that specifies the source of the security settings.

| Value | Meaning |
| --- | --- |
| **wlan_opcode_value_type_set_by_group_policy** | The security settings were set by group policy. |
| **wlan_opcode_value_type_set_by_user** | The security settings were set by the user. A user can set security settings by calling [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings). |

### `pstrCurrentSDDL` [out]

On input, this parameter must be **NULL**.

On output, this parameter receives a pointer to the security descriptor string that specifies the security settings for the object if the function call succeeds. For more information about this string, see [WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings) function.

### `pdwGrantedAccess` [out]

The access mask of the object.

| Value | Meaning |
| --- | --- |
| WLAN_READ_ACCESS | The caller can view the object's permissions. |
| WLAN_EXECUTE_ACCESS | The caller can read from and execute the object. WLAN_EXECUTE_ACCESS has the same value as the bitwise OR combination WLAN_READ_ACCESS \| WLAN_EXECUTE_ACCESS. |
| WLAN_WRITE_ACCESS | The caller can read from, execute, and write to the object. WLAN_WRITE_ACCESS has the same value as the bitwise OR combination WLAN_READ_ACCESS \| WLAN_EXECUTE_ACCESS \| WLAN_WRITE_ACCESS. |

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pstrCurrentSDDL* is **NULL**.<br>* *pdwGrantedAccess* is **NULL**.<br>* *SecurableObject* is set to a value greater than or equal to **WLAN_SECURABLE_OBJECT_COUNT** (12). |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |

## Remarks

The caller is responsible for freeing the memory allocated to the security descriptor string pointed to by the *pstrCurrentSDDL* parameter if the function succeeds. When no longer needed, the memory for the security descriptor string should be freed by calling [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function and passing in the *pstrCurrentSDDL* parameter.

## See also

[Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanSetSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetsecuritysettings)