# FltReleasePushLockEx function

## Description

The **FltReleasePushLockEx** routine releases a specified push lock owned by the current thread.

## Parameters

### `PushLock`

Opaque push lock pointer of type **PEX_PUSH_LOCK**. This pointer must have been initialized by a previous call to [**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

### `Flags`

A bitmask of flags that control the attributes of the lock.

## Return value

None.

## Remarks

**FltReleasePushLockEx** releases a push lock that was previously acquired by calling [**FltAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive) or [**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared).

Because **FltReleasePushLockEx** reenables normal kernel APC delivery, it is not necessary to call [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) after calling **FltReleasePushLockEx**.

## See also

[**FltAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive)

[**FltAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared)

[**FltDeletePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletepushlock)

[**FltInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock)

[**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem)

[**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)