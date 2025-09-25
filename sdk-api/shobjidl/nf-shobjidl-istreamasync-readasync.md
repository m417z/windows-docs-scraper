# IStreamAsync::ReadAsync

## Description

Reads information from a stream asynchronously. For example, the Shell implements this interface on file items when transferring them asynchronously.

## Parameters

### `pv` [out]

Type: **void***

When this method returns successfully, returns a buffer that is *cb* bytes long and contains *pcbRead* bytes of information from the read operation.

### `cb` [in]

Type: **DWORD**

The number of bytes to read from the stream.

### `pcbRead` [out, optional]

Type: **LPDWORD**

Pointer to a **DWORD** value that, when this method returns successfully, states the actual number of bytes read to the buffer pointed to by *pv*. This value can be **NULL**.

### `lpOverlapped` [in]

Type: **LPOVERLAPPED**

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure that contains information used in the asynchronous read operation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IStreamAsync::ReadAsync** should reset the event specified by the **hEvent** member of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure to a nonsignaled state when it begins the input/output (I/O) operation.

This method has been implemented in the Shell as a thin wrapper around the public [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) API.