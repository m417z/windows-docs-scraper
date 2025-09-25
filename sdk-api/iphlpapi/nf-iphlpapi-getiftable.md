# GetIfTable function

## Description

The
**GetIfTable** function retrieves the MIB-II interface table.

## Parameters

### `pIfTable` [out]

A pointer to a buffer that receives the interface table as a
[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable) structure.

### `pdwSize` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *pIfTable* parameter.

On output, if the buffer is not large enough to hold the returned interface table, the function sets this parameter equal to the required buffer size in bytes.

### `bOrder` [in]

A Boolean value that specifies whether the returned interface table should be sorted in ascending order by interface index. If this parameter is **TRUE**, the table is sorted.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pIfTable* parameter is not large enough. The required size is returned in the **DWORD** variable pointed to by the *pdwSize* parameter. |
| **ERROR_INVALID_PARAMETER** | The *pdwSize* parameter is **NULL**, or [GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable) is unable to write to the memory pointed to by the *pdwSize* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The
**GetIfTable** function enumerates physical interfaces on a local system and returns this information in a [MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable) structure. The physical interfaces include the software loopback interface.

The [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2) and [GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) functions available on Windows Vista and later are an enhanced version of the **GetIfTable** function that enumerate both the physical and logical interfaces on a local system. Logical interfaces include various WAN Miniport interfaces used for L2TP, PPTP, PPOE, and other tunnel encapsulations.

Interfaces are returned in a [MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable) structure in the buffer pointed to by the *pIfTable* parameter. The **MIB_IFTABLE** structure contains an interface count and an array of [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structures for each interface.

Note that the returned [MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable) structure pointed to by the *pIfTable* parameter may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) array entry in the **table** member of the **MIB_IFTABLE** structure. Padding for alignment may also be present between the **MIB_IFROW** array entries. Any access to a **MIB_IFROW** array entry should assume padding may exist.

#### Examples

The following example retrieves the interface table and prints the number of entries in the table and some data on each entry.

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
        return 1;
    }
    // Make an initial call to GetIfTable to get the
    // necessary size into dwSize
    dwSize = sizeof (MIB_IFTABLE);
    if (GetIfTable(pIfTable, &dwSize, FALSE) == ERROR_INSUFFICIENT_BUFFER) {
        FREE(pIfTable);
        pIfTable = (MIB_IFTABLE *) MALLOC(dwSize);
        if (pIfTable == NULL) {
            printf("Error allocating memory needed to call GetIfTable\n");
            return 1;
        }
    }
    // Make a second call to GetIfTable to get the actual
    // data we want.
    if ((dwRetVal = GetIfTable(pIfTable, &dwSize, FALSE)) == NO_ERROR) {
        printf("\tNum Entries: %ld\n\n", pIfTable->dwNumEntries);
        for (i = 0; i < pIfTable->dwNumEntries; i++) {
            pIfRow = (MIB_IFROW *) & pIfTable->table[i];
            printf("\tIndex[%d]:\t %ld\n", i, pIfRow->dwIndex);
            printf("\tInterfaceName[%d]:\t %ws", i, pIfRow->wszName);
            printf("\n");
            printf("\tDescription[%d]:\t ", i);
            for (j = 0; j < pIfRow->dwDescrLen; j++)
                printf("%c", pIfRow->bDescr[j]);
            printf("\n");
            printf("\tType[%d]:\t ", i);
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
            printf("\tSpeed[%d]:\t %ld\n", i, pIfRow->dwSpeed);
            printf("\tPhysical Addr:\t ");
            if (pIfRow->dwPhysAddrLen == 0)
                printf("\n");
            for (j = 0; j < pIfRow->dwPhysAddrLen; j++) {
                if (j == (pIfRow->dwPhysAddrLen - 1))
                    printf("%.2X\n", (int) pIfRow->bPhysAddr[j]);
                else
                    printf("%.2X-", (int) pIfRow->bPhysAddr[j]);
            }
            printf("\tAdmin Status[%d]:\t %ld\n", i, pIfRow->dwAdminStatus);
            printf("\tOper Status[%d]:\t ", i);
            switch (pIfRow->dwOperStatus) {
            case IF_OPER_STATUS_NON_OPERATIONAL:
                printf("Non Operational\n");
                break;
            case IF_OPER_STATUS_UNREACHABLE:
                printf("Unreachable\n");
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
                printf("Unknown status %ld\n", pIfRow->dwAdminStatus);
                break;
            }
            printf("\n");
        }
    } else {
        printf("GetIfTable failed with error: \n", dwRetVal);
        if (pIfTable != NULL) {
            FREE(pIfTable);
            pIfTable = NULL;
        }
        return 1;
        // Here you can use FormatMessage to find out why
        // it failed.
    }
    if (pIfTable != NULL) {
        FREE(pIfTable);
        pIfTable = NULL;
    }
    return 0;
}

```

## See also

[GetIfEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getifentry)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[GetNumberOfInterfaces](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnumberofinterfaces)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)