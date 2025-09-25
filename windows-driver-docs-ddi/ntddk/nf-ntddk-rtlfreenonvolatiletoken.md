# RtlFreeNonVolatileToken function

## Description

The routine **RtlFreeNonVolatileToken** is a cleanup function for the opaque **NvToken** which is given by a successful
call to [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken).

## Parameters

### `NvToken` [in]

 A pointer to an opaque structure that has
information about various properties of the non-volatile memory region which [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken) had returned.

## Return value

The routine **RtlFreeNonVolatileToken** returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | **NvToken** is an invalid pointer or token. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

This routine is currently not supported for Windows Server until the next major release of Windows Server.

## See also

[RtlDrainNonVolatileFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldrainnonvolatileflush)

[RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory)

[RtlFlushNonVolatileMemoryRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememoryranges)

[RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken)

[RtlWriteNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlwritenonvolatilememory)