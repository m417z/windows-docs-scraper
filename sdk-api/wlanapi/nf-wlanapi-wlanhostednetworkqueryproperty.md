# WlanHostedNetworkQueryProperty function

## Description

The **WlanHostedNetworkQueryProperty** function queries the current static properties of the wireless Hosted Network.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `OpCode` [in]

The identifier for property to be queried. This identifier can be any of the values in the [WLAN_HOSTED_NETWORK_OPCODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_opcode) enumeration defined in the *Wlanapi.h*  header file.

### `pdwDataSize` [out]

A pointer to a value that specifies the size, in bytes, of the buffer returned in the *ppvData* parameter, if the call to the **WlanHostedNetworkQueryProperty** function succeeds.

### `ppvData` [out]

On input, this parameter must be **NULL**.

On output, this parameter receives a pointer to a buffer returned with the static property requested, if the call to the **WlanHostedNetworkQueryProperty** function succeeds. The data type associated with this buffer depends upon the value of *OpCode* parameter.

### `pWlanOpcodeValueType` [out]

A pointer to a value that receives the value type of the wireless Hosted Network property, if the call to the **WlanHostedNetworkQueryProperty** function succeeds. The returned value is an enumerated type in the [WLAN_OPCODE_VALUE_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_opcode_value_type-r1) enumeration defined in the *Wlanapi.h*  header file.

### `pvReserved`

Reserved for future use. This parameter must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data for the wireless Hosted Network is unconfigured. This error is returned if the application calls the [WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty) function with the *OpCode* parameter set to **wlan_hosted_network_opcode_station_profile** or **wlan_hosted_network_opcode_connection_settings** before a SSID is configured in the wireless Hosted Network. |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *OpCode* is not one of the enumerated values defined in the [WLAN_HOSTED_NETWORK_OPCODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_opcode).<br>* *pdwDataSize* is **NULL**.<br>* *ppvData* is **NULL**.<br>* *pWlanOpcodeValueType* is **NULL**.<br>* *pvReserved* is not **NULL**. |
| **ERROR_INVALID_STATE** | The resource is not in the correct state to perform the requested operation. This can occur if the wireless Hosted Network was in the process of shutting down. |
| **ERROR_OUTOFMEMORY** | Not enough storage is available to complete this operation. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **WlanHostedNetworkQueryProperty** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkQueryProperty** function to query the current static properties of the wireless Hosted Network. This function does not change the state or properties of the wireless Hosted Network.

If the function succeeds, the *ppvData* parameter points to a buffer that contains the requested property. The size of this buffer is returned in a pointer returned in the *pwdDataSize* parameter. The [WLAN_OPCODE_VALUE_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_opcode_value_type-r1) is returned in a pointer returned in the *pWlanOpcodeValueType* parameter. The memory used for the buffer in the *ppvData* parameter that is returned should be released by calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function after the buffer is no longer needed.

The data type associated with the buffer pointed to by the *ppvData* parameter depends upon the value of *OpCode* parameter as follows:

| OpCode | Description |
| --- | --- |
| wlan_hosted_network_opcode_connection_settings | A pointer to a [WLAN_HOSTED_NETWORK_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_connection_settings) structure is returned. |
| wlan_hosted_network_opcode_security_settings | A pointer to a [WLAN_HOSTED_NETWORK_SECURITY_SETTINGS](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_security_settings) structure is returned. |
| wlan_hosted_network_opcode_station_profile | A **PWSTR** to contains an XML WLAN profile for connecting to the wireless Hosted Network is returned. |
| wlan_hosted_network_opcode_enable | A **PBOOL** that indicates if wireless Hosted Network is enabled is returned. |

If the **WlanHostedNetworkQueryProperty** function is passed any of the following values in the *OpCode* parameter before a SSID is configured in the wireless Hosted Network, the function will fail with **ERROR_BAD_CONFIGURATION**:

* wlan_hosted_network_opcode_station_profile
* wlan_hosted_network_opcode_connection_settings

Any user can call the **WlanHostedNetworkQueryProperty** function to query the Hosted Network properties.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_CONNECTION_SETTINGS](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_connection_settings)

[WLAN_HOSTED_NETWORK_OPCODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_opcode)

[WLAN_HOSTED_NETWORK_SECURITY_SETTINGS](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_security_settings)

[WLAN_OPCODE_VALUE_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_opcode_value_type-r1)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanHostedNetworkInitSettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkinitsettings)

[WlanHostedNetworkQuerySecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerysecondarykey)

[WlanHostedNetworkRefreshSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkrefreshsecuritysettings)

[WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty)

[WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)