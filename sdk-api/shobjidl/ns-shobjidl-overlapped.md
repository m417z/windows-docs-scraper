# OVERLAPPED structure

## Description

Contains information used in asynchronous (overlapped) input/output (I/O).

## Members

### `Internal`

Type: **ULONG_PTR**

Reserved for operating system use. This member, which specifies a system-dependent status, is valid when the [IStreamAsync::OverlappedResult](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-overlappedresult) function returns without setting the extended error information to **ERROR_IO_PENDING**.

### `InternalHigh`

Type: **ULONG_PTR**

Reserved for operating system use. This member, which specifies the length of the data transferred, is valid when the [IStreamAsync::OverlappedResult](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-overlappedresult) function returns **TRUE**.

### `Offset`

Type: **DWORD**

File position at which to start the transfer. The file position is a byte offset from the start of the file. The calling process must set this member before it calls the [IStreamAsync::ReadAsync](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-readasync) or [IStreamAsync::WriteAsync](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-writeasync) function.

### `OffsetHigh`

Type: **DWORD**

High-order word of the file position at which to start the transfer.

### `Pointer`

Type: **PVOID**

Reserved.

### `hEvent`

Type: **handle**

Handle to an event that is set to the signaled state when the operation has been completed. The calling process must set this member either to zero or a valid event handle before it calls any overlapped functions. To create an event object, use the [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function. This function returns a handle that can be used to synchronize simultaneous I/O requests for a device.

Functions such as [IStreamAsync::ReadAsync](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-readasync) and [IStreamAsync::WriteAsync](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-writeasync) set this handle to the nonsignaled state before they begin an I/O operation. When the operation has completed, the handle is set to the signaled state.

Functions such as [IStreamAsync::OverlappedResult](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-overlappedresult) and the wait functions reset auto-reset events to the nonsignaled state. Therefore, if an auto-reset event is used, the application can stop responding if it waits for the operation to complete and then calls **IStreamAsync::OverlappedResult**.

## Remarks

This structure should always be initialized to zero before it is used in a function call. If it is not, the function can fail and return **ERROR_INVALID_PARAMETER**.

 Use the [IStreamAsync::CancelIo](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-istreamasync-cancelio) function to cancel an asynchronous I/O operation.

A common mistake is to reuse an **OVERLAPPED** structure before the previous asynchronous operation has been completed. Use a separate structure for each request. Create an event object for each thread that processes data.