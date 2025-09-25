# FltReleasePushLock macro

## Description

The **FltReleasePushLock** routine releases a specified push lock owned by the current thread.

## Parameters

### `PushLock` [in, out]

Opaque push lock pointer of type **PEX_PUSH_LOCK**. This pointer must have been initialized by a previous call to [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

## Return value

None.

## Remarks

**FltReleasePushLock** releases a push lock that was previously acquired by calling [**FltAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive) or [**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared).

Because **FltAcquirePushLockExclusive** disables normal kernel APC delivery, it is not necessary to call [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) before calling **FltAcquirePushLockExclusive**.

For more information about push locks, see the reference entry for [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

To acquire a push lock for exclusive access, call [**FltAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive).

To acquire a push lock for shared access, call [**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared).

To initialize a push lock, call [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

To delete a push lock, call [**FltDeletePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletepushlock).

## See also

[**FltAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive)

[**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared)

[**FltDeletePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletepushlock)

[**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock)

[**FltReleasePushLockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasepushlockex)

[**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem)

[**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)