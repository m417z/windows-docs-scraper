# _DEBUG_READ_USER_MINIDUMP_STREAM structure

## Description

Describes a user minidump to read.

## Members

### `StreamType`

The type of stream.

### `Flags`

Flags.

### `Offset`

The offset of stream.

### `Buffer`

Specifies the beginning of the buffer to read.

### `BufferSize`

Specifies the length of the buffer to read.

### `BufferUsed`

The buffer used value.

## Remarks

The DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation reads a stream from a user-mode minidump target.

### Parameters

The DEBUG_READ_USER_MINIDUMP_STREAM structure holds the parameters for the DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation.

```cpp
typedef struct _DEBUG_READ_USER_MINIDUMP_STREAM
{
    IN ULONG  StreamType;
    IN ULONG  Flags;
    IN ULONG64  Offset;
    OUT PVOID  Buffer;
    IN ULONG  BufferSize;
    OUT ULONG  BufferUsed;
} DEBUG_READ_USER_MINIDUMP_STREAM, *PDEBUG_READ_USER_MINIDUMP_STREAM;
```

### Members

The target must be a user-mode minidump file.

Each minidump file contains a number of *streams*. These streams are blocks of data written to the minidump file.