# GetTcpTable function

## Description

The
**GetTcpTable** function retrieves the IPv4 TCP connection table.

## Parameters

### `TcpTable` [out]

A pointer to a buffer that receives the TCP connection table as a
[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) structure.

### `SizePointer` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *pTcpTable* parameter.

On output, if the buffer is not large enough to hold the returned connection table, the function sets this parameter equal to the required buffer size in bytes.

On the Windows SDK released for Windows Vista and later, the data type for this parameter is changed to a **PULONG** which is equivalent to a **PDWORD**.

### `Order` [in]

A Boolean value that specifies whether the TCP connection table should be sorted. If this parameter is **TRUE**, the table is sorted in the order of:

1. Local IP address
2. Local port
3. Remote IP address
4. Remote port

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pTcpTable* parameter is not large enough. The required size is returned in the **DWORD** variable pointed to by the *pdwSize* parameter.<br><br>This error is also returned if the *pTcpTable* parameter is **NULL**. |
| **ERROR_INVALID_PARAMETER** | The *pdwSize* parameter is **NULL**, or [GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable) is unable to write to the memory pointed to by the *pdwSize* parameter. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. |
| **STATUS_UNSUCCESSFUL** | If you receive this return code then calling the function again is usually enough to clear the issue and get the desired result. This return code can be a consequence of the system being under high load. For example, if the size of the TCP connection table changes by more than 2 additional items 3 consecutive times. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

On the Windows SDK released for Windows Vista and later, the return value from the **GetTcpTable** function is changed to a data type of **ULONG** which is equivalent to a **DWORD**.

#### Examples

The following example retrieves the TCP connection table for IPv4 and prints the state of each connection.

```cpp
// Need to link with Iphlpapi.lib and Ws2_32.lib
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int main()
{

    // Declare and initialize variables
    PMIB_TCPTABLE pTcpTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    char szLocalAddr[128];
    char szRemoteAddr[128];

    struct in_addr IpAddr;

    int i;

    pTcpTable = (MIB_TCPTABLE *) MALLOC(sizeof (MIB_TCPTABLE));
    if (pTcpTable == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    dwSize = sizeof (MIB_TCPTABLE);
// Make an initial call to GetTcpTable to
// get the necessary size into the dwSize variable
    if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) ==
        ERROR_INSUFFICIENT_BUFFER) {
        FREE(pTcpTable);
        pTcpTable = (MIB_TCPTABLE *) MALLOC(dwSize);
        if (pTcpTable == NULL) {
            printf("Error allocating memory\n");
            return 1;
        }
    }
// Make a second call to GetTcpTable to get
// the actual data we require
    if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) == NO_ERROR) {
        printf("\tNumber of entries: %d\n", (int) pTcpTable->dwNumEntries);
        for (i = 0; i < (int) pTcpTable->dwNumEntries; i++) {
            IpAddr.S_un.S_addr = (u_long) pTcpTable->table[i].dwLocalAddr;
            strcpy_s(szLocalAddr, sizeof (szLocalAddr), inet_ntoa(IpAddr));
            IpAddr.S_un.S_addr = (u_long) pTcpTable->table[i].dwRemoteAddr;
            strcpy_s(szRemoteAddr, sizeof (szRemoteAddr), inet_ntoa(IpAddr));

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
            printf("\tTCP[%d] Local Addr: %s\n", i, szLocalAddr);
            printf("\tTCP[%d] Local Port: %d \n", i,
                   ntohs((u_short)pTcpTable->table[i].dwLocalPort));
            printf("\tTCP[%d] Remote Addr: %s\n", i, szRemoteAddr);
            printf("\tTCP[%d] Remote Port: %d\n", i,
                   ntohs((u_short)pTcpTable->table[i].dwRemotePort));
        }
    } else {
        printf("\tGetTcpTable failed with %d\n", dwRetVal);
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

[GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2)

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetTcpStatisticsEx](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex)

[GetTcpTable2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable2)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPROW_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_module)

[MIB_TCPROW_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_owner_pid)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[MIB_TCPTABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_module)

[MIB_TCPTABLE_OWNER_PID](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable_owner_pid)

[SetTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-settcpentry)