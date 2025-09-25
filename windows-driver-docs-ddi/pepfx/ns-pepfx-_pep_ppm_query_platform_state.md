# _PEP_PPM_QUERY_PLATFORM_STATE structure (pepfx.h)

## Description

The **PEP_PPM_QUERY_PLATFORM_STATE** structure contains information about a platform idle state.

## Members

### `StateIndex` [in]

The index of this platform idle state. If the hardware platform supports N platform idle states, the states are numbered 0 to N-1. The Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) previously sent a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification to the platform extension plug-in (PEP) to determine the number of supported platform idle states.

### `State` [out]

A [PEP_PLATFORM_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_platform_idle_state) structure that describes the platform idle state.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) notification. The **StateIndex** member of the **PEP_PPM_QUERY_PLATFORM_STATE** structure contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent to the PEP. The **State** member contains an output value that the PEP writes to the structure in response to the notification.

The buffer that PoFx allocates to hold the **PEP_PPM_QUERY_PLATFORM_STATE** structure is guaranteed to be large enough to contain this structure plus any elements of the **State.DependencyArray** array that follow this structure.

## See also

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states)

[PEP_PLATFORM_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_platform_idle_state)