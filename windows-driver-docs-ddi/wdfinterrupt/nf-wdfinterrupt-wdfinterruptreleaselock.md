# PFN_WDFINTERRUPTRELEASELOCK function

## Description

**[Applies to KMDF and UMDF]**

The **WdfInterruptReleaseLock** method ends a code sequence that executes at the device's DIRQL while holding an interrupt object's spin lock.

For passive level interrupt objects, the method ends a code sequence that executes at passive level while holding an interrupt object's passive lock.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Prototype

```cpp
VOID
(*PFN_WDFINTERRUPTRELEASELOCK)(
    IN PWDF_DRIVER_GLOBALS DriverGlobals,
    WDFINTERRUPT Interrupt
    );
```

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfInterruptReleaseLock** method releases the specified interrupt object's spin lock or wait lock and returns the processor's IRQL to the level that it was set to before the driver called [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)).

Your driver cannot call **WdfInterruptReleaseLock** before the framework has called the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function or after the framework has called the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function.

For more information about the **WdfInterruptReleaseLock** method, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

This method must be called at the DIRQL that was set by [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)).

For passive level interrupts, the driver must call **WdfInterruptReleaseLock** at IRQL = PASSIVE_LEVEL.

## See also

- [WdfInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsynchronize)
- [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85))
- [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable)
- [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable)