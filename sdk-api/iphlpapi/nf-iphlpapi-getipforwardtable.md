# GetIpForwardTable function

## Description

The
**GetIpForwardTable** function retrieves the IPv4 routing table.

## Parameters

### `pIpForwardTable` [out]

A pointer to a buffer that receives the IPv4 routing table as a
[MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable) structure.

### `pdwSize` [in, out]

On input, specifies the size in bytes of the buffer pointed to by the *pIpForwardTable* parameter.

On output, if the buffer is not large enough to hold the returned routing table, the function sets this parameter equal to the required buffer size in bytes.

### `bOrder` [in]

A Boolean value that specifies whether the returned table should be sorted. If this parameter is **TRUE**, the table is sorted in the order of:

1. Destination address
2. Protocol that generated the route
3. Multipath routing policy
4. Next-hop address

## Return value

If the function succeeds, the return value is **NO_ERROR** (zero).

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pIpForwardTable* parameter is not large enough. The required size is returned in the **DWORD** variable pointed to by the *pdwSize* parameter. |
| **ERROR_INVALID_PARAMETER** | The *pdwSize* parameter is **NULL**, or [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) is unable to write to the memory pointed to by the *pdwSize* parameter. |
| **ERROR_NO_DATA** | No data is available. This error is returned if there are no routes present on the local computer. |
| **ERROR_NOT_SUPPORTED** | This function is not supported on the operating system in use on the local system. This error is returned if there is no IP stack installed on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **dwForwardProto** member of the
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure specifies the protocol or routing mechanism that generated the route. See
[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers) for a list of possible protocols and routing mechanisms.

The **dwForwardDest**, **dwForwardMask**, and **dwForwardNextHop** members of the
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure represent an IPv4 address in network byte order.

An IPv4 address of 0.0.0.0 in the **dwForwardDest** member of the
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure is considered a
default route. The [MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable) may contain multiple **MIB_IPFORWARDROW** entries with the **dwForwardDest** member set to 0.0.0.0 when there are multiple network adapters installed.

When **dwForwardAge** is set to **INFINITE**, the route will not be removed based on a timeout
value. Any other value for **dwForwardAge** specifies the number of seconds since the route was added or modified in the network routing table.

On Windows Server 2003 or
Windows 2000 Server when the Routing and Remote Access Service (RRAS) is running, the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) entries returned have the **dwForwardType** and **dwForwardAge** members set to zero.

On Windows Vista and Windows Server 2008, the route metric specified in the **dwForwardMetric1** member of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure represents a combination of the route metric added to the interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure of the associated interface. So the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure should be equal to or greater than **Metric** member of the associated **MIB_IPINTERFACE_ROW** structure. If an application would like to set the route metric to 0 on Windows Vista and Windows Server 2008, then the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure should be set equal to the value of the interface metric specified in the **Metric** member of the associated **MIB_IPINTERFACE_ROW** structure. An application can retrieve the interface metric by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

A number of members of the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure entries returned by **GetIpForwardTable** are not currently used by IPv4 routing. These members include **dwForwardPolicy**, **dwForwardNextHopAS**, **dwForwardMetric2**, **dwForwardMetric3**, **dwForwardMetric4**, and **dwForwardMetric5**.

#### Examples

The following example retrieves the IP routing table then prints some fields for each route in the table.

```cpp
// Need to link with Ws2_32.lib and Iphlpapi.lib
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

    // Declare and initialize variables.

    /* variables used for GetIfForwardTable */
    PMIB_IPFORWARDTABLE pIpForwardTable;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    char szDestIp[128];
    char szMaskIp[128];
    char szGatewayIp[128];

    struct in_addr IpAddr;

    int i;

    pIpForwardTable =
        (MIB_IPFORWARDTABLE *) MALLOC(sizeof (MIB_IPFORWARDTABLE));
    if (pIpForwardTable == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    if (GetIpForwardTable(pIpForwardTable, &dwSize, 0) ==
        ERROR_INSUFFICIENT_BUFFER) {
        FREE(pIpForwardTable);
        pIpForwardTable = (MIB_IPFORWARDTABLE *) MALLOC(dwSize);
        if (pIpForwardTable == NULL) {
            printf("Error allocating memory\n");
            return 1;
        }
    }

    /* Note that the IPv4 addresses returned in
     * GetIpForwardTable entries are in network byte order
     */
    if ((dwRetVal = GetIpForwardTable(pIpForwardTable, &dwSize, 0)) == NO_ERROR) {
        printf("\tNumber of entries: %d\n",
               (int) pIpForwardTable->dwNumEntries);
        for (i = 0; i < (int) pIpForwardTable->dwNumEntries; i++) {
            /* Convert IPv4 addresses to strings */
            IpAddr.S_un.S_addr =
                (u_long) pIpForwardTable->table[i].dwForwardDest;
            strcpy_s(szDestIp, sizeof (szDestIp), inet_ntoa(IpAddr));
            IpAddr.S_un.S_addr =
                (u_long) pIpForwardTable->table[i].dwForwardMask;
            strcpy_s(szMaskIp, sizeof (szMaskIp), inet_ntoa(IpAddr));
            IpAddr.S_un.S_addr =
                (u_long) pIpForwardTable->table[i].dwForwardNextHop;
            strcpy_s(szGatewayIp, sizeof (szGatewayIp), inet_ntoa(IpAddr));

            printf("\n\tRoute[%d] Dest IP: %s\n", i, szDestIp);
            printf("\tRoute[%d] Subnet Mask: %s\n", i, szMaskIp);
            printf("\tRoute[%d] Next Hop: %s\n", i, szGatewayIp);
            printf("\tRoute[%d] If Index: %ld\n", i,
                   pIpForwardTable->table[i].dwForwardIfIndex);
            printf("\tRoute[%d] Type: %ld - ", i,
                   pIpForwardTable->table[i].dwForwardType);
            switch (pIpForwardTable->table[i].dwForwardType) {
            case MIB_IPROUTE_TYPE_OTHER:
                printf("other\n");
                break;
            case MIB_IPROUTE_TYPE_INVALID:
                printf("invalid route\n");
                break;
            case MIB_IPROUTE_TYPE_DIRECT:
                printf("local route where next hop is final destination\n");
                break;
            case MIB_IPROUTE_TYPE_INDIRECT:
                printf
                    ("remote route where next hop is not final destination\n");
                break;
            default:
                printf("UNKNOWN Type value\n");
                break;
            }
            printf("\tRoute[%d] Proto: %ld - ", i,
                   pIpForwardTable->table[i].dwForwardProto);
            switch (pIpForwardTable->table[i].dwForwardProto) {
            case MIB_IPPROTO_OTHER:
                printf("other\n");
                break;
            case MIB_IPPROTO_LOCAL:
                printf("local interface\n");
                break;
            case MIB_IPPROTO_NETMGMT:
                printf("static route set through network management \n");
                break;
            case MIB_IPPROTO_ICMP:
                printf("result of ICMP redirect\n");
                break;
            case MIB_IPPROTO_EGP:
                printf("Exterior Gateway Protocol (EGP)\n");
                break;
            case MIB_IPPROTO_GGP:
                printf("Gateway-to-Gateway Protocol (GGP)\n");
                break;
            case MIB_IPPROTO_HELLO:
                printf("Hello protocol\n");
                break;
            case MIB_IPPROTO_RIP:
                printf("Routing Information Protocol (RIP)\n");
                break;
            case MIB_IPPROTO_IS_IS:
                printf
                    ("Intermediate System-to-Intermediate System (IS-IS) protocol\n");
                break;
            case MIB_IPPROTO_ES_IS:
                printf("End System-to-Intermediate System (ES-IS) protocol\n");
                break;
            case MIB_IPPROTO_CISCO:
                printf("Cisco Interior Gateway Routing Protocol (IGRP)\n");
                break;
            case MIB_IPPROTO_BBN:
                printf("BBN Internet Gateway Protocol (IGP) using SPF\n");
                break;
            case MIB_IPPROTO_OSPF:
                printf("Open Shortest Path First (OSPF) protocol\n");
                break;
            case MIB_IPPROTO_BGP:
                printf("Border Gateway Protocol (BGP)\n");
                break;
            case MIB_IPPROTO_NT_AUTOSTATIC:
                printf("special Windows auto static route\n");
                break;
            case MIB_IPPROTO_NT_STATIC:
                printf("special Windows static route\n");
                break;
            case MIB_IPPROTO_NT_STATIC_NON_DOD:
                printf
                    ("special Windows static route not based on Internet standards\n");
                break;
            default:
                printf("UNKNOWN Proto value\n");
                break;
            }

            printf("\tRoute[%d] Age: %ld\n", i,
                   pIpForwardTable->table[i].dwForwardAge);
            printf("\tRoute[%d] Metric1: %ld\n", i,
                   pIpForwardTable->table[i].dwForwardMetric1);
        }
        FREE(pIpForwardTable);
        return 0;
    } else {
        printf("\tGetIpForwardTable failed.\n");
        FREE(pIpForwardTable);
        return 1;
    }

}

```

## See also

[CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry)

[DeleteIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipforwardentry)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry)