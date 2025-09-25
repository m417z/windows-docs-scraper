# GetIfEntry2 function

## Description

The
**GetIfEntry2** function retrieves information for the specified interface on the local computer.

> [!IMPORTANT]
> For driver developers, it is recommended to use [GetIfEntry2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) with MibIfEntryNormalWithoutStatistics when possible, in order to avoid a deadlock when servicing NDIS OIDs.

## Parameters

### `Row`

A pointer to a
[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure that, on successful return, receives information for an interface on the local computer. On input, the **InterfaceLuid** or the **InterfaceIndex** member of the **MIB_IF_ROW2** must be set to the interface for which to retrieve information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) pointed to by the *Row* parameter was not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** parameter is passed in the *Row* parameter. This error is also returned if the both the **InterfaceLuid** and **InterfaceIndex** member of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) pointed to by the *Row* parameter are unspecified. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIfEntry2** function is defined on Windows Vista and later.

On input, at least one of the following members in the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure passed in the *Row* parameter must be initialized: **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output, the remaining fields of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure pointed to by the *Row* parameter are filled in.

Note that the *Netioapi.h* header file is automatically included in *Iphlpapi.h* header file, and should never be used directly.

#### Examples

The following example retrieves a interface entry specified on the command line and prints some values from the retrieved [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#include <objbase.h>
#include <wtypes.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Iphlpapi.lib
#pragma comment(lib, "iphlpapi.lib")

// Need to link with Ole32.lib to print GUID
#pragma comment(lib, "ole32.lib")

void PrintIfEntry2(PMIB_IF_ROW2 pifRow);

int __cdecl wmain(int argc, WCHAR ** argv)
{

    // Declare and initialize variables

    ULONG retVal = 0;
    ULONG ifIndex;

    MIB_IF_ROW2 ifRow;

    // Make sure the ifRow is zeroed out
    SecureZeroMemory((PVOID) &ifRow, sizeof(MIB_IF_ROW2) );

    // Zero out the MIB_IF_ROW2 struct

    // Validate the parameters
    if (argc < 2) {
        wprintf(L"usage: %s <InterfaceIndex>\n", argv[0]);
        wprintf(L"   Gets the Interface Entry for an interface Index,\n");
        wprintf(L"Example to get the interface at interface index=6\n");
        wprintf(L"       %s 6\n", argv[0]);
        exit(1);
    }

    ifIndex = _wtoi(argv[1]);

    ifRow.InterfaceIndex = ifIndex;

    retVal = GetIfEntry2(&ifRow);

    if (retVal != NO_ERROR) {
        wprintf(L"GetIfEntry returned error: %lu\n", retVal);
        exit(1);
    }
    else
        wprintf(L"GetIfEntry2 function returned okay\n");

    PrintIfEntry2(&ifRow);

    exit(0);
}

// Print some parameters from the MIB_IF_ROW2 structure
void PrintIfEntry2(PMIB_IF_ROW2 pIfRow)
{

    int iRet = 0;
    WCHAR GuidString[40] = { 0 };

    unsigned int j;

    wprintf(L"\tInterfaceIndex:\t %lu\n", pIfRow->InterfaceIndex);

    iRet = StringFromGUID2(pIfRow->InterfaceGuid, (LPOLESTR) & GuidString, 39);
    // For c rather than C++ source code, the above line needs to be
    // iRet = StringFromGUID2(&pIfRow->InterfaceGuid, (LPOLESTR) &GuidString, 39);
    if (iRet == 0)
        wprintf(L"StringFromGUID2 failed\n");
    else {
        wprintf(L"\tInterfaceGUID:   %ws\n", GuidString);
    }

    wprintf(L"\tAlias:\t\t %ws", pIfRow->Alias);
    wprintf(L"\n");
    wprintf(L"\tDescription:\t %ws", pIfRow->Description);
    wprintf(L"\n");
    wprintf(L"\tPhysical Address:\t    ");
    if (pIfRow->PhysicalAddressLength == 0)
        wprintf(L"\n");
    for (j = 0; j < (int) pIfRow->PhysicalAddressLength; j++) {
        if (j == (pIfRow->PhysicalAddressLength - 1))
            wprintf(L"%.2X\n", (int) pIfRow->PhysicalAddress[j]);
        else
            wprintf(L"%.2X-", (int) pIfRow->PhysicalAddress[j]);
    }
    wprintf(L"\tPermanent Physical Address: ");
    if (pIfRow->PhysicalAddressLength == 0)
        wprintf(L"\n");
    for (j = 0; j < (int) pIfRow->PhysicalAddressLength; j++) {
        if (j == (pIfRow->PhysicalAddressLength - 1))
            wprintf(L"%.2X\n", (int) pIfRow->PermanentPhysicalAddress[j]);
        else
            wprintf(L"%.2X-", (int) pIfRow->PermanentPhysicalAddress[j]);
    }
    wprintf(L"\tMtu:\t\t %lu\n", pIfRow->Mtu);

    wprintf(L"\tType:\t\t ");
    switch (pIfRow->Type) {
    case IF_TYPE_OTHER:
        wprintf(L"Other\n");
        break;
    case IF_TYPE_ETHERNET_CSMACD:
        wprintf(L"Ethernet\n");
        break;
    case IF_TYPE_ISO88025_TOKENRING:
        wprintf(L"Token Ring\n");
        break;
    case IF_TYPE_PPP:
        wprintf(L"PPP\n");
        break;
    case IF_TYPE_SOFTWARE_LOOPBACK:
        wprintf(L"Software Lookback\n");
        break;
    case IF_TYPE_ATM:
        wprintf(L"ATM\n");
        break;
    case IF_TYPE_IEEE80211:
        wprintf(L"IEEE 802.11 Wireless\n");
        break;
    case IF_TYPE_TUNNEL:
        wprintf(L"Tunnel type encapsulation\n");
        break;
    case IF_TYPE_IEEE1394:
        wprintf(L"IEEE 1394 Firewire\n");
        break;
    default:
        wprintf(L"Unknown type %ld\n", pIfRow->Type);
        break;
    }

    wprintf(L"\tTunnel Type:\t ");
    switch (pIfRow->TunnelType) {
    case TUNNEL_TYPE_NONE:
        wprintf(L"Not a tunnel\n");
        break;
    case TUNNEL_TYPE_OTHER:
        wprintf(L"None of the known tunnel types\n");
        break;
    case TUNNEL_TYPE_DIRECT:
        wprintf(L"Encapsulated directly within IPv4\n");
        break;
    case TUNNEL_TYPE_6TO4:
        wprintf
            (L"IPv6 packet encapsulated within IPv4 using 6to4 protocol\n");
        break;
    case TUNNEL_TYPE_ISATAP:
        wprintf
            (L"IPv6 packet encapsulated within IPv4 using ISATAP protocol\n");
        break;
    case TUNNEL_TYPE_TEREDO:
        wprintf(L"Teredo encapsulation\n");
        break;
    default:
        wprintf(L"Unknown tunnel type %ld\n", pIfRow->TunnelType);
        break;
    }

    wprintf(L"\tNDIS Media Type:\t ");
    switch (pIfRow->MediaType) {
    case NdisMedium802_3:
        wprintf(L"Ethernet (802.3)\n");
        break;
    case NdisMedium802_5:
        wprintf(L"Token Ring (802.5)\n");
        break;
    case NdisMediumFddi:
        wprintf(L"Fiber Distributed Data Interface (FDDI)\n");
        break;
    case NdisMediumWan:
        wprintf(L"Wide area network (WAN)\n");
        break;
    case NdisMediumLocalTalk:
        wprintf(L"LocalTalk\n");
        break;
    case NdisMediumDix:
        wprintf(L"Ethernet using DIX header format\n");
        break;
    case NdisMediumArcnetRaw:
        wprintf(L"ARCNET\n");
        break;
    case NdisMediumArcnet878_2:
        wprintf(L"ARCNET (878.2)\n");
        break;
    case NdisMediumAtm:
        wprintf(L"ATM\n");
        break;
    case NdisMediumWirelessWan:
        wprintf(L"Wireless WAN\n");
        break;
    case NdisMediumIrda:
        wprintf(L"Infrared (IrDA)\n");
        break;
    case NdisMediumBpc:
        wprintf(L"Broadcast PC\n");
        break;
    case NdisMediumCoWan:
        wprintf(L"Connection-oriented Wide Area Network (CoWAN)\n");
        break;
    case NdisMedium1394:
        wprintf(L"IEEE 1394 (fire wire)\n");
        break;
    case NdisMediumInfiniBand:
        wprintf(L"InfiniBand\n");
        break;
    case NdisMediumTunnel:
        wprintf(L"A Tunnel\n");
        break;
    case NdisMediumNative802_11:
        wprintf(L"Native IEEE 802.11\n");
        break;
    case NdisMediumLoopback:
        wprintf(L"NDIS loopback \n");
        break;
    default:
        wprintf(L"Unknown media type %ld\n", pIfRow->MediaType);
        break;
    }

    printf("\tAdministrative Status:\t ");
    switch (pIfRow->AdminStatus) {
    case NET_IF_ADMIN_STATUS_UP:
        wprintf(L"Interface up and enabled\n");
        break;
    case NET_IF_ADMIN_STATUS_DOWN:
        wprintf(L"Interface down\n");
        break;
    case NET_IF_ADMIN_STATUS_TESTING:
        wprintf(L"Interface in test mode\n");
        break;
    default:
        wprintf(L"Unknown status %ld\n", pIfRow->AdminStatus);
        break;
    }

    printf("\tMedia connection state:\t ");
    switch (pIfRow->MediaConnectState) {
    case MediaConnectStateUnknown:
        wprintf(L"Interface state is unknown\n");
        break;
    case MediaConnectStateConnected:
        wprintf(L"Connected\n");
        break;
    case MediaConnectStateDisconnected:
        wprintf(L"Disconnected\n");
        break;
    default:
        wprintf(L"Unknown state %ld\n", pIfRow->MediaConnectState);
        break;
    }

    wprintf(L"\tTransmit link speed:\t %I64u\n", pIfRow->TransmitLinkSpeed);
    wprintf(L"\tReceive link speed:\t %I64u\n", pIfRow->ReceiveLinkSpeed);

}

```

## See also

**GetIfEntry**

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)