# ExReleaseRundownProtectionEx function

## Description

The **ExReleaseRundownProtectionEx** routine releases run-down protection that the caller previously acquired by calling the [ExAcquireRundownProtectionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectionex) routine.

## Parameters

### `RunRef` [in, out]

A pointer to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

### `Count` [in]

The amount by which to decrement to the run-down instance count of the object. For more information, see Remarks.

## Remarks

The *RunRef* parameter points to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that tracks the run-down status of the associated object. This status information includes a count of the instances of run-down protection that are currently in effect on the object. The [ExAcquireRundownProtectionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectionex) and **ExReleaseRundownProtectionEx** routines increment and decrement this count by arbitrary amounts. Two related routines, [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) and [ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection), increment and decrement this count by one.

As long as the run-down block itself is nonpaged, this function can be called at DISPATCH_LEVEL.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection)

[ExAcquireRundownProtectionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotectionex)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)

[ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection)