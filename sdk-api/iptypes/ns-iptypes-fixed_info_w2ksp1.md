# FIXED_INFO_W2KSP1 structure

## Description

The
**FIXED_INFO** structure contains information that is the same across all the interfaces on a computer.

## Members

### `HostName`

Type: **char[MAX_HOSTNAME_LEN + 4]**

The hostname for the local computer. This may be the fully qualified hostname (including the domain) for a computer that is joined to a domain.

### `DomainName`

Type: **char[MAX_DOMAIN_NAME_LEN + 4]**

The domain in which the local computer is registered.

### `CurrentDnsServer`

Type: **PIP_ADDR_STRING**

Reserved. Use the **DnsServerList** member to obtain the DNS servers for the local computer.

### `DnsServerList`

Type: **IP_ADDR_STRING**

A linked list of
[IP_ADDR_STRING](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_addr_string) structures that specify the set of DNS servers used by the local computer.

### `NodeType`

Type: **UINT**

The node type of the local computer. These values are defined in the
*Iptypes.h* header file.

| NodeType | Meaning |
| --- | --- |
| **BROADCAST_NODETYPE**<br><br>0x0001 | A broadcast nodetype. |
| **PEER_TO_PEER_NODETYPE**<br><br>0x0002 | A peer to peer nodetype. |
| **MIXED_NODETYPE**<br><br>0x0004 | A mixed nodetype. |
| **HYBRID_NODETYPE**<br><br>0x0008 | A hybrid nodetype. |

### `ScopeId`

Type: **char[MAX_SCOPE_ID_LEN + 4]**

The DHCP scope name.

### `EnableRouting`

Type: **UINT**

A Boolean value that specifies whether routing is enabled on the local computer.

### `EnableProxy`

Type: **UINT**

A Boolean value that specifies whether the local computer is acting as an ARP proxy.

### `EnableDns`

Type: **UINT**

A Boolean value that specifies whether DNS is enabled on the local computer.

## Remarks

The
**FIXED_INFO** structure is retrieved by the [GetNetworkParams](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnetworkparams) function.

In the Microsoft Windows Software Development Kit (SDK), the **FIXED_INFO_WIN2KSP1** structure is defined. When compiling an
application if the target platform is Windows 2000 with Service Pack 1 (SP1) and later (`NTDDI_VERSION >= NTDDI_WIN2KSP1`,
`_WIN32_WINNT >= 0x0501`, or
`WINVER >= 0x0501`), the **FIXED_INFO_WIN2KSP1** struct is typedefed to the **FIXED_INFO** structure. When compiling an application if the target
platform is not Windows 2000 with SP1 and later, the
**FIXED_INFO** structure is undefined.

The [GetNetworkParams](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnetworkparams) function and the
**FIXED_INFO** structure are supported on Windows 98and later. But to build an application for a target platform earlier than Windows 2000 with Service Pack 1 (SP1), an earlier version of the Platform Software Development Kit (SDK) must be used.

#### Examples

The following code retrieves a
**FIXED_INFO** structure that contains network configuration information for the local computer. The code prints selected members from the structure.

```cpp
//
// Link with IPHlpAPI.lib
//
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "IPHLPAPI.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main()
{

    FIXED_INFO *pFixedInfo;
    ULONG ulOutBufLen;
    DWORD dwRetVal;
    IP_ADDR_STRING *pIPAddr;

    pFixedInfo = (FIXED_INFO *) MALLOC(sizeof (FIXED_INFO));
    if (pFixedInfo == NULL) {
        printf("Error allocating memory needed to call GetNetworkParams\n");
        return 1;
    }
    ulOutBufLen = sizeof (FIXED_INFO);

// Make an initial call to GetAdaptersInfo to get
// the necessary size into the ulOutBufLen variable
    if (GetNetworkParams(pFixedInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        FREE(pFixedInfo);
        pFixedInfo = (FIXED_INFO *) MALLOC(ulOutBufLen);
        if (pFixedInfo == NULL) {
            printf("Error allocating memory needed to call GetNetworkParams\n");
            return 1;
        }
    }

    if (dwRetVal = GetNetworkParams(pFixedInfo, &ulOutBufLen) == NO_ERROR) {

        printf("Host Name: %s\n", pFixedInfo->HostName);
        printf("Domain Name: %s\n", pFixedInfo->DomainName);

        printf("DNS Servers:\n");
        printf("\t%s\n", pFixedInfo->DnsServerList.IpAddress.String);

        pIPAddr = pFixedInfo->DnsServerList.Next;
        while (pIPAddr) {
            printf("\t%s\n", pIPAddr->IpAddress.String);
            pIPAddr = pIPAddr->Next;
        }

        printf("Node Type: ");
        switch (pFixedInfo->NodeType) {
        case BROADCAST_NODETYPE:
            printf("Broadcast node\n");
            break;
        case PEER_TO_PEER_NODETYPE:
            printf("Peer to Peer node\n");
            break;
        case MIXED_NODETYPE:
            printf("Mixed node\n");
            break;
        case HYBRID_NODETYPE:
            printf("Hybrid node\n");
            break;
        default:
            printf("Unknown node type %0lx\n", pFixedInfo->NodeType);
            break;
        }

        printf("DHCP scope name: %s\n", pFixedInfo->ScopeId);

        if (pFixedInfo->EnableRouting)
            printf("Routing: enabled\n");
        else
            printf("Routing: disabled\n");

        if (pFixedInfo->EnableProxy)
            printf("ARP proxy: enabled\n");
        else
            printf("ARP Proxy: disabled\n");

        if (pFixedInfo->EnableDns)
            printf("DNS: enabled\n");
        else
            printf("DNS: disabled\n");

    } else {
        printf("GetNetworkParams failed with error: %d\n", dwRetVal);
        return 1;
    }

    if (pFixedInfo)
        FREE(pFixedInfo);

    return 0;
}

```

## See also

[GetNetworkParams](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getnetworkparams)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADDR_STRING](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_addr_string)