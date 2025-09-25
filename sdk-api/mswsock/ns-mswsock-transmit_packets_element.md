# TRANSMIT_PACKETS_ELEMENT structure

## Description

The
**TRANSMIT_PACKETS_ELEMENT** structure specifies a single data element to be transmitted by the
[TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets) function.

## Members

### `dwElFlags`

Type: **ULONG**

Flags used to describe the contents of the packet array element, and to customize
**TransmitPackets** function processing. The following table lists valid flags:

| Flag | Meaning |
| --- | --- |
| **TP_ELEMENT_FILE** | Specifies that data resides in a file. Default setting for **dwElFlags**. Mutually exclusive with TP_ELEMENT_MEMORY. |
| **TP_ELEMENT_MEMORY** | Specifies that data resides in memory. Mutually exclusive with TP_ELEMENT_FILE. |
| **TP_ELEMENT_EOP** | Specifies that this element should not be combined with the next element in a single [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) request from the sockets layer to the transport. This flag is used for granular control of the content of each message on a datagram or message-oriented socket. |

### `cLength`

Type: **ULONG**

The number of bytes to transmit. If zero, the entire file is transmitted.

### `nFileOffset`

Type: **LARGE_INTEGER**

The file offset, in bytes, at which to begin the transfer. Valid only if TP_ELEMENT_FILE is specified in **dwEIFlags**. When set to –1, transmission begins at the current byte offset.

### `hFile`

Type: **HANDLE**

A handle to an open file to be transmitted. Valid only if TP_ELEMENT_FILE is specified in **dwEIFlags**. Windows reads the file sequentially; caching performance is improved by opening this handle with FILE_FLAG_SEQUENTIAL_SCAN.

### `pBuffer`

Type: **PVOID**

A pointer to the data in memory to be sent. Valid only if TP_ELEMENT_MEMORY is specified in **dwEIFlags**.

## See also

[TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets)

[LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg)

**send**