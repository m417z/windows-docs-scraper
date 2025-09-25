# RtlDrainNonVolatileFlush function

## Description

The routine **RtlDrainNonVolatileFlush** waits for the flushes initiated by [RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory)
to finish.

## Parameters

### `NvToken` [in]

 A pointer to an opaque structure that has
information about various properties of the non-volatile memory region which [RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken) had returned.

## Return value

The routine **RtlDrainNonVolatileFlush** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | **NvToken** is an invalid pointer or token. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

 This routine **RtlDrainNonVolatileFlush** can also add more context to **NvToken** to help verifiers. This routine is currently not supported for Windows Server until the next major release of Windows Server.

## See also

[RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory)

[RtlFlushNonVolatileMemoryRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememoryranges)

[RtlFreeNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlfreenonvolatiletoken)

[RtlGetNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetnonvolatiletoken)

[RtlWriteNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlwritenonvolatilememory)