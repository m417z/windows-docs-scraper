# _MPIO_DISK_HEALTH_CLASS structure

## Description

The MPIO_DISK_HEALTH_CLASS structure contains the health information for a multi-path disk.

## Members

### `Name`

The name of this multi-path disk.

### `NumberReads`

An unsigned 64-bitfield that specifies the number of read requests that are serviced by this multi-path disk.

### `NumberWrites`

An unsigned 64-bitfield that specifies the number of write requests that are serviced by this multi-path disk.

### `NumberBytesRead`

An unsigned 64-bitfield that specifies the total number of bytes that are read from this multi-path disk.

### `NumberBytesWritten`

An unsigned 64-bitfield that specifies the total number of bytes that are written to this multi-path disk.

### `NumberRetries`

An unsigned 64-bitfield that specifies the total number of retries for this multi-path disk.

### `NumberIoErrors`

An unsigned 64-bitfield that specifies the total number of I/O errors that are encountered by this multi-path disk.

### `CreateTime`

A 64-bit integer that specifies the system time when the health packet was created for this multi-path disk.

### `PathFailures`

A 64-bit integer that specifies the total number of path failures for this multi-path disk.

### `FailTime`

A 64-bit integer that specifies the system time when this multi-path disk went offline or failed.

### `DeviceOffline`

A Boolean field that indicates whether the multi-path disk is offline or has failed.

### `NumberReadsWrap`

An unsigned character field that specifies the total number of times that the *NumberReads* parameter has rolled around to zero.

### `NumberWritesWrap`

An unsigned character field that specifies the total number of times the *NumberWrites* parameter has rolled around to zero.

### `NumberBytesReadWrap`

An unsigned character field that specifies the total number of times that the *NumberBytesRead* parameter has rolled around to zero.

### `NumberBytesWrittenWrap`

An unsigned character field that specifies the total number of times that the *NumberBytesWritten* parameter has rolled around to zero.

### `Pad`

Should be zero.