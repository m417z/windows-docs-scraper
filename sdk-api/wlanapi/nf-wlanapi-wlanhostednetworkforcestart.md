# WlanHostedNetworkForceStart function

## Description

The **WlanHostedNetworkForceStart** function transitions the wireless Hosted Network to the **wlan_hosted_network_active state** without associating the request with the application's calling handle.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pFailReason` [out, optional]

An optional pointer to a value that receives the failure reason if the call to the **WlanHostedNetworkForceStart** function fails. Possible values for the failure reason are from the [WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason) enumeration type defined in the *Wlanapi.h*  header file.

### `pvReserved`

Reserved for future use. This parameter must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pvReserved* is not **NULL**. |
| **ERROR_INVALID_STATE** | The resource is not in the correct state to perform the requested operation.<br><br>This error is returned if the wireless Hosted Network is disabled by group policy on a domain. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **WlanHostedNetworkForceStart** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkForceStart** function to force the start of the wireless Hosted Network by transitioning the wireless Hosted Network to the **wlan_hosted_network_active state** without associating the request with the application's calling handle. A successful call to the **WlanHostedNetworkForceStart** function should eventually be matched by a call to [WlanHostedNetworkForceStop](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestop) function.
Any Hosted Network state change caused by this function would not be automatically undone if the calling application closes its calling handle (by calling [WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle) with the *hClientHandle* parameter) or if the process ends.

The cost of calling the **WlanHostedNetworkForceStart** function over calling [WlanHostedNetworkStartUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstartusing) is the associated privilege required. An application might call the **WlanHostedNetworkForceStart** function after ensuring that an elevated system user accepts the increased power requirements involved in running the wireless Hosted Network for extended durations.

The **WlanHostedNetworkForceStart** function could fail if Hosted Network state is **wlan_hosted_network_unavailable** or the caller does not have sufficient privileges.

This function to force the start of the Hosted Network can only be called if the user has the appropriate associated privilege. Permissions are stored in a discretionary access control list (DACL) associated with a [WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object). To call the **WlanHostedNetworkForceStart**, the client access token of the caller must have elevated privileges exposed by the following enumeration in **WLAN_SECURABLE_OBJECT**:

* **wlan_secure_hosted_network_elevated_access**

The ability to enable the wireless Hosted Network may also be restricted by group policy in a domain.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object)

[WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanHostedNetworkForceStop](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkforcestop)

[WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus)

[WlanHostedNetworkStartUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstartusing)

[WlanHostedNetworkStopUsing](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkstopusing)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)