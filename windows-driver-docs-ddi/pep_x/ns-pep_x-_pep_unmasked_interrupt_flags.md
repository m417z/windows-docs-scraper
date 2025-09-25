# _PEP_UNMASKED_INTERRUPT_FLAGS union (pep_x.h)

## Description

The **PEP_UNMASKED_INTERRUPT_FLAGS** union indicates whether an unmasked interrupt source is a primary interrupt or a secondary interrupt.

## Members

### `SecondaryInterrupt`

Whether this interrupt is a primary interrupt or a secondary interrupt. This bit field is 0 if the interrupt source is a primary interrupt, and is 1 is the interrupt source is a secondary interrupt. For more information, see [Primary and Secondary Interrupts](https://learn.microsoft.com/windows-hardware/drivers/gpio/primary-and-secondary-interrupts).

### `Reserved`

Reserved for future use.

### `AsUSHORT`

A USHORT value that contains all of the unmasked interrupt flags.

Whether this interrupt is a primary interrupt or a secondary interrupt. This bit field is 0 if the interrupt source is a primary interrupt, and is 1 is the interrupt source is a secondary interrupt. For more information, see [Primary and Secondary Interrupts](https://learn.microsoft.com/windows-hardware/drivers/gpio/primary-and-secondary-interrupts).

## Remarks

The unnamed struct contains the bit fields for the individual unmasked interrupt flags.

The *Flags* member of the [ns-pep_x-_pep_work_information.md](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information) structure is a **PEP_UNMASKED_INTERRUPT_FLAGS** union.

## See also

- [PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information)