# IStreamAsync::WriteAsync

## Description

Writes information to a stream asynchronously. For example, the Shell implements this method on file items when transferring them asynchronously.

## Parameters

### `lpBuffer` [in]

Type: **const void***

A pointer to a buffer of size *cb* bytes that contains the information to be written to the stream.

### `cb` [in]

Type: **DWORD**

The size of the buffer pointed to by *lpBuffer*, in bytes.

### `pcbWritten` [out]

Type: **LPDWORD**

Pointer to a **DWORD** value that, when the method returns successfully, states the actual number of bytes written to the stream. This value can be **NULL** if this information is not needed.

### `lpOverlapped` [in]

Type: **LPOVERLAPPED**

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure that contains information used in the asynchronous write operation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**WriteAsync** should reset the event specified by the **hEvent** member of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure to a nonsignaled state when it begins the input/output (I/O) operation.