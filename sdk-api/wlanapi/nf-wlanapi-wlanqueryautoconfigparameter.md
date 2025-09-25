# WlanQueryAutoConfigParameter function

## Description

The **WlanQueryAutoConfigParameter** function queries for the parameters of the auto configuration service.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `OpCode` [in]

A value that specifies the configuration parameter to be queried.

| Value | Meaning |
| --- | --- |
| **wlan_autoconf_opcode_show_denied_networks** | When set, the *ppData* parameter will contain a **BOOL** value indicating whether user and group policy-denied networks will be included in the available networks list. <br><br>If the function returns ERROR_SUCCESS and *ppData* points to **TRUE**, then user and group policy-denied networks will be included in the available networks list; if **FALSE**, user and group policy-denied networks will not be included in the available networks list. |
| **wlan_autoconf_opcode_power_setting** | When set, the *ppData* parameter will contain a [WLAN_POWER_SETTING](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_power_setting-r1) value specifying the power settings. |
| **wlan_autoconf_opcode_only_use_gp_profiles_for_allowed_networks** | When set, the *ppData* parameter will contain a **BOOL** value indicating whether profiles not created by group policy can be used to connect to an allowed network with a matching group policy profile. <br><br>If the function returns ERROR_SUCCESS and *ppData* points to **TRUE**, then only profiles created by group policy can be used; if **FALSE**, any profile can be used. |
| **wlan_autoconf_opcode_allow_explicit_creds** | When set, the *ppData* parameter will contain a **BOOL** value indicating whether the current wireless interface has shared user credentials allowed. <br><br>If the function returns ERROR_SUCCESS and *ppData* points to **TRUE**, then the current wireless interface has shared user credentials allowed; if **FALSE**, the current wireless interface does not allow shared user credentials. |
| **wlan_autoconf_opcode_block_period** | When set, the *ppData* parameter will contain a **DWORD** value that indicates the blocked period setting for the current wireless interface. The blocked period is the amount of time, in seconds, for which automatic connection to a wireless network will not be attempted after a previous failure. |
| **wlan_autoconf_opcode_allow_virtual_station_extensibility** | When set, the *ppData* parameter will contain a **BOOL** value indicating whether extensibility on a virtual station is allowed. By default, extensibility on a virtual station is allowed. The value for this opcode is persisted across restarts. <br><br>If the function returns ERROR_SUCCESS and *ppData* points to **TRUE**, then extensibility on a virtual station is allowed; if **FALSE**, extensibility on a virtual station is not allowed. |

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `pdwDataSize` [out]

Specifies the size of the *ppData* parameter, in bytes.

### `ppData` [out]

Pointer to the memory that contains the queried value for the parameter specified in *OpCode*.

**Note** If *OpCode* is set to **wlan_autoconf_opcode_show_denied_networks**, then the pointer referenced by *ppData* may point to an integer value. If the pointer referenced by *ppData* points to 0, then the integer value should be converted to the boolean value **FALSE**. If the pointer referenced by *ppData* points to a nonzero integer, then the integer value should be converted to the boolean value **TRUE**.

### `pWlanOpcodeValueType` [out, optional]

A [WLAN_OPCODE_VALUE_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_opcode_value_type-r1) value.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to get configuration parameters. <br><br>When called with *OpCode* set to **wlan_autoconf_opcode_show_denied_networks**, [WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter) retrieves the discretionary access control list (DACL) stored with the **wlan_secure_show_denied** object. If the DACL does not contain an access control entry (ACE) that grants WLAN_READ_ACCESS permission to the access token of the calling thread, then **WlanQueryAutoConfigParameter** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *pReserved* is not **NULL**, *ppData* is **NULL**, or *pdwDataSize* is **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanQueryAutoConfigParameter** function queries for the parameters used by Auto Configuration Module (ACM), the wireless configuration component supported on Windows Vista and later.

## See also

[WLAN_AUTOCONF_OPCODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_autoconf_opcode-r1)

[WlanSetAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetautoconfigparameter)