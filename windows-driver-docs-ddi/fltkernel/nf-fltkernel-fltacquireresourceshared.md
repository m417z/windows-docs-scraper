## Description

The **FltAcquireResourceShared** routine acquires the given resource for shared access by the calling thread.

## Parameters

### `Resource` [in/out]

Pointer to an opaque [**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eresource-structures) structure. This structure must be allocated by the caller from nonpaged pool and initialized by calling [**ExInitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite) or [**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite).

## Return value

None.

## Remarks

FltAcquireResourceShared routine acquires the given resource for shared access by the calling thread.

Whether or when the caller is given shared access to the given resource depends on the following:

* If the resource is currently unowned, shared access is granted immediately to the current thread.

* If the caller already has acquired the resource (for shared or exclusive access), the current thread is granted the same type of access recursively. Note that making this call does not convert a caller's exclusive ownership of a given resource to shared.

* If the resource is currently owned as shared by another thread and no thread is waiting for exclusive access to the resource, shared access is granted to the caller immediately. The caller is put into a wait state if there is an exclusive waiter.

* If the resource is currently owned as exclusive by another thread or if there is another thread waiting for exclusive access and the caller does not already have shared access to the resource, the current thread is put into a wait state until the resource can be acquired.

**FltAcquireResourceShared** is a wrapper for [**ExAcquireResourceSharedLite**](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85)) that disables normal kernel APC delivery.

Because **FltAcquireResourceShared** disables normal kernel APC delivery, it is not necessary to call [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) before calling **FltAcquireResourceShared**.

To release the resource after it is acquired, call [**FltReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleaseresource). Every successful call to **FltAcquireResourceShared** must be matched by a subsequent call to **FltReleaseResource**.

To acquire a resource for exclusive access, call [**FltAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceexclusive).

To delete a resource from the system's resource list, call [**ExDeleteResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeleteresourcelite).

To initialize a resource for reuse, call [**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite).

For more information about ERESOURCE structures, see [Introduction to ERESOURCE Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines).