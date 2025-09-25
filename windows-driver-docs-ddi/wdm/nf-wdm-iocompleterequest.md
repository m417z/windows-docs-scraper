# IoCompleteRequest macro

## Description

The **IoCompleteRequest** macro indicates that the caller has completed all processing for a given I/O request and is returning the given IRP to the I/O manager.

> **IoCompleteRequest** wraps **IofCompleteRequest**.

## Parameters

### `Irp`

Pointer to the IRP to be completed.

### `PriorityBoost`

Specifies a system-defined CCHAR constant by which to increment the run-time priority of the original thread that requested the operation. This value is IO_NO_INCREMENT if the original thread requested an operation the driver could complete quickly (so the requesting thread is not compensated for its assumed wait for I/O to be completed) or if the IRP is completed with an error. Otherwise, the set of *PriorityBoost* constants are device-type-specific. See Ntddk.h or Wdm.h for these constants.

## Remarks

When a driver has finished all processing for a given IRP, it calls **IoCompleteRequest**. The I/O manager checks the IRP to determine whether any higher-level drivers have set up an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for the IRP. If so, each *IoCompletion* routine is called, in turn, until every layered driver in the chain has completed the IRP.

When all drivers have completed a given IRP, the I/O manager returns status to the original requester of the operation. Note that a higher-level driver that sets up a driver-created IRP must supply an *IoCompletion* routine to release the IRP it created.

Never call **IoCompleteRequest** while holding a spin lock. Attempting to complete an IRP while holding a spin lock can cause deadlocks.

## See also

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)