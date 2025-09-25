# KeSynchronizeExecution function

## Description

The **KeSynchronizeExecution** routine synchronizes the execution of the specified routine with the interrupt service routine (ISR) that is assigned to a set of one or more interrupt objects.

## Parameters

### `Interrupt` [in, out]

A pointer to a set of interrupt objects. The caller obtained this pointer from the [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) or [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) routine.

### `SynchronizeRoutine` [in]

Specifies a caller-supplied [SynchCritSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ksynchronize_routine) routine whose execution is to be synchronized with the execution of the ISR assigned to the interrupt objects.

### `SynchronizeContext` [in, optional]

A pointer to a caller-supplied context value to be passed to the [SynchCritSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ksynchronize_routine) routine when it is called.

## Return value

**KeSynchronizeExecution** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**.

## Remarks

When this routine is called, the following occurs:

1. The IRQL is raised to the *SynchronizeIrql* value specified in the call to [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) or [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex).
2. Access to *SynchronizeContext* is synchronized with the assigned ISR by acquiring the associated interrupt object spin lock (or system event object, in the case of an ISR that runs at PASSIVE_LEVEL).
3. The specified [SynchCritSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ksynchronize_routine) routine is called with the *SynchronizeContext* value as its parameter.

If the ISR runs at DIRQL >= DISPATCH_LEVEL, the *SynchCritSection* routine runs at the same DIRQL and must therefore run for as brief a time as possible to avoid delaying other high-priority tasks.

Callers of **KeSynchronizeExecution** must be running at IRQL <= DIRQL; that is, at an IRQL that is less than or equal to the value of the **SynchronizeIrql** value that the caller specified when it registered its ISR with **IoConnectInterrupt** or **IoConnectInterruptEx**.

Starting with Windows 8, a driver can call **KeSynchronizeExecution** to synchronize execution of a *SynchCritSection* routine with an ISR that runs at IRQL = PASSIVE_LEVEL. In earlier versions of Windows, **KeSynchronizeExecution** can synchronize execution only with an ISR that runs at IRQL >= DISPATCH_LEVEL. For more information, see [Using Passive-Level Interrupt Service Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-passive-level-interrupt-handling-routines).

## See also

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)