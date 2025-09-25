# FltAcquirePushLockExclusive macro

## Description

The **FltAcquirePushLockExclusive** macro acquires the given push lock for exclusive access by the calling thread.

## Parameters

### `PushLock` [in, out]

Opaque push lock pointer of type **PEX_PUSH_LOCK**. This pointer must have been initialized by a previous call to [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

## Return value

None.

## Remarks

**FltAcquirePushLockExclusive** acquires the given push lock for exclusive access by the calling thread.

Push locks are similar to ERESOURCE structures (also called resources) in that they can be acquired for shared or exclusive access. For more information about push locks, see the reference entry for [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

Unlike ERESOURCE structures, push locks cannot be acquired recursively. If the caller already has acquired the push lock for exclusive or shared access, the thread will hang.

When the caller will be given exclusive access to the given push lock depends on the following:

* If the push lock is currently unowned, exclusive access is granted immediately to the current thread.

* If the push lock has already been acquired for exclusive or shared access by another thread, the current thread is put into a wait state until the push lock can be acquired.

Because **FltAcquirePushLockExclusive** disables normal kernel APC delivery, it is not necessary to call [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) before calling **FltAcquirePushLockExclusive**.

To release the push lock after it is acquired, call [**FltReleasePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasepushlock). Every call to **FltAcquirePushLockExclusive** must be matched by a subsequent call to **FltReleasePushLock**.

To acquire a push lock for shared access, call [**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared).

To initialize a push lock, call [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

To delete a push lock, call [**FltDeletePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletepushlock).

## See also

[**FltAcquirePushLockExclusiveEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusiveex)

[**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared)

[**FltDeletePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletepushlock)

[**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock)

[**FltReleasePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasepushlock)

[**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem)

[**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)