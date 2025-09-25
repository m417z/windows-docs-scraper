# NSPV2_ROUTINE structure

## Description

The **NSPV2_ROUTINE** structure contains information on the functions implemented by a namespace service provider version-2 (NSPv2) provider.

**Note** The *Ws2spi.h* header file structure contains complete prototypes for all the NSPV2 function pointers.

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of the structure.

### `dwMajorVersion`

Type: **DWORD**

The major version of the service provider specification supported by this provider.

### `dwMinorVersion`

Type: **DWORD**

The minor version of the service provider specification supported by this provider.

### `NSPv2Startup`

Type: ** LPNSPV2STARTUP**

A pointer to the [NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup) function for this NSPv2 provider.

### `NSPv2Cleanup`

Type: **LPNSPV2CLEANUP**

A pointer to the [NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup) function for this NSPv2 provider.

### `NSPv2LookupServiceBegin`

Type: **LPNSPV2LOOKUPSERVICEBEGIN**

A pointer to the [NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function for this NSPv2 provider.

### `NSPv2LookupServiceNextEx`

Type: **LPNSPV2LOOKUPSERVICENEXTEX**

A pointer to the [NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex) function for this NSPv2 provider.

### `NSPv2LookupServiceEnd`

Type: **LPNSPV2LOOKUPSERVICEEND**

A pointer to the [NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend) function for this NSPv2 provider.

### `NSPv2SetServiceEx`

Type: **LPNSPV2SETSERVICEEX**

A pointer to the [NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex) function for this NSPv2 provider.

### `NSPv2ClientSessionRundown`

Type: **LPNSPV2CLIENTSESSIONRUNDOWN**

A pointer to the [NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown) function for this NSPv2 provider.

## Remarks

The
**NSPV2_ROUTINE** structure is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NSPV2_ROUTINE** structure can only be used for operations on NS_EMAIL namespace providers.

The
[WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider) function advertises an instance of a NSPv2 provider for clients to find. The **WSAAdvertiseProvider** caller passes a pointer to an **NSPV2_ROUTINE** structure in the *pNSPv2Routine* parameter with the NSPv2 entry points supported by the provider.

A NSPv2 provider is required to implement the following functions:
-
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)
-
[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)
-
[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)
All other functions are optional, dependent on the requirements of the NSPv2 provider.

 If a function isn't implemented, then calls to that function should be intercepted by a stub function that returns [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP). The NSPv2 function pointer to the unimplemented function in the **NSPV2_ROUTINE** structure should point be to the stub function.

In general, NSPv2 providers are implemented in processes other than the calling applications. NSPv2 providers are not activated as a result of client activity. Each provider hosting application decides when to make a specific provider available or unavailable by calling the [WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider) and [WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider) functions. The client activity only results in attempts to contact the provider, when available (when the namespace provider is advertised).

A process can implement and advertise multiple providers at the same time. Windows Sockets will manage the namespace providers by dispatching calls to the correct one. It will also hide RPC interface details and translates cross-process calls into in-process calls. So that the NSPv2 provider has only to implement a table of entry point functions similar to the [NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine) structure used by an NSPv1 provider. A NSPv2 provider does not have to worry about RPC specific requirements (data marshalling and serialization, for example).

The
[WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider) function makes a specific namespace provider no longer available for clients.

## See also

[NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine)

[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)

[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)

[NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex)

[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup)

[WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider)

[WSAProviderCompleteAsyncCall](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaprovidercompleteasynccall)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider)