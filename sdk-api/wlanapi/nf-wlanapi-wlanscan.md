# WlanScan function

## Description

> [!NOTE]
> **Some information relates to pre-released product, which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.**

> [!IMPORTANT]
> This API will be affected by upcoming changes to operating system behavior, planned for fall 2024. For more info, see [Changes to API behavior for Wi-Fi access and location](https://learn.microsoft.com/windows/win32/nativewifi/wi-fi-access-location-changes).

The **WlanScan** function requests a scan for available networks on the indicated interface.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface to be queried.

 The GUID of each wireless LAN interface enabled on a local computer can be determined using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

### `pDot11Ssid` [in, optional]

A pointer to a [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that specifies the SSID of the network to be scanned. This parameter may be **NULL**.
**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** This parameter must be **NULL**.

### `pIeData` [in, optional]

A pointer to an information element to include in probe requests. This parameter points to a [WLAN_RAW_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data) structure that may include client provisioning availability information and 802.1X authentication requirements.**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** This parameter must be **NULL**.

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

## Remarks

The **WlanScan** function requests that the native 802.11 Wireless LAN driver scan for available wireless networks. The driver may or may not send probe requests (an active scan) depending on its implementation and the values passed in the *pDot11Ssid* and *pIeData* parameters.

If the *pIeData* parameter is not **NULL**, the driver will send probe requests during the scan. The probe requests include the information element (IE) pointed to by the *pIeData* parameter. For instance, the Wi-Fi Protected Setup (WPS) IE can be included in the probe requests to discover WPS-capable access points. The buffer pointed to by the *pIeData* parameter must contain the complete IE starting from the Element ID.

The *pIeData* parameter passed to the **WlanScan** function can contain a pointer to an optional [WLAN_RAW_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data) structure that contains a proximity service discovery (PSD) IE data entry.

When used to store a PSD IE, the **DOT11_PSD_IE_MAX_DATA_SIZE** constant defined in the *Wlanapi.h* header file is the maximum value of the **dwDataSize** member.

| Constant | Value | Description |
| --- | --- | --- |
| **DOT11_PSD_IE_MAX_DATA_SIZE** | 240 | The maximum data size, in bytes, of a PSD IE data entry. |

For more information about PSD IEs, including a discussion of the format of a PSD IE, see the [WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist) function.

When the **WlanScan** function is called, the native 802.11 Wireless LAN driver may flush the current list of available wireless networks before the scan is initiated. Applications should not assume that calling the **WlanScan** function will add to the existing list of available wireless networks returned by the [WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist) or [WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist) functions from previous scans.

The **WlanScan** function returns immediately. To be notified when the network scan is complete, a client on Windows Vista and later must register for notifications by calling [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification). The *dwNotifSource* parameter passed to the **WlanRegisterNotification** function must have the WLAN_NOTIFICATION_SOURCE_ACM bit set to register for notifications generated by the auto configuration module. Wireless network drivers that meet Windows logo requirements are required to complete a **WlanScan** function request in 4 seconds.

The Wireless LAN Service does not send notifications when available wireless networks change. The Wireless LAN Service does not track changes to the list of available networks across multiple scans. The current default behavior is that the Wireless LAN Service only asks the wireless interface driver to scan for wireless networks every 60 seconds, and in some cases (when already connected to wireless network) the Wireless LAN Service does not ask for scans at all.
The **WlanScan** function can be used by an application to track wireless network changes. The application should first register for WLAN_NOTIFICATION_SOURCE_ACM notifications. The **WlanScan** function can then be called to initiate a scan. The application should then wait to receive the wlan_notification_acm_scan_complete notification or timeout after 4 seconds. Then the application can call the [WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist) or [WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist) function to retrieve a list of available wireless networks. This process can be repeated periodically with the application keeping tracking of changes to available wireless networks.

The **WlanScan** function returns immediately and does not provide a notification when the scan is complete on Windows XP with SP3 or the Wireless LAN API for Windows XP with SP2.

Since it becomes more difficult for a wireless interface to send and receive data packets while a scan is occurring, the **WlanScan** function may increase latency until the network scan is complete.

## See also

[DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid)

[WLAN_RAW_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_raw_data)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist)

[WlanGetNetworkBssList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetnetworkbsslist)

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)

[WlanSetPsdIEDataList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetpsdiedatalist)