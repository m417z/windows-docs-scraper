# _PEP_PPM_PLATFORM_STATE_RESIDENCY structure (pepfx.h)

## Description

The **PEP_PPM_PLATFORM_STATE_RESIDENCY** structure specifies the accumulated residency time and transition count for a particular platform idle state.

## Members

### `Residency`

The accumulated residency time, in 100-nanosecond units. This is the total amount of time that the hardware platform has spent in this idle state since system startup.

### `TransitionCount`

The total number of times that the platform has entered this idle state since system startup.

## Remarks

The **States** member of the [PEP_PPM_PLATFORM_STATE_RESIDENCIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_platform_state_residencies) structure is a pointer to an array of **PEP_PPM_PLATFORM_STATE_RESIDENCY** structures.

## See also

[PEP_PPM_PLATFORM_STATE_RESIDENCIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_platform_state_residencies)