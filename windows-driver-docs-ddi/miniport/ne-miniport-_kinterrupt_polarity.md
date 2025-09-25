# _KINTERRUPT_POLARITY enumeration (miniport.h)

## Description

The **KINTERRUPT_POLARITY** enumeration indicates how a device signals an interrupt request on an interrupt line.

## Constants

### `InterruptPolarityUnknown`

The interrupt polarity is unknown.

### `InterruptActiveHigh`

Active-high interrupt. The interrupt input type is level-triggered, and an interrupt request is indicated by a high signal level on the interrupt line. The request remains active as long as the line remains high.

### `InterruptRisingEdge`

Rising-edge-triggered interrupt. The interrupt input type is edge-triggered, and an interrupt request is indicated by a low-to-high transition on the interrupt line.

### `InterruptActiveLow`

Active-low interrupt. The interrupt input type is level-triggered, and an interrupt request is indicated by a low signal level on the interrupt line. The request remains active as long as the line remains low.

### `InterruptFallingEdge`

Falling-edge-triggered interrupt. The interrupt input type is edge-triggered, and an interrupt request is indicated by a high-to-low transition on the interrupt line.

### `InterruptActiveBoth`

Active-both interrupt. The interrupt input type is edge-triggered, and an interrupt request is indicated by a low-to-high or a high-to-low transition on the interrupt line. After a low-to-high transition signals an interrupt request, the interrupt line remains high until a high-to-low transition signals the next interrupt request. Similarly, after a high-to-low transition signals an interrupt request, the interrupt line remains low until a low-to-high transition signals the next interrupt request.

### `InterruptActiveBothTriggerLow`

Reserved for use by the operating system.

### `InterruptActiveBothTriggerHigh`

Reserved for use by the operating system.

## Remarks

A **KINTERRUPT_POLARITY** enumeration constant is frequently used in conjunction with a [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) enumeration constant to describe an interrupt signal. A **KINTERRUPT_MODE** enumeration constant indicates whether the interrupt signal from a device is level-triggered or edge-triggered.

## See also

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)