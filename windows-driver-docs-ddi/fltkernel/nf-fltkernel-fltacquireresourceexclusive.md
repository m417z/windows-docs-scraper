## Description

The **FltAcquireResourceExclusive** routine acquires the given resource for exclusive access by the calling thread.

## Parameters

### `Resource` [in/out]

A pointer to an opaque [**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eresource-structures) structure. This structure must be allocated by the caller from nonpaged pool and initialized by calling [**ExInitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite) or [**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite).

## Return value

None

## Remarks

**FltAcquireResourceExclusive** acquires the given resource for exclusive access by the calling thread.

The following circumstances determine whether or when the caller is given exclusive access to the given resource:

* If the resource is currently not owned, exclusive access is granted immediately to the current thread.

* If the caller already has acquired the resource for exclusive access, the current thread is granted the same type of access recursively.

* Callers who have shared access to the resource must release the lock and then reacquire it exclusively.

* If the resource is currently owned as exclusive by another thread, or if the caller only has shared access to the resource, the current thread is put into a wait state until the resource can be acquired.

If two threads each hold a shared lock on the same resource and both attempt to acquire the lock exclusively without releasing their shared lock, they will deadlock. This means that each thread will wait for the other to release its shared hold on the lock, and neither will release its shared hold until the other does.

**FltAcquireResourceExclusive** is a wrapper for [**ExAcquireResourceExclusiveLite**](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85)) that disables normal kernel APC delivery.

Because **FltAcquireResourceExclusive** disables normal kernel APC delivery, it is not necessary to call [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) before calling **FltAcquireResourceExclusive**.

To release the resource after it is acquired, call [**FltReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleaseresource). Every successful call to **FltAcquireResourceExclusive** must be matched by a subsequent call to **FltReleaseResource**.

To acquire a resource for shared access, call [**FltAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceshared).

To delete a resource from the system's resource list, call [**ExDeleteResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeleteresourcelite).

To initialize a resource for reuse, call [**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite).

For more information about ERESOURCE structures, see [Introduction to ERESOURCE Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines).