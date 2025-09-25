# FsRtlPostPagingFileStackOverflow function

## Description

The **FsRtlPostPagingFileStackOverflow** routine posts a paging file stack overflow item to the stack overflow thread.

## Parameters

### `Context` [in]

A context pointer to pass to the stack overflow callback routine.

### `Event` [in]

A pointer to a caller-allocated notification event to pass to the stack overflow callback routine. Must have been initialized as nonsignaled by calling [KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent).

### `StackOverflowRoutine` [in]

A pointer to a callback routine to be invoked when processing the request in the overflow thread.

## Remarks

A file system typically calls **FsRtlPostPagingFileStackOverflow** during a paging file I/O operation when the amount of remaining stack space returned by [IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize) is below the file system's stack overflow read threshold. **FsRtlPostPagingFileStackOverflow** posts the paging I/O request to a special paging stack overflow work queue. When the paging I/O operation has been completed, the caller's *Event* is set to a signaled state.

**Note** Warning: File system filter drivers must never call **FsRtlPostPagingFileStackOverflow**, because doing so can halt the forward progress of paging file I/O operations.

## See also

[FsRtlIsPagingFile](https://learn.microsoft.com/previous-versions/ff546873(v=vs.85))

[FsRtlPostStackOverflow](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpoststackoverflow)

[IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)