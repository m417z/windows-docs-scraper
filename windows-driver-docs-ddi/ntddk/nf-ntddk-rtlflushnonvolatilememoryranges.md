# RtlFlushNonVolatileMemoryRanges function

## Description

The routine **RtlFlushNonVolatileMemoryRanges** optimally flushes the given non-volatile memory regions.

## Parameters

### `NvToken`

 A pointer to an opaque structure that has
information about various properties of the non-volatile memory region which [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken) had returned.

### `NvRanges`

Specifies an array of **NV_MEMORY_RANGE** structures which describe the non-volatile memory regions to flush

### `NumRanges`

Specifies the number of elements in the **NVRanges** array.

### `Flags`

For flags specified, refer [RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory) as this routine also honors the flags apart from passing it to **RtlFlushNonVolatileMemory**.

## Return value

The routine **RtlFlushNonVolatileMemoryRanges** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | **NvToken** is an invalid pointer or token. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

This routine is currently not supported for Windows Server until the next major release of Windows Server.

## See also

[RtlDrainNonVolatileFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldrainnonvolatileflush)

[RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory)

[RtlFreeNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlfreenonvolatiletoken)

[RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken)

[RtlWriteNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlwritenonvolatilememory)