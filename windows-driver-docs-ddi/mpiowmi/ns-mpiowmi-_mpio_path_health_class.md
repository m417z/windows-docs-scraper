# _MPIO_PATH_HEALTH_CLASS structure

## Description

The MPIO_PATH_HEALTH_CLASS structure represents the health information for a path.

## Members

### `PathId`

An unsigned 64-bitfield that represents an identifier that is assigned to a particular path.

### `NumberReads`

An unsigned 64-bitfield that specifies the number of read requests that are serviced by the specified path identifier.

### `NumberWrites`

An unsigned 64-bitfield that specifies the number of write requests that are serviced by the specified path identifier.

### `NumberBytesRead`

An unsigned 64-bitfield that specifies the total number of bytes that are read through the specified path identifier.

### `NumberBytesWritten`

An unsigned 64-bitfield that specifies the total number of bytes that are written through the specified path identifier.

### `NumberRetries`

An unsigned 64-bitfield that specifies the total number of retries by using the specified path identifier.

### `NumberIoErrors`

An unsigned 64-bitfield that specifies the total number of I/O errors that are encountered through the specified path identifier.

### `CreateTime`

A 64-bit integer that specifies the system time when this instance was created and exposed.

### `FailTime`

A 64-bit integer that specifies the system time when the path that is associated with this path ID was removed.

### `PathOffline`

A Boolean field that indicates whether the path that is associated with this path ID is removed.

### `NumberReadsWrap`

An unsigned character field that specifies the total number of times that the *NumberReads* parameter has rolled around to zero.

### `NumberWritesWrap`

An unsigned character field that specifies the total number of times that the *NumberWrites* parameter has rolled around to zero.

### `NumberBytesReadWrap`

An unsigned character field that specifies the total number of times the *NumberBytesRead* parameter has rolled around to zero.

### `NumberBytesWrittenWrap`

An unsigned character field that specifies the total number of times that the *NumberBytesWritten* parameter has rolled around to zero.

### `OutstandingRequests`

An unsigned character field that specifies the total number of outstanding requests.

### `Pad`

Should be zero.