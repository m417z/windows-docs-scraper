# WdfInterruptDisable function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptDisable** method disables a specified device interrupt by calling the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Most framework-based drivers don't need to call **WdfInterruptDisable**, because the framework calls the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function each time the device leaves its working (D0) state.

For [passive-level interrupt objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts), the framework calls **WdfInterruptDisable** at PASSIVE_LEVEL.

Do not call **WdfInterruptDisable** from an arbitrary thread context, such as a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example disables the device interrupt that is associated with a specified interrupt object.

```cpp
WdfInterruptDisable(Interrupt);
```

## See also

[EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable)

[WdfInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptenable)