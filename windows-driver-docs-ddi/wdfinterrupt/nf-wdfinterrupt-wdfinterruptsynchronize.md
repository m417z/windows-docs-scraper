# WdfInterruptSynchronize function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptSynchronize** method executes a specified callback function at the device's DIRQL while holding an interrupt object's spin lock.

For passive level interrupt objects, this method executes a specified callback function at passive level while holding an interrupt object's passive-level interrupt lock.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `Callback` [in]

A pointer to an [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function.

### `Context` [in]

An untyped pointer to driver-supplied information that the framework passes to the [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function.

## Return value

**WdfInterruptSynchronize** returns the Boolean status value that the [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function returns.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If you want your driver to execute code that must run without being preempted and with servicing of device interrupts effectively disabled, you should place that code in an [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function. To schedule execution of the callback function, your driver must call **WdfInterruptSynchronize**.

The **WdfInterruptSynchronize** method returns after the [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function has finished executing.

Instead of calling **WdfInterruptSynchronize**, your driver can call [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)) and [WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85)).

For more information about the **WdfInterruptSynchronize** method, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

For passive level interrupts, the driver must call **WdfInterruptSynchronize** at IRQL = PASSIVE_LEVEL.

Do not call **WdfInterruptSynchronize** from an arbitrary thread context, such as a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

#### Examples

The following code example shows how to call **WdfInterruptSynchronize** to schedule execution of an [EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize) callback function.

```cpp
BOOLEAN synchronizeReturnValue;

synchronizeReturnValue = WdfInterruptSynchronize(
                                         WdfInterrupt,
                                         MyEvtInterruptSynchronize,
                                         CallbackContext
                                         );
```

## See also

[EvtInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_synchronize)

[WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85))

[WdfInterruptReleaseLock](https://learn.microsoft.com/previous-versions/ff547376(v=vs.85))