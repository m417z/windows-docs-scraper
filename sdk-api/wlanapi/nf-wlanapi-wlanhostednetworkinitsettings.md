# WlanHostedNetworkInitSettings function

## Description

The **WlanHostedNetworkInitSettings** function configures and persists to storage the network connection settings (SSID and maximum number of peers, for example) on the wireless Hosted Network if these settings are not already configured.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pFailReason` [out, optional]

An optional pointer to a value that receives the failure reason if the call to the **WlanHostedNetworkInitSettings** function fails. Possible values for the failure reason are from the [WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason) enumeration type defined in the *Wlanapi.h*  header file.

### `pvReserved`

Reserved for future use. This parameter must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pvReserved* is not **NULL**. |
| **ERROR_INVALID_STATE** | The resource is not in the correct state to perform the requested operation. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **WlanHostedNetworkInitSettings** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkInitSettings** function to configure and persist to storage the network connection settings (SSID and maximum number of peers, for example) on the wireless Hosted Network, if the connections settings are not already configured. If the network settings on the wireless Hosted Network settings are already configured (the [WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty) function does not return **ERROR_BAD_CONFIGURATION** for the station profile or connection settings), then this function call returns **ERROR_SUCCESS** without changing the configuration of the network connection settings.

A client application should always call the **WlanHostedNetworkInitSettings** function before using other Hosted Network features on the local computer. This function initializes settings that are required when the wireless Hosted Network is used for the first time on a local computer. The **WlanHostedNetworkInitSettings** function does not change any configuration if the configuration has already been persisted. So it is safe to call the **WlanHostedNetworkInitSettings** function if the configuration has already been persisted. It is recommended that applications that use Hosted Network call the **WlanHostedNetworkInitSettings** function before using other Hosted Network functions.

The **WlanHostedNetworkInitSettings** function computes a random and readable SSID from the host name and computes a random primary key. This function also uses sets a value for the maximum number of peers allowed that defaults to 100. If an application wants to use a different SSID or a different maximum number of peers, then the application should call the [WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty) function to specifically set these properties used by the wireless Hosted Network.

Any Hosted Network state change caused by this function would not be automatically undone if the calling application closes its calling handle (by calling [WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle) with the *hClientHandle* parameter) or if the process ends.

Any user can call the **WlanHostedNetworkInitSettings** function to configure and persist to storage network connection settings on the Hosted Network. If the wireless Hosted Network has already been configured, this function does nothing and returns **ERROR_SUCCESS**.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object)

[WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty)

[WlanHostedNetworkQuerySecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerysecondarykey)

[WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus)

[WlanHostedNetworkRefreshSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkrefreshsecuritysettings)

[WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty)

[WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)