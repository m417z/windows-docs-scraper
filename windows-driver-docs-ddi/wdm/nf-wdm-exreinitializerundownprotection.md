# ExReInitializeRundownProtection function

## Description

The **ExReInitializeRundownProtection** routine reinitializes an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure after the associated object is run down.

## Parameters

### `RunRef` [in, out]

A pointer to an **EX_RUNDOWN_REF** structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

## Remarks

This routine is called by the driver that owns an object that resides in shared memory and that is accessed by other drivers.

**ExReInitializeRundownProtection** enables a previously used [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure to be associated with a new object, and initializes run-down protection on this object. After the **ExReInitializeRundownProtection** call, drivers can call [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) to acquire run-down protection on the new object.

An **ExReInitializeRundownProtection** call must be preceded by a call to the [ExWaitForRundownProtectionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionrelease) routine that runs down the old object. Between the **ExWaitForRundownProtectionRelease** and **ExReInitializeRundownProtection** calls, the driver might call the [ExRundownCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompleted) routine to indicate that the run down of the old object has completed.

On entry, the status information in the **EX_RUNDOWN_REF** structure must indicate that the old object was run down.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)

[ExRundownCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exrundowncompleted)

[ExWaitForRundownProtectionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exwaitforrundownprotectionrelease)