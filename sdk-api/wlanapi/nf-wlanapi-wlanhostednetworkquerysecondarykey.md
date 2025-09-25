# WlanHostedNetworkQuerySecondaryKey function

## Description

The **WlanHostedNetworkQuerySecondaryKey** function queries the secondary security key that is configured to be used by the wireless Hosted Network.

## Parameters

### `hClientHandle` [in]

The client's session handle, returned by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pdwKeyLength` [out]

A pointer to a value that specifies number of valid data bytes in the key data array pointed to by the *ppucKeyData* parameter, if the call to the **WlanHostedNetworkQuerySecondaryKey** function succeeds.

This key length includes the terminating ‘\0’ if the key is a passphrase.

### `ppucKeyData` [out]

A pointer to a value that receives a pointer to the buffer returned with the secondary security key data, if the call to the **WlanHostedNetworkQuerySecondaryKey** function succeeds.

### `pbIsPassPhrase` [out]

A pointer to a Boolean value that indicates if the key data array pointed to by the *ppucKeyData* parameter is in passphrase format.

If this parameter is **TRUE**, the key data array is in passphrase format. If this parameter is **FALSE**, the key data array is not in passphrase format.

### `pbPersistent` [out]

A pointer to a Boolean value that indicates if the key data array pointed to by the *ppucKeyData* parameter is to be stored and reused later or is for one-time use only.

If this parameter is **TRUE**, the key data array is to be stored and reused later. If this parameter is **FALSE**, the key data array is for one-time use only.

### `pFailReason` [out, optional]

An optional pointer to a value that receives the failure reason, if the call to the [WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey) function fails. Possible values for the failure reason are from the [WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason) enumeration type defined in the *Wlanapi.h*  header file.

### `pvReserved`

Reserved for future use. This parameter must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pdwKeyLength* is **NULL**.<br>* *ppucKeyData* is **NULL** or invalid.<br>* *pbIsPassPhrase* is **NULL** or invalid.<br>* *pbPersistent* is **NULL**.<br>* *pvReserved* is not **NULL**. |
| **ERROR_INVALID_STATE** | The resource is not in the correct state to perform the requested operation. This can occur if the wireless Hosted Network was in the process of shutting down. |
| **ERROR_OUTOFMEMORY** | Not enough storage is available to complete this operation. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This error is returned if the WLAN AutoConfig Service is not running. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **WlanHostedNetworkQuerySecondaryKey** function is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and on Windows Server 2008 R2 with the Wireless LAN Service installed.

A client application calls the **WlanHostedNetworkQuerySecondaryKey** function to query the secondary security key that will be used by the wireless Hosted Network. This function will return the key information including key data, key length, whether it is a passphrase, and whether it is persistent or for one-time use. This function does not change the state or properties of the wireless Hosted Network.

The secondary security key is a passphrase if the value pointed to by the *pbIsPassPhrase* parameter is **TRUE**. The secondary security key is a binary key if the value pointed to by the *pbIsPassPhrase* parameter is **FALSE**.

The secondary security key returned in the buffer pointed to by the *ppucKeyData* parameter is used with WPA2-Personal authentication and is in one of the following formats:

* A key passphrase that consists of an array of ASCII characters from 8 to 63 characters. The value pointed to by the *pdwKeyLength* parameter includes the terminating ‘\0’ in the passphrase. The value pointed to by the *pdwKeyLength* parameter should be in the range of 9 to 64.
* A binary key that consists of 32 bytes of binary key data. The value pointed to by the *pdwKeyLength* parameter should be 32 for binary key.

The secondary security key is persistent if the value pointed to by the *pbPersistent* parameter is **TRUE**. When persistent, the secondary security key would be used immediately if the Hosted Network is already started, and also reused whenever Hosted Network is started in the future.

If secondary security key is not specified as persistent, it will be used immediately if the Hosted Network is already started, or only for the next time when the Hosted Network is started. After the Hosted Network is stopped, this secondary security key will never be used again and will be removed from the system.

If there is no secondary security key currently configured, the returned value pointed to by the *pdwKeyLength* parameter will be zero, and the value returned in the *ppucKeyData* parameter will be **NULL**. In such case, the value returned in the *pbIsPassPhrase* and *pbPersistent* parameters will be meaningless.

If the **WlanHostedNetworkQuerySecondaryKey** function succeeds, the memory used for the buffer in the *ppucKeyData* parameter that is returned should be freed after use by calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function.

Any user can call the **WlanHostedNetworkQuerySecondaryKey** function to query the secondary security key used in the Hosted Network. However, the ability to enable the wireless Hosted Network may be restricted by group policy in a domain.

On Windows 7 and later, the operating system installs a virtual device if a Hosted Network capable wireless adapter is present on the machine. This virtual device normally shows up in the “Network Connections Folder” as ‘Wireless Network Connection 2’ with a Device Name of ‘Microsoft Virtual WiFi Miniport adapter’ if the computer has a single wireless network adapter. This virtual device is used exclusively for performing software access point (SoftAP) connections and is not present in the list returned by the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. The lifetime of this virtual device is tied to the physical wireless adapter. If the physical wireless adapter is disabled, this virtual device will be removed as well. This feature is also available on Windows Server 2008 R2 with the Wireless LAN Service installed.

## See also

[About the Wireless Hosted Network](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-wireless-hosted-network)

[Using Wireless Hosted Network and Internet Connection Sharing](https://learn.microsoft.com/windows/desktop/NativeWiFi/using-hosted-network-and-internet-connection-sharing)

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WlanCloseHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanclosehandle)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanHostedNetworkInitSettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkinitsettings)

[WlanHostedNetworkQueryProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkqueryproperty)

[WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus)

[WlanHostedNetworkRefreshSecuritySettings](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkrefreshsecuritysettings)

[WlanHostedNetworkSetProperty](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetproperty)

[WlanHostedNetworkSetSecondaryKey](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworksetsecondarykey)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)