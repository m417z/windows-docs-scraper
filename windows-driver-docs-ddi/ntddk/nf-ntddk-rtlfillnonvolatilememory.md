# RtlFillNonVolatileMemory function

## Description

The routine **RtlFillNonVolatileMemory** fills the non-volatile destination buffer with the given value.

## Parameters

### `NvToken`

A pointer to an opaque structure that has more information about the non-volatile memory region which [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken) had returned.

### `NvDestination`

A pointer to the non-volatile destination buffer.

### `Size`

Specifies the length, in bytes, of the fill operation.

### `Value`

A UCHAR containing the value with which to fill the destination buffer.

### `Flags`

A value of type ULONG containing one or more of the following flags:

| Flags | Meaning |
|---|---|
| FILL_NV_MEMORY_FLAG_FLUSH | Set the provided value, then flush the destination range. Unless FILL_NV_MEMORY_FLAG_NO_DRAIN is specified, the flush is followed by a drain. This flag ensures that the data is durable even in the event of system power loss. |
| FILL_NV_MEMORY_FLAG_NON_TEMPORAL | Perform a non-temporal memset when available. Non-temporal means that data caching is not required. If the processor does not support non-temporal operations for ranges smaller than address bus size, perform a regular memset followed by flush and drain. If the processor ignores non-temporal moves altogether, RtlSetNonVolatileMemory doesn't replace it with flush and drain. However, if Windows doesn't haven an implementation for a given architecture (say ARM64), replace it with flush and drain. |
| FILL_NV_MEMORY_FLAG_PERSIST | Makes sure that the memset is persisted either by flushing or using non-temporal moves. Typically, the system uses the approach that is least costly to persist the data. This flag makes sure that the data is durable even in case of system power loss. Ignored when FILL_NV_MEMORY_FLAG_PERSIST is specified. |
| FILL_NV_MEMORY_FLAG_NO_DRAIN | Tells the routine not to wait for the flush to complete. Must be specified in conjunction with FILL_NV_MEMORY_FLAG_FLUSH and without FILL_NV_MEMORY_FLAG_PERSIST or FILL_NV_MEMORY_FLAG_NON_TEMPORAL. |

## Return value

The routine returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | **NvToken** is an invalid pointer or token. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

## See also