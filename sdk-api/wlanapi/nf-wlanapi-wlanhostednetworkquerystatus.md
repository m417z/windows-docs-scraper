# WlanHostedNetworkQueryStatus function

## Description

The **WlanHostedNetworkQueryStatus** function queries the current status of the wireless Hosted Network.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `ppWlanHostedNetworkStatus` [out]

On input, this parameter must be **NULL**.

On output, this parameter receives a pointer to the current status of the wireless Hosted Network, if the call to the **WlanHostedNetworkQueryStatus** function succeeds. The current status is returned in a [WLAN_HOSTED_NETWORK_STATUS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_status) structure.

### `pvReserved`

Reserved for future use. This parameter must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* ppWlanHostedNetworkStatus is **NULL**.<br>* *pvReserved* is not **NULL**. |
| **ERROR_INVALID_STATE** | The resource is not in the correct state to perform the requested operation. This can occur if the wireless Hosted Network was in the process of shutting down. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **WlanHostedNetworkQueryStatus** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkQueryStatus** function to query the current status of the wireless Hosted Network. This function does not change the state of the wireless Hosted Network.

If the function succeeds, the *ppWlanHostedNetworkStatus* parameter points to a [WLAN_HOSTED_NETWORK_STATUS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_status) structure with the current status. The memory used for the **WLAN_HOSTED_NETWORK_STATUS** structure that is returned should be freed after use by calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function.

Any user can call the **WlanHostedNetworkQueryStatus** function to query the Hosted Network. However, the ability to enable the wireless Hosted Network may be restricted by group policy in a domain.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_STATUS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_status)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty)

[WlanHostedNetworkQuerySecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerysecondarykey)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)