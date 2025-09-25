# _MPIO_DEVINSTANCE_HEALTH_CLASS structure

## Description

The MPIO_DEVINSTANCE_HEALTH_CLASS structure holds the health information for an instance of a device exposed through the specified path identifiers.

## Members

### `PathId`

An unsigned 64-bitfield that returns the path identifier that is associated with this instance of a multi-path disk.

### `NumberReads`

An unsigned 64-bitfield that specifies the number of read requests that are serviced by the specified path identifier.

### `NumberWrites`

An unsigned 64-bitfield that specifies the number of write requests that are serviced by the specified path identifier

### `NumberBytesRead`

An unsigned 64-bitfield that specifies the total number of bytes that are read through the specified path identifier

### `NumberBytesWritten`

An unsigned 64-bitfield that specifies the total number of bytes that are written through the specified path identifier.

### `NumberRetries`

An unsigned 64-bitfield that specifies the total number of retries through the specified path identifier.

### `NumberIoErrors`

An unsigned 64-bitfield that specifies the total number of I/O errors that are encountered through the specified path identifier.

### `CreateTime`

A 64-bit integer that specifies the system time when this instance was created and exposed.

### `FailTime`

A 64-bit integer that specifies the system time when the path associated with this path ID was removed.

### `DeviceOffline`

A Boolean field that indicates whether the path associated with this path ID has been removed.

### `NumberReadsWrap`

An unsigned character field that specifies the total number of times the *NumberReads* parameter has rolled around to zero.

### `NumberWritesWrap`

An unsigned character field that specifies the total number of times the *NumberWrites* parameter has rolled around to zero.

### `NumberBytesReadWrap`

An unsigned character field that specifies the total number of times the *NumberBytesRead* parameter has rolled around to zero.

### `NumberBytesWrittenWrap`

An unsigned character field that specifies the total number of times the *NumberBytesWritten* parameter has rolled around to zero.

### `Pad`

Should be zero.