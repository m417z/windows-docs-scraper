# RtlFlushNonVolatileMemory function

## Description

The routine **RtlFlushNonVolatileMemory** optimally flushes the given non-volatile memory region.

## Parameters

### `NvToken`

 A pointer to an opaque structure that has
information about various properties of the non-volatile memory region which [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken) had returned.

### `NvBuffer`

A pointer to the non-volatile memory to flush. This should be user addresses obtained from
a file mapping object.

### `Size`

The length, in bytes, of the non-volatile memory buffer **NvBuffer** points to.

### `Flags`

One of the following flags can be specified:

| Flags | Meaning |
| --- | --- |
| FLUSH_NV_MEMORY_IN_FLAG_NO_DRAIN | Specifies that this routine does not need to wait for the flush to drain. |

## Return value

The routine **RtlFreeNonVolatileToken** returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | **NvToken** is an invalid pointer or token. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

 This routine **RtlFlushNonVolatileMemory** can also add more context to **NvToken** to help verifiers. This routine is currently not supported for Windows Server until the next major release of Windows Server.

## See also

[RtlDrainNonVolatileFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldrainnonvolatileflush)

[RtlFlushNonVolatileMemoryRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememoryranges)

[RtlFreeNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlfreenonvolatiletoken)

[RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken)

[RtlWriteNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlwritenonvolatilememory)