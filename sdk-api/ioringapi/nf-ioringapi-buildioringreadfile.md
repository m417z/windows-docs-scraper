## Description

Performs an asynchronous read from a file using an I/O ring. This operation is similar to calling [ReadFileEx](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfileex).

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring which will perform the read operation.

### `fileRef`

An [IORING_HANDLE_REF](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_handle_ref) specifying the file to read.

### `dataRef`

An [IORING_BUFFER_REF](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_buffer_ref) specifying the buffer into which the file is read. The provided buffer must have a size of at least *numberOfBytesToRead* bytes.

### `numberOfBytesToRead`

The number of bytes to read.

### `fileOffset`

The offset into the file to begin reading.

### `userData`

A UINT_PTR value identifying the file read operation. Specify this value when cancelling the operation with a call to [BuildIoRingCancelRequest](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-buildioringcancelrequest). If an app implements cancellation behavior for the operation, the *userData* value must be unique. Otherwise, the value is treated as opaque by the system and can be anything, including 0.

### `flags`

A bitwise OR combination of values from the [IORING_SQE_FLAGS](https://learn.microsoft.com/windows/win32/api/ioringapi/ne-ioringapi-ioring_sqe_flags) enumeration specifying kernel behavior options for I/O ring submission queue entries.

## Return value

Returns an HRESULT including, but not limited to the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| IORING_E_SUBMISSION_QUEUE_FULL | The submission queue is full, and no additional entries are available to build. The application must submit the existing entries and wait for some of them to complete before adding more operations to the queue. |
| IORING_E_UNKNOWN_REQUIRED_FLAG | The application provided a required flag that is not known to the implementation. Library code should check the *IoRingVersion* field of the [IORING_INFO](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_info) obtained from a call to [GetIoRingInfo](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-getioringinfo) to determine the API version of an I/O ring which determines the operations and flags that are supported. Applications should know the version they used to create the I/O ring and therefore should not provide unsupported flags at runtime. |

## Remarks

Check I/O ring support for read file operations by calling [IsIoRingOpSupported](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-isioringopsupported) and specifying [IORING_OP_READ](https://learn.microsoft.com/windows/win32/api/ntioring_x/ne-ntioring_x-ioring_op_code) for the *op* parameter.

## See also