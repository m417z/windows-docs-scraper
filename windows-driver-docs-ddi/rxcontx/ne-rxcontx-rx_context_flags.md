## Description

The **RX_CONTEXT_FLAGS** enumeration specifies flags set by RDBSS during context creation.

## Constants

### `RX_CONTEXT_FLAG_FROM_POOL:0x00000001`

The context was allocated from pool memory.

### `RX_CONTEXT_FLAG_WAIT:0x00000002`

The operation should wait for completion.

### `RX_CONTEXT_FLAG_WRITE_THROUGH:0x00000004`

The data must actually be transfered to the file before any requested write operation is considered complete.

### `RX_CONTEXT_FLAG_FLOPPY:0x00000008`

The operation involves a floppy disk.

### `RX_CONTEXT_FLAG_RECURSIVE_CALL:0x00000010`

Indicates that the call is a recursive call.

### `RX_CONTEXT_FLAG_THIS_DEVICE_TOP_LEVEL:0x00000020`

Set when the TopLevelIrp field in the thread local storage isn't the current IRP.

### `RX_CONTEXT_FLAG_DEFERRED_WRITE:0x00000040`

The write operation is deferred.

### `RX_CONTEXT_FLAG_VERIFY_READ:0x00000080`

The read operation should be verified.

### `RX_CONTEXT_FLAG_STACK_IO_CONTEZT:0x00000100`

The I/O context is on the stack.

### `RX_CONTEXT_FLAG_IN_FSP:0x00000200`

The operation is being processed by the file system process.

### `RX_CONTEXT_FLAG_CREATE_MAILSLOT:0x00000400`

A mailslot is being created.

### `RX_CONTEXT_FLAG_MAILSLOT_REPARSE:0x00000800`

Indicates a mailslot reparse operation.

### `RX_CONTEXT_FLAG_ASYNC_OPERATION:0x00001000`

The operation is asynchronous.

### `RX_CONTEXT_FLAG_NO_COMPLETE_FROM_FSP:0x00002000`

The operation should not be completed by the file system process.

### `RX_CONTEXT_FLAG_POST_ON_STABLE_CONDITION:0x00004000`

Post the operation only when the condition is stable.

### `RX_CONTEXT_FLAG_FSP_DELAYED_OVERFLOW_QUEUE:0x00008000`

The operation is in the file system process delayed overflow queue.

### `RX_CONTEXT_FLAG_FSP_CRITICAL_OVERFLOW_QUEUE:0x00010000`

The operation is in the file system process critical overflow queue.

### `RX_CONTEXT_FLAG_MINIRDR_INVOKED:0x00020000`

Indicates that the mini-redirector invoked the operation.

### `RX_CONTEXT_FLAG_WAITING_FOR_RESOURCE:0x00040000`

The operation is waiting for a resource.

### `RX_CONTEXT_FLAG_CANCELLED:0x00080000`

The operation was cancelled.

### `RX_CONTEXT_FLAG_SYNC_EVENT_WAITERS:0x00100000`

There are waiters on a synchronous event.

### `RX_CONTEXT_FLAG_NO_PREPOSTING_NEEDED:0x00200000`

No preposting is needed for the operation.

### `RX_CONTEXT_FLAG_BYPASS_VALIDOP_CHECK:0x00400000`

Bypass the valid operation check.

### `RX_CONTEXT_FLAG_BLOCKED_PIPE_RESUME:0x00800000`

A blocked pipe operation is being resumed.

### `RX_CONTEXT_FLAG_IN_SERIALIZATION_QUEUE:0x01000000`

The operation is in the serialization queue.

### `RX_CONTEXT_FLAG_NO_EXCEPTION_BREAKPOINT:0x02000000`

Prevent an exception breakpoint.

### `RX_CONTEXT_FLAG_NEEDRECONNECT:0x04000000`

A reconnect is needed.

### `RX_CONTEXT_FLAG_MUST_SUCCEED:0x08000000`

The operation must succeed.

### `RX_CONTEXT_FLAG_MUST_SUCCEED_NONBLOCKING:0x10000000`

The operation must succeed without blocking.

### `RX_CONTEXT_FLAG_MUST_SUCCEED_ALLOCATED:0x20000000`

Resources must be allocated for the operation to succeed.

### `RX_CONTEXT_FLAG_MINIRDR_INITIATED:0x80000000`

The operation was initiated by the mini-redirector.

## See also

[**RX_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[**RxCreateRxContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/nf-rxcontx-rxcreaterxcontext)