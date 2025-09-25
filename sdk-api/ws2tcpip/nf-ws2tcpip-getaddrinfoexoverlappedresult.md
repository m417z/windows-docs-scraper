# GetAddrInfoExOverlappedResult function

## Description

The
**GetAddrInfoExOverlappedResult** function gets the return code for an **OVERLAPPED** structure used by an asynchronous operation for the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function.

## Parameters

### `lpOverlapped`

A pointer to an **OVERLAPPED** structure for the asynchronous operation.

## Return value

On success, the **GetAddrInfoExOverlappedResult** function returns **NO_ERROR** (0). When the
underlying operation hasn't yet completed, the **GetAddrInfoExOverlappedResult** function returns **WSAEINPROGRESS**. On failure, the **GetAddrInfoExOverlappedResult** function returns **WSAEINVAL**.

## Remarks

The
**GetAddrInfoExOverlappedResult** function is used with the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function for asynchronous operations.

If the **GetAddrInfoExOverlappedResult** function returns **WSAEINVAL**, the only way to distinguish whether **GetAddrInfoExOverlappedResult** function or the asynchronous operation returned the
error is to check that the *lpOverlapped* parameter was not NULL. If the *lpOverlapped* parameter was NULL, then the **GetAddrInfoExOverlappedResult** function was passed a NULL pointer and failed.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)