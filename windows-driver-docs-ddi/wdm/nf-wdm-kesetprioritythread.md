# KeSetPriorityThread function

## Description

The **KeSetPriorityThread** routine sets the run-time priority of a driver-created thread.

## Parameters

### `Thread` [in, out]

Pointer to the driver-created thread.

### `Priority` [in]

Specifies the priority of the driver-created thread, usually to the real-time priority value, LOW_REALTIME_PRIORITY. The value LOW_PRIORITY is reserved for system use.

## Return value

**KeSetPriorityThread** returns the old priority of the thread.

## Remarks

If a call to **KeSetPriorityThread** resets the thread's priority to a lower value, execution of the thread can be rescheduled even if it is currently running or is about to be dispatched for execution.

## See also

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[KeQueryPriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryprioritythread)

[KeSetBasePriorityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetbaseprioritythread)