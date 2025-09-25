## Description

The **ClfsTerminateReadLog** routine invalidates a specified read context after freeing resources associated with the context.

## Parameters

### `pvCursorContext` [in]

A pointer to the read context to be invalidated. The caller previously obtained this pointer by calling [ClfsReadLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadlogrecord) or [ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea).

## Return value

**ClfsTerminateReadLog** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

> [!WARNING]
> Failure to call this routine can lead to memory leaks, premature exhaustion of log I/O blocks, and increased frequency of log flushes. Attempting to use *pvCursorContext* after it is freed is equivalent to accessing freed memory and can lead to unexpected behavior.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsReadLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadlogrecord)

[ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea)