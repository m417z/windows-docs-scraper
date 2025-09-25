# WlanGetProfileCustomUserData function

## Description

The **WlanGetProfileCustomUserData** function gets the custom user data associated with a wireless profile.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

A pointer to the GUID of the wireless LAN interface.

### `strProfileName` [in]

The name of the profile with which the custom user data is associated. Profile names are case-sensitive. This string must be NULL-terminated.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `pdwDataSize` [out]

The size, in bytes, of the user data buffer pointed to by the *ppData* parameter.

### `ppData` [out]

A pointer to the user data.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if no user custom data exists for the profile specified. |
| **ERROR_INVALID_PARAMETER** | The *hClientHandle* parameter is **NULL** or not valid, the *pInterfaceGuid* parameter is **NULL**, the *strProfileName* parameter is **NULL**, the *pReserved* parameter is not **NULL**, the *pdwDataSize* parameter is 0, or the *ppData* parameter is **NULL**. |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if no custom user data exists for the profile specified. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

For every wireless WLAN profile used by the Native Wifi AutoConfig service, Windows maintains the concept of custom user data. This custom user data is initially non-existent, but can be set by calling the [WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata) function. The custom user data gets reset to empty any time the profile is modified by calling the [WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile) function.

Once custom user data has been set, this data can be accessed using the **WlanGetProfileCustomUserData** function.

The caller is responsible for freeing the memory allocated for the buffer pointed to by the *ppData* parameter using the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function.

#### Examples

The following example enumerates the wireless LAN interfaces on the local computer, and then tries to retrieve any custom user data information for a specific wireless profile on each wireless LAN interface. The size of the user custom data is printed.

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

    PBYTE pProfileData = NULL;
    DWORD dwDataSize = 0;

        // Validate the parameters
    if (argc < 2) {
        wprintf(L"usage: %s <profile>\n", argv[0]);
        wprintf(L"   Gets a wireless profile\n");
        wprintf(L"   Example\n");
        wprintf(L"       %s \"Default Wireless\"\n", argv[0]);
        exit(1);
    }

    pProfileName = argv[1];

    wprintf(L"Custom user data information for profile: %ws\n\n", pProfileName);

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
            wprintf(L"\n");

            dwResult = WlanGetProfileCustomUserData(hClient,
                                             &pIfInfo->InterfaceGuid,
                                             pProfileName,
                                             NULL,
                                             &dwDataSize,
                                             &pProfileData);

            if (dwResult != ERROR_SUCCESS) {
                wprintf(L"WlanGetProfileCustomData failed with error: %u\n",
                        dwResult);
                // You can use FormatMessage to find out why the function failed
            } else {
                wprintf(L"Profile Name:  %ws\n", pProfileName);

                wprintf(L"  dwDataSize:\t    0x%x\n", dwDataSize);
                wprintf(L"  Profile Custom Data:\n");
//                wprintf(L"%ws\n\n", pProfileXml);

                wprintf(L"\n");

                wprintf(L"\n");
            }
        }

    }
    if (pProfileData != NULL) {
        WlanFreeMemory(pProfileData);
        pProfileData = NULL;
    }

    if (pIfList != NULL) {
        WlanFreeMemory(pIfList);
        pIfList = NULL;
    }

    return dwRetVal;
}

```

## See also

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)

[WlanSetProfileCustomUserData](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofilecustomuserdata)