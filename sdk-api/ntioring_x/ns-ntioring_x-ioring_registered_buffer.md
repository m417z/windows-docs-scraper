## Description

Represents a buffer that has been registered with an I/O ring with a call to [BuildIoRingRegisterBuffers](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-buildioringregisterbuffers).

## Members

### `BufferIndex`

A **UINT32** specifying the index of the registered buffer.

### `Offset`

A **UINT32** specifying the offset into the registered buffer.

## Remarks

By using both a buffer index within the submission queue and an offset within the buffer, you can use large buffers and schedule multiple I/O ring operations within the same buffer to be performed asynchronously.

## See also