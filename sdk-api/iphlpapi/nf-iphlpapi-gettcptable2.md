# GetTcpTable2 function

## Description

The
**GetTcpTable2** function retrieves the IPv4 TCP connection table.

## Parameters

### `TcpTable` [out]

A pointer to a buffer that receives the TCP connection table as a
[MIB_TCPTABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable2) structure.

### `SizePointer` [in, out]

On input, specifies the size of the buffer pointed to by the *TcpTable* parameter.

On output, if the buffer is not large enough to hold the returned connection table, the function sets this parameter equal to the required buffer size.

### `Order` [in]

A value that specifies whether the TCP connection table should be sorted. If this parameter is **TRUE**, the table is sorted in the order of:

1. Local IP address
2. Local port
3. Remote IP address
4. Remote port

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *TcpTable* parameter is not large enough. The required size is returned in the **PULONG** variable pointed to by the *SizePointer* parameter.<br><br>This error is also returned if the *pTcpTable* parameter is **NULL**. |
| **ERROR_INVALID_PARAMETER** | The *SizePointer* parameter is **NULL**, or [GetTcpTable2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable2) is unable to write to the memory pointed to by the *SizePointer* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetTcpTable2** function is defined on Windows Vista and later.

The **GetTcpTable2** function is an enhanced version of the [GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable) function that also retrieves information on the TCP offload state of the TCP connection.

#### Examples

The following example retrieves the TCP connection table for IPv4 and prints the state of each connection.

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
                printf("UNKNOWN dwState value\n");
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

[GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable)

[GetOwnerModuleFromTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getownermodulefromtcpentry)

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable)

[MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2)

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module)

[MIB_TCP6TABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_pid)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2)

[MIB_TCPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_module)

[MIB_TCPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_pid)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[MIB_TCPTABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable2)

[MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module)

[MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid)

[SetTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-settcpentry)