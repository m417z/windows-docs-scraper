# RIO_BUF structure

## Description

The **RIO_BUF** structure specifies a portion of a registered buffer used for sending or receiving network data with the Winsock registered I/O extensions.

## Members

### `BufferId`

The registered buffer descriptor for a Winsock registered I/O buffer used with send and receive requests.

### `Offset`

The offset, in bytes, into the buffer specified by the **BufferId** member. An **Offset** value of zero points to the beginning of the buffer

### `Length`

A length, in bytes, of the buffer to use from the **Offset** member.

## Remarks

The Winsock registered I/O extensions often operate on portions of registered buffers sometimes called buffer slices. The **RIO_BUF** structure is used by an application that needs to use a small amount of registered memory for sending or receiving network data. The application can often increase performance by registering one large buffer and then using small chunks of the buffer as needed. The **RIO_BUF** structure may describe any contiguous segment of memory contained in a single buffer registration.

A pointer to a **RIO_BUF** structure is passed as the *pData* parameter to the [RIOSend](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend), [RIOSendEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437216(v=vs.85)), [RIOReceive](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive), and [RIOReceiveEx](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex) functions to send or receive network data.

An application cannot resize a registered buffer simply by using a buffer slice with values larger than the original buffer that was registered using the [RIORegisterBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437199(v=vs.85)) function.

The **RIO_BUF** structure is defined in the *Mswsockdef.h* header file which is automatically included in the *Mswsock.h* header file. The *Mswsockdef.h* header file should never be used directly.

## See also

[RIODeregisterBuffer](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioderegisterbuffer)

[RIOReceive](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive)

[RIOReceiveEx](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex)

[RIORegisterBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437199(v=vs.85))

[RIOSend](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend)

[RIOSendEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437216(v=vs.85))

[RIO_BUFFERID](https://learn.microsoft.com/windows/desktop/WinSock/rio-bufferid)