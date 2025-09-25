# IInterruptSync::CallSynchronizedRoutine

## Description

The `CallSynchronizedRoutine` method calls a routine that is not an interrupt service routine (ISR) but whose execution needs to be synchronized with ISRs.

## Parameters

### `Routine` [in]

Pointer to the routine that is to be called. This routine will run exclusive of the object's ISR and all other routines that are synchronized through the object. Even on multiple-processor machines, routines that are synchronized by a given object will not run concurrently. This parameter is a function pointer of type PINTERRUPTSYNCROUTINE (see [IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)).

### `DynamicContext` [in]

A context value to be passed to the routine.

## Return value

`CallSynchronizedRoutine` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

Execution of any registered ISR is guaranteed to be held off until the call to the routine that is passed to `CallSynchronizedRoutine` has completed.

Callers of `CallSynchronizedRoutine` must be running at an IRQL that is less than or equal to the level of the interrupt that is associated with the synchronization object. This interrupt was specified by the [PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync) function's *ResourceList* and *ResourceIndex* parameters.

## See also

[IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)

[PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync)