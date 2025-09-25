# NSP_ROUTINE structure

## Description

The **NSP_ROUTINE** structure contains information regarding the functions implemented by a namespace service provider version 1 (NSPv1) provider.

**Note** The *Ws2spi.h* header file structure contains complete prototypes for all the NSPv1 function pointers.

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of the structure. Note that the size of the **NSP_ROUTINE** structure changed on Windows XP and later.

### `dwMajorVersion`

Type: **DWORD**

The major version of the service provider specification supported by this provider.

### `dwMinorVersion`

Type: **DWORD**

The minor version of the service provider specification supported by this provider.

### `NSPCleanup`

Type: **LPNSPCLEANUP**

A pointer to the [NSPCleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspcleanup) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPCleanup** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPLookupServiceBegin`

Type: **LPNSPLOOKUPSERVICEBEGIN**

A pointer to the [NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPLookupServiceBegin** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPLookupServiceNext`

Type: **LPNSPLOOKUPSERVICENEXT**

A pointer to the [NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPLookupServiceNext** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPLookupServiceEnd`

Type: **LPNSPLOOKUPSERVICEEND**

A pointer to the [NSPLookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupserviceend) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPLookupServiceEnd** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPSetService`

Type: **LPNSPSETSERVICE**

A pointer to the [NSPSetService](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspsetservice) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPSetService** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPInstallServiceClass`

Type: **LPNSPINSTALLSERVICECLASS**

A pointer to the [NSPInstallServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspinstallserviceclass) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPInstallServiceClass** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPRemoveServiceClass`

Type: **LPNSPREMOVESERVICECLASS**

A pointer to the [NSPRemoveServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspremoveserviceclass) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPRemoveServiceClass** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPGetServiceClassInfo`

Type: **LPNSPGETSERVICECLASSINFO**

A pointer to the [NSPGetServiceClassInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspgetserviceclassinfo) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPGetServiceClassInfo** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

### `NSPIoctl`

Type: **LPNSPIOCTL**

A pointer to the [NSPIoctl](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspioctl) function implemented by the namespace provider. Every NSP function entry must point to a valid function. If the provider does not implement this function, the **NSPIoctl** function should return [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP).

**Note** This structure member is only available on Windows XP and later.

## Remarks

The size of the **NSP_ROUTINE** structure changed on Windows XP and later. The **cbSize** member should be used to determine which version of the **NSP_ROUTINE** structure is being used.

The version of the **NSP_ROUTINE** structure on Windows XP and later has the following new member added: **NSPIoctl**.

## See also

[NSPCleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspcleanup)

[NSPGetServiceClassInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspgetserviceclassinfo)

[NSPInstallServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspinstallserviceclass)

[NSPIoctl](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspioctl)

[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPLookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupserviceend)

[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext)

[NSPRemoveServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspremoveserviceclass)

[NSPSetService](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspsetservice)

[NSPStartup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-nspstartup)

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)