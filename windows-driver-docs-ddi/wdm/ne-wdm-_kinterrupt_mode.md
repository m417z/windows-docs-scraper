# _KINTERRUPT_MODE enumeration (wdm.h)

## Description

The **KINTERRUPT_MODE** enumeration type indicates whether an interrupt is level-triggered or edge-triggered.

## Constants

### `LevelSensitive`

The interrupt is level-triggered. This is the mode for traditional PCI line-based interrupts.

### `Latched`

The interrupt is edge-triggered. This is the mode for PCI message-signaled interrupts.

## Remarks

The interrupt mode is an electrical characteristic of the interrupt. A device signals a level-triggered interrupt by changing the voltage on the interrupt pin, and holding it there until the processor signals that the interrupt is received. In contrast, to signal an edge-triggered interrupt, the device changes the voltage state for a fixed period of time, before reverting to the original voltage state.

## See also

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)

[KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity)