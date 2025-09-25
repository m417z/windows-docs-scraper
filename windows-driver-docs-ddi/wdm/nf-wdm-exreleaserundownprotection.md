# ExReleaseRundownProtection function

## Description

The **ExReleaseRundownProtection** routine releases run-down protection that the caller previously acquired by calling the [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) routine.

## Parameters

### `RunRef` [in, out]

A pointer to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

## Remarks

A driver that calls [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) to acquire run-time protection for an object access is responsible for calling **ExReleaseRundownProtection** to release the run-time protection when the access is finished.

As long as the run-down block itself is nonpaged, this function can be called at DISPATCH_LEVEL.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)