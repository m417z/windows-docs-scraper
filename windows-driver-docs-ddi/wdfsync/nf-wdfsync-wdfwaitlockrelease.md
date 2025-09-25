# WdfWaitLockRelease function

## Description

[Applies to KMDF and UMDF]

The **WdfWaitLockRelease** method releases a specified wait lock.

## Parameters

### `Lock` [in]

A handle to a framework wait-lock object, obtained by a previous call to [WdfWaitLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfwaitlockcreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfWaitLockRelease** method releases a wait lock that the driver acquired by a previous call to [WdfWaitLockAcquire](https://learn.microsoft.com/previous-versions/ff551168(v=vs.85)).

For more information about wait locks, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

#### Examples

For a code example that uses **WdfWaitLockRelease**, see [WdfWaitLockAcquire](https://learn.microsoft.com/previous-versions/ff551168(v=vs.85)).

## See also

[WdfWaitLockAcquire](https://learn.microsoft.com/previous-versions/ff551168(v=vs.85))

[WdfWaitLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfwaitlockcreate)