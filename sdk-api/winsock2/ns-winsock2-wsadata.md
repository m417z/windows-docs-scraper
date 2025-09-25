# WSADATA structure

## Description

The
**WSADATA** structure contains information about the Windows Sockets implementation.

## Members

### `wVersion`

Type: **WORD**

The version of the Windows Sockets specification that the *Ws2_32.dll* expects the caller to use. The high-order byte specifies the minor version number; the low-order byte specifies the major version number.

### `wHighVersion`

Type: **WORD**

The highest version of the Windows Sockets specification that the *Ws2_32.dll* can support. The high-order byte specifies the minor version number; the low-order byte specifies the major version number.

This is the same value as the **wVersion** member when the version requested in the *wVersionRequested* parameter passed to the [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function is the highest version of the Windows Sockets specification that the *Ws2_32.dll* can support.

### `szDescription`

Type: **char[WSADESCRIPTION_LEN+1]**

A **NULL**-terminated ASCII string into which the *Ws2_32.dll* copies a description of the Windows Sockets implementation. The text (up to 256 characters in length) can contain any characters except control and formatting characters. The most likely use that an application would have for this member is to display it (possibly truncated) in a status message.

### `szSystemStatus`

Type: **char[WSASYS_STATUS_LEN+1]**

A **NULL**-terminated ASCII string into which the *Ws2_32.dll* copies relevant status or configuration information. The *Ws2_32.dll* should use this parameter only if the information might be useful to the user or support staff. This member should not be considered as an extension of the **szDescription** parameter.

### `iMaxSockets`

Type: **unsigned short**

The maximum number of sockets that may be opened. This member should be ignored for Windows Sockets version 2 and later.

The **iMaxSockets** member is retained for compatibility with Windows Sockets specification 1.1, but should not be used when developing new applications. No single value can be appropriate for all underlying service providers. The architecture of Windows Sockets changed in version 2 to support multiple providers, and the **WSADATA** structure no longer applies to a single vendor's stack.

### `iMaxUdpDg`

Type: **unsigned short**

The maximum datagram message size. This member is ignored for Windows Sockets version 2 and later.

The **iMaxUdpDg** member is retained for compatibility with Windows Sockets specification 1.1, but should not be used when developing new applications. The architecture of Windows Sockets changed in version 2 to support multiple providers, and the **WSADATA** structure no longer applies to a single vendor's stack. For the actual maximum message size specific to a particular Windows Sockets service provider and socket type, applications should use
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) to retrieve the value of option SO_MAX_MSG_SIZE after a socket has been created.

### `lpVendorInfo`

Type: **char FAR***

A pointer to vendor-specific information. This member should be ignored for Windows Sockets version 2 and later.

The **lpVendorInfo** member is retained for compatibility with Windows Sockets specification 1.1. The architecture of Windows Sockets changed in version 2 to support multiple providers, and the **WSADATA** structure no longer applies to a single vendor's stack. Applications needing to access vendor-specific configuration information should use
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) to retrieve the value of option PVD_CONFIG for vendor-specific information.

## Remarks

The [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) function initiates the use of the Windows Sockets DLL by a process. The **WSAStartup** function returns a pointer to the
**WSADATA** structure in the *lpWSAData* parameter.

The current version of the Windows Sockets specification returned in the **wHighVersion** member of the
**WSADATA** structure is version 2.2 encoded with the major version number in the low-byte and the minor version number in the high-byte. This version of the current Winsock DLL, *Ws2_32.dll*, supports applications that request any of the following versions of the Windows Sockets specification:

* 1.0
* 1.1
* 2.0
* 2.1
* 2.2

Depending on the version requested by the application, one of the above version numbers is the value encoded as the major version number in the low-byte and the minor version number in the high-byte that is returned in the **wVersion** member of the **WSADATA** structure.

**Note** An application should ignore the **iMaxsockets**, **iMaxUdpDg**, and **lpVendorInfo** members in **WSADATA** if the value in **wVersion** after a successful call to
[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) is at least 2. This is because the architecture of Windows Sockets changed in version 2 to support multiple providers, and **WSADATA** no longer applies to a single vendor's stack. Two new socket options are introduced to supply provider-specific information: SO_MAX_MSG_SIZE (replaces the **iMaxUdpDg** member) and PVD_CONFIG (allows any other provider-specific configuration to occur).

#### Examples

The following example demonstrates the use of the **WSADATA** structure.

```cpp
WORD wVersionRequested;
WSADATA wsaData;
int err;

wVersionRequested = MAKEWORD( 2, 2 );

err = WSAStartup( wVersionRequested, &wsaData );
if ( err != 0 ) {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    return;
}

/* Confirm that the WinSock DLL supports 2.2.*/
/* Note that if the DLL supports versions greater    */
/* than 2.2 in addition to 2.2, it will still return */
/* 2.2 in wVersion since that is the version we      */
/* requested.                                        */

if ( LOBYTE( wsaData.wVersion ) != 2 ||
        HIBYTE( wsaData.wVersion ) != 2 ) {
    /* Tell the user that we could not find a usable */
    /* WinSock DLL.                                  */
    WSACleanup( );
    return;
}

/* The WinSock DLL is acceptable. Proceed. */

```

## See also

[SOL_SOCKET Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options)

[Socket Options and IOCTLs](https://learn.microsoft.com/windows/desktop/WinSock/socket-options-and-ioctls-2)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)