# IoThreadToProcess function

## Description

The **IoThreadToProcess** routine returns a pointer to the process for the specified thread.

## Parameters

### `Thread` [in]

Thread whose process is to be returned.

## Return value

**IoThreadToProcess** returns a pointer to the thread's process.

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Driver Threads, Dispatcher Objects, and Resources](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-threads-dispatcher-objects-and-resources).

## See also

[IoGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)