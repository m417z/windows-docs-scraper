# WlanConnect function

## Description

The **WlanConnect** function attempts to connect to a specific network.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface to use for the connection.

### `pConnectionParameters` [in]

Pointer to a [WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters) structure that specifies the connection type, mode, network profile, SSID that identifies the network, and other parameters.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** There are some constraints on the [WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters) members. This means that structures that are valid for Windows Server 2008 and Windows Vista may not be valid for Windows XP with SP3 or Wireless LAN API for Windows XP with SP2. For a list of constraints, see **WLAN_CONNECTION_PARAMETERS**.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *hClientHandle* is **NULL** or invalid.<br>* *pInterfaceGuid* is **NULL**.<br>* *pConnectionParameters* is **NULL**.<br>* The **dwFlags** member of the structure pointed to by *pConnectionParameters* is not set to one of the values specified on the [WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters) page.<br>* The **wlanConnectionMode** member of the structure pointed to by *pConnectionParameters* is set to **wlan_connection_mode_discovery_secure** or **wlan_connection_mode_discovery_unsecure**, and the **pDot11Ssid** member of the same structure is **NULL**.<br>* The **wlanConnectionMode** member of the structure pointed to by *pConnectionParameters* is set to **wlan_connection_mode_discovery_secure** or **wlan_connection_mode_discovery_unsecure**, and the **dot11BssType** member of the same structure is set to **dot11_BSS_type_any**.<br>* The **wlanConnectionMode** member of the structure pointed to by *pConnectionParameters* is set to **wlan_connection_mode_profile**, and the **strProfile** member of the same structure is **NULL** or the length of the profile exceeds WLAN_MAX_NAME_LENGTH.<br>* The **wlanConnectionMode** member of the structure pointed to by *pConnectionParameters* is set to **wlan_connection_mode_profile**, and the **strProfile** member of the same structure is **NULL** or the length of the profile is zero.<br>* The **wlanConnectionMode** member of the structure pointed to by *pConnectionParameters* is set to **wlan_connection_mode_invalid** or **wlan_connection_mode_auto**.<br>* The **dot11BssType** member of the structure pointed to by *pConnectionParameters* is set to **dot11_BSS_type_infrastructure**, and the **dwFlags** member of the same structure is set to **WLAN_CONNECTION_ADHOC_JOIN_ONLY**.<br>* The **dot11BssType** member of the structure pointed to by *pConnectionParameters* is set to **dot11_BSS_type_independent**, and the **dwFlags** member of the same structure is set to **WLAN_CONNECTION_HIDDEN_NETWORK**.<br>* The **dwFlags** member of the structure pointed to by *pConnectionParameters* is set to **WLAN_CONNECTION_IGNORE_PRIVACY_BIT**, and either the **wlanConnectionMode** member of the same structure is not set to **wlan_connection_mode_temporary_profile** or the **dot11BssType** member of the same structure is set to **dot11_BSS_type_independent**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **RPC_STATUS** | Various error codes. |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. |

## Remarks

The **WlanConnect** function returns immediately. To be notified when a connection is established or when no further connections will be attempted, a client must register for notifications by calling [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification).

The **strProfile** member of the [WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters) structure pointed to by *pConnectionParameters* specifies the profile to use for connection. If this profile is an all-user profile, the **WlanConnect** caller must have execute access on the profile. Otherwise, the **WlanConnect** call will fail with return value ERROR_ACCESS_DENIED. The permissions on an all-user profile are established when the profile is created or saved using [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) or [WlanSaveTemporaryProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansavetemporaryprofile).

To perform a connection operation at the command line, use the **netsh wlan connect** command. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** You can only use **WlanConnect** to connect to networks on the preferred network list. To add a network to the preferred network list, call [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile).

## See also

[WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters)

[WlanDisconnect](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlandisconnect)