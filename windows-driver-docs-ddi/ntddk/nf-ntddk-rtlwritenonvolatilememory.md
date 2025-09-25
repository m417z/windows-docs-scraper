# RtlWriteNonVolatileMemory function

## Description

The routine **RtlWriteNonVolatileMemory** copies the contents of a source buffer to a non-volatile destination memory buffer.

## Parameters

### `NvToken`

 A pointer to an opaque structure that has
information about various properties of the non-volatile memory region which [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken) had returned.

### `NvDestination`

A pointer to the non-volatile destination buffer to copy to.

### `Source`

A pointer to the source buffer to copy from.

### `Size`

The length, in bytes, of the copy operation.

### `Flags`

Reserved for future use.

## Return value

The routine **RtlWriteNonVolatileMemory** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | **NvToken** is an invalid pointer or token. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

 This is a [RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory) equivalent for non-volatile memory
the value add is only with verifier enabled. When the verifier is enabled,
ranges that are modified can be tracked in **NvToken** and can be reported
in [RtlFreeNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlfreenonvolatiletoken) if a flush is not called for a write. This routine is currently not supported for Windows Server until the next major release of Windows Server.

## See also

[RtlCopyMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopymemory)

[RtlDrainNonVolatileFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldrainnonvolatileflush)

[RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory)

[RtlFlushNonVolatileMemoryRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememoryranges)

[RtlFreeNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlfreenonvolatiletoken)

[RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken)