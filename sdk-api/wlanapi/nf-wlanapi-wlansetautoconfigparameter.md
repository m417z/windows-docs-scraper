# WlanSetAutoConfigParameter function

## Description

The **WlanSetAutoConfigParameter** function sets parameters for the automatic configuration service.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `OpCode` [in]

A [WLAN_AUTOCONF_OPCODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_autoconf_opcode-r1) value that specifies the parameter to be set. Only some of the opcodes in the **WLAN_AUTOCONF_OPCODE** enumeration support set operations.

| Value | Meaning |
| --- | --- |
| **wlan_autoconf_opcode_show_denied_networks** | When set, the *pData* parameter will contain a **BOOL** value indicating whether user and group policy-denied networks will be included in the available networks list. |
| **wlan_autoconf_opcode_allow_explicit_creds** | When set, the *pData* parameter will contain a **BOOL** value indicating whether the current wireless interface has shared user credentials allowed. |
| **wlan_autoconf_opcode_block_period** | When set, the *pData* parameter will contain a **DWORD** value for the blocked period setting for the current wireless interface. The blocked period is the amount of time, in seconds, for which automatic connection to a wireless network will not be attempted after a previous failure. |
| **wlan_autoconf_opcode_allow_virtual_station_extensibility** | When set, the *pData* parameter will contain a **BOOL** value indicating whether extensibility on a virtual station is allowed. By default, extensibility on a virtual station is allowed. The value for this opcode is persisted across restarts.<br><br>This enumeration value is supported on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed. |

### `dwDataSize` [in]

The size of the *pData* parameter, in bytes. This parameter must be set to `sizeof(BOOL)` for a BOOL or `sizeof(DWORD)` for a DWORD, depending on the value of the *OpCode* parameter.

### `pData` [in]

The value to be set for the parameter specified in *OpCode* parameter. The *pData* parameter must point to a boolean or DWORD value, depending on the value of the *OpCode* parameter. The *pData* parameter must not be **NULL**.

**Note** The *pData* parameter may point to an integer value when a boolean is required. If *pData* points to 0, then the value is converted to **FALSE**. If *pData* points to a nonzero integer, then the value is converted to **TRUE**.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller does not have sufficient permissions to set the configuration parameter when the *OpCode* parameter is wlan_autoconf_opcode_show_denied_networks or wlan_autoconf_opcode_allow_virtual_station_extensibility. When the *OpCode* parameter is set to one of these values, the [WlanSetAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetautoconfigparameter) function retrieves the discretionary access control list (DACL) stored for opcode object. If the DACL does not contain an access control entry (ACE) that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread, then **WlanSetAutoConfigParameter** returns **ERROR_ACCESS_DENIED**.<br><br>This error is also returned if the configuration parameter is set by group policy on a domain. When group policy is set for an opcode, applications are prevented from making changes. For the following *OpCode* parameters may be set by group policy: wlan_autoconf_opcode_show_denied_networks, wlan_autoconf_opcode_allow_explicit_creds, and wlan_autoconf_opcode_block_period |
| **ERROR_INVALID_PARAMETER** | A parameter was bad. This error is returned if the *hClientHandle* parameter is **NULL**, the *pData* parameter is **NULL**, or the *pReserved* parameter is not **NULL**. This error is also returned if *OpCode* parameter specified is not one of the [WLAN_AUTOCONF_OPCODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_autoconf_opcode-r1) values for a configuration parameter that can be set. This error is also returned if the *dwDataSize* parameter is not set to `sizeof(BOOL)`, or the *dwDataSize* is not set to `sizeof(BOOL)` depending on the value of the *OpCode* parameter. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanSetAutoConfigParameter** function sets parameters used by Auto Configuration Module (ACM), the wireless configuration component supported on Windows Vista and later.

Depending on the value of the *OpCode* parameter, the data pointed to by *pData* will be converted to a boolean value before the automatic configuration parameter is set. If *pData* points to 0, then the parameter is set to **FALSE**; otherwise, the parameter is set to **TRUE**.

## See also

[WLAN_AUTOCONF_OPCODE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_autoconf_opcode-r1)

[WlanQueryAutoConfigParameter](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryautoconfigparameter)