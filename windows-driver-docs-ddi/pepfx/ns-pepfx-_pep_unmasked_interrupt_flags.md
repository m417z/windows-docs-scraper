# _PEP_UNMASKED_INTERRUPT_FLAGS structure (pepfx.h)

## Description

The **PEP_UNMASKED_INTERRUPT_FLAGS** union indicates whether an unmasked interrupt source is a primary interrupt or a secondary interrupt.

## Members

### `SecondaryInterrupt`

Whether this interrupt is a primary interrupt or a secondary interrupt. This bit field is 0 if the interrupt source is a primary interrupt, and is 1 is the interrupt source is a secondary interrupt. For more information, see [Primary and Secondary Interrupts](https://learn.microsoft.com/windows-hardware/drivers/gpio/primary-and-secondary-interrupts).

### `Reserved`

Reserved for future use. Set to zero.

### `AsUSHORT`

A USHORT value that contains all of the unmasked interrupt flags.

## Remarks

The *Flags* member of the [PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information) structure is a **PEP_UNMASKED_INTERRUPT_FLAGS** union.

The unnamed structure contains the bit fields for the individual unmasked interrupt flags.

## See also

- [PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information)