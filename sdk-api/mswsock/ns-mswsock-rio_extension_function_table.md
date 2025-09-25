# RIO_EXTENSION_FUNCTION_TABLE structure

## Description

The **RIO_EXTENSION_FUNCTION_TABLE** structure contains information on the functions that implement the Winsock registered I/O extensions.

## Members

### `cbSize`

The size, in bytes, of the structure.

### `RIOReceive`

A pointer to the [RIOReceive](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive) function.

### `RIOReceiveEx`

A pointer to the [RIOReceiveEx](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex) function.

### `RIOSend`

A pointer to the [RIOSend](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend) function.

### `RIOSendEx`

A pointer to the [RIOSendEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437216(v=vs.85)) function.

### `RIOCloseCompletionQueue`

A pointer to the [RIOCloseCompletionQueue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh448837(v=vs.85)) function.

### `RIOCreateCompletionQueue`

A pointer to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function.

### `RIOCreateRequestQueue`

A pointer to the [RIOCreateRequestQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreaterequestqueue) function.

### `RIODequeueCompletion`

A pointer to the [RIODequeueCompletion](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion) function.

### `RIODeregisterBuffer`

A pointer to the [RIODeregisterBuffer](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioderegisterbuffer) function.

### `RIONotify`

A pointer to the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function.

### `RIORegisterBuffer`

A pointer to the [RIORegisterBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437199(v=vs.85)) function.

### `RIOResizeCompletionQueue`

A pointer to the [RIOResizeCompletionQueue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437202(v=vs.85)) function.

### `RIOResizeRequestQueue`

A pointer to the [RIOResizeRequestQueue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437204(v=vs.85)) function.

## Remarks

The **RIO_EXTENSION_FUNCTION_TABLE** structure contains information on the functions that implement the Winsock registered I/O extensions.

The function pointers for the
Winsock registered I/O extension functions must be obtained at run time by making a call to the
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with the **SIO_GET_MULTIPLE_EXTENSION_FUNCTION_POINTER** opcode specified. The input buffer passed to the **WSAIoctl** function must contain **WSAID_MULTIPLE_RIO**, a globally unique identifier (GUID) whose value identifies the Winsock registered I/O extension functions. On success, the output returned by the **WSAIoctl** function contains a pointer to the **RIO_EXTENSION_FUNCTION_TABLE** structure that contains pointers to the Winsock registered I/O extension functions. The **SIO_GET_MULTIPLE_EXTENSION_FUNCTION_POINTER** IOCTL is defined in the *Ws2def.h* header file.The **WSAID_MULTIPLE_RIO** GUID is defined in the *Mswsock.h* header file.

## See also

[RIOCloseCompletionQueue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh448837(v=vs.85))

[RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue)

[RIOCreateRequestQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreaterequestqueue)

[RIODequeueCompletion](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riodequeuecompletion)

[RIODeregisterBuffer](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioderegisterbuffer)

[RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify)

[RIOReceive](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceive)

[RIOReceiveEx](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rioreceiveex)

[RIORegisterBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437199(v=vs.85))

[RIOResizeCompletionQueue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437202(v=vs.85))

[RIOResizeRequestQueue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437204(v=vs.85))

[RIOSend](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riosend)

[RIOSendEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437216(v=vs.85))

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)