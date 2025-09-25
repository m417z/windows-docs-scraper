# WdfWaitLockAcquire function

## Description

[Applies to KMDF and UMDF]

The **WdfWaitLockAcquire** method acquires a specified wait lock.

## Parameters

### `Lock` [in]

A handle to a framework wait-lock object, obtained by a previous call to [WdfWaitLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfwaitlockcreate).

### `Timeout` [in, optional]

An optional pointer to a time-out value. The time-out value is specified in system time units (100-nanosecond intervals).

 If the pointer is non-**NULL**, the framework cancels the attempt to obtain the lock if it is not completed within the specified time-out period. Time-out values can be negative, positive, or zero, as follows:

* If the time-out value is negative, the expiration time is relative to the current system time.
* If the time-out value is positive, the expiration time is specified as an absolute time (which is actually relative to January 1, 1601).
* If the time-out value is zero, **WdfWaitLockAcquire** attempts to acquire the lock and then returns immediately, whether it has acquired the lock or not.

Relative expiration times are not affected by any changes to the system time that might occur within the specified time-out period. Absolute expiration times do reflect system time changes.

The framework provides [time conversion functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/) that convert time values into system time units.

If the caller supplies a **NULL** pointer, the method waits indefinitely until it has acquired the lock.

## Return value

**WdfWaitLockAcquire** can return the following [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values):

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The caller has acquired the wait lock. |
| **STATUS_TIMEOUT** | The specified *Timeout* interval expired before the lock was acquired. |

Note that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(status) equals **TRUE** for all of these status values.

The caller does not have to check the return value if the *Timeout* pointer is **NULL**, because in that case **WdfWaitLockAcquire** returns only after it acquires the lock.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfWaitLockAcquire** method does not return until it acquires the wait lock or until the time-out period expires.

**WdfWaitLockAcquire** calls [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) before acquiring the wait lock. As a result, when the method returns, [normal kernel APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs) are disabled. **WdfWaitLockAcquire** does not alter the caller's IRQL.

If the *Timeout* pointer is **NULL**, or if the time-out value is not zero, **WdfWaitLockAcquire** must be called at IRQL = PASSIVE_LEVEL.

If the time-out value is zero, **WdfWaitLockAcquire** must be called at IRQL < DISPATCH_LEVEL. Note that this is in disagreement with the header file (wdfsync.h), which indicates that this method can be called at DISPATCH_LEVEL.

For more information about wait locks, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

#### Examples

The following code example acquires a wait lock, adds a device object to an object collection, and releases the wait lock.

```cpp
WdfWaitLockAcquire(
                   FilterDeviceCollectionLock,
                   NULL
                   );
status = WdfCollectionAdd(
                          FilterDeviceCollection,
                          deviceHandle
                          );
if (!NT_SUCCESS(status)) {
    addFailed = TRUE;
}
WdfWaitLockRelease(FilterDeviceCollectionLock);
```

## See also

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)

[WdfWaitLockCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfsync/nf-wdfsync-wdfwaitlockcreate)

[WdfWaitLockRelease](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfwaitlockrelease)