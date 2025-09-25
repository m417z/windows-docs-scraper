# SetAddrInfoExW function

## Description

The
**SetAddrInfoEx** function registers or deregisters a name, a service name, and associated addresses with
a specific namespace provider.

## Parameters

### `pName` [in]

A pointer to a **NULL**-terminated string containing a name under which addresses are to be registered or deregistered. The interpretation of this parameter specific to the namespace provider.

### `pServiceName` [in]

A pointer to an optional **NULL**-terminated string that contains the service name associated with the name being registered. The interpretation of this parameter is specific to the namespace provider.

### `pAddresses` [in, out]

A pointer to an optional list of addresses to register with the namespace provider.

### `dwAddressCount` [in]

The number of addresses passed in *pAddresses* parameter.
If this parameter is zero, the *pName* parameter is deregistered from the namespace provider.

### `lpBlob` [in, optional]

An optional pointer to data that is used to set provider-specific namespace information that is associated with the *pName* parameter beyond a list of addresses. Any information that cannot be passed in the *pAddresses* parameter can be passed in the *lpBlob* parameter. The format of this information is specific to the namespace provider.

### `dwFlags` [in]

A set of flags controlling how the *pName* and *pServiceName* parameters are to be registered with the namespace provider. The interpretation of this information is specific to the namespace provider.

### `dwNameSpace` [in]

A namespace identifier that determines which namespace provider to register this information with. Passing a specific namespace identifier will result in registering this information only with the namespace providers that support the specified namespace. Specifying NS_ALL will result in registering the information with all installed and active namespace providers.

Options for the *dwNameSpace* parameter are listed in the *Winsock2.h* include file. Several namespace providers are included with Windows Vista and later. Other namespace providers can be installed, so the following possible values are only those commonly available. Many others are possible.

| Value | Meaning |
| --- | --- |
| **NS_ALL** | All installed and active namespaces. |
| **NS_BTH** | The Bluetooth namespace. This namespace identifier is supported on Windows Vista and later. |
| **NS_DNS** | The domain name system (DNS) namespace. |
| **NS_EMAIL** | The email namespace. This namespace identifier is supported on Windows Vista and later. |
| **NS_NLA** | The network location awareness (NLA) namespace. This namespace identifier is supported on Windows XP and later. |
| **NS_PNRPNAME** | The peer-to-peer namespace for a specific peer name. This namespace identifier is supported on Windows Vista and later. |
| **NS_PNRPCLOUD** | The peer-to-peer namespace for a collection of peer names. This namespace identifier is supported on Windows Vista and later. |

### `lpNspId` [in, optional]

A pointer to an optional GUID of a specific namespace provider to register this information with in the case where multiple namespace providers are registered under a single namespace such as NS_DNS. Passing the GUID for a specific namespace provider will result in the information being registered with only the specified namespace provider. The [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa) function can be called to retrieve the GUID for a namespace provider.

### `timeout` [in, optional]

An optional parameter indicating the time, in milliseconds, to wait for a response from the namespace provider before aborting the call. This parameter is currently reserved and must be set to **NULL** since a *timeout* option is not supported.

### `lpOverlapped` [in, optional]

An optional pointer to an overlapped structure used for asynchronous operation. This parameter is currently reserved and must be set to **NULL** since asynchronous operations are not supported.

### `lpCompletionRoutine` [in, optional]

An optional pointer to a function to be invoked upon successful completion for asynchronous operations. This parameter is currently reserved and must be set to **NULL** since asynchronous operations are not supported.

### `lpNameHandle` [out, optional]

An optional pointer used only for asynchronous operations. This parameter is currently reserved and must be set to **NULL** since asynchronous operations are not supported.

## Return value

On success, **SetAddrInfoEx** returns NO_ERROR (0). Failure returns a nonzero Windows Sockets error code, as found in the
[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A temporary failure in name resolution occurred. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was provided. This error is returned if any of the reserved parameters are not **NULL**. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient buffer space is available. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable failure in name resolution occurred. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A memory allocation failure occurred. |

## Remarks

The **SetAddrInfoEx** function provides a protocol-independent method to register or deregister a name and one or more addresses with a namespace provider. The NS_EMAIL namespace provider in Windows Vista and later supports registration and deregistration of addresses. The default NS_DNS, NS_PNRPNAME, and NS_PNRPNAME namespace providers do not currently support name registration.

If the **SetAddrInfoEx** function is called with NS_ALL set as the *dwNameSpace* parameter and the *lpNspId* parameter unspecified, then **SetAddrInfoEx** will attempt to register or deregister the name and associated addresses with all installed and active namespaces. The **SetAddrInfoEx** function will return success if any of the namespace providers successfully registered or deregistered the name, but there will not be any indication of which namespace provider succeeded or which ones failed the request.

When **UNICODE** or **_UNICODE** is defined, **SetAddrInfoEx** is defined to [SetAddrInfoExW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), the Unicode version of this function. The string parameters are defined to the **PWSTR** data type.

When **UNICODE** or **_UNICODE** is not defined, **SetAddrInfoEx** is defined to [SetAddrInfoExA](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), the ANSI version of this function. The string parameters are of the **PCSTR** data type.

Information that is registered with a namespace provider can be returned by calling the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa), [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo), or [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) functions. The **GetAddrInfoEx** function is an enhanced version of the **getaddrinfo** and **GetAddrInfoW** functions.

On Windows Vista and later, when **SetAddrInfoEx** is called from a service, if the operation is the result of a user process calling the service, then the service should impersonate the user. This is to allow security and routing compartments to be properly enforced.

**Windows 8.1** and **Windows Server 2012 R2**: The **SetAddrInfoExW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The ws2tcpip.h header defines SetAddrInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)