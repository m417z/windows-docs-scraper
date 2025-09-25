# KeReadStateTimer function

## Description

The **KeReadStateTimer** routine reads the current state of a timer object.

## Parameters

### `Timer` [in]

A pointer to an initialized timer object, for which the caller provides the storage.

## Return value

**KeReadStateTimer** returns **TRUE** if the current state of the timer object is signaled; otherwise, it returns **FALSE**.

## Remarks

This routine provides an efficient way to poll the signal state of a timer. **KeReadStateTimer** reads the state of the timer without synchronizing its access to the timer. Do not assume that accesses of a timer state by **KeReadStateTimer** are mutually exclusive of accesses by routines, such as [KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer) and [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject), that do synchronize their access to the timer state.

For more information about timer objects, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs).

## See also

[KTIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer)

[KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)