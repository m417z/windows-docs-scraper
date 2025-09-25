# RtlGetNonVolatileToken function

## Description

The routine, **RtlGetNonVolatileToken**, gets various properties about a non-volatile memory
buffer and stores them in the variable **NvToken**.

## Parameters

### `NvBuffer`

A pointer to the non-volatile memory that the returned **NvToken** is going to track state for. This should be an address obtained from a file mapping object.

### `Size`

The length, in bytes, of the non-volatile memory buffer **NvBuffer** points to.

### `NvToken`

 A pointer to an opaque structure that tracks
information about the given non-volatile memory region which **RtlGetNonVolatileToken** had returned.

## Return value

The routine **RtlGetNonVolatileToken** returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller had insufficient access rights to perform the requested action. |
| **STATUS_INFO_LENGTH_MISMATCH** | The specified base address is outside the range of accessible addresses. |
| **STATUS_INVALID_PARAMETER** | The **NvBuffer** is not the same length as specified in**Size**. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

This routine is currently not supported for Windows Server until the next major release of Windows Server.

## See also

[RtlDrainNonVolatileFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldrainnonvolatileflush)

[RtlFlushNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememory)

[RtlFlushNonVolatileMemoryRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlflushnonvolatilememoryranges)

[RtlFreeNonVolatileToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlfreenonvolatiletoken)

[RtlWriteNonVolatileMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlwritenonvolatilememory)