# ExWaitForRundownProtectionRelease function

## Description

The **ExWaitForRundownProtectionRelease** routine waits until all drivers that have already been granted run-down protection complete their accesses of the shared object.

## Parameters

### `RunRef` [in, out]

A pointer to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

## Remarks

This routine is called by the driver that owns an object that resides in shared memory and that is accessed by other drivers. Before deleting this object, the owning driver must call this routine to wait for any outstanding accesses of the object to complete. After **ExWaitForRundownProtectionRelease** returns, the owning driver can safely delete the object.

After **ExWaitForRundownProtectionRelease** is called, the [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) routine grants no further requests for run-down protection from drivers that are trying to access the shared object. The routine waits to return until all drivers that were previously granted run-down protection finish accessing the object. As each driver finishes, it calls the [ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection) routine to release the previously acquired run-down protection. When all outstanding accesses are completed, **ExWaitForRundownProtectionRelease** returns and the object can be safely deleted.

If **ExWaitForRundownProtectionRelease** is called when all drivers that were previously granted run-down protection have already finished accessing the shared object, the routine changes the object status to *run down*, and returns immediately, without waiting.

If **ExWaitForRundownProtectionRelease** is called to run down a shared object, but the *RunRef* parameter indicates that this object is already run down, the call has no effect but is not treated as an error.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)

[ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection)