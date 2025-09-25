# PFN_WDFINTERRUPTACQUIRELOCK function

## Description

**[Applies to KMDF and UMDF]**

The **WdfInterruptAcquireLock** method begins a code sequence that executes at the device's device interrupt request level (DIRQL) while holding an interrupt object's spin lock.

For passive level interrupt objects, the method begins a code sequence that executes at passive level while holding an interrupt object's passive lock.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Prototype

```cpp
VOID
(*PFN_WDFINTERRUPTACQUIRELOCK)(
    IN PWDF_DRIVER_GLOBALS DriverGlobals,
    WDFINTERRUPT Interrupt
    );
```

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

When a driver calls **WdfInterruptAcquireLock** on a DIRQL interrupt object, the system raises the processor's IRQL to the device's DIRQL and acquires the spin lock that the driver specified in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure. As a result, the interrupt object's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) and [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback functions (and any other code that calls **WdfInterruptAcquireLock** for the same interrupt object) cannot execute.

When the driver calls [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85)), the system returns the processor's IRQL to its previous level and releases the spin lock.

When a driver calls **WdfInterruptAcquireLock** on a passive-level interrupt object, the system acquires the passive-level interrupt lock that the driver configured in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

When the driver calls [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85)), the system releases the interrupt lock.

For passive level interrupts, the driver must call **WdfInterruptAcquireLock** at IRQL = PASSIVE_LEVEL.

Do not call **WdfInterruptAcquireLock** from an arbitrary thread context, such as a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

You can use **WdfInterruptAcquireLock** and [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85)) if your driver must execute a few lines of code without being preempted and with servicing of device interrupts effectively disabled. For larger sections of code, your driver should provide an [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function.

Your driver cannot call **WdfInterruptAcquireLock** before the framework has called the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function or after the framework has called the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function.

After your driver calls **WdfInterruptAcquireLock**, it must not call the method again for the same interrupt object before calling [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85)).

For more information about the **WdfInterruptAcquireLock** method, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

For passive-level interrupt objects, drivers must call [WdfInterruptTryToAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterrupttrytoacquirelock) instead of **WdfInterruptAcquireLock**, when running in an arbitrary thread, such as a [queue object callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/). For example, the driver might call **WdfInterruptTryToAcquireLock** from [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read).

Doing so avoids the possibility of deadlock, as described in the following scenario.

1. In order to determine if its device interrupted, the function driver for an SPB peripheral device sends I/O to its bus from within its ISR, with the passive-level interrupt lock held.
1. The bus driver completes a second request in the same thread in which it received the above request.
1. The completion routine of the second request sends a request to the peripheral driver.
1. The peripheral driver's I/O dispatch routine calls **WdfInterruptAcquireLock**, which then deadlocks attempting to acquire the interrupt object's passive lock.

## See also

- [WdfInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsynchronize)
- [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize)
- [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable)
- [WdfInterruptTryToAcquireLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterrupttrytoacquirelock)
- [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable)
- [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)
- [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)
- [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85))