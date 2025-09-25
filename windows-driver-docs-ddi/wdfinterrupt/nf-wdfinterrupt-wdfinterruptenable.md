# WdfInterruptEnable function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptEnable** method enables a specified device interrupt by calling the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Most framework-based drivers don't need to call **WdfInterruptEnable**, because the framework calls the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function each time the device enters its working (D0) state.

For [passive-level interrupt objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts), the framework calls **WdfInterruptEnable** at PASSIVE_LEVEL.

Do not call **WdfInterruptEnable** from an arbitrary thread context, such as a [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example enables the device interrupt that is associated with a specified interrupt object.

```cpp
WdfInterruptEnable(Interrupt);
```

## See also

[EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable)

[WdfInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptdisable)