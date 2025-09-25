# WlanDeleteProfile function

## Description

The **WlanDeleteProfile** function deletes a wireless profile for a wireless interface on the local computer.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface from which to delete the profile.

### `strProfileName` [in]

The name of the profile to be deleted. Profile names are case-sensitive. This string must be NULL-terminated.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The supplied name must match the profile name derived automatically from the SSID of the network. For an infrastructure network profile, the SSID must be supplied for the profile name. For an ad hoc network profile, the supplied name must be the SSID of the ad hoc network followed by `-adhoc`.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hClientHandle* parameter is **NULL** or not valid, the *pInterfaceGuid* parameter is **NULL**, the *strProfileName* parameter is **NULL**, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle specified in the *hClientHandle* parameter was not found in the handle table. |
| **ERROR_NOT_FOUND** | The wireless profile specified by *strProfileName* was not found in the profile store. |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to delete the profile. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The **WlanDeleteProfile** function deletes a wireless profile for a wireless interface on the local computer.

All wireless LAN functions require an interface GUID for the wireless interface when performing profile operations. When a wireless interface is removed, its state is cleared from Wireless LAN Service (WLANSVC) and no profile operations are possible.

The **WlanDeleteProfile** function can fail with **ERROR_INVALID_PARAMETER** if the wireless interface specified in the *pInterfaceGuid* parameter for the wireless LAN profile has been removed from the system (a USB wireless adapter that has been removed, for example).

To delete a profile at the command line, use the **netsh wlan delete profile** command. For more information, see [Netsh Commands for Wireless Local Area Network (wlan)](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755301(v=ws.10)).

#### Examples

The following example enumerates the wireless LAN interfaces on the local computer and tries to delete a specific wireless profile on each wireless LAN interface.

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

int _cdecl wmain(int argc, WCHAR ** argv)
{

    // Declare and initialize variables.

    HANDLE hClient = NULL;
    DWORD dwMaxClient = 2;      //
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;
    DWORD dwRetVal = 0;
    int iRet = 0;

    WCHAR GuidString[39] = { 0 };

    unsigned int i;

    /* variables used for WlanEnumInterfaces  */

    PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
    PWLAN_INTERFACE_INFO pIfInfo = NULL;

    LPCWSTR pProfileName = NULL;

    // Validate the parameters
    if (argc < 2) {
        wprintf(L"usage: %s <profile>\n", argv[0]);
        wprintf(L"   Deletes a wireless profile\n");
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
        wprintf(L"Current Index: %lu\n", pIfList->dwIndex);
        for (i = 0; i < pIfList->dwNumberOfItems; i++) {
            pIfInfo = (WLAN_INTERFACE_INFO *) & pIfList->InterfaceInfo[i];
            wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
            iRet =
                StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR) & GuidString,
                                sizeof (GuidString) / sizeof (*GuidString));
            // For c rather than C++ source code, the above line needs to be
            // iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString,
            //     sizeof(GuidString)/sizeof(*GuidString));
            if (iRet == 0)
                wprintf(L"StringFromGUID2 failed\n");
            else {
                wprintf(L"  InterfaceGUID[%d]: %ws\n", i, GuidString);
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
                wprintf
                    (L"Auto configuration is discovering settings for the network\n");
                break;
            case wlan_interface_state_authenticating:
                wprintf(L"In process of authenticating\n");
                break;
            default:
                wprintf(L"Unknown state %ld\n", pIfInfo->isState);
                break;
            }
            wprintf(L"\n");

            dwResult = WlanDeleteProfile(hClient,
                                         &pIfInfo->InterfaceGuid,
                                         pProfileName, NULL);

            if (dwResult != ERROR_SUCCESS) {
                wprintf
                    (L"WlanDeleteProfile failed on this interface with error: %u\n",
                     dwResult);
                if (dwResult == ERROR_NOT_FOUND)
                    wprintf
                        (L"  Error was the following profile was not found: %ws\n",
                         pProfileName);
                // You can use FormatMessage to find out why the function failed
            } else {
                wprintf(L"Successfully deleted Profile Name: %ws\n",
                        pProfileName);
            }
            wprintf(L"\n");
        }

    }
    if (pIfList != NULL) {
        WlanFreeMemory(pIfList);
        pIfList = NULL;
    }

    return dwRetVal;
}

```

## See also

[Native Wifi API Permissions](https://learn.microsoft.com/windows/desktop/NativeWiFi/native-wifi-api-permissions)

[WlanGetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofile)

[WlanGetProfileList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetprofilelist)

[WlanRenameProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanrenameprofile)

[WlanSetProfile](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetprofile)