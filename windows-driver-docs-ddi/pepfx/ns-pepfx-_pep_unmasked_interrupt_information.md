# _PEP_UNMASKED_INTERRUPT_INFORMATION structure (pepfx.h)

## Description

The **PEP_UNMASKED_INTERRUPT_INFORMATION** structure contains information about an interrupt source.

## Members

### `Version`

The version of this structure.

### `Size`

The size, in bytes, of this structure.

### `Flags`

A [PEP_UNMASKED_INTERRUPT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_flags) union that indicates whether the interrupt is a primary or secondary interrupt. For more information, see [Primary and Secondary Interrupts](https://learn.microsoft.com/windows-hardware/drivers/gpio/primary-and-secondary-interrupts).

### `Mode`

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) enumeration value. This member indicates whether the interrupt is edge-triggered or level-triggered.

### `Polarity`

A [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity) enumeration value. This member indicates which edge or level of the interrupt signal triggers the interrupt.

### `Gsiv`

The global system interrupt vector (GSIV) number that identifies this interrupt. The ACPI firmware assigns GSIV numbers to all primary interrupt lines. For secondary (GPIO) interrupt lines, the GSIV number is dynamically assigned by the operating system.

### `PinNumber`

For secondary interrupt sources, this member identifies the number of the pin on the general-purpose I/O (GPIO) controller that is connected to the interrupt signal line from the interrupting device. For primary interrupt sources, this member is undefined.

If a GPIO controller has N GPIO pins, the pins are numbered 0 to N–1. One or more of these GPIO pins might be configured as interrupt inputs.

### `DeviceHandle`

For secondary interrupt sources, this member contains the PEP device handle for the GPIO controller that is the source for this interrupt. For primary interrupt sources, this field is undefined.

## Remarks

This structure is used by the [EnumerateInterruptSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-ppo_enumerate_interrupt_source_callback) callback routine.

## See also

[EnumerateInterruptSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-ppo_enumerate_interrupt_source_callback)

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity)

[PEP_UNMASKED_INTERRUPT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_flags)