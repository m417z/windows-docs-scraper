# WDF_INTERRUPT_INFO_INIT function (wdfinterrupt.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_INFO_INIT** function initializes a [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure.

## Parameters

### `Info` [out]

A pointer to a driver-allocated [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure.

## Remarks

The **WDF_INTERRUPT_INFO_INIT** function zeros the specified [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure and sets the structure's **Size** member.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

For a code example that uses **WDF_INTERRUPT_INFO_INIT**, see [WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo).

## See also

[WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info)

[WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo)