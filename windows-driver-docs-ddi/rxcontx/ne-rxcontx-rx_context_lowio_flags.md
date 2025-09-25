## Description

The **RX_CONTEXT_LOWIO_FLAGS** enumeration specifies flags set by RDBSS during low I/O operations.

## Constants

### `RXCONTEXT_FLAG4LOWIO_PIPE_OPERATION:0x1`

The operation is a pipe operation.

### `RXCONTEXT_FLAG4LOWIO_PIPE_SYNC_OPERATION:0x2`

The operation is a synchronous pipe operation.

### `RXCONTEXT_FLAG4LOWIO_READAHEAD:0x4`

Enables read-ahead.

### `RXCONTEXT_FLAG4LOWIO_THIS_READ_ENLARGED:0x8`

This read operation is enlarged.

### `RXCONTEXT_FLAG4LOWIO_THIS_IO_BUFFERED:0x10`

The I/O operation is buffered.

### `RXCONTEXT_FLAG4LOWIO_LOCK_FCB_RESOURCE_HELD:0x20`

The FCB (File Control Block) resource is held.

### `RXCONTEXT_FLAG4LOWIO_LOCK_WAS_QUEUED_IN_LOCKMANAGER:0x40`

The lock was queued in the lock manager.

### `RXCONTEXT_FLAG4LOWIO_THIS_IO_FAST:0x80`

The I/O operation is fast I/O.

### `RXCONTEXT_FLAG4LOWIO_LOCK_OPERATION_COMPLETED:0x100`

The lock operation is completed.

### `RXCONTEXT_FLAG4LOWIO_LOCK_BUFFERED_ON_ENTRY:0x200`

The lock operation is buffered on entry.