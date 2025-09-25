# GetAddrInfoExA function

## Description

The
**GetAddrInfoEx** function provides protocol-independent name resolution with additional parameters to qualify which namespace providers should handle the request.

## Parameters

### `pName` [in, optional]

A pointer to a **NULL**-terminated string containing a host (node) name or a numeric host address string. For the Internet protocol, the numeric host address string is a dotted-decimal IPv4 address or an IPv6 hex address.

### `pServiceName` [in, optional]

A pointer to an optional **NULL**-terminated string that contains either a service name or port number represented as a string.

A service name is a string alias for a port number. For example, “http” is an alias for port 80 defined by the Internet Engineering Task Force (IETF) as the default port used by web servers for the HTTP protocol. Possible values for the *pServiceName* parameter when a port number is not specified are listed in the following file:

`%WINDIR%\system32\drivers\etc\services`

### `dwNameSpace` [in]

An optional namespace identifier that determines which namespace providers are queried. Passing a specific namespace identifier will result in only namespace providers that support the specified namespace being queried. Specifying **NS_ALL** will result in all installed and active namespace providers being queried.

Options for the *dwNameSpace* parameter are listed in the *Winsock2.h* include file. Several namespace providers are added on Windows Vista and later. Other namespace providers can be installed, so the following possible values are only those commonly available. Many other values are possible.

| Value | Meaning |
| --- | --- |
| **NS_ALL**<br><br>0 | All installed and active namespaces. |
| **NS_DNS**<br><br>12 | The domain name system (DNS) namespace. |
| **NS_NETBT**<br><br>13 | The NetBIOS over TCP/IP (NETBT) namespace. |
| **NS_WINS**<br><br>14 | The Windows Internet Naming Service (NS_WINS) namespace. |
| **NS_NLA**<br><br>15 | The network location awareness (NLA) namespace. <br><br>This namespace identifier is supported on Windows XP and later. |
| **NS_BTH**<br><br>16 | The Bluetooth namespace. <br><br>This namespace identifier is supported on Windows Vista and later. |
| **NS_NTDS**<br><br>32 | The Windows NT Directory Services (NS_NTDS) namespace. |
| **NS_EMAIL**<br><br>37 | The email namespace. <br><br>This namespace identifier is supported on Windows Vista and later. |
| **NS_PNRPNAME**<br><br>38 | The peer-to-peer namespace for a specific peer name. <br><br>This namespace identifier is supported on Windows Vista and later. |
| **NS_PNRPCLOUD**<br><br>39 | The peer-to-peer namespace for a collection of peer names. <br><br>This namespace identifier is supported on Windows Vista and later. |

### `lpNspId` [in, optional]

A pointer to an optional GUID of a specific namespace provider to query in the case where multiple namespace providers are registered under a single namespace such as **NS_DNS**. Passing the GUID for specific namespace provider will result in only the specified namespace provider being queried. The [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa) function can be called to retrieve the GUID for a namespace provider.

### `hints` [in, optional]

A pointer to an
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure that provides hints about the type of socket the caller supports.

The **ai_addrlen**, **ai_canonname**, **ai_addr**, and **ai_next** members of the [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure pointed to by the *pHints* parameter must be zero or **NULL**. Otherwise the **GetAddrInfoEx** function will fail with [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

See the Remarks for more details.

### `ppResult` [out]

A pointer to a linked list of one or more
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structures that contains response information about the host.

### `timeout` [in, optional]

An optional parameter indicating the time, in milliseconds, to wait for a response from the namespace provider before aborting the call.

This parameter is only supported when the **UNICODE** or **_UNICODE** macro has been defined in the sources before calling the **GetAddrInfoEx** function. Otherwise, this parameter is currently reserved and must be set to **NULL** since a *timeout* option is not supported.

### `lpOverlapped` [in, optional]

An optional pointer to an overlapped structure used for asynchronous operation.

This parameter is only supported when the **UNICODE** or **_UNICODE** macro has been defined in the sources before calling the **GetAddrInfoEx** function.

On Windows 8 and Windows Server 2012, if no *lpCompletionRoutine* parameter is specified, the **hEvent** member of the **OVERLAPPED** structure must be set to a manual-reset event to be called upon completion of an asynchronous call. If a completion routine has been specified, the **hEvent** member must be NULL. When the event specified by **hEvent** has been set, the result of the operation can be retrieved by calling [GetAddrInfoExOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexoverlappedresult) function.

On Windows 8 and Windows Server 2012 whenever the **UNICODE** or **_UNICODE** macro is not defined, this parameter is currently reserved and must be set to **NULL**.

On Windows 7 and Windows Server 2008 R2 or earlier, this parameter is currently reserved and must be set to **NULL** since asynchronous operations are not supported.

### `lpCompletionRoutine` [in, optional]

An optional pointer to a function to be invoked upon successful completion for asynchronous operations.

This parameter is only supported when the **UNICODE** or **_UNICODE** macro has been defined in the sources before calling the **GetAddrInfoEx** function.

If this parameter is specified, it must be a pointer to a function with the following signature:

```cpp
typedef
void
(CALLBACK * LPLOOKUPSERVICE_COMPLETION_ROUTINE)(
    __in      DWORD    dwError,
    __in      DWORD    dwBytes,
    __in      LPWSAOVERLAPPED lpOverlapped
    );

```

When the asynchronous operation has completed, the completion routine will be invoked with *lpOverlapped* parameter set to the value of *lpOverlapped* parameter passed to **GetAddrInfoEx**. The **Pointer** member of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure will be set to the value of the *ppResult* parameter of the original call. If the **Pointer** member points to a non-NULL pointer to the [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure, it is the caller’s responsibility to call [FreeAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfoex) to free the **addrinfoex** structure. The *dwError* parameter passed to the completion routine will be set to a Winsock error code. The *dwBytes* parameter is reserved for future use and must be ignored.

On Windows 8 and Windows Server 2012 whenever the **UNICODE** or **_UNICODE** macro is not defined, this parameter is currently reserved and must be set to **NULL**.

On Windows 7 and Windows Server 2008 R2 or earlier, this parameter is currently reserved and must be set to **NULL** since asynchronous operations are not supported.

### `lpNameHandle` [out, optional]

An optional pointer used only for asynchronous operations.

This parameter is only supported when the **UNICODE** or **_UNICODE** macro has been defined in the sources before calling the **GetAddrInfoEx** function.

On Windows 8 and Windows Server 2012, if the **GetAddrInfoEx** function will complete asynchronously, the pointer returned in this field may be used with the **GetAddrInfoExCancel** function. The handle returned is valid when **GetAddrInfoEx** returns until the completion routine is called, the event is triggered, or [GetAddrInfoExCancel](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexcancel) function is called with this handle.

On Windows 8 and Windows Server 2012 whenever the **UNICODE** or **_UNICODE** macro is not defined, this parameter is currently reserved and must be set to **NULL**.

On Windows 7 and Windows Server 2008 R2 or earlier, this parameter is currently reserved and must be set to **NULL** since asynchronous operations are not supported.

## Return value

On success, **GetAddrInfoEx** returns **NO_ERROR** (0). Failure returns a nonzero Windows Sockets error code, as found in the
[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Most nonzero error codes returned by the
**GetAddrInfoEx** function map to the set of errors outlined by Internet Engineering Task Force (IETF) recommendations. The following table shows these error codes and their WSA equivalents. It is recommended that the WSA error codes be used, as they offer familiar and comprehensive error information for Winsock programmers.

| Error value | WSA equivalent | Description |
| --- | --- | --- |
| EAI_AGAIN | [WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A temporary failure in name resolution occurred. |
| EAI_BADFLAGS | [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | An invalid parameter was provided. This error is returned if any of the reserved parameters are not **NULL**. This error is also returned if an invalid value was provided for the **ai_flags** member of the *pHints* parameter. |
| EAI_FAIL | [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A nonrecoverable failure in name resolution occurred. |
| EAI_FAMILY | [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The **ai_family** member of the *pHints* parameter is not supported. |
| EAI_MEMORY | [WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A memory allocation failure occurred. |
| EAI_NONAME | [WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The name does not resolve for the supplied parameters or the *pName* and *pServiceName* parameters were not provided. |
| EAI_SERVICE | [WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The *pServiceName* parameter is not supported for the specified **ai_socktype** member of the *pHints* parameter. |
| EAI_SOCKTYPE | [WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The **ai_socktype** member of the *pHints* parameter is not supported. |

Use the
[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora) function to print error messages based on the EAI codes returned by the
**GetAddrInfoEx** function. The
**gai_strerror** function is provided for compliance with IETF recommendations, but it is not thread safe. Therefore, use of traditional Windows Sockets functions such as
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) is recommended.

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An address incompatible with the requested protocol was used. This error is returned if the **ai_family** member of the [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure pointed to by the *pHints* parameter is not supported. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied. This error is returned if an invalid value was provided for the **ai_flags** member of the [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure pointed to by the *pHints* parameter. This error is also returned when the *dwNameSpace* parameter is NS_PNRPNAME or NS_PNRPCLOUD and the peer-to-peer name service is not operating. |
| **[WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The support for the specified socket type does not exist in this address family. This error is returned if the **ai_socktype** member of the [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure pointed to by the *pHints* parameter is not supported. |
| **[WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No such host is known. This error is returned if the name does not resolve for the supplied parameters or the *pName* and *pServiceName* parameters were not provided. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred during a database lookup. This error is returned if nonrecoverable error in name resolution occurred. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No such service is known. The service cannot be found in the specified name space. This error is returned if the *pName* or *pServiceName* parameter is not found for the namespace specified in the *dwNameSpace* parameter or the namespace specified in the *dwNameSpace* parameter is not installed. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server. This error is returned when a temporary failure in name resolution occurred. |
| **[WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified class was not found. The *pServiceName* parameter is not supported for the specified **ai_socktype** member of the [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure pointed to by the *pHints* parameter. |

## Remarks

The **GetAddrInfoEx** function provides protocol-independent translation from host name to address and from service name to port number. The **GetAddrInfoEx** function is an enhanced version of the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) and [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) functions. The **GetAddrInfoEx** function allows specifying the namespace provider to resolve the query.

The **GetAddrInfoEx** function aggregates and returns results from multiple namespace providers, unless a specific namespace provider is specified. For use with the IPv6 and IPv4 protocol, name resolution can be by the Domain Name System (DNS), a local *hosts* file, an email provider (the **NS_EMAIL** namespace), or by other naming mechanisms.

When UNICODE or _UNICODE is defined, **GetAddrInfoEx** is defined to **GetAddrInfoExW**, the Unicode version of this function. The string parameters are defined to the **PWSTR** data type and the **ADDRINFOEXW** structure is used. On Windows 8 and Windows Server 2012, the *timeout*, *lpOverlapped*, *lpCompletionRoutine*, and *lpNameHandle* parameters may be used to call the **GetAddrInfoEx** function so that it can complete asynchronously.

When UNICODE or _UNICODE is not defined, **GetAddrInfoEx** is defined to **GetAddrInfoExA**, the ANSI version of this function. The string parameters are of the **PCSTR** data type and the **ADDRINFOEXA** structure is used. The *timeout*, *lpOverlapped*, *lpCompletionRoutine*, and *lpNameHandle* parameters must be set to **NULL**.

One or both of the *pName* or *pServiceName* parameters must point to a **NULL**-terminated string. Generally both are provided.

Upon success, a linked list of
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structures is returned in the *ppResult* parameter. The list can be processed by following the pointer provided in the **ai_next** member of each returned
**addrinfoex** structure until a **NULL** pointer is encountered. In each returned
**addrinfoex** structure, the **ai_family**, **ai_socktype**, and **ai_protocol** members correspond to respective arguments in a
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) or [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) function call. Also, the **ai_addr** member in each returned
**addrinfoex** structure points to a filled-in socket address structure, the length of which is specified in its **ai_addrlen** member.

If the *pName* parameter points to a computer name, all permanent addresses for the computer that can be used as a source address are returned. On Windows Vista and later, these addresses would include all unicast IP addresses returned by the [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) or [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) functions in which the **SkipAsSource** member is set to false in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure.

If the *pName* parameter points to a string equal to "localhost", all loopback addresses on the local computer are returned.

If the *pName* parameter contains an empty string, all registered addresses on the local computer are returned.

On Windows Server 2003 and later if the *pName* parameter points to a string equal to "..localmachine", all registered addresses on the local computer are returned.

If the *pName* parameter refers to a cluster virtual server name, only virtual server addresses are returned. On Windows Vista and later, these addresses would include all unicast IP addresses returned by the [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) or [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) functions in which the **SkipAsSource** member is set to true in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure. See [Windows Clustering](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/windows-clustering) for more information about clustering.

Windows 7 with Service Pack 1 (SP1) and Windows Server 2008 R2 with Service Pack 1 (SP1) add support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This also changes the behavior such that if the **SkipAsSource** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS.

A hotfix is available for Windows 7 and Windows Server 2008 R2 that adds support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes behavior such that if the **SkipAsSource** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS. For more information, see [Knowledge Base (KB) 2386184](https://support.microsoft.com/kb/2386184).

A similar hotfix is also available for Windows Vista with Service Pack 2 (SP2) and Windows Server 2008 with Service Pack 2 (SP2) that adds support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes behavior such that if the **SkipAsSource** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS.

Callers of the
**GetAddrInfoEx** function can provide hints about the type of socket supported through an
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure pointed to by the *pHints* parameter. When the *pHints* parameter is used, the following rules apply to its associated
**addrinfoex** structure:

* A value of **AF_UNSPEC** for **ai_family** indicates the caller will accept only the **AF_INET** and **AF_INET6** address families. Note that **AF_UNSPEC** and **PF_UNSPEC** are the same.
* A value of zero for **ai_socktype** indicates the caller will accept any socket type.
* A value of zero for **ai_protocol** indicates the caller will accept any protocol.
* The **ai_addrlen** member must be set to zero.
* The **ai_canonname** member must be set to **NULL**.
* The **ai_addr** member must be set to **NULL**.
* The **ai_next** member must be set to **NULL**.

Other values in the
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure provided in the *pHints* parameter indicate specific requirements. For example, if the caller handles only IPv4 and does not handle IPv6, the **ai_family** member should be set to **AF_INET**. For another example, if the caller handles only TCP and does not handle UDP, the **ai_socktype** member should be set to **SOCK_STREAM**.

If the *pHints* parameter is a **NULL** pointer, the
**GetAddrInfoEx** function treats it as if the
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure in *pHints* were initialized with its **ai_family** member set to **AF_UNSPEC** and all other members set to **NULL** or zero.

When **GetAddrInfoEx** is called from a service, if the operation is the result of a user process calling the service, the service should impersonate the user. This is to allow security to be properly enforced.

The
**GetAddrInfoEx** function can be used to convert a text string representation of an IP address to an [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure that contains a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for the IP address and other information. To be used in this way, the string pointed to by the *pName* parameter must contain a text representation of an IP address and the **addrinfoex** structure pointed to by the *pHints* parameter must have the AI_NUMERICHOST flag set in the **ai_flags** member. The string pointed to by the *pName* parameter may contain a text representation of either an IPv4 or an IPv6 address. The text IP address is converted to an **addrinfoex** structure pointed to by the *ppResult* parameter. The returned **addrinfoex** structure contains a **sockaddr** structure for the IP address along with additional information about the IP address.

Multiple namespace providers may be installed on a local computer for the same namespace. For example, the base Windows TCP/IP networking software registers for the NS_DNS namespace. The Microsoft Forefront Threat Management Gateway (TMG) and the older Microsoft Internet Security and Acceleration (ISA) Server include Firewall Client software that also registers for the NS_DNS namespace. When the *dwNameSpace* parameter is set to a value (NS_DNS, for example) and the *lpNspId* parameter is **NULL**, the results returned by the **GetAddrInfoEx** function are the merged results from all namespace providers that register for the specified namespace with duplicate results eliminated. The *lpNspId* parameter should be set to the GUID of the specific namespace provider if only a single namespace provider is to be queried.

If the *pNameSpace* parameter is set to NS_ALL, then the results from querying all namespace providers is merged and returned. In this case, duplicate responses may be returned in the results pointed to by the *ppResult* parameter if multiple namespace providers return the same information.

On Windows 8 and Windows Server 2012, if the **GetAddrInfoEx** function will complete asynchronously, the pointer returned in the *lpNameHandle* parameter may be used with the **GetAddrInfoExCancel** function. The handle returned is valid when **GetAddrInfoEx** returns until the completion routine is called, the event is triggered, or [GetAddrInfoExCancel](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexcancel) function is called with this handle.

### Freeing Address Information from Dynamic Allocation

All information returned by the
**GetAddrInfoEx** function pointed to by the *ppResult* parameter is dynamically allocated, including all
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structures, socket address structures, and canonical host name strings pointed to by
**addrinfoex** structures. Memory allocated by a successful call to this function must be released with a subsequent call to [FreeAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfoex).

### Example Code

The following example demonstrates the use of the **GetAddrInfoEx** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <objbase.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

// Need to link with Ole32.lib to print GUID
#pragma comment(lib, "ole32.lib")

int __cdecl wmain(int argc, wchar_t ** argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    DWORD dwRetval;

    int i = 1;

    DWORD dwNamespace = NS_ALL;
    LPGUID lpNspid = NULL;

    ADDRINFOEX *result = NULL;
    ADDRINFOEX *ptr = NULL;
    ADDRINFOEX hints;

    // LPSOCKADDR sockaddr_ip;
    struct sockaddr_in *sockaddr_ipv4;
    struct sockaddr_in6 *sockaddr_ipv6;

    // DWORD ipbufferlength = 46;
    wchar_t ipstringbuffer[46];

    // variables needed to print namespace provider GUID
    int iRet = 0;
    WCHAR GuidString[40] = { 0 };

    // Validate the parameters
    if (argc != 4) {
        wprintf(L"usage: %ws <hostname> <servicename> <namespace>\n", argv[0]);
        wprintf(L"getaddrinfoex provides protocol-independent translation\n");
        wprintf(L"   from a host name to an IP address\n");
        wprintf(L"%ws example usage\n", argv[0]);
        wprintf(L"   %ws www.contoso.com 0 12\n", argv[0]);
        wprintf(L"   looks up the www.contoso.com in the NS_DNS namespace\n",
                argv[0]);
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
    // which is passed to the getaddrinfo() function
    ZeroMemory(&hints, sizeof (hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    dwNamespace = (DWORD) _wtoi(argv[3]);

    wprintf(L"Calling GetAddrInfoEx with following parameters:\n");
    wprintf(L"\tName = %ws\n", argv[1]);
    wprintf(L"\tServiceName (or port) = %ws\n", argv[2]);
    wprintf(L"\tNamespace = %s (", argv[3]);
    switch (dwNamespace) {
    case NS_ALL:
        wprintf(L"(NS_ALL)\n");
        break;
    case NS_DNS:
        wprintf(L"(NS_DNS)\n");
        break;
    case NS_NETBT:
        wprintf(L"NS_NETBT");
        break;
    case NS_WINS:
        wprintf(L"NS_WINS");
        break;
    case NS_NLA:
        wprintf(L"NS_NLA");
        break;
    case NS_BTH:
        wprintf(L"NS_BTH");
        break;
    case NS_NTDS:
        wprintf(L"NS_NTDS");
        break;
    case NS_EMAIL:
        wprintf(L"NS_EMAIL");
        break;
    case NS_PNRPNAME:
        wprintf(L"NS_PNRPNAME");
        break;
    case NS_PNRPCLOUD:
        wprintf(L"NS_PNRPCLOUD");
        break;
    default:
        wprintf(L"Other");
        break;
    }
    wprintf(L")\n\n");

//--------------------------------
// Call getaddrinfoex(). If the call succeeds,
// the result variable will hold a linked list
// of addrinfo structures containing response
// information
    dwRetval =
        GetAddrInfoEx(argv[1], argv[2], dwNamespace, lpNspid, &hints, &result,
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

        if (ptr->ai_blob == NULL)
            wprintf(L"\tBlob: (null)\n");
        else
            wprintf(L"\tLength of the blob: %u\n",
                    (DWORD) ptr->ai_bloblen);

        if (ptr->ai_provider == NULL)
            wprintf(L"\tNamespace provider GUID: (null)\n");
        else {
            iRet =
                StringFromGUID2(*(ptr->ai_provider), (LPOLESTR) & GuidString,
                                39);
            // For c rather than C++ source code, the above line needs to be
            // iRet = StringFromGUID2(&ptr.ai_provider, (LPOLESTR) &GuidString, 39);
            if (iRet == 0)
                wprintf(L"StringFromGUID2 failed\n");
            else {
                wprintf(L"\tNamespace provider: %ws\n", GuidString);
            }
        }
    }

    FreeAddrInfoEx(result);
    WSACleanup();

    return 0;
}

```

The following example demonstrates how to use the **GetAddrInfoEx** function asynchronous to
resolve a name to an IP address..

```cpp
//
//    This sample demonstrates how to use asynchronous GetAddrInfoEx to
//    resolve a name to an IP address.
//
//    ResolveName <QueryName>
//

#ifndef UNICODE
#define UNICODE
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

#define MAX_ADDRESS_STRING_LENGTH   64

//
//  Asynchronous query context structure.
//

typedef struct _QueryContext
{
    OVERLAPPED      QueryOverlapped;
    PADDRINFOEX     QueryResults;
    HANDLE          CompleteEvent;
}QUERY_CONTEXT, *PQUERY_CONTEXT;

VOID
WINAPI
QueryCompleteCallback(
    _In_ DWORD Error,
    _In_ DWORD Bytes,
    _In_ LPOVERLAPPED Overlapped
    );

int
__cdecl
wmain(
    _In_ int Argc, PWCHAR Argv[]
    )
{
    INT                 Error = ERROR_SUCCESS;
    WSADATA             wsaData;
    BOOL                IsWSAStartupCalled = FALSE;
    ADDRINFOEX          Hints;
    QUERY_CONTEXT       QueryContext;
    HANDLE              CancelHandle = NULL;
    DWORD               QueryTimeout = 5 * 1000; // 5 seconds

    ZeroMemory(&QueryContext, sizeof(QueryContext));

    //
    //  Validate the parameters
    //

    if (Argc != 2)
    {
        wprintf(L"Usage: ResolveName <QueryName>\n");
        goto exit;
    }

    //
    //  All Winsock functions require WSAStartup() to be called first
    //

    Error = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (Error != 0)
    {
        wprintf(L"WSAStartup failed with %d\n", Error);
        goto exit;
    }

    IsWSAStartupCalled = TRUE;

    ZeroMemory(&Hints, sizeof(Hints));
    Hints.ai_family = AF_UNSPEC;

    //
    //  Note that this is a simple sample that waits/cancels a single
    //  asynchronous query. The reader may extend this to support
    //  multiple asynchronous queries.
    //

    QueryContext.CompleteEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

    if (QueryContext.CompleteEvent == NULL)
    {
        Error = GetLastError();
        wprintf(L"Failed to create completion event: Error %d\n",  Error);
        goto exit;
    }

    //
    //  Initiate asynchronous GetAddrInfoExW.
    //
    //  Note GetAddrInfoEx can also be invoked asynchronously using an event
    //  in the overlapped object (Just set hEvent in the Overlapped object
    //  and set NULL as completion callback.)
    //
    //  This sample uses the completion callback method.
    //

    Error = GetAddrInfoExW(Argv[1],
                           NULL,
                           NS_DNS,
                           NULL,
                           &Hints,
                           &QueryContext.QueryResults,
                           NULL,
                           &QueryContext.QueryOverlapped,
                           QueryCompleteCallback,
                           &CancelHandle);

    //
    //  If GetAddrInfoExW() returns  WSA_IO_PENDING, GetAddrInfoExW will invoke
    //  the completion routine. If GetAddrInfoExW returned anything else we must
    //  invoke the completion directly.
    //

    if (Error != WSA_IO_PENDING)
    {
        QueryCompleteCallback(Error, 0, &QueryContext.QueryOverlapped);
        goto exit;
    }

    //
    //  Wait for query completion for 5 seconds and cancel the query if it has
    //  not yet completed.
    //

    if (WaitForSingleObject(QueryContext.CompleteEvent,
                            QueryTimeout)  == WAIT_TIMEOUT )
    {

        //
        //  Cancel the query: Note that the GetAddrInfoExCancelcancel call does
        //  not block, so we must wait for the completion routine to be invoked.
        //  If we fail to wait, WSACleanup() could be called while an
        //  asynchronous query is still in progress, possibly causing a crash.
        //

        wprintf(L"The query took longer than %d seconds to complete; "
                L"cancelling the query...\n", QueryTimeout/1000);

        GetAddrInfoExCancel(&CancelHandle);

        WaitForSingleObject(QueryContext.CompleteEvent,
                            INFINITE);
    }

exit:

    if (IsWSAStartupCalled)
    {
        WSACleanup();
    }

    if (QueryContext.CompleteEvent)
    {
        CloseHandle(QueryContext.CompleteEvent);
    }

    return Error;
}

//
// Callback function called by Winsock as part of asynchronous query complete
//

VOID
WINAPI
QueryCompleteCallback(
    _In_ DWORD Error,
    _In_ DWORD Bytes,
    _In_ LPOVERLAPPED Overlapped
    )
{
    PQUERY_CONTEXT  QueryContext = NULL;
    PADDRINFOEX     QueryResults = NULL;
    WCHAR           AddrString[MAX_ADDRESS_STRING_LENGTH];
    DWORD           AddressStringLength;

    UNREFERENCED_PARAMETER(Bytes);

    QueryContext = CONTAINING_RECORD(Overlapped,
                                     QUERY_CONTEXT,
                                     QueryOverlapped);

    if (Error != ERROR_SUCCESS)
    {
        wprintf(L"ResolveName failed with %d\n", Error);
        goto exit;
    }

    wprintf(L"ResolveName succeeded. Query Results:\n");

    QueryResults = QueryContext->QueryResults;

    while(QueryResults)
    {
        AddressStringLength = MAX_ADDRESS_STRING_LENGTH;

        WSAAddressToString(QueryResults->ai_addr,
                           (DWORD)QueryResults->ai_addrlen,
                           NULL,
                           AddrString,
                           &AddressStringLength);

        wprintf(L"Ip Address: %s\n", AddrString);
        QueryResults = QueryResults->ai_next;
    }

exit:

    if (QueryContext->QueryResults)
    {
        FreeAddrInfoEx(QueryContext->QueryResults);
    }

    //
    //  Notify caller that the query completed
    //

    SetEvent(QueryContext->CompleteEvent);
    return;
}

```

**Note** Ensure that the development environment targets the newest version of *Ws2tcpip.h* which includes structure and function definitions for [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) and **GetAddrInfoEx**, respectively.

### Internationalized Domain Names

Internet host names typically consist of a very restricted set of characters:

* Upper and lower case ASCII letters from the English alphabet.
* Digits from 0 to 9.
* ASCII hyphen characters.

With the growth of the Internet, there is a growing need to identify Internet host names for other languages not represented by the ASCII character set. Identifiers which facilitate this need and allow non-ASCII characters (Unicode) to be represented as special ASCII character strings are known as Internationalized Domain Names (IDNs). A mechanism called
Internationalizing Domain Names in Applications (IDNA) is used to handle
IDNs in a standard fashion. The specifications for IDNs and IDNA are documented in [RFC 3490](http://tools.ietf.org/html/rfc3490), [RTF 5890](http://tools.ietf.org/html/rfc5890), and [RFC 6365](http://tools.ietf.org/html/rfc6365) published by the Internet Engineering Task Force (IETF).

On Windows 8 and Windows Server 2012, the **GetAddrInfoEx** function provides support for Internationalized Domain Name (IDN) parsing applied to the name passed in the *pName* parameter. Winsock performs Punycode/IDN encoding and conversion. This behavior can be disabled using the **AI_DISABLE_IDN_ENCODING** flag discussed below.

On Windows 7 and Windows Server 2008 R2 or earlier, the **GetAddrInfoEx** function does not currently provide support for IDN parsing applied to the name passed in the *pName* parameter. The wide character version of the **GetAddrInfoEx** function does not use Punycode to convert an IDN Punycode format as per [RFC 3490](http://tools.ietf.org/html/rfc3490). The wide character version of the **GetAddrInfoEx** function when querying DNS encodes the Unicode name in UTF-8 format, the format used by Microsoft DNS servers in an enterprise environment.

Several functions on Windows Vista and later support conversion between Unicode labels in an IDN to their ASCII equivalents. The resulting representation of each Unicode label contains only ASCII characters and starts with the xn-- prefix if the Unicode label contained any non-ASCII characters. The reason for this is to support existing DNS servers on the Internet, since some DNS tools and servers only support ASCII characters (see [RFC 3490](http://tools.ietf.org/html/rfc3490)).

The [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii) function uses Punycode to convert an IDN to the ASCII representation of the original Unicode string using the standard algorithm defined in [RFC 3490](http://tools.ietf.org/html/rfc3490). The [IdnToUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntounicode) function converts the ASCII form of an IDN to the normal Unicode UTF-16 encoding syntax. For more information and links to related draft standards, see [Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

The [IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii) function can be used to convert an IDN name to an ASCII form that then can be passed in the *pName* parameter to the **GetAddrInfoEx** function when the ASCII version of this function is used (when UNICODE and _UNICODE are not defined). To pass this IDN name to the **GetAddrInfoEx** function when the wide character version of this function is used (when UNICODE or _UNICODE is defined), you can use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to convert the **CHAR** string into a **WCHAR** string.

### Use of ai_flags in the hints parameter

Flags in the **ai_flags** member of the optional
[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure provided in the *hints* parameter modify the behavior of the function.

These flag bits are defined in the *Ws2def.h* header file on the Microsoft Windows Software Development Kit (SDK) for Windows 7. These flag bits are defined in the *Ws2tcpip.h* header file on the Windows SDK for Windows Server 2008 and Windows Vista. These flag bits are defined in the *Ws2tcpip.h* header file on the Platform Software Development Kit (SDK) for Windows Server 2003, and Windows XP.

The flag bits can be a combination of the following:

| Flag Bits | Description |
| --- | --- |
| **AI_PASSIVE** | Setting the **AI_PASSIVE** flag indicates the caller intends to use the returned socket address structure in a call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. When the **AI_PASSIVE** flag is set and *pName* is a **NULL** pointer, the IP address portion of the socket address structure is set to **INADDR_ANY** for IPv4 addresses and **IN6ADDR_ANY_INIT** for IPv6 addresses.<br><br>When the **AI_PASSIVE** flag is not set, the returned socket address structure is ready for a call to the [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function for a connection-oriented protocol, or ready for a call to either the **connect**, [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto), or [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) functions for a connectionless protocol. If the *pName* parameter is a **NULL** pointer in this case, the IP address portion of the socket address structure is set to the loopback address. |
| **AI_CANONNAME** | If neither **AI_CANONNAME** nor **AI_NUMERICHOST** is used, the **GetAddrInfoEx** function attempts resolution. If a literal string is passed **GetAddrInfoEx** attempts to convert the string, and if a host name is passed the **GetAddrInfoEx** function attempts to resolve the name to an address or multiple addresses.<br><br>When the **AI_CANONNAME** bit is set, the *pName* parameter cannot be **NULL**. Otherwise the **GetAddrInfoEx** function will fail with [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).<br><br>When the **AI_CANONNAME** bit is set and the **GetAddrInfoEx** function returns success, the **ai_canonname** member in the *ppResult* parameter points to a **NULL**-terminated string that contains the canonical name of the specified node.<br><br>**Note** The **GetAddrInfoEx** function can return success when the **AI_CANONNAME** flag is set, yet the **ai_canonname** member in the associated [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure is **NULL**. Therefore, the recommended use of the **AI_CANONNAME** flag includes testing whether the **ai_canonname** member in the associated [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure is **NULL**. |
| **AI_NUMERICHOST** | When the **AI_NUMERICHOST** bit is set, the *pName* parameter must contain a non-**NULL** numeric host address string, otherwise the **EAI_NONAME** error is returned. This flag prevents a name resolution service from being called. |
| **AI_NUMERICSERV** | When the **AI_NUMERICSERV** bit is set, the *pServiceName* parameter must contain a non-**NULL** numeric port number, otherwise the **EAI_NONAME** error is returned. This flag prevents a name resolution service from being called. <br><br>The **AI_NUMERICSERV** flag is defined on Windows SDK for Windows Vista and later. The **AI_NUMERICSERV** flag is not supported by Microsoft providers. |
| **AI_ALL** | If the **AI_ALL** bit is set, a request is made for IPv6 addresses and IPv4 addresses with **AI_V4MAPPED**. <br><br>The **AI_ALL** flag is defined on the Windows SDK for Windows Vista and later. The **AI_ALL** flag is supported on Windows Vista and later. |
| **AI_ADDRCONFIG** | If the **AI_ADDRCONFIG** bit is set, **GetAddrInfoEx** will resolve only if a global address is configured. If **AI_ADDRCONFIG** flag is specified, IPv4 addresses shall be returned only if an IPv4 address is configured on the local system, and IPv6 addresses shall be returned only if an IPv6 address is configured on the local system. The IPv4 or IPv6 loopback address is not considered a valid global address.<br><br>The **AI_ADDRCONFIG** flag is defined on the Windows SDK for Windows Vista and later. The **AI_ADDRCONFIG** flag is supported on Windows Vista and later. |
| **AI_V4MAPPED** | If the **AI_V4MAPPED** bit is set and a request for IPv6 addresses fails, a name service request is made for IPv4 addresses and these addresses are converted to IPv4-mapped IPv6 address format.<br><br>The **AI_V4MAPPED** flag is defined on the Windows SDK for Windows Vista and later. The **AI_V4MAPPED** flag is supported on Windows Vista and later. |
| **AI_NON_AUTHORITATIVE** | If the **AI_NON_AUTHORITATIVE** bit is set, the **NS_EMAIL** namespace provider returns both authoritative and non-authoritative results. If the **AI_NON_AUTHORITATIVE** bit is not set, the **NS_EMAIL** namespace provider returns only authoritative results. <br><br>The **AI_NON_AUTHORITATIVE** flag is defined on the Windows SDK for Windows Vista and later. The **AI_NON_AUTHORITATIVE** flag is supported on Windows Vista and later and applies only to the **NS_EMAIL** namespace. |
| **AI_SECURE** | If the **AI_SECURE** bit is set, the **NS_EMAIL** namespace provider will return results that were obtained with enhanced security to minimize possible spoofing.<br><br>The **AI_SECURE** flag is defined on the Windows SDK for Windows Vista and later. The **AI_SECURE** flag is supported on Windows Vista and later and applies only to the **NS_EMAIL** namespace. |
| **AI_RETURN_PREFERRED_NAMES** | If the **AI_RETURN_PREFERRED_NAMES** is set, then no name should be provided in the *pName* parameter. The **NS_EMAIL** namespace provider will return preferred names for publication.<br><br>The **AI_RETURN_PREFERRED_NAMES** flag is defined on the Windows SDK for Windows Vista and later. The **AI_RETURN_PREFERRED_NAMES** flag is supported on Windows Vista and later and applies only to the **NS_EMAIL** namespace. |
| **AI_FQDN** | If the **AI_FQDN** is set and a flat name (single label) is specified, **GetAddrInfoEx** will return the fully qualified domain name that the name eventually resolved to. The fully qualified domain name is returned in the **ai_canonname** member in the associated [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure. This is different than **AI_CANONNAME** bit flag that returns the canonical name registered in DNS which may be different than the fully qualified domain name that the flat name resolved to. <br><br>When the **AI_FQDN** bit is set, the *pName* parameter cannot be **NULL**. Otherwise the **GetAddrInfoEx** function will fail with [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).<br><br>On Windows 8 and Windows Server 2012, both the **AI_FQDN** and **AI_CANONNAME** bits can be set. If the **GetAddrInfoEx** function is called with both the **AI_FQDN** and **AI_CANONNAME** bits, the *ppResult* parameter returns a pointer to an [addrinfoex2](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoex2w) structure, not an [addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw) structure.<br><br>On Windows 7 and Windows Server 2008 R2, only one of the **AI_FQDN** and **AI_CANONNAME** bits can be set. The **GetAddrInfoEx** function will fail if both flags are present with **EAI_BADFLAGS**.<br><br>**Windows 7:** The **AI_FQDN** flag is defined on the Windows SDK for Windows 7 and later. The **AI_FQDN** flag is supported on Windows 7 and later. |
| **AI_FILESERVER** | If the **AI_FILESERVER** is set, this is a hint to the namespace provider that the hostname being queried is being used in file share scenario. The namespace provider may ignore this hint.<br><br>**Windows 7:** The **AI_FILESERVER** flag is defined on the Windows SDK for Windows 7 and later. The **AI_FILESERVER** flag is supported on Windows 7 and later. |
| **AI_DISABLE_IDN_ENCODING** | If the **AI_DISABLE_IDN_ENCODING** is set, this disables the automatic International Domain Name encoding using Punycode in the name resolution functions called by the **GetAddrInfoEx** function. <br><br>**Windows 8:** The **AI_DISABLE_IDN_ENCODING** flag is defined on the Windows SDK for Windows 8 and later. The **AI_DISABLE_IDN_ENCODING** flag is supported on Windows 8 and later. |

> [!NOTE]
> The ws2tcpip.h header defines GetAddrInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FreeAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-freeaddrinfoex)

[GetAddrInfoExCancel](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexcancel)

[GetAddrInfoExOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexoverlappedresult)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[IdnToAscii](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntoascii)

[IdnToUnicode](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-idntounicode)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)

[addrinfoex](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoexw)

[addrinfoex2](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoex2w)

[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)