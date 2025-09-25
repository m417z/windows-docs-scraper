# OVERLAPPED structure

## Description

Contains information used in asynchronous (or *overlapped*) input and output (I/O).

## Members

### `Internal`

The status code for the I/O request. When the request is issued, the system sets this member to **STATUS_PENDING** to indicate that the operation has not yet started. When the request is completed, the system sets this member to the status code for the completed request.

The **Internal** member was originally reserved for system use and its behavior may change.

### `InternalHigh`

The number of bytes transferred for the I/O request. The system sets this member if the request is completed without errors.

The **InternalHigh** member was originally reserved for system use and its behavior may change.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Offset`

The low-order portion of the file position at which to start the I/O request, as specified by the user.

This member is nonzero only when performing I/O requests on a seeking device that supports the concept of an offset (also referred to as a file pointer mechanism), such as a file. Otherwise, this member must be zero.

For additional information, see Remarks.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.OffsetHigh`

The high-order portion of the file position at which to start the I/O request, as specified by the user.

This member is nonzero only when performing I/O requests on a seeking device that supports the concept of an offset (also referred to as a file pointer mechanism), such as a file. Otherwise, this member must be zero.

For additional information, see Remarks.

### `DUMMYUNIONNAME.Pointer`

Reserved for system use; do not use after initialization to zero.

### `hEvent`

A handle to the event that will be set to a signaled state by the system when the operation has completed. The user must initialize this member either to zero or a valid event handle using the [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function before passing this structure to any overlapped functions. This event can then be used to synchronize simultaneous I/O requests for a device. For additional information, see Remarks.

Functions such as [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) and [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) set this handle to the nonsignaled state before they begin an I/O operation. When the operation has completed, the handle is set to the signaled state.

Functions such as [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) and the synchronization [wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) reset auto-reset events to the nonsignaled state. Therefore, you should use a manual reset event; if you use an auto-reset event, your application can stop responding if you wait for the operation to complete and then call **GetOverlappedResult** with the *bWait* parameter set to **TRUE**.

## Remarks

Any unused members of this structure should always be initialized to zero before the structure is used in a function call. Otherwise, the function may fail and return **ERROR_INVALID_PARAMETER**.

The **Offset** and **OffsetHigh** members together represent a 64-bit file position. It is a byte offset from the start of the file or file-like device, and it is specified by the user; the system will not modify these values. The calling process must set this member before passing the **OVERLAPPED** structure to functions that use an offset, such as the
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) or
[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) (and related) functions.

You can use the
[HasOverlappedIoCompleted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-hasoverlappediocompleted) macro to check whether an asynchronous I/O operation has completed if [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) is too cumbersome for your application.

You can use the
[CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio) function to cancel an asynchronous I/O operation.

A common mistake is to reuse an **OVERLAPPED** structure before the previous asynchronous operation has been completed. You should use a separate structure for each request. You should also create an event object for each thread that processes data. If you store the event handles in an array, you could easily wait for all events to be signaled using the [WaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects) function.

For additional information and potential pitfalls of asynchronous I/O usage, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea), [ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile), [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile), and related functions.

For a general synchronization overview and conceptual **OVERLAPPED** usage information, see [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output) and related topics.

For a file I/O–oriented overview of synchronous and asynchronous I/O, see [Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o).

#### Examples

For an example, see [Named Pipe Server Using Overlapped I/O](https://learn.microsoft.com/windows/desktop/ipc/named-pipe-server-using-overlapped-i-o).

## See also

[CancelIo](https://learn.microsoft.com/windows/desktop/FileIO/cancelio)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[HasOverlappedIoCompleted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-hasoverlappediocompleted)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)

[Synchronous and Asynchronous I/O](https://learn.microsoft.com/windows/desktop/FileIO/synchronous-and-asynchronous-i-o)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)