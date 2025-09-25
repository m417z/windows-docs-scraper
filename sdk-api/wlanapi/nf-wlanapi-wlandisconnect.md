# WlanDisconnect function

## Description

The **WlanDisconnect** function disconnects an interface from its current network.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface to be disconnected.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *pInterfaceGuid* is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **RPC_STATUS** | Various error codes. |
| **ERROR_NOT_ENOUGH_MEMORY** | Failed to allocate memory for the query results. |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. |

## Remarks

When the connection was established using [WlanConnect](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanconnect), a profile was specified by the **strProfile** member of the [WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters) structure pointed to by *pConnectionParameters*. If that profile was an all-user profile, the **WlanDisconnect** caller must have execute access on the profile. Otherwise, the **WlanDisconnect** call will fail with return value ERROR_ACCESS_DENIED. The permissions on an all-user profile are established when the profile is created or saved using [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) or [WlanSaveTemporaryProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansavetemporaryprofile).

To perform a disconnection operation at the command line, use the **netsh wlan disconnect** command. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** **WlanDisconnect** has the side effect of modifying the profile associated with the disconnected network. A network profile becomes an on-demand profile after a **WlanDisconnect** call. The Wireless Zero Configuration service will not connect automatically to a network with an on-demand profile when the network is in range. Do not call **WlanDisconnect** before calling [WlanConnect](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanconnect) unless you want to change a profile to an on-demand profile. When you call **WlanConnect** to establish a network connection, any existing network connection is dropped automatically.

## See also

[WlanConnect](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanconnect)