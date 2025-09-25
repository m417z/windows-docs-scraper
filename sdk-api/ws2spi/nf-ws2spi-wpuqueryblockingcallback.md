# WPUQueryBlockingCallback function

## Description

The
**WPUQueryBlockingCallback** function returns a pointer to a callback function the service provider should invoke periodically while servicing blocking operations.

## Parameters

### `dwCatalogEntryId` [in]

Descriptor identifying the calling service provider.

### `lplpfnCallback` [out]

Pointer that receives the blocking callback function.

### `lpdwContext` [out]

Pointer that receives a context value that the service provider must pass into the blocking callback.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUQueryBlockingCallback** returns zero and stores a pointer to a blocking callback function in *lpfnCallback* and an associated context value in *lpdwContext*. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpfnCallback* or the *lpdwContext* parameter is not a valid part of the process address space. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *dwCatalogEntryId* parameter is invalid. |

## Remarks

The
**WPUQueryBlockingCallback** function returns a pointer to a callback function in *lpfnCallback* to be invoked periodically during blocking operations. This function also returns a context value in *lpdwContext* to be passed into the blocking callback.

In Windows, this function can return null in *lpfnCallback*, indicating that no user defined–blocking hook is installed. In this case, the service provider should use the native Windows synchronization objects to implement blocking.

LPBLOCKINGCALLBACK is defined as follows:

```cpp
typedef BOOL ( CALLBACK FAR * LPBLOCKINGCALLBACK )( DWORD dwContext );

```

The blocking callback will return **TRUE** if the service provider is to continue waiting for the blocking operation to complete. It will return **FALSE** if the blocking operation has been canceled with the
[WSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall).

Any missing components of the address will default to a reasonable value if possible. For example, a missing port number will default to zero.

## See also

[WSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall)