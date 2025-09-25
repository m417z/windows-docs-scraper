# _PEP_PPM_PLATFORM_STATE_RESIDENCIES structure (pepfx.h)

## Description

The **PEP_PPM_PLATFORM_STATE_RESIDENCIES** structure contains the accumulated residency times and transition counts for the idle states that are supported by the hardware platform.

## Members

### `Count` [in]

The number of elements in the array pointed to by the **States** member. The number of array elements equals the number of platform idle states that the PEP previously provided in response to a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification.

### `States` [in]

A pointer to an output buffer to which the PEP writes an array of [PEP_PPM_PLATFORM_STATE_RESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_platform_state_residency) structures. Each structure contains the accumulated residency and transition count information for a particular platform idle state. This buffer is guaranteed to be large enough to contain the number of array elements specified by the **Count** member. Each idle state is identified by its array index. If the array contains N elements, idle state indexes range from 0 to N-1.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE_RESIDENCIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_platform_state_residencies) notification. Both members of the structure contain input values that the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) supplies when this notification is sent to the PEP. PoFx allocates the output buffer pointed to by the **States** member, and the PEP writes to this buffer.

## See also

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE_RESIDENCIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_platform_state_residencies)

[PEP_PPM_PLATFORM_STATE_RESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_platform_state_residency)