# PsIsThreadTerminating function

## Description

The **PsIsThreadTerminating** routine checks whether a thread is terminating.

## Parameters

### `Thread` [in]

A pointer to the thread to be checked for termination.

## Return value

The **PsIsThreadTerminating** routine returns **TRUE** if the thread is terminating, otherwise **FALSE**.

## Remarks

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Driver Threads, Dispatcher Objects, and Resources](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-threads-dispatcher-objects-and-resources).

## See also

[PsGetProcessExitTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psgetprocessexittime)