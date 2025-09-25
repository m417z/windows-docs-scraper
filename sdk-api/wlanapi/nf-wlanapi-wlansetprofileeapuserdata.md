# WlanSetProfileEapUserData function

## Description

The **WlanSetProfileEapUserData** function sets the Extensible Authentication Protocol (EAP) user credentials as specified by raw EAP data. The user credentials apply to a profile on an interface.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `strProfileName` [in]

The name of the profile associated with the EAP user data. Profile names are case-sensitive. This string must be NULL-terminated.

### `eapType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains the method for which the caller is supplying EAP user credentials.

### `dwFlags` [in]

A set of flags that modify the behavior of the function.

On Windows Vista and Windows Server 2008, this parameter is reserved and should be set to zero.

On Windows 7, Windows Server 2008 R2, and later, this parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WLAN_SET_EAPHOST_DATA_ALL_USERS**<br><br>0x00000001 | Set EAP host data for all users of this profile. |

### `dwEapUserDataSize` [in]

The size, in bytes, of the data pointed to by *pbEapUserData*.

### `pbEapUserData` [in]

A pointer to the raw EAP data used to set the user credentials.

On Windows Vista and Windows Server 2008, this parameter must not be **NULL**.

On Windows 7, Windows Server 2008 R2, and later, this parameter can be set to **NULL** to delete the stored credentials for this profile if the *dwFlags* parameter contains **WLAN_SET_EAPHOST_DATA_ALL_USERS** and the *dwEapUserDataSize* parameter is 0.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This value is returned if the caller does not have write access to the profile. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This value is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pInterfaceGuid* is **NULL**.<br>* *strProfileName* is **NULL**<br>* *pvReserved* is not **NULL**.<br><br>On Windows Vista and Windows Server 2008, this value is returned if the *pbEapUserData* parameter is **NULL**. <br><br>On Windows 7, Windows Server 2008 R2 , and later, this error is returned if the *pbEapUserData* parameter is **NULL**, but the *dwEapUserDataSize* parameter is not 0 or the *dwFlags* parameter does not contain **WLAN_SET_EAPHOST_DATA_ALL_USERS**. |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. <br><br>This value is returned when profile settings do not permit storage of user data. This can occur when single signon (SSO) is enabled or when the request was to delete the stored credentials for this profile (the *pbEapUserData* parameter was **NULL**, the *dwFlags* parameter contains **WLAN_SET_EAPHOST_DATA_ALL_USERS**, and the *dwEapUserDataSize* parameter is 0). <br><br>On Windows 10, Windows Server 2016 , and later, this value is returned if the [WlanSetProfileEapUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapuserdata) function was called on a profile that uses a method other than 802.1X for authentication. <br><br>This value is also returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. This value is returned if the Wireless LAN service is not running. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanSetProfileEapUserData** function sets the EAP user credentials to use on a profile. On Windows Vista and Windows Server 2008, these credentials can only be used by the caller.

The *eapType* parameter is an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains type, identification, and author information about an EAP method. The **eapType** member of the **EAP_METHOD_TYPE** structure is an [EAP_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_type) structure that contains the type and vendor identification information for an EAP method.

For more information on the allocation of EAP method types, see section 6.2 of [RFC 3748](http://tools.ietf.org/html/rfc3748) published by the IETF.

On Windows 7, Windows Server 2008 R2, and later, the **WlanSetProfileEapUserData** function is enhanced. EAP user credentials can be set for all users of a profile if the *dwFlags* parameter contains **WLAN_SET_EAPHOST_DATA_ALL_USERS**. The EAP user credentials on a profile can also be deleted. To delete the EAP user credentials on a profile, the *pbEapUserData* parameter must be **NULL**, the *dwFlags* parameter must equal **WLAN_SET_EAPHOST_DATA_ALL_USERS**, and the *dwEapUserDataSize* parameter must be 0.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanSetProfileEapUserData** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter has been removed from the system (a USB wireless adapter that has been removed, for example).

## See also

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type)

[EAP_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_type)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileEapXmlUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapxmluserdata)