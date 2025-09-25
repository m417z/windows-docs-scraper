# WlanGetNetworkBssList function

## Description

> [!NOTE]
> **Some information relates to pre-released product, which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.**

> [!IMPORTANT]
> This API will be affected by upcoming changes to operating system behavior, planned for fall 2024. For more info, see [Changes to API behavior for Wi-Fi access and location](https://learn.microsoft.com/windows/win32/nativewifi/wi-fi-access-location-changes).

The **WlanGetNetworkBssList** function retrieves a list of the basic service set (BSS) entries of the wireless network or networks on a given wireless LAN interface.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

A pointer to the GUID of the wireless LAN interface to be queried.

 The GUID of each wireless LAN interface enabled on a local computer can be determined using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

### `pDot11Ssid` [optional]

A pointer to a [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure that specifies the SSID of the network from which the BSS list is requested. This parameter is optional. When set to **NULL**, the returned list contains all of available BSS entries on a wireless LAN interface.

If a pointer to a [DOT11_SSID](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-ssid) structure is specified, the SSID length specified in the **uSSIDLength** member of **DOT11_SSID** structure must be less than or equal to **DOT11_SSID_MAX_LENGTH** defined in the *Wlantypes.h* header file. In addition, the *dot11BssType* parameter must be set to either **dot11_BSS_type_infrastructure** or **dot11_BSS_type_independent** and the *bSecurityEnabled* parameter must be specified.

### `dot11BssType` [in]

The BSS type of the network. This parameter is ignored if the SSID of the network for the BSS list is unspecified (the *pDot11Ssid* parameter is **NULL**).

This parameter can be one of the following values defined in the [DOT11_BSS_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-bss-type) enumeration defined in the *Wlantypes.h* header file.

| Value | Meaning |
| --- | --- |
| **dot11_BSS_type_infrastructure** | An infrastructure BSS network. |
| **dot11_BSS_type_independent** | An independent BSS (IBSS) network (an ad hoc network). |
| **dot11_BSS_type_any** | Any BSS network. |

### `bSecurityEnabled` [in]

A value that indicates whether security is enabled on the network. This parameter is only valid when the SSID of the network for the BSS list is specified (the *pDot11Ssid* parameter is not **NULL**).

### `pReserved`

Reserved for future use. This parameter must be set to **NULL**.

### `ppWlanBssList` [out]

A pointer to storage for a pointer to receive the returned list of BSS entries in a [WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list) structure.

The buffer for the [WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list) returned is allocated by the **WlanGetNetworkBssList** function if the call succeeds.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *hClientHandle*, *pInterfaceGuid*, or *ppWlanBssList* parameter is **NULL**. This error is returned if the *pReserved* is not **NULL**. This error is also returned if the *hClientHandle*, the SSID specified in the *pDot11Ssid* parameter, or the BSS type specified in the *dot11BssType* parameter is not valid. |
| **ERROR_NDIS_DOT11_POWER_STATE_INVALID** | The radio associated with the interface is turned off. The BSS list is not available when the radio is off. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to process this request and allocate memory for the query results. |
| **ERROR_NOT_FOUND** | The element was not found. This error is returned if the GUID of the interface to be queried that was specified in the *pInterfaceGuid* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. This error is also returned if the WLAN AutoConfig service is disabled. |
| **ERROR_SERVICE_NOT_ACTIVE** | The WLAN AutoConfig service has not been started. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanGetNetworkBssList** function retrieves the basic service set list for each wireless network or networks accessible on a given interface. The list of information returned for each wireless network also contains a list of information elements returned by each access point for an infrastructure BSS network or a network peer for an independent BSS network (ad hoc network). The information is returned as a pointer to an [WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list) structure in the *ppWlanBssList* parameter. The **WLAN_BSS_LIST** structure contains an item count followed by an array of [WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry) structure entries.

Since the information returned by the **WlanGetNetworkBssList** function is sent by an access point for an infrastructure BSS network or by a network peer for an independent BSS network (ad hoc network), the information returned should not be trusted. The **ulIeOffset** and **ulIeSize** members in the [WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry) structure should be used to determine the size of the information element data blob in the **WLAN_BSS_ENTRY** structure, not the data in the information element data blob itself. The **WlanGetNetworkBssList** function does not validate that any information returned in the information element data blob pointed to by the **ulIeOffset** member is a valid information element as defined by the IEEE 802.11 standards for wireless LANs.

If the *pDot11Ssid* parameter is specified (not **NULL**), then the *dot11BssType* parameter specified must be set to either **dot11_BSS_type_infrastructure** for an infrastructure BSS network or **dot11_BSS_type_independent** for an independent BSS network (ad hoc network). If the *dot11BssType* parameter is set to **dot11_BSS_type_any**, then the **WlanGetNetworkBssList** function returns ERROR_SUCCESS but no BSS entries will be returned.

To return a list of all the infrastructure BSS networks and independent BSS networks (ad hoc networks) on a wireless LAN interface, set the *pDot11Ssid* parameter to **NULL**. When the wireless LAN interface is also operating as a Wireless Hosted Network , the BSS list will contain an entry for the BSS created for the Wireless Hosted Network.

The **WlanGetNetworkBssList** function returns ERROR_SUCCESS when an empty BSS list is returned by the WLAN AutoConfig Service. An application that calls the **WlanGetNetworkBssList** function must check that the **dwNumberOfItems** member of the [WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list) pointed to by the *ppWlanBssList* parameter is not zero before accessing the **wlanBssEntries[0]** member in **WLAN_BSS_LIST** structure.

The **WlanGetNetworkBssList** function allocates memory for the basic service set list that is returned in a buffer pointed to by the *ppWlanBssList* parameter when the function succeeds. The memory used for the buffer pointed to by *ppWlanBssList* parameter should be released by calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function after the buffer is no longer needed.

## See also

[WLAN_AVAILABLE_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network)

[WLAN_AVAILABLE_NETWORK_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network_list)

[WLAN_BSS_ENTRY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_entry)

[WLAN_BSS_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_bss_list)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist)

[WlanScan](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanscan)