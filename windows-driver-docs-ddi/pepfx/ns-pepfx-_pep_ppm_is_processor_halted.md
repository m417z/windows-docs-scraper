# _PEP_PPM_IS_PROCESSOR_HALTED structure (pepfx.h)

## Description

The **PEP_PPM_IS_PROCESSOR_HALTED** structure indicates whether the processor is currently halted in its selected idle state.

## Members

### `Halted` [out]

Whether the processor is halted. Set to **TRUE** if the processor is halted, or to **FALSE** if it is not halted.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_IS_PROCESSOR_HALTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_is_processor_halted) notification. The **Halted** member contains an output value that the platform extension plug-in (PEP) writes to the structure in response to this notification.

## See also

[PEP_NOTIFY_PPM_IS_PROCESSOR_HALTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_is_processor_halted)