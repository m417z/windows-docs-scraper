# WPUQueueApc function

## Description

The
**WPUQueueApc** function queues a user mode–asynchronous procedure call (APC) to the specified thread in order to facilitate invocation of overlapped I/O completion routines.

## Parameters

### `lpThreadId` [in]

Pointer to a
[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid) structure that identifies the thread context. A pointer to this structure is supplied to the service provider by the Ws2_32.dll as an input parameter to an overlapped operation. The provider should store the
**WSATHREADID** structure locally and provide a pointer to this local store. The local copy of
**WSATHREADID** is no longer needed once
**WPUQueueApc** returns.

### `lpfnUserApc` [in]

Pointer to the APC function to be called.

### `dwContext` [in]

32-bit context value that is subsequently supplied as an input parameter to the APC function.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUQueueApc** returns zero and queues the completion routine for the specified thread. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *dwThreadId* parameter does not specify a valid thread. |

## Remarks

This function queues an APC function against the specified thread. Under Windows, this will be done using a user mode–asynchronous procedure call (APC). The APC will only execute when the specified thread is blocked in an alertable wait and a callback will be made directly. This call is safe for use within an interrupt context.

LPWSAUSERAPC is defined as follows:

```cpp
typedef void ( CALLBACK FAR * LPWSAUSERAPC )( DWORD dwContext );

```

Because the APC mechanism supports only a single context value, *lpfnUserApc* itself cannot be the client specified–completion routine, which involves more parameters. The service provider must instead supply a pointer to its own APC function that uses the supplied *dwContext* value to access the needed result information for the overlapped operation, and then invokes the client specified–completion routine.

For service providers where a user-mode component implements overlapped I/O, a typical usage of the APC mechanism is as follows.

- When the I/O operation completes, the provider allocates a small buffer and packs it with a pointer to the client-supplied completion procedure and parameter values to pass to the procedure.
- It queues an APC, specifying the pointer to the buffer as the *dwContext* value and its own intermediate procedure as the target procedure *lpfnUserApc*.
- When the target thread eventually enters alertable wait state, the service provider's intermediate procedure is called in the proper thread context.
- The intermediate procedure simply unpacks parameters, deallocates the buffer, and calls the client-supplied completion procedure.

## See also

[WSATHREADID](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-wsathreadid)

[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)

[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)

[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)

[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)

[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)