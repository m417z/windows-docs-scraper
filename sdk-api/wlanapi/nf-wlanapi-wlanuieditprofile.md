# WlanUIEditProfile function

## Description

Displays the wireless profile user interface (UI). This UI is used to view and edit advanced settings of a wireless network profile.

## Parameters

### `dwClientVersion` [in]

Specifies the highest version of the WLAN API that the client supports.
Values other than WLAN_UI_API_VERSION will be ignored.

### `wstrProfileName` [in]

Contains the name of the profile to be viewed or edited. Profile names are case-sensitive. This string must be NULL-terminated.

The supplied profile must be present on the interface *pInterfaceGuid*. That means the profile must have been previously created and saved in the profile store and that the profile must be valid for the supplied interface.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `hWnd` [in]

The handle of the application window requesting the UI display.

### `wlStartPage` [in]

A [WL_DISPLAY_PAGES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wl_display_pages) value that specifies the active tab when the UI dialog box appears.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `pWlanReasonCode` [out]

A pointer to a [WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code) value that indicates why the UI display failed.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the supplied parameters is not valid. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

If **WlanUIEditProfile** returns ERROR_SUCCESS, any changes to the profile made in the UI will be saved in the profile store.