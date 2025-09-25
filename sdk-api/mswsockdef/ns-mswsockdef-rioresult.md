# RIORESULT structure

## Description

The **RIORESULT** structure contains data used to indicate request completion results used with the Winsock registered I/O extensions.

## Members

### `Status`

The completion status of the Winsock registered I/O request.

### `BytesTransferred`

The number of bytes sent or received in the I/O request.

### `SocketContext`

An application-provided context specified in call to the [RIOCreateRequestQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreaterequestqueue) function.

### `RequestContext`

An application-provided context specified with the registered I/O request to the [RIOReceive](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive), [RIOReceiveEx](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex), [RIOSend](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend), and [RIOSendEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437216(v=vs.85)) functions.

## Remarks

The **RIORESULT** structure defines the data format used to indicate request completion by the Winsock registered I/O extensions. An application requests completion indications by allocating an array of **RIORESULT** structures and passing the array of **RIORESULT** structures to the [RIODequeueCompletion](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion) function along with the element count. The application need not perform any initialization of the **RIORESULT** structure elements before calling the **RIODequeueCompletion** function.

The **SocketContext** member of the **RIORESULT** structure can be used by an application to identify the [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue) object or the associated application object on which the Winsock registered I/O request was issued. The **RequestContext** member of the **RIORESULT** structure can similarly be used to identify the particular Winsock registered I/O request that was completed.

The **RIORESULT** structure is defined in the *Mswsockdef.h* header file which is automatically included in the *Mswsock.h* header file. The *Mswsockdef.h* header file should never be used directly.

## See also

[RIOCreateRequestQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreaterequestqueue)

[RIODequeueCompletion](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion)

[RIOReceive](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive)

[RIOReceiveEx](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex)

[RIOSend](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend)

[RIOSendEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437216(v=vs.85))