# WlanEnumInterfaces function

## Description

The **WlanEnumInterfaces** function enumerates all of the wireless LAN interfaces currently enabled on the local computer.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pReserved` [in]

Reserved for future use. This parameter must be set to **NULL**.

### `ppInterfaceList` [out]

A pointer to storage for a pointer to receive the returned list of wireless LAN interfaces in a [WLAN_INTERFACE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info_list) structure.

The buffer for the [WLAN_INTERFACE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info_list) returned is allocated by the **WlanEnumInterfaces** function if the call succeeds.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *hClientHandle* or *ppInterfaceList* parameter is **NULL**. This error is returned if the *pReserved* is not **NULL**. This error is also returned if the *hClientHandle* parameter is not valid. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **RPC_STATUS** | Various error codes. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to process this request and allocate memory for the query results. |

## Remarks

The **WlanEnumInterfaces** function allocates memory for the list of returned interfaces that is returned in the buffer pointed to by the *ppInterfaceList* parameter when the function succeeds. The memory used for the buffer pointed to by *ppInterfaceList* parameter should be released by calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function after the buffer is no longer needed.

#### Examples

The following example enumerates the wireless LAN interfaces on the local computer and prints values from the retrieved [WLAN_INTERFACE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info_list) structure and the enumerated [WLAN_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info) structures.

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
    DWORD dwMaxClient = 2;   //
    DWORD dwCurVersion = 0;
    DWORD dwResult = 0;
    int iRet = 0;

    WCHAR GuidString[40] = {0};

    int i;

    /* variables used for WlanEnumInterfaces  */

    PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
    PWLAN_INTERFACE_INFO pIfInfo = NULL;

    dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
    if (dwResult != ERROR_SUCCESS)  {
        wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
        // FormatMessage can be used to find out why the function failed
        return 1;
    }

    dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
    if (dwResult != ERROR_SUCCESS)  {
        wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
        // FormatMessage can be used to find out why the function failed
        return 1;
    }
    else {
        wprintf(L"Num Entries: %lu\n", pIfList->dwNumberOfItems);
        wprintf(L"Current Index: %lu\n", pIfList->dwIndex);
        for (i = 0; i < (int) pIfList->dwNumberOfItems; i++) {
            pIfInfo = (WLAN_INTERFACE_INFO *) &pIfList->InterfaceInfo[i];
            wprintf(L"  Interface Index[%d]:\t %lu\n", i, i);
            iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 39);
            // For c rather than C++ source code, the above line needs to be
            // iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 39);
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
        }
    }

    if (pIfList != NULL) {
        WlanFreeMemory(pIfList);
        pIfList = NULL;
    }
    return 0;
}

```

## See also

[WLAN_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info)

[WLAN_INTERFACE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info_list)

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)