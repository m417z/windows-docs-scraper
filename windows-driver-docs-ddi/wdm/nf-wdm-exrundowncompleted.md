# ExRundownCompleted function

## Description

The **ExRundownCompleted** routine updates the run-down status of a shared object to indicate that the run down of the object has completed.

## Parameters

### `RunRef` [out]

A pointer to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

## Remarks

This routine is called by the driver that owns an object that resides in shared memory and that is accessed by other drivers. The **ExRundownCompleted** call must be preceded by a call to the [ExWaitForRundownProtectionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionrelease) routine that runs down the object.

After an **ExRundownCompleted** call, additional calls to **ExWaitForRundownProtectionRelease** to run down the associated object return immediately without waiting. However, calls to [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) to acquire run-down protection on the associated object fail (return **FALSE**).

After an **ExRundownCompleted** call, the driver can call the [ExReInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializerundownprotection) routine to associate the [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure with a new object and to initialize run-down protection on this object. After the **ExReInitializeRundownProtection** call, drivers can call **ExAcquireRundownProtection** to acquire run-down protection on the new object.

On entry, the status information in the **EX_RUNDOWN_REF** structure must indicate that the object that was associated with this structure was run down.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)