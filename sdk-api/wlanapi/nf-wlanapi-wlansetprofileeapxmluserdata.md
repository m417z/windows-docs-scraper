## Description

The **WlanSetProfileEapXmlUserData** function sets the Extensible Authentication Protocol (EAP) user credentials as specified by an XML string. The user credentials apply to a profile on an adapter. These credentials can be used only by the caller.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `strProfileName` [in]

The name of the profile associated with the EAP user data. Profile names are case-sensitive. This string must be NULL-terminated.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The supplied name must match the profile name derived automatically from the SSID of the network. For an infrastructure network profile, the SSID must be supplied for the profile name. For an ad hoc network profile, the supplied name must be the SSID of the ad hoc network followed by `-adhoc`.

### `dwFlags` [in]

A set of flags that modify the behavior of the function.

On Wireless LAN API for Windows XP with SP2, Windows XP with SP3,Windows Vista, and Windows Server 2008, this parameter is reserved and should be set to zero.

On Windows 7, Windows Server 2008 R2, and later, this parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WLAN_SET_EAPHOST_DATA_ALL_USERS**<br><br>0x00000001 | Set EAP host data for all users of this profile. |

### `strEapXmlUserData` [in]

A pointer to XML data used to set the user credentials.

The XML data must be based on the [EAPHost User Credentials schema](https://learn.microsoft.com/windows/win32/eaphost/eaphostusercredentialsschema-schema). To view sample user credential XML data, see EAPHost [User Properties](https://learn.microsoft.com/windows/win32/eaphost/user-profiles).

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This value is returned if the caller does not have write access to the profile. |
| **ERROR_BAD_PROFILE** | The network connection profile is corrupted. This error is returned if the profile specified in the *strProfileName* parameter could not be parsed. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This value is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pInterfaceGuid* is **NULL**.<br>* *strProfileName* is **NULL**.<br>* *strEapXmlUserData* is **NULL**.<br>* *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. <br><br>This value is returned when profile settings do not permit storage of user data. This can occur when single signon (SSO) is enabled. <br><br>On Windows 7, Windows Server 2008 R2 , and later, this value is returned if the [WlanSetProfileEapXmlUserData](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlansetprofileeapxmluserdata) function was called on a profile that uses a method other than 802.1X for authentication. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This value is returned if the Wireless LAN service is not running. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanSetProfileEapXmlUserData** function sets the EAP user credentials to use on a profile. This function can be called only on a profile that uses 802.1X for authentication. On Windows Vista and Windows Server 2008, these credentials can only be used by the caller.

The *eapType* parameter is an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains type, identification, and author information about an EAP method. The **eapType** member of the **EAP_METHOD_TYPE** structure is an [EAP_TYPE](https://learn.microsoft.com/windows/win32/api/eaptypes/ns-eaptypes-eap_type) structure that contains the type and vendor identification information for an EAP method.

For more information on the allocation of EAP method types, see section 6.2 of [RFC 3748](http://tools.ietf.org/html/rfc3748) published by the IETF.

On Windows 10, Windows Server 2016, and later, the **WlanSetProfileEapXmlUserData** function is enhanced. EAP user credentials can be set for all users of a profile if the *dwFlags* parameter contains **WLAN_SET_EAPHOST_DATA_ALL_USERS**.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanSetProfileEapXmlUserData** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter has been removed from the system (a USB wireless adapter that has been removed, for example).

The **WlanSetProfileEapXmlUserData** might cause wireless connection failure when you use **EAP-TTLS** and the API is called from a 32-bit application running on a 64-bit operating system (OS). Your application should be built for the same CPU architecture as the target OS.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** This function can only be used for Protected EAP (PEAP) credentials. It can't be used for other EAP types.

## See also

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/eaptypes/ns-eaptypes-eap_method_type)

[EAP_TYPE](https://learn.microsoft.com/windows/win32/api/eaptypes/ns-eaptypes-eap_type)

[WlanGetProfile](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata)

[WlanGetProfileList](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetProfile](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata)

[WlanSetProfileEapUserData](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlansetprofileeapuserdata)