# MIB_TCP6TABLE structure

## Description

The
**MIB_TCP6TABLE** structure contains a table of TCP connections for IPv6 on the local computer.

## Members

### `dwNumEntries`

A value that specifies the number of TCP connections in the array.

### `table`

An array of
[MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row) structures containing TCP connection entries.

## Remarks

The **MIB_TCP6TABLE** structure is defined on Windows Vista and later.

The [GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table) function retrieves the IPv6 TCP connection table on the local computer and returns this information in a **MIB_TCP6TABLE** structure.

An array of [MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row) structures are contained in the **MIB_TCP6TABLE** structure.

The **MIB_TCP6TABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row) array entry in the **table** member. Padding for alignment may also be present between the **MIB_TCP6ROW** array entries in the **table** member. Any access to a **MIB_TCP6ROW** array entry should assume padding may exist.

#### Examples

The following example retrieves the TCP connection table for IPv6 as a **MIB_TCP6TABLE** structure and prints the state of each connection represented as a [MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row) structure.

```cpp
#define UNICODE 1

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

int wmain()
{

    // Declare and initialize variables
    PMIB_TCP6TABLE pTcpTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    wchar_t ipstringbuffer[46];

    int i;

    pTcpTable = (MIB_TCP6TABLE *) MALLOC(sizeof (MIB_TCP6TABLE));
    if (pTcpTable == NULL) {
        wprintf(L"Error allocating memory\n");
        return 1;
    }

    dwSize = sizeof (MIB_TCP6TABLE);
// Make an initial call to GetTcp6Table to
// get the necessary size into the dwSize variable
    if ((dwRetVal = GetTcp6Table(pTcpTable, &dwSize, TRUE)) ==
        ERROR_INSUFFICIENT_BUFFER) {
        FREE(pTcpTable);
        pTcpTable = (MIB_TCP6TABLE *) MALLOC(dwSize);
        if (pTcpTable == NULL) {
            wprintf(L"Error allocating memory\n");
            return 1;
        }
    }
// Make a second call to GetTcp6Table to get
// the actual data we require
    if ((dwRetVal = GetTcp6Table(pTcpTable, &dwSize, TRUE)) == NO_ERROR) {
        wprintf(L"\tNumber of entries: %d\n", (int) pTcpTable->dwNumEntries);
        for (i = 0; i < (int) pTcpTable->dwNumEntries; i++) {
            wprintf(L"\n\tTCP[%d] State: %ld - ", i,
                   pTcpTable->table[i].State);
            switch (pTcpTable->table[i].State) {
            case MIB_TCP_STATE_CLOSED:
                wprintf(L"CLOSED\n");
                break;
            case MIB_TCP_STATE_LISTEN:
                wprintf(L"LISTEN\n");
                break;
            case MIB_TCP_STATE_SYN_SENT:
                wprintf(L"SYN-SENT\n");
                break;
            case MIB_TCP_STATE_SYN_RCVD:
                wprintf(L"SYN-RECEIVED\n");
                break;
            case MIB_TCP_STATE_ESTAB:
                wprintf(L"ESTABLISHED\n");
                break;
            case MIB_TCP_STATE_FIN_WAIT1:
                wprintf(L"FIN-WAIT-1\n");
                break;
            case MIB_TCP_STATE_FIN_WAIT2:
                wprintf(L"FIN-WAIT-2 \n");
                break;
            case MIB_TCP_STATE_CLOSE_WAIT:
                wprintf(L"CLOSE-WAIT\n");
                break;
            case MIB_TCP_STATE_CLOSING:
                wprintf(L"CLOSING\n");
                break;
            case MIB_TCP_STATE_LAST_ACK:
                wprintf(L"LAST-ACK\n");
                break;
            case MIB_TCP_STATE_TIME_WAIT:
                wprintf(L"TIME-WAIT\n");
                break;
            case MIB_TCP_STATE_DELETE_TCB:
                wprintf(L"DELETE-TCB\n");
                break;
            default:
                wprintf(L"UNKNOWN dwState value\n");
                break;
            }

            if (InetNtop(AF_INET6, &pTcpTable->table[i].LocalAddr, ipstringbuffer, 46) == NULL)
                wprintf(L"  InetNtop function failed for local IPv6 address\n");
            else
                wprintf(L"\tTCP[%d] Local Addr: %s\n", i, ipstringbuffer);
            wprintf(L"\tTCP[%d] Local Scope ID: %d \n", i,
                   ntohl (pTcpTable->table[i].dwLocalScopeId));
            wprintf(L"\tTCP[%d] Local Port: %d \n", i,
                   ntohs((u_short)pTcpTable->table[i].dwLocalPort));

            if (InetNtop(AF_INET6, &pTcpTable->table[i].RemoteAddr, ipstringbuffer, 46) == NULL)
                wprintf(L"  InetNtop function failed for remote IPv6 address\n");
            else
                wprintf(L"\tTCP[%d] Remote Addr: %s\n", i, ipstringbuffer);
            wprintf(L"\tTCP[%d] Remote Scope ID: %d \n", i,
                   ntohl(pTcpTable->table[i].dwRemoteScopeId));
            wprintf(L"\tTCP[%d] Remote Port: %d\n", i,
                   ntohs((u_short)pTcpTable->table[i].dwRemotePort));
        }
    } else {
        wprintf(L"\tGetTcp6Table failed with %d\n", dwRetVal);
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

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[MIB_TCPTABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable2)