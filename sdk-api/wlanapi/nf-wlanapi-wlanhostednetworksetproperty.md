# WlanHostedNetworkSetProperty function

## Description

The **WlanHostedNetworkSetProperty** function sets static properties of the wireless Hosted Network.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `OpCode` [in]

The identifier for the property to be set. This identifier can only be the following values in the [WLAN_HOSTED_NETWORK_OPCODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_opcode) enumeration defined in the *Wlanapi.h*  header file:

* **wlan_hosted_network_opcode_connection_settings**

The Hosted Network connection settings.

* **wlan_hosted_network_opcode_enable**

The Hosted Network enabled flag.

### `dwDataSize` [in]

A value that specifies the size, in bytes, of the buffer pointed to by the *pvData* parameter.

### `pvData` [in]

A pointer to a buffer with the static property to set. The data type associated with this buffer depends upon the value of *OpCode* parameter.

### `pFailReason` [out, optional]

An optional pointer to a value that receives the failure reason, if the call to the **WlanHostedNetworkSetProperty** function fails. Possible values for the failure reason are from the [WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason) enumeration type defined in the *Wlanapi.h*  header file.

### `pvReserved`

Reserved for future use. This parameter must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. This error is also returned if the *OpCode* parameter was **wlan_hosted_network_opcode_enable** and the wireless Hosted Network is disabled by group policy on a domain. |
| **ERROR_BAD_PROFILE** | The network connection profile used by the wireless Hosted Network is corrupted. |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *OpCode* is not one of the enumerated values defined in the [WLAN_HOSTED_NETWORK_OPCODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_opcode).<br>* *dwDataSize* is zero.<br>* *pvData* is **NULL**.<br>* *pvData* does not point to a well- formed static property.<br>* *pvReserved* is not **NULL**. |
| **ERROR_INVALID_STATE** | The resource is not in the correct state to perform the requested operation. This can occur if the wireless Hosted Network was in the process of shutting down. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the application calls the [WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty) function with the *OpCode* parameter set to **wlan_hosted_network_opcode_station_profile** or **wlan_hosted_network_opcode_security_settings**. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **WlanHostedNetworkSetProperty** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkSetProperty** function to set the current static properties of the wireless Hosted Network.
Any Hosted Network property change caused by this function would not be automatically undone if the calling application closes its calling handle (by calling [WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle) with the *hClientHandle* parameter) or if the process ends.

The data type associated with the buffer pointed to by the *pvData* parameter depends upon the value of *OpCode* parameter as follows:

| OpCode | Description |
| --- | --- |
| wlan_hosted_network_opcode_connection_settings | A pointer to a [WLAN_HOSTED_NETWORK_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_connection_settings) structure is passed in the *pvData* parameter. |
| wlan_hosted_network_opcode_enable | A pointer to **BOOL** is passed in the *pvData* parameter. |

If the **WlanHostedNetworkSetProperty** function is called with the *OpCode* parameter set to **wlan_hosted_network_opcode_enable**, the user must have the appropriate associated privilege. Permissions are stored in a discretionary access control list (DACL) associated with a [WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object). To call the **WlanHostedNetworkSetProperty** function with the *OpCode* parameter of **wlan_hosted_network_opcode_enable**, the client access token of the caller must have elevated privileges exposed by the following enumeration in **WLAN_SECURABLE_OBJECT**:

* **wlan_secure_hosted_network_elevated_access**

If the **WlanHostedNetworkSetProperty** function is passed any of the following values in the *OpCode* parameter, the function will fail with **ERROR_NOT_SUPPORTED**:

* wlan_hosted_network_opcode_station_profile
* wlan_hosted_network_opcode_connection_settings

In order to succeed, the **WlanHostedNetworkSetProperty** function must persist the new settings which requires that the Hosted Network state be transitioned to **wlan_hosted_network_idle** if it was currently running (wlan_hosted_network_active).

Any user can call this function to set the Hosted Network properties. However, to set the **wlan_hosted_network_opcode_enable** flag requires elevated privileges. The ability to enable the wireless Hosted Network may also be restricted by group policy in a domain.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_connection_settings)

[WLAN_HOSTED_NETWORK_OPCODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_opcode)

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanHostedNetworkInitSettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkinitsettings)

[WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty)

[WlanHostedNetworkQuerySecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerysecondarykey)

[WlanHostedNetworkRefreshSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkrefreshsecuritysettings)

[WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)