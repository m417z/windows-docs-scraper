# IInterruptSync::RegisterServiceRoutine

## Description

The `RegisterServiceRoutine` method registers an interrupt service routine (ISR) that is to be called when an interrupt occurs.

## Parameters

### `Routine` [in]

Pointer to the routine that is to be called. This parameter is a function pointer of type PINTERRUPTSYNCROUTINE (see [IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)).

### `DynamicContext` [in]

Specifies a context value that is passed to the routine when it is called.

### `First` [in]

Specifies whether the routine is added at the head or tail of the list of ISRs. If **TRUE**, the routine is added at the head of the list. If **FALSE**, it is added at the tail.

## Return value

`RegisterServiceRoutine` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method adds the specified routine to the synchronization object's list of ISRs. When an interrupt occurs, the routine at the head of the list is called first, and the routine at the tail is called last.