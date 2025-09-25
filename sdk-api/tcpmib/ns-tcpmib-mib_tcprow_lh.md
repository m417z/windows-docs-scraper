# MIB_TCPROW_LH structure

## Description

The
**MIB_TCPROW** structure contains information that descibes an IPv4 TCP connection.

## Members

### `dwState`

Type: **DWORD**

The state of the TCP connection. This member can be one of the values defined in the *Iprtrmib.h* header file.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed. This member can be one of the values from the **MIB_TCP_STATE** enumeration defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

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

### `State`

### `dwLocalAddr`

Type: **DWORD**

The local IPv4 address for the TCP connection on the local computer. A value of zero indicates the listener can accept a connection on any interface.

### `dwLocalPort`

Type: **DWORD**

The local port number in network byte order for the TCP connection on the local computer.

 The maximum size of an IP port number is 16 bits, so only the lower 16 bits should be used. The upper 16 bits may contain uninitialized data.

### `dwRemoteAddr`

Type: **DWORD**

The IPv4 address for the TCP connection on the remote computer. When the **dwState** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

### `dwRemotePort`

Type: **DWORD**

The remote port number in network byte order for the TCP connection on the remote computer. When the **dwState** member is **MIB_TCP_STATE_LISTEN**, this member has no meaning.

The maximum size of an IP port number is 16 bits, so only the lower 16 bits should be used. The upper 16 bits may contain uninitialized data.

## Remarks

The [GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable) function retrieves the IPv4 TCP connection table on the local computer and returns this information in a [MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable) structure.

An array of **MIB_TCPROW** structures are contained in the **MIB_TCPTABLE** structure. The **MIB_TCPROW** structure is also used by the [SetTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-settcpentry) function.

 The **dwState** member indicates the state of the TCP entry in a TCP state diagram. A TCP connection progresses through a series of states during its
lifetime. The states are: LISTEN, SYN-SENT, SYN-RECEIVED,
ESTABLISHED, FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, CLOSING, LAST-ACK,
TIME-WAIT, and the fictional state CLOSED. The CLOSED state is fictional
because it represents the state when there is no Transmission Control Block, and therefore,
no connection. The TCP protocol is described in RFC 793. For more information, see
[http://www.ietf.org/rfc/rfc793.txt](https://www.ietf.org/rfc/rfc793.txt).

The **dwLocalAddr** and **dwRemoteAddr** members are stored as a **DWORD** in the same format as the [in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure. In order to use the **dwLocalAddr** or **dwRemoteAddr** members, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed. On Windows Vista and later, the [RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa) or [RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw) functions may be used to convert the IPv4 address in the **dwLocalAddr** or **dwRemoteAddr** members to a string without loading the Windows Sockets DLL.

The **dwLocalPort**, and **dwRemotePort** members are in network byte order. In order to use the **dwLocalPort** or **dwRemotePort** members, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **MIB_TCPROW** structure changed slightly on Windows Vista and later. On Windows Vista and later, the **dwState** member is replaced by a union that contains the following members.

| Member | Description |
| --- | --- |
| DWORD dwState | The state of the TCP connection. |
| MIB_TCP_STATE State | The state of the TCP connection. This member can be one of the values from the **MIB_TCP_STATE** enumeration type defined in the *Tcpmib.h* header file. The possible values are the same as those defined for the **dwState** member. |

In the Windows SDK, the version of the structure for use on Windows Vista and later is defined as **MIB_TCPROW_LH**. In the Windows SDK, the version of this structure to be used on earlier systems including Windows 2000 and later is defined as **MIB_TCPROW_W2K**. When compiling an application if the target platform is Windows Vista and later (`NTDDI_VERSION >= NTDDI_LONGHORN`, `_WIN32_WINNT >= 0x0600`, or `WINVER >= 0x0600`), the **MIB_TCPROW_LH** structure is typedefed to the **MIB_TCPROW** structure. When compiling an application if the target platform is not Windows Vista and later, the **MIB_TCPROW_W2K** structure is typedefed to the **MIB_TCPROW** structure.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

#### Examples

The following example retrieves the TCP connection table and prints the state of each connection represented as a **MIB_TCPROW** structure.

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
                printf("UNKNOWN dwState value: %d\n", pTcpTable->table[i].dwState);
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

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2)

[GetTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable)

[GetTcpTable2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcptable2)

[MIB_TCP6ROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row)

**MIB_TCP6ROW2**

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[MIB_TCPTABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable2)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[SetTcpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-settcpentry)

[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)