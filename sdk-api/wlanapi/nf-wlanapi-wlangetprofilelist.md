# WlanGetProfileList function

## Description

The **WlanGetProfileList** function retrieves the list of profiles in preference order.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the wireless interface.

A list of the GUIDs for wireless interfaces on the local computer can be retrieved using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

### `pReserved` [in]

Reserved for future use. Must be set to **NULL**.

### `ppProfileList` [out]

A [PWLAN_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info_list) structure that contains the list of profile information.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *hClientHandle* is **NULL**.<br>* *pInterfaceGuid* is **NULL**.<br>* *ppProfileList* is **NULL**.<br>* *pReserved* is not **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to process this request and allocate memory for the query results. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanGetProfileList** function returns only the basic information on the wireless profiles on a wireless interface. The list of wireless profiles on a wireless interface are retrieved in the preference order. The [WlanSetProfilePosition](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileposition) can be used to change the preference order for the wireless profiles on a wireless interface.

More detailed information for a wireless profile on a wireless interface can be retrieved by using the [WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile) function. The [WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata) function can be used to retrieve custom user data for a wireless profile on a wireless interface. A list of the wireless interfaces and associated GUIDs on the local computer can be retrieved using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

The **WlanGetProfileList** function allocates memory for the list of profiles returned in the buffer pointed to by the *ppProfileList* parameter. The caller is responsible for freeing this memory using the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function when this buffer is no longer needed.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Guest profiles, profiles with Wireless Provisioning Service (WPS) authentication, and profiles with Wi-Fi Protected Access-None (WPA-None) authentication are not supported. These types of profiles are not returned by **WlanGetProfileList**, even if a profile of this type appears on the preferred profile list.

#### Examples

The following example enumerates the wireless LAN interfaces on the local computer, retrieves the list of profiles on each wireless LAN interface, and prints values from the retrieved [WLAN_PROFILE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info_list) that contains the [WLAN_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_profile_info) entries.

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

int wmain()
{

    // Declare and initialize variables.

    HANDLE hClient = NULL;
    DWORD dwMaxClient = 2;      //
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;
    DWORD dwRetVal = 0;
    int iRet = 0;

    WCHAR GuidString[39] = {0};

    unsigned int i, j;

    /* variables used for WlanEnumInterfaces  */

    PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
    PWLAN_INTERFACE_INFO pIfInfo = NULL;

    PWLAN_PROFILE_INFO_LIST pProfileList = NULL;
    PWLAN_PROFILE_INFO pProfile = NULL;

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
        wprintf(L"Current Index: %lu\n", pIfList->dwIndex);
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
                wprintf(L"  Interface GUID[%d]: %ws\n",i, GuidString);
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
            wprintf(L"\n");

            dwResult = WlanGetProfileList(hClient,
                                             &pIfInfo->InterfaceGuid,
                                             NULL,
                                             &pProfileList);

            if (dwResult != ERROR_SUCCESS) {
                wprintf(L"WlanGetProfileList failed with error: %u\n",
                        dwResult);
                dwRetVal = 1;
                // You can use FormatMessage to find out why the function failed
            } else {
                wprintf(L"WLAN_PROFILE_INFO_LIST for this interface\n");

                wprintf(L"  Num Entries: %lu\n\n", pProfileList->dwNumberOfItems);

                for (j = 0; j < pProfileList->dwNumberOfItems; j++) {
                    pProfile =
                        (WLAN_PROFILE_INFO *) & pProfileList->ProfileInfo[j];

                    wprintf(L"  Profile Name[%u]:  %ws\n", j, pProfile->strProfileName);

                    wprintf(L"  Flags[%u]:\t    0x%x", j, pProfile->dwFlags);
                    if (pProfile->dwFlags & WLAN_PROFILE_GROUP_POLICY)
                        wprintf(L"   Group Policy");
                    if (pProfile->dwFlags & WLAN_PROFILE_USER)
                        wprintf(L"   Per User Profile");
                    wprintf(L"\n");

                    wprintf(L"\n");
                }
            }
        }

    }
    if (pProfileList != NULL) {
        WlanFreeMemory(pProfileList);
        pProfileList = NULL;
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

[WlanDeleteProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlandeleteprofile)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilecustomuserdata)

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)

[WlanRenameProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanrenameprofile)

[WlanSaveTemporaryProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansavetemporaryprofile)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata)

[WlanSetProfileEapUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapuserdata)

[WlanSetProfileEapXmlUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileeapxmluserdata)

[WlanSetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilelist)

[WlanSetProfilePosition](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofileposition)