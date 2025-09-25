# _PEP_PPM_QUERY_IDLE_STATES_V2 structure (pep_x.h)

## Description

The **PEP_PPM_QUERY_IDLE_STATES_V2** structure is used during processor initialization to query the platform extension plug-in (PEP) for a list of processor idle states that the processor supports.

## Members

### `Count` [in]

The number of elements in the **IdleStates** array. The Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) previously sent the PEP a [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities) notification to determine this number.

### `IdleStates` [out]

The first element in an array of [PEP_PROCESSOR_IDLE_STATE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_v2) structures that describe the processor idle states. If this array contains more than one element, the addition array elements follow the end of the **PEP_PPM_QUERY_IDLE_STATES_V2** structure.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification. The **Count** member of the **PEP_PPM_QUERY_IDLE_STATES_V2** structure contains an input value that is supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The **IdleStates** array elements contain output values that the PEP writes to the structure in response to this notification.

## See also

[PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities)

[PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)

[PEP_PROCESSOR_IDLE_STATE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_v2)