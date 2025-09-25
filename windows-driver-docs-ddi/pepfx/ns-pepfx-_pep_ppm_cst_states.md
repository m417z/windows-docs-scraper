# _PEP_PPM_CST_STATES structure (pepfx.h)

## Description

The **PEP_PPM_CST_STATES** structure specifies the properties of the C states (ACPI processor power states) that are supported for a processor.

## Members

### `Count`

The number of elements in the **IdleStates** array.

### `IdleStates`

A pointer to an array of [PEP_PPM_CST_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_state) structures.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states) notification. The contents of this structure are obtained from the _CST object that is located in the ACPI namespace for the processor.

## See also

[PEP_NOTIFY_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states)

[PEP_PPM_CST_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_state)