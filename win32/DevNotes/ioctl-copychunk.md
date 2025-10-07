# IOCTL\_COPYCHUNK control code

The **IOCTL\_COPYCHUNK** control code initiates a server-side copy of a range of data, also called a chunk.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_COPYCHUNK,              // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
  (LPVOID) lpOutBuffer,         // output buffer
  (DWORD) nOutBufferSize,       // size of output buffer
  (LPDWORD) lpBytesReturned,    // number of bytes returned
  (LPOVERLAPPED) lpOverlapped   // OVERLAPPED structure
);
```

## Parameters

*hDevice* \[in\]

A handle to the file that is the target of the server-side copy operation. To obtain this handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function.

*dwIoControlCode* \[in\]

The control code for the operation. Use **IOCTL\_COPYCHUNK** for this operation.

*lpInBuffer*

A pointer to the input buffer, a **SRV\_COPYCHUNK\_COPY** structure. For more information, see the Remarks section.

*nInBufferSize* \[in\]

The size of the input buffer, in bytes.

*lpOutBuffer* \[out\]

A pointer to the output buffer, a **SRV\_COPYCHUNK\_RESPONSE** structure. For more information, see the Remarks section.

*nOutBufferSize* \[in\]

The size of the output buffer, in bytes.

*lpBytesReturned* \[out\]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

If the output buffer is too small, the call fails, the [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR\_INSUFFICIENT\_BUFFER**, and *lpBytesReturned* is zero.

If the *lpOverlapped* parameter is **NULL**, *lpBytesReturned* cannot be **NULL**. Even when an operation returns no output data and the *lpOutBuffer* parameter is **NULL**, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) makes use of *lpBytesReturned*. After such an operation, the value of *lpBytesReturned* is meaningless.

If *lpOverlapped* is not **NULL**, *lpBytesReturned* can be **NULL**. If *lpOverlapped* is not **NULL** and the operation returns data, *lpBytesReturned* is meaningless until the overlapped operation has completed. To retrieve the number of bytes returned, call the [**GetOverlappedResult**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult) function. If the *hDevice* parameter is associated with an I/O completion port, you can retrieve the number of bytes returned by calling the [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

*lpOverlapped* \[in\]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

If the *hDevice* parameter was opened without specifying **FILE\_FLAG\_OVERLAPPED**, *lpOverlapped* is ignored.

If *hDevice* was opened with the **FILE\_FLAG\_OVERLAPPED** flag, the operation is performed as an overlapped (asynchronous) operation. In this case, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. Otherwise, the function fails in unpredictable ways.

For overlapped operations, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns immediately, and the event object is signaled when the operation has been completed. Otherwise, the function does not return until the operation has been completed or until an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This control code has no associated header file. You must define the control code and data structures as follows.

``` syntax
#define IOCTL_COPYCHUNK CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 262, METHOD_BUFFERED,  FILE_READ_ACCESS)

typedef struct _SRV_COPYCHUNK {
    LARGE_INTEGER SourceOffset;
    LARGE_INTEGER DestinationOffset;
    ULONG  Length;
} SRV_COPYCHUNK, *PSRV_COPYCHUNK;

typedef struct _SRV_COPYCHUNK_COPY {
    SRV_RESUME_KEY SourceFile;
    ULONG          ChunkCount;
    ULONG          Reserved;
    SRV_COPYCHUNK  Chunk[1];    // Array
} SRV_COPYCHUNK_COPY, *PSRV_COPYCHUNK_COPY;

typedef struct _SRV_COPYCHUNK_RESPONSE {
    ULONG          ChunksWritten;
    ULONG          ChunkBytesWritten;
    ULONG          TotalBytesWritten;
} SRV_COPYCHUNK_RESPONSE, *PSRV_COPYCHUNK_RESPONSE;
```

These members can be described as follows.

| Member | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SourceOffset**<br> | The offset, in bytes, from the beginning of the source file to the chunk to be copied.<br> |
| **DestinationOffset**<br> | The offset, in bytes, from the beginning of the target file to the location where the chunk is to be copied.<br> |
| **Length**<br> | The number of bytes of data in the chunk to be copied. Must be greater than zero and less than or equal to 1 MB. **Length** \* **ChunkCount** must be less than or equal to 16 MB.<br> |
| **SourceFile**<br> | A key that represents the source file with the data to be copied. This key is obtained through [**FSCTL\_SRV\_REQUEST\_RESUME\_KEY**](https://learn.microsoft.com/windows/win32/devnotes/fsctl-srv-request-resume-key).<br> |
| **ChunkCount**<br> | The number of chunks to be copied. Must be greater than zero and less than or equal to 256.<br> |
| **Reserved**<br> | This member is reserved for system use; do not use.<br> |
| **Chunk**<br> | An array of **ChunkCount** **SRV\_COPYCHUNK** structures, one for each chunk to be copied. The length, in bytes, of this array must be **ChunkCount** \* sizeof(**SRV\_COPYCHUNK**).<br> |
| **ChunksWritten**<br> | If the operation failed with **ERROR\_INVALID\_PARAMETER**, this value indicates the maximum number of chunks the server will accept in a single request, which is 256. Otherwise, this value indicates the number of chunks that were successfully written.<br> |
| **ChunkBytesWritten**<br> | If the operation failed with **ERROR\_INVALID\_PARAMETER**, this value indicates the maximum number of bytes the server will allow to be written in a single chunk, which is 1 MB. Otherwise, this value indicates the number of bytes that were successfully written in the last chunk that was not successfully processed (if a partial write occurred).<br> |
| **TotalBytesWritten**<br> | If the operation failed with **ERROR\_INVALID\_PARAMETER**, this value indicates the maximum number of bytes the server will copy in a single request, which is 16 MB. Otherwise, this value indicates the number of bytes that were successfully written.<br> |

## See also

[**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)

[**FSCTL\_SRV\_REQUEST\_RESUME\_KEY**](https://learn.microsoft.com/windows/win32/devnotes/fsctl-srv-request-resume-key)

