# _WDF_INTERRUPT_PRIORITY enumeration (wdfinterrupt.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_PRIORITY** enumeration type identifies relative priorities for device interrupts.

## Constants

### `WdfIrqPriorityUndefined:0`

The relative priority of a device's interrupt is undefined.

### `WdfIrqPriorityLow`

The device's interrupt has a relatively low priority, typically because the interrupt does not have to be serviced immediately.

### `WdfIrqPriorityNormal`

The device's interrupt priority is neither relatively low nor relatively high.

### `WdfIrqPriorityHigh`

The device's interrupt has a relatively high priority, typically because the interrupt must be serviced immediately.

## Remarks

The **WDF_INTERRUPT_PRIORITY** enumeration type is used as input to the [WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy) method.

## See also

[WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy)