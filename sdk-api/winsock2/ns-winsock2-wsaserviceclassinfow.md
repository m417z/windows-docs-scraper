# WSASERVICECLASSINFOW structure

## Description

The
**WSASERVICECLASSINFO** structure contains information about a specified service class. For each service class in Windows Sockets 2, there is a single
**WSASERVICECLASSINFO** structure.

## Members

### `lpServiceClassId`

Unique Identifier (GUID) for the service class.

### `lpszServiceClassName`

Well known name associated with the service class.

### `dwCount`

Number of entries in **lpClassInfos**.

### `lpClassInfos`

Array of [WSANSCLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsansclassinfow) structures that contains information about the service class.

## See also

[NSPGetServiceClassInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspgetserviceclassinfo)

[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

## Remarks

> [!NOTE]
> The winsock2.h header defines WSASERVICECLASSINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).