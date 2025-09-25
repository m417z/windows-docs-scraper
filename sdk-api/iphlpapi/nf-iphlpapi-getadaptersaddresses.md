# GetAdaptersAddresses function

## Description

The
**GetAdaptersAddresses** function retrieves the addresses associated with the adapters on the local computer.

## Parameters

### `Family` [in]

The address family of the addresses to retrieve. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | Return both IPv4 and IPv6 addresses associated with adapters with IPv4 or IPv6 enabled. |
| **AF_INET**<br><br>2 | Return only IPv4 addresses associated with adapters with IPv4 enabled. |
| **AF_INET6**<br><br>23 | Return only IPv6 addresses associated with adapters with IPv6 enabled. |

### `Flags` [in]

The type of addresses to retrieve. The possible values are defined in the *Iptypes.h* header file. Note that the *Iptypes.h* header file is automatically included in *Iphlpapi.h*, and should never be used directly.

This parameter is a combination of the following values. If this parameter is zero, then unicast, anycast, and multicast IP addresses will be returned.

| Value | Meaning |
| --- | --- |
| **GAA_FLAG_SKIP_UNICAST**<br><br>0x0001 | Do not return unicast addresses. |
| **GAA_FLAG_SKIP_ANYCAST**<br><br>0x0002 | Do not return IPv6 anycast addresses. |
| **GAA_FLAG_SKIP_MULTICAST**<br><br>0x0004 | Do not return multicast addresses. |
| **GAA_FLAG_SKIP_DNS_SERVER**<br><br>0x0008 | Do not return addresses of DNS servers. |
| **GAA_FLAG_INCLUDE_PREFIX**<br><br>0x0010 | Return a list of IP address prefixes on this adapter. When this flag is set, IP address prefixes are returned for both IPv6 and IPv4 addresses. <br><br>This flag is supported on Windows XP with SP1 and later. |
| **GAA_FLAG_SKIP_FRIENDLY_NAME**<br><br>0x0020 | Do not return the adapter friendly name. |
| **GAA_FLAG_INCLUDE_WINS_INFO**<br><br>0x0040 | Return addresses of Windows Internet Name Service (WINS) servers. <br><br>This flag is supported on Windows Vista and later. |
| **GAA_FLAG_INCLUDE_GATEWAYS**<br><br>0x0080 | Return the addresses of default gateways. <br><br>This flag is supported on Windows Vista and later. |
| **GAA_FLAG_INCLUDE_ALL_INTERFACES**<br><br>0x0100 | Return addresses for all NDIS interfaces. <br><br>This flag is supported on Windows Vista and later. |
| **GAA_FLAG_INCLUDE_ALL_COMPARTMENTS**<br><br>0x0200 | Return addresses in all routing compartments. <br><br>This flag is not currently supported and reserved for future use. |
| **GAA_FLAG_INCLUDE_TUNNEL_BINDINGORDER**<br><br>0x0400 | Return the adapter addresses sorted in tunnel binding order. This flag is supported on Windows Vista and later. |

### `Reserved` [in]

This parameter is not currently used, but is reserved for future system use. The calling application should pass **NULL** for this parameter.

### `AdapterAddresses` [in, out]

A pointer to a buffer that contains a linked list of [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structures on successful return.

### `SizePointer` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by *AdapterAddresses*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** (defined to the same value as **NO_ERROR**).

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ADDRESS_NOT_ASSOCIATED** | An address has not yet been associated with the network endpoint. DHCP lease information was available. |
| **ERROR_BUFFER_OVERFLOW** | The buffer size indicated by the *SizePointer* parameter is too small to hold the adapter information or the *AdapterAddresses* parameter is **NULL**. The *SizePointer* parameter returned points to the required size of the buffer to hold the adapter information. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. This error is returned for any of the following conditions: the *SizePointer* parameter is **NULL**, the *Address* parameter is not **AF_INET**, **AF_INET6**, or **AF_UNSPEC**, or the address information for the parameters requested is greater than **ULONG_MAX**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **ERROR_NO_DATA** | No addresses were found for the requested parameters. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The
**GetAdaptersAddresses** function can retrieve information for IPv4 and IPv6 addresses.

Addresses are returned as a linked list of [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structures in the buffer pointed to by the *AdapterAddresses* parameter. The application that calls the **GetAdaptersAddresses** function must allocate the amount of memory needed to return the **IP_ADAPTER_ADDRESSES** structures pointed to by the *AdapterAddresses* parameter. When these returned structures are no longer required, the application should free the memory allocated. This can be accomplished by calling the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function to allocate memory and later calling the [HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree) function to free the allocated memory, as shown in the example code. Other memory allocation and free functions can be used as long as the same family of functions are used for both the allocation and the free function.

**GetAdaptersAddresses** is implemented only as a synchronous function call. The **GetAdaptersAddresses** function requires a significant amount of network resources and time to complete since all of the low-level network interface tables must be traversed.

One method that can be used to determine the memory needed to return the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structures pointed to by the *AdapterAddresses* parameter is to pass too small a buffer size as indicated in the *SizePointer* parameter in the first call to the **GetAdaptersAddresses** function, so the function will fail with **ERROR_BUFFER_OVERFLOW**. When the return value is **ERROR_BUFFER_OVERFLOW**, the *SizePointer* parameter returned points to the required size of the buffer to hold the adapter information. Note that it is possible for the buffer size required for the **IP_ADAPTER_ADDRESSES** structures pointed to by the *AdapterAddresses* parameter to change between subsequent calls to the **GetAdaptersAddresses** function if an adapter address is added or removed. However, this method of using the **GetAdaptersAddresses** function is strongly discouraged. This method requires calling the **GetAdaptersAddresses** function multiple times.

The recommended method of calling the **GetAdaptersAddresses** function is to pre-allocate a 15KB working buffer pointed to by the *AdapterAddresses* parameter. On typical computers, this dramatically reduces the chances that the **GetAdaptersAddresses** function returns **ERROR_BUFFER_OVERFLOW**, which would require calling **GetAdaptersAddresses** function multiple times. The example code illustrates this method of use.

In versions prior to Windows 10, the order in which adapters appear in the list returned by this function can be controlled from the Network Connections folder: select the Advanced Settings menu item from the Advanced menu. Starting with Windows 10, the order in which adapters appear in the list is determined by the IPv4 or IPv6 route metric.

If the GAA_FLAG_INCLUDE_ALL_INTERFACES is set, then all NDIS adapters will be retrieved even those addresses associated with adapters not bound to an address family specified in the *Family* parameter. When this flag is not set, then only the addresses that are bound to an adapter enabled for the address family specified in the *Family* parameter are returned.

The size of the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure was changed on Windows XP with Service Pack 1 (SP1) and later. Several additional members were added to this structure. The size of the **IP_ADAPTER_ADDRESSES** structure was also changed on Windows Vista and later. A number of additional members were added to this structure. The size of the
**IP_ADAPTER_ADDRESSES** structure also changed on
Windows Vista with Service Pack 1 (SP1)and later and onWindows Server 2008 and later. One additional member was added to this structure. The **Length** member of the **IP_ADAPTER_ADDRESSES** structure returned in the linked list of structures in the buffer pointed to by the *AdapterAddresses* parameter should be used to determine which version of the **IP_ADAPTER_ADDRESSES** structure is being used.

The [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function retrieves the interface–to–IPv4 address mapping table on a local computer and returns this information in an [MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure.

On the Platform Software Development Kit (SDK) released for Windows Server 2003 and earlier, the return value for the **GetAdaptersAddresses** function was defined as a **DWORD**, rather than a **ULONG**.

The [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure is used in the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure pointed to by the *AdapterAddresses* parameter. On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **SOCKET_ADDRESS** structure is defined in the *Ws2def.h* header file which is automatically included by the *Winsock2.h* header file. On the Platform SDK released for Windows Server 2003 and Windows XP, the **SOCKET_ADDRESS** structure is declared in the *Winsock2.h* header file. In order to use the **IP_ADAPTER_ADDRESSES** structure, the *Winsock2.h* header file must be included before the *Iphlpapi.h* header file.

#### Examples

This example retrieves the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure for the adapters associated with the system and prints some members for each adapter interface.

```cpp
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main(int argc, char **argv)
{

    /* Declare and initialize variables */

    DWORD dwRetVal = 0;

    unsigned int i = 0;

    // Set the flags to pass to GetAdaptersAddresses
    ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

    // default to unspecified address family (both)
    ULONG family = AF_UNSPEC;

    LPVOID lpMsgBuf = NULL;

    PIP_ADAPTER_ADDRESSES pAddresses = NULL;
    ULONG outBufLen = 0;
    ULONG Iterations = 0;

    PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
    PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
    PIP_ADAPTER_ANYCAST_ADDRESS pAnycast = NULL;
    PIP_ADAPTER_MULTICAST_ADDRESS pMulticast = NULL;
    IP_ADAPTER_DNS_SERVER_ADDRESS *pDnServer = NULL;
    IP_ADAPTER_PREFIX *pPrefix = NULL;

    if (argc != 2) {
        printf(" Usage: getadapteraddresses family\n");
        printf("        getadapteraddresses 4 (for IPv4)\n");
        printf("        getadapteraddresses 6 (for IPv6)\n");
        printf("        getadapteraddresses A (for both IPv4 and IPv6)\n");
        exit(1);
    }

    if (atoi(argv[1]) == 4)
        family = AF_INET;
    else if (atoi(argv[1]) == 6)
        family = AF_INET6;

    printf("Calling GetAdaptersAddresses function with family = ");
    if (family == AF_INET)
        printf("AF_INET\n");
    if (family == AF_INET6)
        printf("AF_INET6\n");
    if (family == AF_UNSPEC)
        printf("AF_UNSPEC\n\n");

    // Allocate a 15 KB buffer to start with.
    outBufLen = WORKING_BUFFER_SIZE;

    do {

        pAddresses = (IP_ADAPTER_ADDRESSES *) MALLOC(outBufLen);
        if (pAddresses == NULL) {
            printf
                ("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
            exit(1);
        }

        dwRetVal =
            GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

        if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
            FREE(pAddresses);
            pAddresses = NULL;
        } else {
            break;
        }

        Iterations++;

    } while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < MAX_TRIES));

    if (dwRetVal == NO_ERROR) {
        // If successful, output some information from the data we received
        pCurrAddresses = pAddresses;
        while (pCurrAddresses) {
            printf("\tLength of the IP_ADAPTER_ADDRESS struct: %ld\n",
                   pCurrAddresses->Length);
            printf("\tIfIndex (IPv4 interface): %u\n", pCurrAddresses->IfIndex);
            printf("\tAdapter name: %s\n", pCurrAddresses->AdapterName);

            pUnicast = pCurrAddresses->FirstUnicastAddress;
            if (pUnicast != NULL) {
                for (i = 0; pUnicast != NULL; i++)
                    pUnicast = pUnicast->Next;
                printf("\tNumber of Unicast Addresses: %d\n", i);
            } else
                printf("\tNo Unicast Addresses\n");

            pAnycast = pCurrAddresses->FirstAnycastAddress;
            if (pAnycast) {
                for (i = 0; pAnycast != NULL; i++)
                    pAnycast = pAnycast->Next;
                printf("\tNumber of Anycast Addresses: %d\n", i);
            } else
                printf("\tNo Anycast Addresses\n");

            pMulticast = pCurrAddresses->FirstMulticastAddress;
            if (pMulticast) {
                for (i = 0; pMulticast != NULL; i++)
                    pMulticast = pMulticast->Next;
                printf("\tNumber of Multicast Addresses: %d\n", i);
            } else
                printf("\tNo Multicast Addresses\n");

            pDnServer = pCurrAddresses->FirstDnsServerAddress;
            if (pDnServer) {
                for (i = 0; pDnServer != NULL; i++)
                    pDnServer = pDnServer->Next;
                printf("\tNumber of DNS Server Addresses: %d\n", i);
            } else
                printf("\tNo DNS Server Addresses\n");

            printf("\tDNS Suffix: %wS\n", pCurrAddresses->DnsSuffix);
            printf("\tDescription: %wS\n", pCurrAddresses->Description);
            printf("\tFriendly name: %wS\n", pCurrAddresses->FriendlyName);

            if (pCurrAddresses->PhysicalAddressLength != 0) {
                printf("\tPhysical address: ");
                for (i = 0; i < (int) pCurrAddresses->PhysicalAddressLength;
                     i++) {
                    if (i == (pCurrAddresses->PhysicalAddressLength - 1))
                        printf("%.2X\n",
                               (int) pCurrAddresses->PhysicalAddress[i]);
                    else
                        printf("%.2X-",
                               (int) pCurrAddresses->PhysicalAddress[i]);
                }
            }
            printf("\tFlags: %ld\n", pCurrAddresses->Flags);
            printf("\tMtu: %lu\n", pCurrAddresses->Mtu);
            printf("\tIfType: %ld\n", pCurrAddresses->IfType);
            printf("\tOperStatus: %ld\n", pCurrAddresses->OperStatus);
            printf("\tIpv6IfIndex (IPv6 interface): %u\n",
                   pCurrAddresses->Ipv6IfIndex);
            printf("\tZoneIndices (hex): ");
            for (i = 0; i < 16; i++)
                printf("%lx ", pCurrAddresses->ZoneIndices[i]);
            printf("\n");

            printf("\tTransmit link speed: %I64u\n", pCurrAddresses->TransmitLinkSpeed);
            printf("\tReceive link speed: %I64u\n", pCurrAddresses->ReceiveLinkSpeed);

            pPrefix = pCurrAddresses->FirstPrefix;
            if (pPrefix) {
                for (i = 0; pPrefix != NULL; i++)
                    pPrefix = pPrefix->Next;
                printf("\tNumber of IP Adapter Prefix entries: %d\n", i);
            } else
                printf("\tNumber of IP Adapter Prefix entries: 0\n");

            printf("\n");

            pCurrAddresses = pCurrAddresses->Next;
        }
    } else {
        printf("Call to GetAdaptersAddresses failed with error: %d\n",
               dwRetVal);
        if (dwRetVal == ERROR_NO_DATA)
            printf("\tNo addresses were found for the requested parameters\n");
        else {

            if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                    // Default language
                    (LPTSTR) & lpMsgBuf, 0, NULL)) {
                printf("\tError: %s", lpMsgBuf);
                LocalFree(lpMsgBuf);
                if (pAddresses)
                    FREE(pAddresses);
                exit(1);
            }
        }
    }

    if (pAddresses) {
        FREE(pAddresses);
    }

    return 0;
}

```

## See also

[GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable)

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapFree](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapfree)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)

[MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)

[Windows Sockets](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-start-page-2)