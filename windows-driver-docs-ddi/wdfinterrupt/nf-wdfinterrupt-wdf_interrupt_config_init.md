# WDF_INTERRUPT_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_CONFIG_INIT** function initializes a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

## Parameters

### `Configuration` [out]

A pointer to a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

### `EvtInterruptIsr` [in]

A pointer to the driver's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

### `EvtInterruptDpc` [in, optional]

A pointer to the driver's [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function, or **NULL**.

## Remarks

The **WDF_INTERRUPT_CONFIG_INIT** function zeros the specified [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure and sets its **Size** member to the structure's size. It also sets the structure's **ShareVector** member to **WdfUseDefault** and stores the specified callback function pointers. Finally, it sets the **ReportInactiveOnPowerDown** member of the specified **WDF_INTERRUPT_CONFIG** structure to **WdfDefault**.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

For a code example that uses **WDF_INTERRUPT_CONFIG_INIT**, see [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)