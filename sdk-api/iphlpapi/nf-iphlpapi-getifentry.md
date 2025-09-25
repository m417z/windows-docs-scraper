# GetIfEntry function

## Description

The
**GetIfEntry** function retrieves information for the specified interface on the local computer.

## Parameters

### `pIfRow` [in, out]

A pointer to a
[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure that, on successful return, receives information for an interface on the local computer. On input, set the **dwIndex** member of **MIB_IFROW** to the index of the interface for which to retrieve information. The value for the **dwIndex** must be retrieved by a previous call to the [GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable), [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2), or [GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) function.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The request could not be completed. This is an internal error. |
| **ERROR_INVALID_DATA** | The data is invalid. This error is returned if the network interface index specified by the **dwIndex** member of the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure pointed to by the *pIfRow* parameter is not a valid interface index on the local computer. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *pIfRow* parameter. |
| **ERROR_NOT_FOUND** | The specified interface could not be found. This error is returned if the network interface index specified by the **dwIndex** member of the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure pointed to by the *pIfRow* parameter could not be found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if IPv4 is not configured on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetIfEntry** function retrieves information for an interface on a local computer.

The **dwIndex** member in the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structure pointed to by the *pIfRow* parameter must be initialized to a valid network interface index retrieved by a previous call to the [GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable), [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2), or [GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) function.

The **GetIfEntry** function will fail if the **dwIndex** member of the [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) pointed to by the *pIfRow* parameter does not match an existing interface index on the local computer.

#### Examples

The following example retrieves the entries from the interface table and prints some of the information available for that entry.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "IPHLPAPI.lib")

#include <iphlpapi.h>

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int main()
{

    // Declare and initialize variables.

    // Declare and initialize variables.
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    unsigned int i, j;

    /* variables used for GetIfTable and GetIfEntry */
    MIB_IFTABLE *pIfTable;
    MIB_IFROW *pIfRow;

    // Allocate memory for our pointers.
    pIfTable = (MIB_IFTABLE *) MALLOC(sizeof (MIB_IFTABLE));
    if (pIfTable == NULL) {
        printf("Error allocating memory needed to call GetIfTable\n");
        exit (1);
    }
    // Before calling GetIfEntry, we call GetIfTable to make
    // sure there are entries to get and retrieve the interface index.

    // Make an initial call to GetIfTable to get the
    // necessary size into dwSize
    dwSize = sizeof (MIB_IFTABLE);
    if (GetIfTable(pIfTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) {
        FREE(pIfTable);
        pIfTable = (MIB_IFTABLE *) MALLOC(dwSize);
        if (pIfTable == NULL) {
            printf("Error allocating memory\n");
            exit (1);
        }
    }
    // Make a second call to GetIfTable to get the actual
    // data we want.
    if ((dwRetVal = GetIfTable(pIfTable, &dwSize, 0)) == NO_ERROR) {
        if (pIfTable->dwNumEntries > 0) {
            pIfRow = (MIB_IFROW *) MALLOC(sizeof (MIB_IFROW));
            if (pIfRow == NULL) {
                printf("Error allocating memory\n");
                if (pIfTable != NULL) {
                    FREE(pIfTable);
                    pIfTable = NULL;
                }
                exit (1);
            }

            printf("\tNum Entries: %ld\n\n", pIfTable->dwNumEntries);
            for (i = 0; i < pIfTable->dwNumEntries; i++) {
                pIfRow->dwIndex = pIfTable->table[i].dwIndex;
                if ((dwRetVal = GetIfEntry(pIfRow)) == NO_ERROR) {
                    printf("\tIndex:\t %ld\n", pIfRow->dwIndex);
                    printf("\tInterfaceName[%d]:\t ", i);
                    if (pIfRow->wszName != NULL)
                        printf("%ws", pIfRow->wszName);
                    printf("\n");

                    printf("\tDescription[%d]:\t ", i);
                    for (j = 0; j < pIfRow->dwDescrLen; j++)
                        printf("%c", pIfRow->bDescr[j]);
                    printf("\n");

                    printf("\tIndex[%d]:\t\t %d\n", i, pIfRow->dwIndex);

                    printf("\tType[%d]:\t\t ", i);
                    switch (pIfRow->dwType) {
                    case IF_TYPE_OTHER:
                        printf("Other\n");
                        break;
                    case IF_TYPE_ETHERNET_CSMACD:
                        printf("Ethernet\n");
                        break;
                    case IF_TYPE_ISO88025_TOKENRING:
                        printf("Token Ring\n");
                        break;
                    case IF_TYPE_PPP:
                        printf("PPP\n");
                        break;
                    case IF_TYPE_SOFTWARE_LOOPBACK:
                        printf("Software Lookback\n");
                        break;
                    case IF_TYPE_ATM:
                        printf("ATM\n");
                        break;
                    case IF_TYPE_IEEE80211:
                        printf("IEEE 802.11 Wireless\n");
                        break;
                    case IF_TYPE_TUNNEL:
                        printf("Tunnel type encapsulation\n");
                        break;
                    case IF_TYPE_IEEE1394:
                        printf("IEEE 1394 Firewire\n");
                        break;
                    default:
                        printf("Unknown type %ld\n", pIfRow->dwType);
                        break;
                    }

                    printf("\tMtu[%d]:\t\t %ld\n", i, pIfRow->dwMtu);

                    printf("\tSpeed[%d]:\t\t %ld\n", i, pIfRow->dwSpeed);

                    printf("\tPhysical Addr:\t\t ");
                    if (pIfRow->dwPhysAddrLen == 0)
                        printf("\n");
//                    for (j = 0; j < (int) pIfRow->dwPhysAddrLen; j++) {
                    for (j = 0; j < pIfRow->dwPhysAddrLen; j++) {
                        if (j == (pIfRow->dwPhysAddrLen - 1))
                            printf("%.2X\n", (int) pIfRow->bPhysAddr[j]);
                        else
                            printf("%.2X-", (int) pIfRow->bPhysAddr[j]);
                    }
                    printf("\tAdmin Status[%d]:\t %ld\n", i,
                           pIfRow->dwAdminStatus);

                    printf("\tOper Status[%d]:\t ", i);
                    switch (pIfRow->dwOperStatus) {
                    case IF_OPER_STATUS_NON_OPERATIONAL:
                        printf("Non Operational\n");
                        break;
                    case IF_OPER_STATUS_UNREACHABLE:
                        printf("Unreasonable\n");
                        break;
                    case IF_OPER_STATUS_DISCONNECTED:
                        printf("Disconnected\n");
                        break;
                    case IF_OPER_STATUS_CONNECTING:
                        printf("Connecting\n");
                        break;
                    case IF_OPER_STATUS_CONNECTED:
                        printf("Connected\n");
                        break;
                    case IF_OPER_STATUS_OPERATIONAL:
                        printf("Operational\n");
                        break;
                    default:
                        printf("Unknown status %ld\n",
                            pIfRow->dwOperStatus);
                        break;
                    }
                    printf("\n");
                }

                else {
                    printf("GetIfEntry failed for index %d with error: %ld\n",
                           i, dwRetVal);
                    // Here you can use FormatMessage to find out why
                    // it failed.

                }
            }
        } else {
            printf("\tGetIfTable failed with error: %ld\n", dwRetVal);
        }

    }

    exit (0);
}

```

## See also

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[GetNumberOfInterfaces](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnumberofinterfaces)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

**SetIfEntry**