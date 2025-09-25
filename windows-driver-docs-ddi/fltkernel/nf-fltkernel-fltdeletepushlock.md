# FltDeletePushLock function

## Description

The **FltDeletePushLock** routine deletes a given push lock.

## Parameters

### `PushLock` [in]

Opaque push lock pointer. This pointer must have been initialized by a previous call to [FltInitializePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

## Return value

None

## Remarks

This routine is available on Microsoft Windows XP SP2, Microsoft Windows Server 2003 SP1, and later.

After calling **FltDeletePushLock**, the caller can free the memory that it allocated for the push lock.

For more information about push locks, see the reference entry for [FltInitializePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

To acquire a push lock for exclusive access, call [FltAcquirePushLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive).

To acquire a push lock for shared access, call [FltAcquirePushLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared).

To release a push lock, call [FltReleasePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasepushlock).

To initialize a push lock, call [FltInitializePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock).

## See also

[FltAcquirePushLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockexclusive)

[FltAcquirePushLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquirepushlockshared)

[FltInitializePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializepushlock)

[FltReleasePushLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasepushlock)