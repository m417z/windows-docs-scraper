# MIB_TCPTABLE2 structure

## Description

The
**MIB_TCPTABLE2** structure contains a table of IPv4 TCP connections on the local computer.

## Members

### `dwNumEntries`

The number of entries in the table.

### `table`

A pointer to a table of TCP connections implemented as an array of
[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2) structures.

## Remarks

The [GetTcpTable2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable2) function retrieves the IPv4 TCP connection table on the local computer and returns this information in a **MIB_TCPTABLE2** structure. An array of [MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2) structures are contained in the **MIB_TCPTABLE2** structure.

The **MIB_TCPTABLE2** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2) array entry in the **table** member. Padding for alignment may also be present between the **MIB_TCPROW2** array entries in the **table** member. Any access to a **MIB_TCPROW2** array entry should assume padding may exist.

#### Examples

The following example retrieves the TCP connection table for IPv4 as a **MIB_TCPTABLE2** structure prints the state of each connection represented as a [MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2) structure.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

// Need to link with Iphlpapi.lib and Ws2_32.lib
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
/* Note: could also use malloc() and free() */

int main()
{

    // Declare and initialize variables
    PMIB_TCPTABLE2 pTcpTable;
    ULONG ulSize = 0;
    DWORD dwRetVal = 0;

    char szLocalAddr[128];
    char szRemoteAddr[128];

    struct in_addr IpAddr;

    int i;

    pTcpTable = (MIB_TCPTABLE2 *) MALLOC(sizeof (MIB_TCPTABLE2));
    if (pTcpTable == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    ulSize = sizeof (MIB_TCPTABLE);
// Make an initial call to GetTcpTable2 to
// get the necessary size into the ulSize variable
    if ((dwRetVal = GetTcpTable2(pTcpTable, &ulSize, TRUE)) ==
        ERROR_INSUFFICIENT_BUFFER) {
        FREE(pTcpTable);
        pTcpTable = (MIB_TCPTABLE2 *) MALLOC(ulSize);
        if (pTcpTable == NULL) {
            printf("Error allocating memory\n");
            return 1;
        }
    }
// Make a second call to GetTcpTable2 to get
// the actual data we require
    if ((dwRetVal = GetTcpTable2(pTcpTable, &ulSize, TRUE)) == NO_ERROR) {
        printf("\tNumber of entries: %d\n", (int) pTcpTable->dwNumEntries);
        for (i = 0; i < (int) pTcpTable->dwNumEntries; i++) {
            printf("\n\tTCP[%d] State: %ld - ", i,
                   pTcpTable->table[i].dwState);
            switch (pTcpTable->table[i].dwState) {
            case MIB_TCP_STATE_CLOSED:
                printf("CLOSED\n");
                break;
            case MIB_TCP_STATE_LISTEN:
                printf("LISTEN\n");
                break;
            case MIB_TCP_STATE_SYN_SENT:
                printf("SYN-SENT\n");
                break;
            case MIB_TCP_STATE_SYN_RCVD:
                printf("SYN-RECEIVED\n");
                break;
            case MIB_TCP_STATE_ESTAB:
                printf("ESTABLISHED\n");
                break;
            case MIB_TCP_STATE_FIN_WAIT1:
                printf("FIN-WAIT-1\n");
                break;
            case MIB_TCP_STATE_FIN_WAIT2:
                printf("FIN-WAIT-2 \n");
                break;
            case MIB_TCP_STATE_CLOSE_WAIT:
                printf("CLOSE-WAIT\n");
                break;
            case MIB_TCP_STATE_CLOSING:
                printf("CLOSING\n");
                break;
            case MIB_TCP_STATE_LAST_ACK:
                printf("LAST-ACK\n");
                break;
            case MIB_TCP_STATE_TIME_WAIT:
                printf("TIME-WAIT\n");
                break;
            case MIB_TCP_STATE_DELETE_TCB:
                printf("DELETE-TCB\n");
                break;
            default:
                wprintf(L"UNKNOWN dwState value: %d\n", pTcpTable->table[i].dwState);
                break;
            }

            IpAddr.S_un.S_addr = (u_long) pTcpTable->table[i].dwLocalAddr;
            strcpy_s(szLocalAddr, sizeof (szLocalAddr), inet_ntoa(IpAddr));
            printf("\tTCP[%d] Local Addr: %s\n", i, szLocalAddr);

            printf("\tTCP[%d] Local Port: %d \n", i,
                   ntohs((u_short)pTcpTable->table[i].dwLocalPort));

            IpAddr.S_un.S_addr = (u_long) pTcpTable->table[i].dwRemoteAddr;
            strcpy_s(szRemoteAddr, sizeof (szRemoteAddr), inet_ntoa(IpAddr));
            printf("\tTCP[%d] Remote Addr: %s\n", i, szRemoteAddr);

            printf("\tTCP[%d] Remote Port: %d\n", i,
                   ntohs((u_short)pTcpTable->table[i].dwRemotePort));

            printf("\tTCP[%d] Owning PID: %d\n", i, pTcpTable->table[i].dwOwningPid);

            printf("\tTCP[%d] Offload State: %ld - ", i,
                   pTcpTable->table[i].dwOffloadState);
            switch (pTcpTable->table[i].dwOffloadState) {
            case TcpConnectionOffloadStateInHost:
                printf("Owned by the network stack and not offloaded \n");
                break;
            case TcpConnectionOffloadStateOffloading:
                printf("In the process of being offloaded\n");
                break;
            case TcpConnectionOffloadStateOffloaded:
                printf("Offloaded to the network interface control\n");
                break;
            case TcpConnectionOffloadStateUploading:
                printf("In the process of being uploaded back to the network stack \n");
                break;
            default:
                printf("UNKNOWN Offload state value\n");
                break;
            }

        }
    } else {
        printf("\tGetTcpTable2 failed with %d\n", dwRetVal);
        FREE(pTcpTable);
        return 1;
    }

    if (pTcpTable != NULL) {
        FREE(pTcpTable);
        pTcpTable = NULL;
    }

    return 0;
}

```

## See also

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2)

[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable)

[GetTcpTable2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable2)

[MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row)

[MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2)

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)