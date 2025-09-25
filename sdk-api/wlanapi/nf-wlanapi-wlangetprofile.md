# WlanGetProfile function

## Description

The **WlanGetProfile** function retrieves all information about a specified wireless profile.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the wireless interface.

A list of the GUIDs for wireless interfaces on the local computer can be retrieved using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

### `strProfileName` [in]

The name of the profile. Profile names are case-sensitive. This string must be NULL-terminated. The maximum length of the profile name is 255 characters. This means that the maximum length of this string, including the NULL terminator, is 256 characters.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The name of the profile is derived automatically from the SSID of the network. For infrastructure network profiles, the name of the profile is the SSID of the network. For ad hoc network profiles, the name of the profile is the SSID of the ad hoc network followed by `-adhoc`.

### `pReserved` [in]

Reserved for future use. Must be set to **NULL**.

### `pstrProfileXml` [out]

A string that is the XML representation of the queried profile. There is no predefined maximum string length.

### `pdwFlags` [in, out, optional]

On input, a pointer to the address location used to provide additional information about the request. If this parameter is **NULL** on input, then no information on profile flags will be returned. On output, a pointer to the address location used to receive profile flags.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Per-user profiles are not supported. Set this parameter to **NULL**.

The *pdwFlags* parameter can point to an address location that contains the following values:

| Value | Meaning |
| --- | --- |
| **WLAN_PROFILE_GET_PLAINTEXT_KEY** | On input, this flag indicates that the caller wants to retrieve the plain text key from a wireless profile. If the calling thread has the required permissions, the **WlanGetProfile** function returns the plain text key in the [keyMaterial](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#keymaterial) element of the profile returned in the buffer pointed to by the *pstrProfileXml* parameter.<br><br>For the **WlanGetProfile** call to return the plain text key, the **wlan_secure_get_plaintext_key** permissions from the [WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object) enumerated type must be set on the calling thread. The DACL must also contain an ACE that grants **WLAN_READ_ACCESS** permission to the access token of the calling thread. By default, the permissions for retrieving the plain text key is allowed only to the members of the Administrators group on a local machine.<br><br>If the calling thread lacks the required permissions, the **WlanGetProfile** function returns the encrypted key in the [keyMaterial](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#keymaterial) element of the profile returned in the buffer pointed to by the *pstrProfileXml* parameter. No error is returned if the calling thread lacks the required permissions. <br><br>**Windows 7:** This flag passed on input is an extension to native wireless APIs added on Windows 7 and later. The *pdwFlags* parameter is an __inout_opt parameter on Windows 7 and later. |
| **WLAN_PROFILE_GROUP_POLICY** | On output when the **WlanGetProfile** call is successful, this flag indicates that this profile was created by group policy. A group policy profile is read-only. Neither the content nor the preference order of the profile can be changed. |
| **WLAN_PROFILE_USER** | On output when the **WlanGetProfile** call is successful, this flag indicates that the profile is a user profile for the specific user in whose context the calling thread resides. If not set, this profile is an all-user profile. |

### `pdwGrantedAccess` [out, optional]

The access mask of the all-user profile.

| Value | Meaning |
| --- | --- |
| WLAN_READ_ACCESS | The user can view the contents of the profile. |
| WLAN_EXECUTE_ACCESS | The user has read access, and the user can also connect to and disconnect from a network using the profile. If a user has WLAN_EXECUTE_ACCESS, then the user also has WLAN_READ_ACCESS. |
| WLAN_WRITE_ACCESS | The user has execute access and the user can also modify the content of the profile or delete the profile. If a user has WLAN_WRITE_ACCESS, then the user also has WLAN_EXECUTE_ACCESS and WLAN_READ_ACCESS. |

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions. This error is returned if the *pstrProfileXml* parameter specifies an all-user profile, but the caller does not have read access on the profile. |
| **ERROR_INVALID_HANDLE** | A handle is invalid. This error is returned if the handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pInterfaceGuid* is **NULL**.<br>* *pstrProfileXml* is **NULL**.<br>* *pReserved* is not **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. This error is returned if the system was unable to allocate memory for the profile. |
| **ERROR_NOT_FOUND** | The profile specified by *strProfileName* was not found. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

If the **WlanGetProfile** function succeeds, the wireless profile is returned in the buffer pointed to by the *pstrProfileXml* parameter. The buffer contains a string that is the XML representation of the queried profile. For a description of the XML representation of the wireless profile, see [WLAN_profile Schema](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-policyschema-schema).

The caller is responsible for calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function to free the memory allocated for the buffer pointer to by the *pstrProfileXml* parameter when the buffer is no longer needed.

If *pstrProfileXml* specifies an all-user profile, the **WlanGetProfile** caller must have read access on the profile. Otherwise, the **WlanGetProfile** call will fail with a return value of **ERROR_ACCESS_DENIED**. The permissions on an all-user profile are established when the profile is created or saved using [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) or [WlanSaveTemporaryProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansavetemporaryprofile).

**Windows 7:**

The [keyMaterial](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#keymaterial) element returned in the profile schema pointed to by the *pstrProfileXml* may be requested as plaintext if the **WlanGetProfile** function is called with the **WLAN_PROFILE_GET_PLAINTEXT_KEY** flag set in the value pointed to by the *pdwFlags* parameter on input.

For a WEP key, both 5 ASCII characters or 10 hexadecimal characters can be used to set the plaintext key when the profile is created or updated. However, a WEP profile will be saved with 10 hexadecimal characters in the key no matter what the original input was used to create the profile. So in the profile returned by the **WlanGetProfile** function, the plaintext WEP key is always returned as 10 hexadecimal characters.

For the **WlanGetProfile** call to return the plain text key, the **wlan_secure_get_plaintext_key** permissions from the [WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object) enumerated type must be set on the calling thread. The DACL must also contain an ACE that grants **WLAN_READ_ACCESS** permission to the access token of the calling thread. By default, the permissions for retrieving the plain text key is allowed only to the members of the Administrators group on a local machine.

If the calling thread lacks the required permissions, the **WlanGetProfile** function returns the encrypted key in the [keyMaterial](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#keymaterial) element of the profile returned in the buffer pointed to by the *pstrProfileXml* parameter. No error is returned if the calling thread lacks the required permissions.

By default, the [keyMaterial](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#keymaterial) element returned in the profile pointed to by the *pstrProfileXml* is encrypted. If your process runs in the context of the LocalSystem account on the same computer, then you can unencrypt key material by calling the [CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata) function.

**Windows Server 2008 and Windows Vista:** The [keyMaterial](https://learn.microsoft.com/windows/win32/nativewifi/wlan-profileschema-sharedkey-security-element#keymaterial) element returned in the profile schema pointed to by the *pstrProfileXml* is always encrypted. If your process runs in the context of the LocalSystem account, then you can unencrypt key material by calling the [CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata) function.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The key material is never encrypted.

#### Examples

The following example enumerates the wireless LAN interfaces on the local computer, retrieves information for a specific wireless profile on each wireless LAN interface, and prints the values retrieved. The string that is the XML representation of the queried profile is also printed.

**Note** This example will fail to load on Windows Server 2008 and Windows Server 2008 R2 if the Wireless LAN Service is not installed and started.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <wlanapi.h>
#include <objbase.h>
#include <wtypes.h>

#include <stdio.h>
#include <stdlib.h>

// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")

int _cdecl wmain(int argc, WCHAR **argv)
{

    // Declare and initialize variables.

    HANDLE hClient = NULL;
    DWORD dwMaxClient = 2;      //
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;
    DWORD dwRetVal = 0;
    int iRet = 0;

    WCHAR GuidString[39] = {0};

    unsigned int i;

    /* variables used for WlanEnumInterfaces  */

    PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
    PWLAN_INTERFACE_INFO pIfInfo = NULL;

    LPCWSTR pProfileName = NULL;
    LPWSTR pProfileXml = NULL;
    DWORD dwFlags = 0;
    DWORD dwGrantedAccess = 0;

        // Validate the parameters
    if (argc < 2) {
        wprintf(L"usage: %s <profile>\n", argv[0]);
        wprintf(L"   Gets a wireless profile\n");
        wprintf(L"   Example\n");
        wprintf(L"       %s \"Default Wireless\"\n", argv[0]);
        exit(1);
    }

    pProfileName = argv[1];

    wprintf(L"Information for profile: %ws\n\n", pProfileName);

    dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
    if (dwResult != ERROR_SUCCESS) {
        wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
        return 1;
        // You can use FormatMessage here to find out why the function failed
    }

    dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
    if (dwResult != ERROR_SUCCESS) {
        wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
        return 1;
        // You can use FormatMessage here to find out why the function failed
    } else {
        wprintf(L"WLAN_INTERFACE_INFO_LIST for this system\n");

        wprintf(L"Num Entries: %lu\n", pIfList->dwNumberOfItems);
        wprintf(L"Current Index: %lu\n\n", pIfList->dwIndex);
        for (i = 0; i < (int) pIfList->dwNumberOfItems; i++) {
            pIfInfo = (WLAN_INTERFACE_INFO *) &pIfList->InterfaceInfo[i];
            wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
            iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString,
                sizeof(GuidString)/sizeof(*GuidString));
            // For c rather than C++ source code, the above line needs to be
            // iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString,
            //     sizeof(GuidString)/sizeof(*GuidString));
            if (iRet == 0)
                wprintf(L"StringFromGUID2 failed\n");
            else {
                wprintf(L"  InterfaceGUID[%d]: %ws\n",i, GuidString);
            }
            wprintf(L"  Interface Description[%d]: %ws", i,
                pIfInfo->strInterfaceDescription);
            wprintf(L"\n");
            wprintf(L"  Interface State[%d]:\t ", i);
            switch (pIfInfo->isState) {
            case wlan_interface_state_not_ready:
                wprintf(L"Not ready\n");
                break;
            case wlan_interface_state_connected:
                wprintf(L"Connected\n");
                break;
            case wlan_interface_state_ad_hoc_network_formed:
                wprintf(L"First node in a ad hoc network\n");
                break;
            case wlan_interface_state_disconnecting:
                wprintf(L"Disconnecting\n");
                break;
            case wlan_interface_state_disconnected:
                wprintf(L"Not connected\n");
                break;
            case wlan_interface_state_associating:
                wprintf(L"Attempting to associate with a network\n");
                break;
            case wlan_interface_state_discovering:
                wprintf(L"Auto configuration is discovering settings for the network\n");
                break;
            case wlan_interface_state_authenticating:
                wprintf(L"In process of authenticating\n");
                break;
            default:
                wprintf(L"Unknown state %ld\n", pIfInfo->isState);
                break;
            }
            wprintf(L"\n\n");

            dwResult = WlanGetProfile(hClient,
                                             &pIfInfo->InterfaceGuid,
                                             pProfileName,
                                             NULL,
                                             &pProfileXml,
                                             &dwFlags,
                                             &dwGrantedAccess);

            if (dwResult != ERROR_SUCCESS) {
                wprintf(L"WlanGetProfile failed with error: %u\n",
                        dwResult);
                // You can use FormatMessage to find out why the function failed
            } else {
                wprintf(L"  Profile Name:  %ws\n", pProfileName);

                wprintf(L"  Profile XML string:\n");
                wprintf(L"%ws\n\n", pProfileXml);

                wprintf(L"  dwFlags:\t    0x%x", dwFlags);
//                    if (dwFlags & WLAN_PROFILE_GET_PLAINTEXT_KEY)
//                        wprintf(L"   Get Plain Text Key");
                    if (dwFlags & WLAN_PROFILE_GROUP_POLICY)
                        wprintf(L"  Group Policy");
                    if (dwFlags & WLAN_PROFILE_USER)
                        wprintf(L"  Per User Profile");
                    wprintf(L"\n");

                wprintf(L"  dwGrantedAccess:  0x%x", dwGrantedAccess);
                if (dwGrantedAccess & WLAN_READ_ACCESS)
                    wprintf(L"  Read access");
                if (dwGrantedAccess & WLAN_EXECUTE_ACCESS)
                    wprintf(L"  Execute access");
                if (dwGrantedAccess & WLAN_WRITE_ACCESS)
                    wprintf(L"  Write access");
                wprintf(L"\n");

                wprintf(L"\n");
            }
        }

    }
    if (pProfileXml != NULL) {
        WlanFreeMemory(pProfileXml);
        pProfileXml = NULL;
    }

    if (pIfList != NULL) {
        WlanFreeMemory(pIfList);
        pIfList = NULL;
    }

    return dwRetVal;
}

```

## See also

[WLAN_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info)

[WLAN_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info_list)

[WLAN_SECURABLE_OBJECT](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_securable_object)

[WLAN_profile Schema](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-policyschema-schema)

[WlanDeleteProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlandeleteprofile)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)

[WlanRenameProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanrenameprofile)

[WlanSaveTemporaryProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansavetemporaryprofile)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata)

[WlanSetProfileEapUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapuserdata)

[WlanSetProfileEapXmlUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapxmluserdata)

[WlanSetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilelist)

[WlanSetProfilePosition](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileposition)