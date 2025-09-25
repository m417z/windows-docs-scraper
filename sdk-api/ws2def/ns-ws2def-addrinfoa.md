# ADDRINFOA structure

## Description

The
**addrinfo** structure is used by the
[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function to hold host address information.

## Members

### `ai_flags`

Type: **int**

Flags that indicate options used in the
[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function.

Supported values for the **ai_flags** member are defined in the *Ws2def.h* header file on the Windows SDK for Windows 7 and later. These values are defined in the *Ws2tcpip.h* header file on the Windows SDK for Windows Server 2008 and Windows Vista. These values are defined in the *Ws2tcpip.h* header file on the Platform SDK for Windows Server 2003, and Windows XP. Supported values for the **ai_flags** member can be a combination of the following options.

| Value | Meaning |
| --- | --- |
| **AI_PASSIVE**<br><br>0x01 | The socket address will be used in a call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. |
| **AI_CANONNAME**<br><br>0x02 | The canonical name is returned in the first **ai_canonname** member. |
| **AI_NUMERICHOST**<br><br>0x04 | The *nodename* parameter passed to the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function must be a numeric string. |
| **AI_ALL**<br><br>0x0100 | If this bit is set, a request is made for IPv6 addresses and IPv4 addresses with **AI_V4MAPPED**.<br><br> This option is supported on Windows Vista and later. |
| **AI_ADDRCONFIG**<br><br>0x0400 | The [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) will resolve only if a global address is configured. The IPv6 and IPv4 loopback address is not considered a valid global address.<br><br> This option is supported on Windows Vista and later. |
| **AI_V4MAPPED**<br><br>0x0800 | If the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) request for IPv6 addresses fails, a name service request is made for IPv4 addresses and these addresses are converted to IPv4-mapped IPv6 address format.<br><br>This option is supported on Windows Vista and later. |
| **AI_NON_AUTHORITATIVE**<br><br>0x04000 | The address information can be from a non-authoritative namespace provider. <br><br>This option is only supported on Windows Vista and later for the **NS_EMAIL** namespace. |
| **AI_SECURE**<br><br>0x08000 | The address information is from a secure channel. <br><br>This option is only supported on Windows Vista and later for the **NS_EMAIL** namespace. |
| **AI_RETURN_PREFERRED_NAMES**<br><br>0x010000 | The address information is for a preferred name for a user. <br><br>This option is only supported on Windows Vista and later for the **NS_EMAIL** namespace. |
| **AI_FQDN**<br><br>0x00020000 | If a flat name (single label) is specified, [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) will return the fully qualified domain name that the name eventually resolved to. The fully qualified domain name is returned in the **ai_canonname** member. <br><br>This is different than **AI_CANONNAME** bit flag that returns the canonical name registered in DNS which may be different than the fully qualified domain name that the flat name resolved to. <br><br>Only one of the **AI_FQDN** and **AI_CANONNAME** bits can be set. The [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function will fail if both flags are present with **EAI_BADFLAGS**.<br><br>This option is supported on Windows 7, Windows Server 2008 R2, and later. |
| **AI_FILESERVER**<br><br>0x00040000 | A hint to the namespace provider that the hostname being queried is being used in a file share scenario. The namespace provider may ignore this hint.<br><br>This option is supported on Windows 7, Windows Server 2008 R2, and later. |

### `ai_family`

Type: **int**

The address family. Possible values for the address family are defined in the *Winsock2.h* header file.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the possible values for the address family are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET** or **AF_INET6**, which are the Internet
address family formats for IPv4 and IPv6. Other options for address family (**AF_NETBIOS** for use with NetBIOS, for example) are supported if a Windows Sockets service provider for the address family is installed. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_UNSPEC** and **PF_UNSPEC**), so either constant can be used.

The following table lists common values for the address family although many other values are possible.

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

The socket type. Possible values for the socket type are defined in the *Winsock2.h* header file.

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

The protocol type. The possible options are specific to the address family and socket type specified. Possible values for the **ai_protocol** are defined in the *Winsock2.h* and *Wsrm.h* header files.

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

Type: **char***

The canonical name for the host.

### `ai_addr`

Type: **struct sockaddr***

A pointer to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. The **ai_addr** member in each returned **addrinfo** structure points to a filled-in socket address structure. The length, in bytes, of each returned **addrinfo** structure is specified in the **ai_addrlen** member.

### `ai_next`

Type: **struct addrinfo***

A pointer to the next structure in a linked list. This parameter is set to **NULL** in the last
**addrinfo** structure of a linked list.

## Remarks

The
**addrinfo** structure is used by the
ANSI [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function to hold host address information.

 The [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure is the version of this structure used by the Unicode [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) function.

Macros in the *Ws2tcpip.h* header file define a **ADDRINFOT** structure and a mixed-case function name of **GetAddrInfo**. The **GetAddrInfo** function should be called with the *nodename* and *servname* parameters of a pointer of type **TCHAR** and the *hints* and *res* parameters of a pointer of type **ADDRINFOT**. When UNICODE or _UNICODE is not defined, **ADDRINFOT** is defined to the **addrinfo** structure and **GetAddrInfo** is defined to [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo), the ANSI version of this function. When UNICODE or _UNICODE is defined, **ADDRINFOT** is defined to the [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure and **GetAddrInfo** is defined to [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow), the Unicode version of this function.

Upon a successful call to [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo), a linked list of
**addrinfo** structures is returned in the *res* parameter passed to the **getaddrinfo** function. The list can be processed by following the pointer provided in the **ai_next** member of each returned
**addrinfo** structure until a **NULL** pointer is encountered. In each returned
**addrinfo** structure, the **ai_family**, **ai_socktype**, and **ai_protocol** members correspond to respective arguments in a
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) or [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function call. Also, the **ai_addr** member in each returned
**addrinfo** structure points to a filled-in socket address structure, the length of which is specified in its **ai_addrlen** member.

### Support for getaddrinfo and the addrinfo struct on older versions of Windows

The [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function that uses the **addrinfo** structure was added to the *Ws2_32.dll* on Windows XP and later. The **addrinfo** structure is defined in the Ws2tcpip.h header file included with the Platform SDK released for Windows XP and later and the Windows SDK released for Windows Vista and later.

To execute an application that uses the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function and the **addrinfo** structure on earlier versions of Windows (Windows 2000), then you need to include the *Ws2tcpip.h* and *Wspiapi.h* files. When the *Wspiapi.h* include file is added, the **getaddrinfo** function is defined to the WspiapiGetAddrInfo inline function in the *Wspiapi.h* file. At runtime, the WspiapiGetAddrInfo function is implemented in such a way that if the *Ws2_32.dll* or the *Wship6.dll* (the file containing **getaddrinfo** in the IPv6 Technology Preview for Windows 2000) does not include **getaddrinfo**, then a version of **getaddrinfo** is implemented inline based on code in the *Wspiapi.h* header file. This inline code will be used on older Windows platforms that do not natively support the **getaddrinfo** function.

The IPv6 protocol is supported on Windows 2000 when the IPv6 Technology Preview for Windows 2000 is installed. Otherwise [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) support on versions of Windows earlier than Windows XP is limited to handling IPv4 name resolution.

The [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) function that uses the [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure is the Unicode version of the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function and associated **addrinfo** structure. The **GetAddrInfoW** function was added to the *Ws2_32.dll* in Windows XP with Service Pack 2 (SP2). The **GetAddrInfoW** function and the **addrinfoW** structure cannot be used on versions of Windows earlier than Windows XP with SP2.

#### Examples

The following code example shows the use of the **addrinfo** structure.

```cpp

#undef UNICODE

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// link with Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int __cdecl main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;
    INT iRetval;

    DWORD dwRetval;

    int i = 1;

    struct addrinfo *result = NULL;
    struct addrinfo *ptr = NULL;
    struct addrinfo hints;

    struct sockaddr_in  *sockaddr_ipv4;
//    struct sockaddr_in6 *sockaddr_ipv6;
    LPSOCKADDR sockaddr_ip;

    char ipstringbuffer[46];
    DWORD ipbufferlength = 46;

    // Validate the parameters
    if (argc != 3) {
        printf("usage: %s <hostname> <servicename>\n", argv[0]);
        printf("       provides protocol-independent translation\n");
        printf("       from an ANSI host name to an IP address\n");
        printf("%s example usage\n", argv[0]);
        printf("   %s www.contoso.com 0\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    //--------------------------------
    // Setup the hints address info structure
    // which is passed to the getaddrinfo() function
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    printf("Calling getaddrinfo with following parameters:\n");
    printf("\tnodename = %s\n", argv[1]);
    printf("\tservname (or port) = %s\n\n", argv[2]);

//--------------------------------
// Call getaddrinfo(). If the call succeeds,
// the result variable will hold a linked list
// of addrinfo structures containing response
// information
    dwRetval = getaddrinfo(argv[1], argv[2], &hints, &result);
    if ( dwRetval != 0 ) {
        printf("getaddrinfo failed with error: %d\n", dwRetval);
        WSACleanup();
        return 1;
    }

    printf("getaddrinfo returned success\n");

    // Retrieve each address and print out the hex bytes
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        printf("getaddrinfo response %d\n", i++);
        printf("\tFlags: 0x%x\n", ptr->ai_flags);
        printf("\tFamily: ");
        switch (ptr->ai_family) {
            case AF_UNSPEC:
                printf("Unspecified\n");
                break;
            case AF_INET:
                printf("AF_INET (IPv4)\n");
                sockaddr_ipv4 = (struct sockaddr_in *) ptr->ai_addr;
                printf("\tIPv4 address %s\n",
                    inet_ntoa(sockaddr_ipv4->sin_addr) );
                break;
            case AF_INET6:
                printf("AF_INET6 (IPv6)\n");
                // the InetNtop function is available on Windows Vista and later
                // sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr;
                // printf("\tIPv6 address %s\n",
                //    InetNtop(AF_INET6, &sockaddr_ipv6->sin6_addr, ipstringbuffer, 46) );

                // We use WSAAddressToString since it is supported on Windows XP and later
                sockaddr_ip = (LPSOCKADDR) ptr->ai_addr;
                // The buffer length is changed by each call to WSAAddresstoString
                // So we need to set it for each iteration through the loop for safety
                ipbufferlength = 46;
                iRetval = WSAAddressToString(sockaddr_ip, (DWORD) ptr->ai_addrlen, NULL,
                    ipstringbuffer, &ipbufferlength );
                if (iRetval)
                    printf("WSAAddressToString failed with %u\n", WSAGetLastError() );
                else
                    printf("\tIPv6 address %s\n", ipstringbuffer);
                break;
            case AF_NETBIOS:
                printf("AF_NETBIOS (NetBIOS)\n");
                break;
            default:
                printf("Other %ld\n", ptr->ai_family);
                break;
        }
        printf("\tSocket type: ");
        switch (ptr->ai_socktype) {
            case 0:
                printf("Unspecified\n");
                break;
            case SOCK_STREAM:
                printf("SOCK_STREAM (stream)\n");
                break;
            case SOCK_DGRAM:
                printf("SOCK_DGRAM (datagram) \n");
                break;
            case SOCK_RAW:
                printf("SOCK_RAW (raw) \n");
                break;
            case SOCK_RDM:
                printf("SOCK_RDM (reliable message datagram)\n");
                break;
            case SOCK_SEQPACKET:
                printf("SOCK_SEQPACKET (pseudo-stream packet)\n");
                break;
            default:
                printf("Other %ld\n", ptr->ai_socktype);
                break;
        }
        printf("\tProtocol: ");
        switch (ptr->ai_protocol) {
            case 0:
                printf("Unspecified\n");
                break;
            case IPPROTO_TCP:
                printf("IPPROTO_TCP (TCP)\n");
                break;
            case IPPROTO_UDP:
                printf("IPPROTO_UDP (UDP) \n");
                break;
            default:
                printf("Other %ld\n", ptr->ai_protocol);
                break;
        }
        printf("\tLength of this sockaddr: %d\n", ptr->ai_addrlen);
        printf("\tCanonical name: %s\n", ptr->ai_canonname);
    }

    freeaddrinfo(result);
    WSACleanup();

    return 0;
}

```

## See also

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)