# FsRtlPostStackOverflow function

## Description

The **FsRtlPostStackOverflow** routine posts a stack overflow item to the stack overflow thread.

## Parameters

### `Context` [in]

A context pointer to be passed to the stack overflow callback routine.

### `Event` [in]

A pointer to a caller-allocated notification event to pass to the stack overflow callback routine. Must have been initialized as nonsignaled by calling [KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent).

### `StackOverflowRoutine` [in]

A pointer to a callback routine to be invoked when processing the request in the overflow thread.

## Remarks

A file system typically calls **FsRtlPostStackOverflow** during a file I/O operation when the amount of remaining stack space returned by [IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize) is below the file system's stack overflow threshold for the operation. **FsRtlPostStackOverflow** posts the I/O request to a special stack overflow work queue. When the I/O operation has been completed, the caller's *Event* is set to a signaled state.

File system filter drivers should use [IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem) instead of **FsRtlPostStackOverflow**, because **IoQueueWorkItem** ensures that the device object that is associated with the specified work item is available for the processing of the work item.

If a pool allocation failure occurs, **FsRtlPostStackOverflow** raises a STATUS_INSUFFICIENT_RESOURCES exception. To gain control if this pool allocation failure occurs, the driver should wrap the call to **FsRtlPostStackOverflow** in a **try-except** or **try-finally** statement.

## See also

[FsRtlPostPagingFileStackOverflow](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlpostpagingfilestackoverflow)

[IoGetRemainingStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetremainingstacksize)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)