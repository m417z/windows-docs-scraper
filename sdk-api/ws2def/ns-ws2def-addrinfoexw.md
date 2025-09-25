# ADDRINFOEXW structure

## Description

The
**addrinfoex** structure is used by the
[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function to hold host address information.

## Members

### `ai_flags`

Type: **int**

Flags that indicate options used in the
[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function.

Supported values for the **ai_flags** member are defined in the *Winsock2.h* include file and can be a combination of the following options.

| Value | Meaning |
| --- | --- |
| **AI_PASSIVE**<br><br>0x01 | The socket address will be used in a call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. |
| **AI_CANONNAME**<br><br>0x02 | The canonical name is returned in the first **ai_canonname** member.<br><br>When both the **AI_CANONNAME** and **AI_FQDN** bits are set, an [addrinfoex2](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoex2w) structure is returned not the **addrinfoex** structure. |
| **AI_NUMERICHOST**<br><br>0x04 | The *nodename* parameter passed to the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function must be a numeric string. |
| **AI_ALL**<br><br>0x0100 | If this bit is set, a request is made for IPv6 addresses and IPv4 addresses with **AI_V4MAPPED**.<br><br> This option is supported on Windows Vista and later. |
| **AI_ADDRCONFIG**<br><br>0x0400 | The [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) will resolve only if a global address is configured. The IPv6 and IPv4 loopback address is not considered a valid global address. <br><br>This option is only supported on Windows Vista and later. |
| **AI_V4MAPPED**<br><br>0x0800 | If the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) request for an IPv6 addresses fails, a name service request is made for IPv4 addresses and these addresses are converted to IPv4-mapped IPv6 address format.<br><br>This option is supported on Windows Vista and later. |
| **AI_NON_AUTHORITATIVE**<br><br>0x04000 | The address information is from non-authoritative results. <br><br>When this option is set in the *pHints* parameter of [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), the **NS_EMAIL** namespace provider returns both authoritative and non-authoritative results. If this option is not set, then only authoritative results are returned. <br><br>In the *ppResults* parameter returned by [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), this flag is set in the **ai_flags** member of the **addrinfoex** structure for non-authoritative results. <br><br>This option is only supported on Windows Vista and later for the **NS_EMAIL** namespace. |
| **AI_SECURE**<br><br>0x08000 | The address information is from a secure channel. If the **AI_SECURE** bit is set, the **NS_EMAIL** namespace provider will return results that were obtained with enhanced security to minimize possible spoofing. <br><br>When this option is set in the *pHints* parameter of [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), the **NS_EMAIL** namespace provider returns only results that were obtained with enhanced security to minimize possible spoofing. <br><br>In the *ppResults* parameter returned by [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), this flag is set in the **ai_flags** member of the **addrinfoex** structure for results returned with enhanced security to minimize possible spoofing. <br><br>This option is only supported on Windows Vista and later for the **NS_EMAIL** namespace. |
| **AI_RETURN_PREFERRED_NAMES**<br><br>0x010000 | The address information is for a preferred names for publication with a specific namespace. <br><br>When this option is set in the *pHints* parameter of [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), no name should be provided in the *pName* parameter and the **NS_EMAIL** namespace provider will return preferred names for publication.<br><br>In the *ppResults* parameter returned by [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), this flag is set in the **ai_flags** member of the **addrinfoex** structure for results returned for preferred names for publication. <br><br>This option is only supported on Windows Vista and later for the **NS_EMAIL** namespace. |
| **AI_FQDN**<br><br>0x00020000 | The fully qualified domain name is returned in the first **ai_canonicalname** member.<br><br>When this option is set in the *pHints* parameter of [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) and a flat name (single label) is specified in the *pName* parameter, the fully qualified domain name that the name eventually resolved to will be returned.<br><br>When both the **AI_CANONNAME** and **AI_FQDN** bits are set, an [addrinfoex2](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoex2w) structure is returned not the **addrinfoex** structure. <br><br>This option is supported on Windows 7, Windows Server 2008 R2, and later. |
| **AI_FILESERVER**<br><br>0x00040000 | A hint to the namespace provider that the hostname being queried is being used in a file share scenario. The namespace provider may ignore this hint.<br><br>This option is supported on Windows 7, Windows Server 2008 R2, and later. |
| **AI_DISABLE_IDN_ENCODING**<br><br>0x00080000 | Disable the automatic International Domain Name encoding using Punycode in the name resolution functions called by the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function. <br><br>This option is supported on Windows 8, Windows Server 2012, and later. |

### `ai_family`

Type: **int**

The address family. Possible values for the address family are defined in the *Winsock2.h* include file.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the possible values for the address family are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET** or **AF_INET6**, which are the Internet
address family formats for IPv4 and IPv6. Other options for address family (**AF_NETBIOS** for use with NetBIOS, for example) are supported if a Windows Sockets service provider for the address family is installed. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_UNSPEC** and **PF_UNSPEC**), so either constant can be used.

The table below lists common values for the address family although many other values are possible.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_NETBIOS**<br><br>17 | The NetBIOS address family. This address family is only supported if a Windows Sockets provider for NetBIOS is installed. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |
| **AF_IRDA**<br><br>26 | The Infrared Data Association (IrDA) address family. This address family is only supported if the computer has an infrared port and driver installed. |
| **AF_BTH**<br><br>32 | The Bluetooth address family. This address family is only supported if a Bluetooth adapter is installed on Windows Server 2003 or later. |

### `ai_socktype`

Type: **int**

The socket type. Possible values for the socket type are defined in the *Winsock2.h* include file.

The following table lists the possible values for the socket type supported for Windows Sockets 2:

| Value | Meaning |
| --- | --- |
| **SOCK_STREAM**<br><br>1 | Provides sequenced, reliable, two-way, connection-based byte streams with an OOB data transmission mechanism. Uses the Transmission Control Protocol (TCP) for the Internet address family (**AF_INET** or **AF_INET6**). If the **ai_family** member is **AF_IRDA**, then **SOCK_STREAM** is the only supported socket type. |
| **SOCK_DGRAM**<br><br>2 | Supports datagrams, which are connectionless, unreliable buffers of a fixed (typically small) maximum length. Uses the User Datagram Protocol (UDP) for the Internet address family (**AF_INET** or **AF_INET6**). |
| **SOCK_RAW**<br><br>3 | Provides a raw socket that allows an application to manipulate the next upper-layer protocol header. To manipulate the IPv4 header, the [IP_HDRINCL](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) socket option must be set on the socket. To manipulate the IPv6 header, the [IPV6_HDRINCL](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options) socket option must be set on the socket. |
| **SOCK_RDM**<br><br>4 | Provides a reliable message datagram. An example of this type is the Pragmatic General Multicast (PGM) multicast protocol implementation in Windows, often referred to as [reliable multicast programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-). |
| **SOCK_SEQPACKET**<br><br>5 | Provides a pseudo-stream packet based on datagrams. |

In Windows Sockets 2, new socket types were introduced. An application can dynamically discover the attributes of each available transport protocol through the
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function. So an application can determine the possible socket type and protocol options for an address family and use this information when specifying this parameter. Socket type definitions in the *Winsock2.h* and *Ws2def.h* header files will be periodically updated as new socket types, address families, and protocols are defined.

In Windows Sockets 1.1, the only possible socket types are **SOCK_DATAGRAM** and **SOCK_STREAM**.

### `ai_protocol`

Type: **int**

The protocol type. The possible options are specific to the address family and socket type specified. Possible values for the **ai_protocol** are defined in *Winsock2.h* and the *Wsrm.h* header files.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and this member can be one of the values from the **IPPROTO** enumeration type defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

If a value of 0 is specified for **ai_protocol**, the caller does not
wish to specify a protocol and the service provider will choose the **ai_protocol** to use. For protocols other than IPv4 and IPv6, set **ai_protocol** to zero.

The following table lists common values for the **ai_protocol** member although many other values are possible.

| Value | Meaning |
| --- | --- |
| **IPPROTO_TCP**<br><br>6 | The Transmission Control Protocol (TCP). This is a possible value when the **ai_family** member is **AF_INET** or **AF_INET6** and the **ai_socktype** member is **SOCK_STREAM**. |
| **IPPROTO_UDP**<br><br>17 | The User Datagram Protocol (UDP). This is a possible value when the **ai_family** member is **AF_INET** or **AF_INET6** and the *type* parameter is **SOCK_DGRAM**. |
| **IPPROTO_RM**<br><br>113 | The PGM protocol for reliable multicast. This is a possible value when the **ai_family** member is **AF_INET** and the **ai_socktype** member is **SOCK_RDM**. On the Windows SDK released for Windows Vista and later, this value is also called **IPPROTO_PGM**. |

If the **ai_family** member is **AF_IRDA**, then the **ai_protocol** must be 0.

### `ai_addrlen`

Type: **size_t**

The length, in bytes, of the buffer pointed to by the **ai_addr** member.

### `ai_canonname`

Type: **PCTSTR**

The canonical name for the host.

### `ai_addr`

Type: **struct sockaddr***

A pointer to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. The **ai_addr** member in each returned **addrinfoex** structure points to a filled-in socket address structure. The length, in bytes, of each returned **addrinfoex** structure is specified in the **ai_addrlen** member.

### `ai_blob`

Type: **void***

A pointer to data that is used to return provider-specific namespace information that is associated with the name beyond a list of addresses. The length, in bytes, of the buffer pointed to by **ai_blob** must be specified in the **ai_bloblen** member.

### `ai_bloblen`

Type: **size_t**

The length, in bytes, of the **ai_blob** member.

### `ai_provider`

Type: **LPGUID**

A pointer to the GUID of a specific namespace provider.

### `ai_next`

Type: **struct addrinfoex***

A pointer to the next structure in a linked list. This parameter is set to **NULL** in the last
**addrinfoex** structure of a linked list.

## Remarks

The
**addrinfoex** structure is used by the
[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function to hold host address information. The **addrinfoex** structure is an enhanced version of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) and [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structures. The extra structure members are for blob data and the GUID for the namespace provider. The blob data is used to return additional provider-specific namespace information associated with a name. The format of data in the **ai_blob** member is specific to a particular namespace provider. Currently, blob data is used by the **NS_EMAIL** namespace provider to supply additional information.

The **addrinfoex** structure is an enhanced version of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) and [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure used with [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function. The **GetAddrInfoEx** function allows specifying the namespace provider to resolve the query. For use with the IPv6 and IPv4 protocol, name resolution can be by the Domain Name System (DNS), a local *hosts* file, an email provider (the **NS_EMAIL** namespace), or by other naming mechanisms.

When UNICODE or _UNICODE is defined, **addrinfoex** is defined to **addrinfoexW**, the Unicode version of this structure. The string parameters are defined to the **PWSTR** data type and the **addrinfoexW** structure is used.

When UNICODE or _UNICODE is not defined, **addrinfoex** is defined to **addrinfoexA**, the ANSI version of this structure. The string parameters are of the **PCSTR** data type and the **addrinfoexA** structure is used.

Upon a successful call to [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), a linked list of
**addrinfoex** structures is returned in the *ppResult* parameter passed to the **GetAddrInfoEx** function. The list can be processed by following the pointer provided in the **ai_next** member of each returned
**addrinfoex** structure until a **NULL** pointer is encountered. In each returned
**addrinfoex** structure, the **ai_family**, **ai_socktype**, and **ai_protocol** members correspond to respective arguments in a
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) or [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function call. Also, the **ai_addr** member in each returned
**addrinfoex** structure points to a filled-in socket address structure, the length of which is specified in its **ai_addrlen** member.

#### Examples

The following example demonstrates the use of the **addrinfoex** structure.

```cpp

#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

int __cdecl wmain(int argc, wchar_t ** argv)
{
//--------------------------------
// Declare and initialize variables.
    WSADATA wsaData;
    int iResult;

    ADDRINFOEX *result = NULL;
    ADDRINFOEX *ptr = NULL;
    ADDRINFOEX hints;

    DWORD dwRetval = 0;
    int i = 1;

    DWORD dwNamespace = NS_DNS;
    LPGUID lpNspid = NULL;

    struct sockaddr_in *sockaddr_ipv4;
    struct sockaddr_in6 *sockaddr_ipv6;
//    LPSOCKADDR sockaddr_ip;

    wchar_t ipstringbuffer[46];

    // Validate the parameters
    if (argc != 3) {
        wprintf(L"usage: %ws <hostname> <servicename>\n", argv[0]);
        wprintf(L"       provides protocol-independent translation\n");
        wprintf(L"       from a host name to an IP address\n");
        wprintf(L"%ws example usage\n", argv[0]);
        wprintf(L"   %ws www.contoso.com 0\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iResult);
        return 1;
    }
//--------------------------------
// Setup the hints address info structure
// which is passed to the GetAddrInfoW() function
    memset(&hints, 0, sizeof (hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    wprintf(L"Calling GetAddrInfoEx with following parameters:\n");
    wprintf(L"\tName = %ws\n", argv[1]);
    wprintf(L"\tServiceName (or port) = %ws\n\n", argv[2]);

//--------------------------------
// Call GetAddrInfoEx(). If the call succeeds,
// the aiList variable will hold a linked list
// of ADDRINFOEX structures containing response
// information about the host
    dwRetval = GetAddrInfoEx(argv[1], argv[2],
                             dwNamespace, lpNspid, &hints, &result,
                             NULL, NULL, NULL, NULL);

    if (dwRetval != 0) {
        wprintf(L"GetAddrInfoEx failed with error: %d\n", dwRetval);
        WSACleanup();
        return 1;
    }
    wprintf(L"GetAddrInfoEx returned success\n");

    // Retrieve each address and print out the hex bytes
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        wprintf(L"GetAddrInfoEx response %d\n", i++);
        wprintf(L"\tFlags: 0x%x\n", ptr->ai_flags);
        wprintf(L"\tFamily: ");
        switch (ptr->ai_family) {
        case AF_UNSPEC:
            wprintf(L"Unspecified\n");
            break;
        case AF_INET:
            wprintf(L"AF_INET (IPv4)\n");
            // the InetNtop function is available on Windows Vista and later
            sockaddr_ipv4 = (struct sockaddr_in *) ptr->ai_addr;
            wprintf(L"\tIPv4 address %ws\n",
                    InetNtop(AF_INET, &sockaddr_ipv4->sin_addr, ipstringbuffer,
                             46));

            // We could also use the WSAAddressToString function
            // sockaddr_ip = (LPSOCKADDR) ptr->ai_addr;
            // The buffer length is changed by each call to WSAAddresstoString
            // So we need to set it for each iteration through the loop for safety
            // ipbufferlength = 46;
            // iRetval = WSAAddressToString(sockaddr_ip, (DWORD) ptr->ai_addrlen, NULL,
            //    ipstringbuffer, &ipbufferlength );
            // if (iRetval)
            //    wprintf(L"WSAAddressToString failed with %u\n", WSAGetLastError() );
            // else
            //    wprintf(L"\tIPv4 address %ws\n", ipstringbuffer);
            break;
        case AF_INET6:
            wprintf(L"AF_INET6 (IPv6)\n");
            // the InetNtop function is available on Windows Vista and later
            sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
            wprintf(L"\tIPv6 address %ws\n",
                    InetNtop(AF_INET6, &sockaddr_ipv6->sin6_addr,
                             ipstringbuffer, 46));

            // We could also use WSAAddressToString which also returns the scope ID
            // sockaddr_ip = (LPSOCKADDR) ptr->ai_addr;
            // The buffer length is changed by each call to WSAAddresstoString
            // So we need to set it for each iteration through the loop for safety
            // ipbufferlength = 46;
            //iRetval = WSAAddressToString(sockaddr_ip, (DWORD) ptr->ai_addrlen, NULL,
            //    ipstringbuffer, &ipbufferlength );
            //if (iRetval)
            //    wprintf(L"WSAAddressToString failed with %u\n", WSAGetLastError() );
            //else
            //    wprintf(L"\tIPv6 address %ws\n", ipstringbuffer);
            break;
        default:
            wprintf(L"Other %ld\n", ptr->ai_family);
            break;
        }
        wprintf(L"\tSocket type: ");
        switch (ptr->ai_socktype) {
        case 0:
            wprintf(L"Unspecified\n");
            break;
        case SOCK_STREAM:
            wprintf(L"SOCK_STREAM (stream)\n");
            break;
        case SOCK_DGRAM:
            wprintf(L"SOCK_DGRAM (datagram) \n");
            break;
        case SOCK_RAW:
            wprintf(L"SOCK_RAW (raw) \n");
            break;
        case SOCK_RDM:
            wprintf(L"SOCK_RDM (reliable message datagram)\n");
            break;
        case SOCK_SEQPACKET:
            wprintf(L"SOCK_SEQPACKET (pseudo-stream packet)\n");
            break;
        default:
            wprintf(L"Other %ld\n", ptr->ai_socktype);
            break;
        }
        wprintf(L"\tProtocol: ");
        switch (ptr->ai_protocol) {
        case 0:
            wprintf(L"Unspecified\n");
            break;
        case IPPROTO_TCP:
            wprintf(L"IPPROTO_TCP (TCP)\n");
            break;
        case IPPROTO_UDP:
            wprintf(L"IPPROTO_UDP (UDP) \n");
            break;
        default:
            wprintf(L"Other %ld\n", ptr->ai_protocol);
            break;
        }
        wprintf(L"\tLength of this sockaddr: %d\n", ptr->ai_addrlen);
        wprintf(L"\tCanonical name: %s\n", ptr->ai_canonname);
    }

    FreeAddrInfoEx(result);
    WSACleanup();

    return 0;
}

```

**Note** Ensure that the development environment targets the newest version of *Ws2tcpip.h* which includes structure and function definitions for **ADDRINFOEX** and [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), respectively.

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)