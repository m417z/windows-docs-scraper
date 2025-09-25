# WlanSetProfileCustomUserData function

## Description

The **WlanSetProfileCustomUserData** function sets the custom user data associated with a profile.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `strProfileName` [in]

The name of the profile associated with the custom user data. Profile names are case-sensitive. This string must be NULL-terminated.

### `dwDataSize` [in]

The size of *pData*, in bytes.

### `pData` [in]

A pointer to the user data to be set.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the following conditions occurred:<br><br>* *hClientHandle* is **NULL** or invalid.<br>* *pInterfaceGuid* is **NULL**.<br>* *strProfileName* is **NULL**.<br>* *pReserved* is not **NULL**.<br>* *dwDataSize* is not 0 and *pData* is **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

For every wireless WLAN profile used by the Native Wifi AutoConfig service, Windows maintains the concept of custom user data. This custom user data is initially non-existent, but can be set by calling the **WlanSetProfileCustomUserData** function. The custom user data gets reset to empty any time the profile is modified by calling the [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) function.

Once custom user data has been set, this data can be accessed using the [WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata) function.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanSetProfileCustomUserData** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter has been removed from the system (a USB wireless adapter that has been removed, for example).

## See also

[WLAN_profile Schema](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-profileschema-schema)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileEapUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapuserdata)

[WlanSetProfileEapXmlUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapxmluserdata)