# EnumProtocolsW function

## Description

The
**EnumProtocols** function retrieves information about a specified set of network protocols that are active on a local host.

**Note** The
**EnumProtocols** function is a Microsoft-specific extension to the Windows Sockets 1.1 specification. This function is obsolete. For the convenience of Windows Sockets 1.1 developers, the reference material is included. The
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function provides equivalent functionality in Windows Sockets 2.

## Parameters

### `lpiProtocols` [in, optional]

A pointer to a **null**-terminated array of protocol identifiers. The
**EnumProtocols** function retrieves information about the protocols specified by this array.

If *lpiProtocols* is **NULL**, the function retrieves information about all available protocols.

The following protocol identifier values are defined.

| Value | Meaning |
| --- | --- |
| **IPPROTO_TCP** | The Transmission Control Protocol (TCP), a connection-oriented stream protocol. |
| **IPPROTO_UDP** | The User Datagram Protocol (UDP), a connectionless datagram protocol. |
| **ISOPROTO_TP4** | The ISO connection-oriented transport protocol. |
| **NSPROTO_IPX** | The Internet Packet Exchange (IPX) protocol, a connectionless datagram protocol. |
| **NSPROTO_SPX** | The Sequenced Packet Exchange (SPX) protocol, a connection-oriented stream protocol. |
| **NSPROTO_SPXII** | The Sequenced Packet Exchange (SPX) protocol version 2, a connection-oriented stream protocol. |

### `lpProtocolBuffer` [out]

A pointer to a buffer that the function fills with an array of
[PROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-protocol_infoa) data structures.

### `lpdwBufferLength` [in, out]

A pointer to a variable that, on input, specifies the size, in bytes, of the buffer pointed to by *lpProtocolBuffer*.

On output, the function sets this variable to the minimum buffer size needed to retrieve all of the requested information. For the function to succeed, the buffer must be at least this size.

## Return value

If the function succeeds, the return value is the number of
[PROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-protocol_infoa) data structures written to the buffer pointed to by *lpProtocolBuffer*.

If the function fails, the return value is SOCKET_ERROR(–1). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns the following extended error code.

| Error code | Meaning |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by *lpProtocolBuffer* was too small to receive all of the relevant [PROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-protocol_infoa) structures. Call the function with a buffer at least as large as the value returned in **lpdwBufferLength*. |

## Remarks

In the following sample code, the
**EnumProtocols** function retrieves information about all protocols that are available on a system. The code then examines each of the protocols in greater detail.

```cpp
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Nspapi.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib and Mswsock.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")

int FindProtocol(BOOL Reliable,
    BOOL MessageOriented, BOOL StreamOriented,
    BOOL Connectionless, DWORD *ProtocolUsed);

int __cdecl main(int argc, char **argv)
{
    WSADATA wsaData;

    int ProtocolError = SOCKET_ERROR;
    int iResult;

    BOOLEAN bReliable = FALSE;
    BOOLEAN bMessageOriented = FALSE;
    BOOLEAN bStreamOriented = TRUE;
    BOOLEAN bConnectionless = FALSE;
    DWORD *pProtocols = NULL;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s servicename\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ProtocolError = FindProtocol( bReliable, bMessageOriented,
        bStreamOriented, bConnectionless, pProtocols);
    if (ProtocolError == SOCKET_ERROR) {
        printf("Unable to find a protocol to support the parameters requested\n");
        return 1;
    }

    // Connect to the servicename ...

    return 0;

}

#define MAX_PROTOCOLS 1024

int FindProtocol (
    BOOL Reliable,
    BOOL MessageOriented,
    BOOL StreamOriented,
    BOOL Connectionless,
    DWORD *ProtocolUsed
    )
{
    // local variables
    INT protocols[MAX_PROTOCOLS+1];
    BYTE buffer[2048];
    DWORD bytesRequired;
    INT err;
    PPROTOCOL_INFO protocolInfo;
    INT protocolCount;
    INT i;
    DWORD protocolIndex;
//    PCSADDR_INFO csaddrInfo;
//    INT addressCount;
//    SOCKET s;

    // First look up the protocols installed on this computer.
    //
    bytesRequired = sizeof(buffer);
    err = EnumProtocols( NULL, buffer, &bytesRequired );
    if ( err <= 0 )
        return SOCKET_ERROR;

    // Walk through the available protocols and pick out the ones which
    // support the desired characteristics.
    //
    protocolCount = err;
    protocolInfo = (PPROTOCOL_INFO)buffer;

    for ( i = 0, protocolIndex = 0;
        i < protocolCount && protocolIndex < MAX_PROTOCOLS;
        i++, protocolInfo++ ) {

        // If connection-oriented support is requested, then check if
        // supported by this protocol.  We assume here that connection-
        // oriented support implies fully reliable service.
        //

        if ( Reliable ) {
            // Check to see if the protocol is reliable.  It must
            // guarantee both delivery of all data and the order in
            // which the data arrives.
            //
            if ( (protocolInfo->dwServiceFlags &
                    XP_GUARANTEED_DELIVERY) == 0
                ||
                    (protocolInfo->dwServiceFlags &
                    XP_GUARANTEED_ORDER) == 0 ) {

                continue;
            }

            // Check to see that the protocol matches the stream/message
            // characteristics requested.
            //
            if ( StreamOriented &&
                (protocolInfo->dwServiceFlags & XP_MESSAGE_ORIENTED)
                    != 0 &&
                (protocolInfo->dwServiceFlags & XP_PSEUDO_STREAM)
                     == 0 ) {
                continue;
            }

            if ( MessageOriented &&
                    (protocolInfo->dwServiceFlags & XP_MESSAGE_ORIENTED)
                              == 0 ) {
                continue;
            }

        }
        else if ( Connectionless ) {
            // Make sure that this is a connectionless protocol.
            //
            if ( (protocolInfo->dwServiceFlags & XP_CONNECTIONLESS)
                     != 0 )
                continue;
        }

        // This protocol fits all the criteria.  Add it to the list of
        // protocols in which we're interested.
        //
        protocols[protocolIndex++] = protocolInfo->iProtocol;
     }

     *ProtocolUsed = (INT) protocolIndex;
     return 0;
}

```

> [!NOTE]
> The nspapi.h header defines EnumProtocols as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAddressByName](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-getaddressbynamea)

[PROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-protocol_infoa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)