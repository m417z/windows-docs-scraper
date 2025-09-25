# ExInitializeRundownProtection function

## Description

The **ExInitializeRundownProtection** routine initializes run-down protection on a shared object.

## Parameters

### `RunRef` [out]

A pointer to a caller-allocated [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that is to be initialized. The allocation must be 4-byte aligned on 32-bit platforms, and 8-byte aligned on 64-bit platforms. For more information, see Remarks.

## Remarks

This routine is called by the driver that owns an object that resides in shared memory and is that accessed by other drivers.

**ExInitializeRundownProtection** must be called to initialize an **EX_RUNDOWN_REF** structure before it is passed as a parameter to any other run-down protection routine.

The run-down protection routines use the **EX_RUNDOWN_REF** structure to track the run-down status of a shared object that is associated with the structure. This status information includes a count of instances of run-down protection that are currently in effect on the object. **ExInitializeRundownProtection** initializes this count to zero.

After an **EX_RUNDOWN_REF** structure is initialized, other drivers that access the associated object can call the [ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection) and [ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection) routines to acquire and release run-down protection on the object.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExAcquireRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirerundownprotection)

[ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection)