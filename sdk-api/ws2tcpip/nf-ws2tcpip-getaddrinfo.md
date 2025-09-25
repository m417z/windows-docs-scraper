# getaddrinfo function

## Description

The
**getaddrinfo** function provides protocol-independent translation from an ANSI host name to an address.

## Parameters

### `pNodeName` [in, optional]

A pointer to a **NULL**-terminated ANSI string that contains a host (node) name or a numeric host address string. For the Internet protocol, the numeric host address string is a dotted-decimal IPv4 address or an IPv6 hex address.

### `pServiceName` [in, optional]

A pointer to a **NULL**-terminated ANSI string that contains either a service name or port number represented as a string.

A service name is a string alias for a port number. For example, “http” is an alias for port 80 defined by the Internet Engineering Task Force (IETF) as the default port used by web servers for the HTTP protocol. Possible values for the *pServiceName* parameter when a port number is not specified are listed in the following file:

`%WINDIR%\system32\drivers\etc\services`

### `pHints` [in, optional]

A pointer to an
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure that provides hints about the type of socket the caller supports.

The **ai_addrlen**, **ai_canonname**, **ai_addr**, and **ai_next** members of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure pointed to by the *pHints* parameter must be zero or **NULL**. Otherwise the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function will fail with [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

See the Remarks for more details.

### `ppResult` [out]

A pointer to a linked list of one or more
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structures that contains response information about the host.

## Return value

Success returns zero. Failure returns a nonzero Windows Sockets error code, as found in the
[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Most nonzero error codes returned by the
**getaddrinfo** function map to the set of errors outlined by Internet Engineering Task Force (IETF) recommendations. The following table lists these error codes and their WSA equivalents. It is recommended that the WSA error codes be used, as they offer familiar and comprehensive error information for Winsock programmers.

| Error value | WSA equivalent | Description |
| --- | --- | --- |
| EAI_AGAIN | [WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A temporary failure in name resolution occurred. |
| EAI_BADFLAGS | [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | An invalid value was provided for the **ai_flags** member of the *pHints* parameter. |
| EAI_FAIL | [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A nonrecoverable failure in name resolution occurred. |
| EAI_FAMILY | [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The **ai_family** member of the *pHints* parameter is not supported. |
| EAI_MEMORY | [WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A memory allocation failure occurred. |
| EAI_NONAME | [WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The name does not resolve for the supplied parameters or the *pNodeName* and *pServiceName* parameters were not provided. |
| EAI_SERVICE | [WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The *pServiceName* parameter is not supported for the specified **ai_socktype** member of the *pHints* parameter. |
| EAI_SOCKTYPE | [WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The **ai_socktype** member of the *pHints* parameter is not supported. |

Use the
[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora) function to print error messages based on the EAI codes returned by the
**getaddrinfo** function. The
**gai_strerror** function is provided for compliance with IETF recommendations, but it is not thread safe. Therefore, use of traditional Windows Sockets functions such as
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) is recommended.

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An address incompatible with the requested protocol was used. This error is returned if the **ai_family** member of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure pointed to by the *pHints* parameter is not supported. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied. This error is returned if an invalid value was provided for the **ai_flags** member of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure pointed to by the *pHints* parameter. |
| **[WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The support for the specified socket type does not exist in this address family. This error is returned if the **ai_socktype** member of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure pointed to by the *pHints* parameter is not supported. |
| **[WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No such host is known. This error is returned if the name does not resolve for the supplied parameters or the *pNodeName* and *pServiceName* parameters were not provided. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred during a database lookup. This error is returned if nonrecoverable error in name resolution occurred. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server. This error is returned when a temporary failure in name resolution occurred. |
| **[WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified class was not found. The *pServiceName* parameter is not supported for the specified **ai_socktype** member of the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure pointed to by the *pHints* parameter. |

## Remarks

The **getaddrinfo** function is the ANSI version of a function that provides protocol-independent translation from host name to address. The Unicode version of this function is [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow). Developers are encouraged to use the **GetAddrInfoW** Unicode function rather than the **getaddrinfo** ANSI function.

The **getaddrinfo** function returns results for the **NS_DNS** namespace. The **getaddrinfo** function aggregates all responses if more than
one namespace provider returns information. For use with the IPv6 and IPv4 protocol, name resolution can be by the Domain Name System (DNS), a local *hosts* file, or by other naming mechanisms for the **NS_DNS** namespace.

Another name that can be used for the **getaddrinfo** function is **GetAddrInfoA**. Macros in the *Ws2tcpip.h* header file define **GetAddrInfoA** to **getaddrinfo**.

Macros in the *Ws2tcpip.h* header file define a mixed-case function name of **GetAddrInfo** and a **ADDRINFOT** structure. This **GetAddrInfo** function should be called with the *pNodeName* and *pServiceName* parameters of a pointer of type **TCHAR** and the *pHints* and *ppResult* parameters of a pointer of type **ADDRINFOT**. When UNICODE or _UNICODE is not defined, **GetAddrInfo** is defined to **getaddrinfo**, the ANSI version of the function, and **ADDRINFOT** is defined to the [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure. When **UNICODE** or **_UNICODE** is defined, **GetAddrInfo** is defined to [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow), the Unicode version of the function, and **ADDRINFOT** is defined to the [addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow) structure.

The parameter names and parameter types for the **getaddrinfo** function defined in the *Ws2tcpip.h* header file on the Platform Software Development Kit (SDK) for Windows Server 2003, and Windows XP were different.

One or both of the *pNodeName* or *pServiceName* parameters must point to a **NULL**-terminated ANSI string; generally both are provided.

Upon success, a linked list of
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structures is returned in the *ppResult* parameter. The list can be processed by following the pointer provided in the **ai_next** member of each returned
**addrinfo** structure until a **NULL** pointer is encountered. In each returned
**addrinfo** structure, the **ai_family**, **ai_socktype**, and **ai_protocol** members correspond to respective arguments in a
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) or [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function call. Also, the **ai_addr** member in each returned
**addrinfo** structure points to a filled-in socket address structure, the length of which is specified in its **ai_addrlen** member.

If the *pNodeName* parameter points to a computer name, all permanent addresses for the computer that can be used as a source address are returned. On Windows Vista and later, these addresses would include all unicast IP addresses returned by the [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) or [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) functions in which the **SkipAsSource** member is set to false in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure.

If the *pNodeName* parameter points to a string equal to "localhost", all loopback addresses on the local computer are returned.

If the *pNodeName* parameter contains an empty string, all registered addresses on the local computer are returned.

On Windows Server 2003 and later if the *pNodeName* parameter points to a string equal to "..localmachine", all registered addresses on the local computer are returned.

If the *pNodeName* parameter refers to a cluster virtual server name, only virtual server addresses are returned. On Windows Vista and later, these addresses would include all unicast IP addresses returned by the [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) or [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) functions in which the **SkipAsSource** member is set to true in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure. See [Windows Clustering](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/windows-clustering) for more information about clustering.

Windows 7 with Service Pack 1 (SP1) and Windows Server 2008 R2 with Service Pack 1 (SP1) add support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This also changes the behavior such that if the **SkipAsSource** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS.

A hotfix is available for Windows 7 and Windows Server 2008 R2 that adds support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes behavior such that if the **SkipAsSource** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS. For more information, see [Knowledge Base (KB) 2386184](https://support.microsoft.com/kb/2386184).

A similar hotfix is also available for Windows Vista with Service Pack 2 (SP2) and Windows Server 2008 with Service Pack 2 (SP2) that adds support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes behavior such that if the **SkipAsSource** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS.

Callers of the
**getaddrinfo** function can provide hints about the type of socket supported through an
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure pointed to by the *pHints* parameter. When the *pHints* parameter is used, the following rules apply to its associated
**addrinfo** structure:

* A value of **AF_UNSPEC** for **ai_family** indicates the caller will accept only the **AF_INET** and **AF_INET6** address families. Note that **AF_UNSPEC** and **PF_UNSPEC** are the same.
* A value of zero for **ai_socktype** indicates the caller will accept any socket type.
* A value of zero for **ai_protocol** indicates the caller will accept any protocol.
* The **ai_addrlen** member must be set to zero.
* The **ai_canonname** member must be set to **NULL**.
* The **ai_addr** member must be set to **NULL**.
* The **ai_next** member must be set to **NULL**.

A value of **AF_UNSPEC** for **ai_family** indicates the caller will accept any protocol family. This value can be used to return both IPv4 and IPv6 addresses for the host name pointed to by the *pNodeName* parameter. On Windows Server 2003 and Windows XP, IPv6 addresses are returned only if IPv6 is installed on the local computer.

Other values in the
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure provided in the *pHints* parameter indicate specific requirements. For example, if the caller handles only IPv4 and does not handle IPv6, the **ai_family** member should be set to AF_INET. For another example, if the caller handles only TCP and does not handle UDP, the **ai_socktype** member should be set to **SOCK_STREAM**.

If the *pHints* parameter is a **NULL** pointer, the
**getaddrinfo** function treats it as if the
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure in *pHints* were initialized with its **ai_family** member set to **AF_UNSPEC** and all other members set to zero.

On Windows Vista and later when **getaddrinfo** is called from a service, if the operation is the result of a user process calling the service, then the service should impersonate the user. This is to allow security to be properly enforced.

The
**getaddrinfo** function can be used to convert a text string representation of an IP address to an [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure that contains a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for the IP address and other information. To be used in this way, the string pointed to by the *pNodeName* parameter must contain a text representation of an IP address and the **addrinfo** structure pointed to by the *pHints* parameter must have the AI_NUMERICHOST flag set in the **ai_flags** member. The string pointed to by the *pNodeName* parameter may contain a text representation of either an IPv4 or an IPv6 address. The text IP address is converted to an **addrinfo** structure pointed to by the *ppResult* parameter. The returned **addrinfo** structure contains a **sockaddr** structure for the IP address along with addition information about the IP address. For this method to work with an IPv6 address string on Windows Server 2003 and Windows XP, the IPv6 protocol must be installed on the local computer. Otherwise, the [WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error is returned.

### Freeing Address Information from Dynamic Allocation

All information returned by the
**getaddrinfo** function pointed to by the *ppResult* parameter is dynamically allocated, including all
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structures, socket address structures, and canonical host name strings pointed to by
**addrinfo** structures. Memory allocated by a successful call to this function must be released with a subsequent call to [freeaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfo).

### Example Code

The following code example shows how to use the **getaddrinfo** function.

```cpp
#undef UNICODE

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

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
        printf("getaddrinfo provides protocol-independent translation\n");
        printf("   from an ANSI host name to an IP address\n");
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

**Note** Ensure that the development environment targets the newest version of *Ws2tcpip.h* which includes structure and function definitions for [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) and **getaddrinfo**, respectively.

### Internationalized Domain Names

Internet host names typically consist of a very restricted set of characters:

* Upper and lower case ASCII letters from the English alphabet.
* Digits from 0 to 9.
* ASCII hyphen characters.

With the growth of the Internet, there is a growing need to identify Internet host names for other languages not represented by the ASCII character set. Identifiers which facilitate this need and allow non-ASCII characters (Unicode) to be represented as special ASCII character strings are known as Internationalized Domain Names (IDNs). A mechanism called
Internationalizing Domain Names in Applications (IDNA) is used to handle
IDNs in a standard fashion. The specifications for IDNs and IDNA are documented in [RFC 3490](http://tools.ietf.org/html/rfc3490), [RTF 5890](http://tools.ietf.org/html/rfc5890), and [RFC 6365](http://tools.ietf.org/html/rfc6365) published by the Internet Engineering Task Force (IETF).

On Windows 8 and Windows Server 2012, the **getaddrinfo** function provides support for Internationalized Domain Name (IDN) parsing applied to the name passed in the *pNodeName* parameter. Winsock performs Punycode/IDN encoding and conversion. This behavior can be disabled using the **AI_DISABLE_IDN_ENCODING** flag discussed below.

On Windows 7 and Windows Server 2008 R2 or earlier, the **getaddrinfo** function does not currently provide support IDN parsing applied to the name passed in the *pNodeName* parameter. Winsock does not perform any Punycode/IDN conversion. The wide character version of the **GetAddrInfo** function does not use Punycode to convert an IDN as per [RFC 3490](http://tools.ietf.org/html/rfc3490). The wide character version of the **GetAddrInfo** function when querying DNS encodes the Unicode name in UTF-8 format, the format used by Microsoft DNS servers in an enterprise environment.

Several functions on Windows Vista and later support conversion between Unicode labels in an IDN to their ASCII equivalents. The resulting representation of each Unicode label contains only ASCII characters and starts with the xn-- prefix if the Unicode label contained any non-ASCII characters. The reason for this is to support existing DNS servers on the Internet, since some DNS tools and servers only support ASCII characters (see [RFC 3490](http://tools.ietf.org/html/rfc3490)).

The [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii) function uses Punycode to convert an IDN to the ASCII representation of the original Unicode string using the standard algorithm defined in [RFC 3490](http://tools.ietf.org/html/rfc3490). The [IdnToUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntounicode) function converts the ASCII form of an IDN to the normal Unicode UTF-16 encoding syntax. For more information and links to related draft standards, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

The [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii) function can be used to convert an IDN name to the ASCII form that then can be passed in the *pNodeName* parameter to the **getaddrinfo** function. To pass this IDN name to the **GetAddrInfo** function when the wide character version of this function is used (when UNICODE or _UNICODE is defined), you can use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to convert the **CHAR** string into a **WCHAR** string.

### Use of ai_flags in the pHints parameter

Flags in the **ai_flags** member of the optional
[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure provided in the *pHints* parameter modify the behavior of the function.

These flag bits are defined in the *Ws2def.h* header file on the Microsoft Windows Software Development Kit (SDK) for Windows 7. These flag bits are defined in the *Ws2tcpip.h* header file on the Windows SDK for Windows Server 2008 and Windows Vista. These flag bits are defined in the *Ws2tcpip.h* header file on the Platform SDK for Windows Server 2003, and Windows XP.

The flag bits can be a combination of the following:

| Flag Bits | Description |
| --- | --- |
| **AI_PASSIVE** | Setting the **AI_PASSIVE** flag indicates the caller intends to use the returned socket address structure in a call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. When the **AI_PASSIVE** flag is set and *pNodeName* is a **NULL** pointer, the IP address portion of the socket address structure is set to **INADDR_ANY** for IPv4 addresses and **IN6ADDR_ANY_INIT** for IPv6 addresses.<br><br>When the **AI_PASSIVE** flag is not set, the returned socket address structure is ready for a call to the [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function for a connection-oriented protocol, or ready for a call to either the **connect**, [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto), or [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) functions for a connectionless protocol. If the *pNodeName* parameter is a **NULL** pointer in this case, the IP address portion of the socket address structure is set to the loopback address. |
| **AI_CANONNAME** | If neither **AI_CANONNAME** nor **AI_NUMERICHOST** is used, the **getaddrinfo** function attempts resolution. If a literal string is passed **getaddrinfo** attempts to convert the string, and if a host name is passed the **getaddrinfo** function attempts to resolve the name to an address or multiple addresses.<br><br>When the **AI_CANONNAME** bit is set, the *pNodeName* parameter cannot be **NULL**. Otherwise the **getaddrinfo** function will fail with [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).<br><br>When the **AI_CANONNAME** bit is set and the **getaddrinfo** function returns success, the **ai_canonname** member in the *ppResult* parameter points to a **NULL**-terminated string that contains the canonical name of the specified node.<br><br>**Note** The **getaddrinfo** function can return success when the **AI_CANONNAME** flag is set, yet the **ai_canonname** member in the associated [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure is **NULL**. Therefore, the recommended use of the **AI_CANONNAME** flag includes testing whether the **ai_canonname** member in the associated **addrinfo** structure is **NULL**. |
| **AI_NUMERICHOST** | When the **AI_NUMERICHOST** bit is set, the *pNodeName* parameter must contain a non-**NULL** numeric host address string, otherwise the **EAI_NONAME** error is returned. This flag prevents a name resolution service from being called. |
| **AI_NUMERICSERV** | When the **AI_NUMERICSERV** bit is set, the *pServiceName* parameter must contain a non-**NULL** numeric port number, otherwise the **EAI_NONAME** error is returned. This flag prevents a name resolution service from being called. <br><br>The **AI_NUMERICSERV** flag is defined on Windows SDK for Windows Vista and later. The **AI_NUMERICSERV** flag is not supported by Microsoft providers. |
| **AI_ALL** | If the **AI_ALL** bit is set, a request is made for IPv6 addresses and IPv4 addresses with **AI_V4MAPPED**. <br><br>The **AI_ALL** flag is defined on the Windows SDK for Windows Vista and later. The **AI_ALL** flag is supported on Windows Vista and later. |
| **AI_ADDRCONFIG** | If the **AI_ADDRCONFIG** bit is set, **getaddrinfo** will resolve only if a global address is configured. If **AI_ADDRCONFIG** flag is specified, IPv4 addresses shall be returned only if an IPv4 address is configured on the local system, and IPv6 addresses shall be returned only if an IPv6 address is configured on the local system. The IPv4 or IPv6 loopback address is not considered a valid global address.<br><br>The **AI_ADDRCONFIG** flag is defined on the Windows SDK for Windows Vista and later. The **AI_ADDRCONFIG** flag is supported on Windows Vista and later. |
| **AI_V4MAPPED** | If the **AI_V4MAPPED** bit is set and a request for IPv6 addresses fails, a name service request is made for IPv4 addresses and these addresses are converted to IPv4-mapped IPv6 address format.<br><br>The **AI_V4MAPPED** flag is defined on the Windows SDK for Windows Vista and later. The **AI_V4MAPPED** flag is supported on Windows Vista and later. |
| **AI_NON_AUTHORITATIVE** | If the **AI_NON_AUTHORITATIVE** bit is set, the **NS_EMAIL** namespace provider returns both authoritative and non-authoritative results. If the **AI_NON_AUTHORITATIVE** bit is not set, the **NS_EMAIL** namespace provider returns only authoritative results. <br><br>The **AI_NON_AUTHORITATIVE** flag is defined on the Windows SDK for Windows Vista and later. The **AI_NON_AUTHORITATIVE** flag is supported on Windows Vista and later and applies only to the **NS_EMAIL** namespace. |
| **AI_SECURE** | If the **AI_SECURE** bit is set, the **NS_EMAIL** namespace provider will return results that were obtained with enhanced security to minimize possible spoofing.<br><br>The **AI_SECURE** flag is defined on the Windows SDK for Windows Vista and later. The **AI_SECURE** flag is supported on Windows Vista and later and applies only to the **NS_EMAIL** namespace. |
| **AI_RETURN_PREFERRED_NAMES** | If the **AI_RETURN_PREFERRED_NAMES** is set, then no name should be provided in the *pNodeName* parameter. The **NS_EMAIL** namespace provider will return preferred names for publication.<br><br>The **AI_RETURN_PREFERRED_NAMES** flag is defined on the Windows SDK for Windows Vista and later. The **AI_RETURN_PREFERRED_NAMES** flag is supported on Windows Vista and later and applies only to the **NS_EMAIL** namespace. |
| **AI_FQDN** | If the **AI_FQDN** is set and a flat name (single label) is specified, **getaddrinfo** will return the fully qualified domain name that the name eventually resolved to. The fully qualified domain name is returned in the **ai_canonname** member in the associated [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure. This is different than **AI_CANONNAME** bit flag that returns the canonical name registered in DNS which may be different than the fully qualified domain name that the flat name resolved to. Only one of the **AI_FQDN** and **AI_CANONNAME** bits can be set. The **getaddrinfo** function will fail if both flags are present with **EAI_BADFLAGS**.<br><br>When the **AI_FQDN** bit is set, the *pNodeName* parameter cannot be **NULL**. Otherwise the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function will fail with [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).<br><br>**Windows 7:** The **AI_FQDN** flag is defined on the Windows SDK for Windows 7 and later. The **AI_FQDN** flag is supported on Windows 7 and later. |
| **AI_FILESERVER** | If the **AI_FILESERVER** is set, this is a hint to the namespace provider that the hostname being queried is being used in file share scenario. The namespace provider may ignore this hint.<br><br>**Windows 7:** The **AI_FILESERVER** flag is defined on the Windows SDK for Windows 7 and later. The **AI_FILESERVER** flag is supported on Windows 7 and later. |

### Example code using AI_NUMERICHOST

The following code example shows how to use the **getaddrinfo** function to convert a text string representation of an IP address to an [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure that contains a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for the IP address and other information.

```cpp
#undef UNICODE

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

int __cdecl main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    DWORD dwRetval;

    int i = 1;

    struct addrinfo *result = NULL;
    struct addrinfo *ptr = NULL;
    struct addrinfo hints;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s <IP Address String>\n", argv[0]);
        printf("  getaddrinfo determines the IP binary network address\n");
        printf("       %s 207.46.197.32\n", argv[0]);  /* www.contoso.com */
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
    hints.ai_flags = AI_NUMERICHOST;
    hints.ai_family = AF_UNSPEC;
//    hints.ai_socktype = SOCK_STREAM;
//    hints.ai_protocol = IPPROTO_TCP;

//--------------------------------
// Call getaddrinfo(). If the call succeeds,
// the result variable will hold a linked list
// of addrinfo structures containing response
// information
    dwRetval = getaddrinfo(argv[1], NULL, &hints, &result);
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
                break;
            case AF_INET6:
                printf("AF_INET6 (IPv6)\n");
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

### Support for getaddrinfo on Windows 2000 and older versions

The **getaddrinfo** function was added to the Ws2_32.dll on Windows XP and later. To execute an application that uses this function on earlier versions of Windows, then you need to include the *Ws2tcpip.h* and *Wspiapi.h* files. When the *Wspiapi.h* include file is added, the **getaddrinfo** function is defined to the **WspiapiGetAddrInfo** inline function in the *Wspiapi.h* file. At runtime, the **WspiapiGetAddrInfo** function is implemented in such a way that if the Ws2_32.dll or the Wship6.dll (the file containing **getaddrinfo** in the IPv6 Technology Preview for Windows 2000) does not include **getaddrinfo**, then a version of **getaddrinfo** is implemented inline based on code in the Wspiapi.h header file. This inline code will be used on older Windows platforms that do not natively support the **getaddrinfo** function.

The IPv6 protocol is supported on Windows 2000 when the IPv6 Technology Preview for Windows 2000 is installed. Otherwise **getaddrinfo** support on versions of Windows earlier than Windows XP is limited to handling IPv4 name resolution.

The [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) function is the Unicode version of **getaddrinfo**. The **GetAddrInfoW** function was added to the Ws2_32.dll in Windows XP with Service Pack 2 (SP2). The **GetAddrInfoW** function cannot be used on versions of Windows earlier than Windows XP with SP2.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii)

[IdnToUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntounicode)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw)

[addrinfoex2](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoex2w)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[freeaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfo)

[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)