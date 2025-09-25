# IStreamAsync::OverlappedResult

## Description

Retrieves the results of an overlapped operation.

## Parameters

### `lpOverlapped` [in]

Type: **LPOVERLAPPED***

A pointer to the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/shobjidl/ns-shobjidl-overlapped) structure that was specified when the overlapped operation was started.

### `lpNumberOfBytesTransferred` [out]

Type: **LPDWORD**

When this method returns, contains the number of bytes that were actually transferred by a read or write operation.

### `bWait` [in]

Type: **BOOL**

If **TRUE** the method does not return until the operation has been completed. If **FALSE** and an operation is pending, the method returns the HRESULT equivalent to ERROR_IO_INCOMPLETE.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.