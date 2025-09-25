# WlanHostedNetworkRefreshSecuritySettings function

## Description

The **WlanHostedNetworkRefreshSecuritySettings** function refreshes the configurable and auto-generated parts of the wireless Hosted Network security settings.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pFailReason` [out, optional]

An optional pointer to a value that receives the failure reason, if the call to the **WlanHostedNetworkRefreshSecuritySettings** function fails. Possible values for the failure reason are from the [WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason) enumeration type defined in the *Wlanapi.h*  header file.

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

The **WlanHostedNetworkRefreshSecuritySettings** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkRefreshSecuritySettings** function to force a refresh of the configurable and auto-generated parts of the security settings (the primary key) on the wireless Hosted Network.

An application might call the **WlanHostedNetworkRefreshSecuritySettings** function after ensuring that the user accepts the impact of updating the security settings. In order to succeed, this function must persist the new settings which would require that Hosted Network state be transitioned to wlan_hosted_network_idle if it was currently running (wlan_hosted_network_active).

**Note** Any network clients (PCs or devices) on the wireless Hosted Network would have to be re-configured after calling the **WlanHostedNetworkRefreshSecuritySettings** function if their continued usage is a goal. An application would typically call this function in situations where the user feels that the security of the previous primary key used for security by the wireless Hosted Network has been violated. Note that the **WlanHostedNetworkRefreshSecuritySettings** function does not change or reset the secondary key.

Any Hosted Network state change caused by this function would not be automatically undone if the calling application closes its calling handle (by calling [WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle) with the *hClientHandle* parameter) or if the process ends.

Any user can call the **WlanHostedNetworkRefreshSecuritySettings** function to refresh the security settings on the Hosted Network. However, the ability to enable the wireless Hosted Network may be restricted by group policy in a domain.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object)

[WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanHostedNetworkInitSettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkinitsettings)

[WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty)

[WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus)

[WlanHostedNetworkRefreshSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkrefreshsecuritysettings)

[WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty)

[WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)