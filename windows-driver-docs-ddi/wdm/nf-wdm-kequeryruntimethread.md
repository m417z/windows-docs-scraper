# KeQueryRuntimeThread function

## Description

The **KeQueryRuntimeThread** routine reports the accumulated kernel-mode and user-mode run time of a thread, in clock ticks.

## Parameters

### `Thread` [in]

Pointer to a dispatcher object of type KTHREAD.

### `UserTime` [out]

Pointer to the memory location where **KeQueryRuntimeThread** returns the accumulated user-mode run time of the current thread, in clock ticks.

## Return value

**KeQueryRuntimeThread** returns the accumulated kernel-mode run time of the current thread, in clock ticks.

## See also

[KeQueryTimeIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerytimeincrement)