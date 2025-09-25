# _WDF_INTERRUPT_POLARITY enumeration (wdfinterrupt.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_POLARITY** enumeration type is used to specify an interrupt signal's polarity.

## Constants

### `WdfInterruptPolarityUnknown:0`

The interrupt signal's polarity is unknown.

### `WdfInterruptActiveHigh`

The interrupt signal is active when it is high.

### `WdfInterruptActiveLow`

The interrupt signal is active when it is low.

## Remarks

The **WDF_INTERRUPT_POLARITY** enumeration type is used to specify a member of the [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info) structure.

## See also

[WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_info)