# ExAcquireRundownProtectionEx function

## Description

The **ExAcquireRundownProtectionEx** routine tries to acquire run-down protection on a shared object so the caller can safely access the object.

## Parameters

### `RunRef` [in, out]

A pointer to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

### `Count` [in]

The amount by which to increment to the run-down instance count of the object. The count is incremented only if the routine returns **TRUE**. For more information, see Remarks

## Return value

**ExAcquireRundownProtectionEx** returns **TRUE** if the routine successfully acquires run-down protection for the caller. Otherwise, it returns **FALSE**. A return value of **FALSE** indicates that the run down of the object has started and that the object must be treated as invalid.

## Remarks

To safely access a shared object, a driver calls **ExAcquireRundownProtectionEx** to acquire run-down protection on the object.

The *RunRef* parameter points to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that tracks the run-down status of the associated object. This status information includes a count of instances of run-down protection that are currently in effect on the object. The **ExAcquireRundownProtectionEx** and [ExReleaseRundownProtectionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectionex) routines increment and decrement this count by arbitrary amounts. Two related routines, [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) and [ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection), increment and decrement this count by one.

As long as the run-down block itself is nonpaged, this function can be called at DISPATCH_LEVEL.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)

[ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection)

[ExReleaseRundownProtectionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotectionex)