# IoIsSystemThread function

## Description

The **IoIsSystemThread** routine checks whether a given thread is a system thread.

## Parameters

### `Thread` [in]

Pointer to the thread to be checked.

## Return value

**IoIsSystemThread** returns **TRUE** if the specified thread is a system thread, otherwise **FALSE**.

## Remarks

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Driver Threads, Dispatcher Objects, and Resources](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-threads-dispatcher-objects-and-resources).

## See also

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[PsIsSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psissystemthread)