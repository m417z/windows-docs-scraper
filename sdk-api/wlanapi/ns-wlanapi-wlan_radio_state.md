# WLAN_RADIO_STATE structure

## Description

The **WLAN_RADIO_STATE** structure specifies the radio state on a list of physical layer (PHY) types.

## Members

### `dwNumberOfPhys`

The number of valid PHY indices in the **PhyRadioState** member.

### `PhyRadioState`

An array of [WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state) structures that specify the radio states of a number of PHY indices. Only the first **dwNumberOfPhys** entries in this array are valid. WLAN_MAX_PHY_INDEX is set to 64.

## Remarks

The **WLAN_RADIO_STATE** structure is used with the [WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface) function when the *OpCode* parameter is set to **wlan_intf_opcode_radio_state**. If the call is successful, the *ppData* parameter points to a **WLAN_RADIO_STATE** structure.

The [WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state) structure members in the **WLAN_RADIO_STATE** structure can be used with the [WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface) function when the *OpCode* parameter is set to **wlan_intf_opcode_radio_state** to change the radio state.

The [WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state) structure is also used for notification by the media specific module (MSM) when the radio state changes. An application registers to receive MSM notifications by calling the [WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification) function with the *dwNotifSource* parameter set to a value that includes **WLAN_NOTIFICATION_SOURCE_MSM**. For more information on these notifications, see the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure and the [WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1) enumeration reference.

#### Examples

The following example enumerates the wireless LAN interfaces on the local computer, queries each interface for the **WLAN_RADIO_STATE** on the interface, and prints values from the retrieved **WLAN_RADIO_STATE** structure.

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

    WCHAR GuidString[39] = { 0 };

    unsigned int i;

    // variables used for WlanEnumInterfaces

    PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
    PWLAN_INTERFACE_INFO pIfInfo = NULL;

    // variables used for WlanQueryInterfaces for opcode = wlan_intf_opcode_radio_state
    PWLAN_RADIO_STATE pradioStateInfo = NULL;
    DWORD radioStateInfoSize = sizeof (WLAN_RADIO_STATE);
    WLAN_OPCODE_VALUE_TYPE opCode = wlan_opcode_value_type_invalid;

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
        wprintf(L"Num Entries: %lu\n", pIfList->dwNumberOfItems);
        wprintf(L"Current Index: %lu\n", pIfList->dwIndex);
        for (i = 0; i < (int) pIfList->dwNumberOfItems; i++) {
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
                wprintf(L"  InterfaceGUID[%d]:\t %ws\n", i, GuidString);
            }
            wprintf(L"  Interface Description[%d]: %ws", i, pIfInfo->strInterfaceDescription);
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

            dwResult = WlanQueryInterface(hClient,
                                          &pIfInfo->InterfaceGuid,
                                          wlan_intf_opcode_radio_state,
                                          NULL,
                                          &radioStateInfoSize,
                                          (PVOID *) & pradioStateInfo, &opCode);

            if (dwResult != ERROR_SUCCESS) {
                wprintf(L"WlanQueryInterface failed with error: %u\n", dwResult);
                dwRetVal = 1;
                // You can use FormatMessage to find out why the function failed
            } else {
                wprintf(L"  WLAN_RADIO_STATE for this interface\n");

                wprintf(L"  Number of valid PHYs:\t %u\n", pradioStateInfo->dwNumberOfPhys);
                wprintf(L"  Radio state:\n");
                wprintf(L"      Index of PHYs type[0]:\t %u\n",
                        pradioStateInfo->PhyRadioState[0].dwPhyIndex);

                wprintf(L"      Software radio state[0]:\t ");
                switch (pradioStateInfo->PhyRadioState[0].dot11SoftwareRadioState) {
                case dot11_radio_state_unknown:
                    wprintf(L"Unknown\n");
                    break;
                case dot11_radio_state_on:
                    wprintf(L"On\n");
                    break;
                case dot11_radio_state_off:
                    wprintf(L"Off\n");
                    break;
                default:
                    wprintf(L"Other Unknown state %ld\n", pradioStateInfo->PhyRadioState[0].dot11SoftwareRadioState);
                    break;
                }

                wprintf(L"      Hardware radio state[0]:\t ");
                switch (pradioStateInfo->PhyRadioState[0].dot11HardwareRadioState) {
                case dot11_radio_state_unknown:
                    wprintf(L"Unknown\n");
                    break;
                case dot11_radio_state_on:
                    wprintf(L"On\n");
                    break;
                case dot11_radio_state_off:
                    wprintf(L"Off\n");
                    break;
                default:
                    wprintf(L"Other Unknown state %ld\n", pradioStateInfo->PhyRadioState[0].dot11HardwareRadioState);
                    break;
                }

                wprintf(L"\n");
            }
        }
    }

if (pradioStateInfo != NULL) {
    WlanFreeMemory(pradioStateInfo);
    pradioStateInfo = NULL;
}

if (pIfList != NULL) {
    WlanFreeMemory(pIfList);
    pIfList = NULL;
}

return dwRetVal;
}

```

## See also

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WLAN_NOTIFICATION_MSM](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_notification_msm-r1)

[WLAN_PHY_RADIO_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_phy_radio_state)

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)

[WlanSetInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetinterface)