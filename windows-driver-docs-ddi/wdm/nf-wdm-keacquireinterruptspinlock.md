## Description

The **KeAcquireInterruptSpinLock** routine acquires the spin lock associated with an interrupt object.

## Parameters

### `Interrupt`

[in, out] Specifies a pointer to an interrupt object. This value must be supplied by [**IoConnectInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) or [**IoConnectInterruptEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex).

## Return value

**KeAcquireInterruptSpinLock** returns the current IRQL at the time the routine is called. This value is passed to [**KeReleaseInterruptSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinterruptspinlock) when the spin lock is released.

## Remarks

Drivers use the interrupt spin lock to synchronize access to memory shared with the interrupt's ISR. The driver can release the spin lock by calling [**KeReleaseInterruptSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinterruptspinlock).

Any code that executes while the interrupt spin lock is held does so at IRQL = DIRQL for the specified *Interrupt*, so it must execute very quickly. For more information, see [Using Critical Sections](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-critical-sections).

The preferred way to synchronize a driver routine to an ISR is to use the [**KeSynchronizeExecution**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution) routine.

Starting with Windows 8, a driver can use [**IoConnectInterruptEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) to register an interrupt service routine that runs at IRQL = PASSIVE\_LEVEL and that does not use a spin lock for interrupt synchronization. If *Interrupt* points to an interrupt object that connects to a passive-level ISR, **KeAcquireInterruptSpinLock** causes a bug check. For more information, see [Using Passive-Level Interrupt Service Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-passive-level-interrupt-handling-routines).

Callers must be running at IRQL \<= DIRQL for *Interrupt*. (This is the value the driver passed as the *SynchronizeIrql* parameter of [**IoConnectInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) when *Interrupt* is created.)

## See also

[**IoConnectInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[**KeReleaseInterruptSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseinterruptspinlock)

[**KeSynchronizeExecution**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)