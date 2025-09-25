# MIB_TCP6ROW structure

## Description

The
**MIB_TCP6ROW** structure contains information that describes an IPv6 TCP connection.

## Members

### `State`

Type: **MIB_TCP_STATE**

The state of the TCP connection. This member can be one of the values from the **MIB_TCP_STATE** enumeration type defined in the *Tcpmib.h* header file.

| Value | Meaning |
| --- | --- |
| **MIB_TCP_STATE_CLOSED**<br><br>1 | The TCP connection is in the CLOSED state that represents no connection state at all. |
| **MIB_TCP_STATE_LISTEN**<br><br>2 | The TCP connection is in the LISTEN state waiting for a connection request from any remote TCP and port. |
| **MIB_TCP_STATE_SYN_SENT**<br><br>3 | The TCP connection is in the SYN-SENT state waiting for a matching connection request after having sent a connection request (SYN packet). |
| **MIB_TCP_STATE_SYN_RCVD**<br><br>4 | The TCP connection is in the SYN-RECEIVED state waiting for a confirming connection request acknowledgment after having both received and sent a connection request (SYN packet). |
| **MIB_TCP_STATE_ESTAB**<br><br>5 | The TCP connection is in the ESTABLISHED state that represents an open connection, data received can be delivered to the user. This is the normal state for the data transfer phase of the TCP connection. |
| **MIB_TCP_STATE_FIN_WAIT1**<br><br>6 | The TCP connection is FIN-WAIT-1 state waiting for a connection termination request from the remote TCP, or an acknowledgment of the connection termination request previously sent. |
| **MIB_TCP_STATE_FIN_WAIT2**<br><br>7 | The TCP connection is FIN-WAIT-1 state waiting for a connection termination request from the remote TCP. |
| **MIB_TCP_STATE_CLOSE_WAIT**<br><br>8 | The TCP connection is in the CLOSE-WAIT state waiting for a connection termination request from the local user. |
| **MIB_TCP_STATE_CLOSING**<br><br>9 | The TCP connection is in the CLOSING state waiting for a connection termination request acknowledgment from the remote TCP. |
| **MIB_TCP_STATE_LAST_ACK**<br><br>10 | The TCP connection is in the LAST-ACK state waiting for an acknowledgment of the connection termination request previously sent to the remote TCP (which includes an acknowledgment of its connection termination request). |
| **MIB_TCP_STATE_TIME_WAIT**<br><br>11 | The TCP connection is in the TIME-WAIT state waiting for enough time to pass to be sure the remote TCP received the acknowledgment of its connection termination request. |
| **MIB_TCP_STATE_DELETE_TCB**<br><br>12 | The TCP connection is in the delete TCB state that represents the deletion of the Transmission Control Block (TCB), a data structure used to maintain information on each TCP entry. |

### `LocalAddr`

Type: **IN6_ADDR**

The local IPv6 address for the TCP connection on the local computer. A value of zero indicates the listener can accept a connection on any interface.

### `dwLocalScopeId`

Type: **DWORD**

The local scope ID for the TCP connection on the local computer.

### `dwLocalPort`

Type: **DWORD**

The local port number in network byte order for the TCP connection on the local computer.

 The maximum size of an IP port number is 16 bits, so only the lower 16 bits should be used. The upper 16 bits may contain uninitialized data.

### `RemoteAddr`

Type: **IN6_ADDR**

The IPv6 address for the TCP connection on the remote computer. When the **State** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

### `dwRemoteScopeId`

Type: **DWORD**

The remote scope ID for the TCP connection on the remote computer. When the **State** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

### `dwRemotePort`

Type: **DWORD**

The remote port number in network byte order for the TCP connection on the remote computer. When the **State** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

 The maximum size of an IP port number is 16 bits, so only the lower 16 bits should be used. The upper 16 bits may contain uninitialized data.

## Remarks

The **MIB_TCP6ROW** structure is defined on Windows Vista and later.

The [GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table) function retrieves the IPv6 TCP connection table on the local computer and returns this information in a [MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table) structure.

An array of **MIB_TCP6ROW** structures are contained in the **MIB_TCP6TABLE** structure.

 The **State** member indicates the state of the TCP entry in a TCP state diagram. A TCP connection progresses through a series of states during its
lifetime. The states are: LISTEN, SYN-SENT, SYN-RECEIVED,
ESTABLISHED, FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, CLOSING, LAST-ACK,
TIME-WAIT, and the fictional state CLOSED. The CLOSED state is fictional
because it represents the state when there is no Transmission Control Block, and therefore,
no connection. The TCP protocol is described in RFC 793. For more information, see
[http://www.ietf.org/rfc/rfc793.txt](https://www.ietf.org/rfc/rfc793.txt).

The **dwLocalPort**, and **dwRemotePort** members are in network byte order. In order to use the **dwLocalPort** or **dwRemotePort** members, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **dwLocalScopeId**, and **dwRemoteScopeId** members are in network byte order. In order to use the **dwLocalScopeId** or **dwRemoteScopeId** members, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **LocalAddr** and **RemoteAddr** members are stored in [in6_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structures. The [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) or [RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw) functions may be used to convert the IPv6 address in the **LocalAddr** or **RemoteAddr** members to a string without loading the Windows Sockets DLL.

#### Examples

The following example retrieves the TCP connection table for IPv6 and prints the state of each connection represented as a **MIB_TCP6ROW** structure.

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

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[in6_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)