# _PEP_PROCESSOR_IDLE_STATE_UPDATE structure (pepfx.h)

## Description

The **PEP_PROCESSOR_IDLE_STATE_UPDATE** structure contains the updated properties of a processor idle state.

## Members

### `Version`

The version number of this structure. Set this member to PEP_PROCESSOR_IDLE_STATE_UPDATE_VERSION.

### `Latency`

The worst-case latency, in 100-nanosecond units, that the platform requires to wake from this platform idle state in response to a wake event.

### `BreakEvenDuration`

The minimum amount of time, specified in 100-nanosecond units, that the platform must spend in this idle state to make a transition to this state worthwhile. PoFx uses this member value as a hint to avoid switching the platform to an idle state unless the platform is likely to remain in this state for at least the amount of time specified by **BreakEvenDuration**.

## Remarks

The *Update* parameter to the [UpdateProcessorIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateprocessoridlestate) routine is a pointer to a **PEP_PROCESSOR_IDLE_STATE_UPDATE** structure. This routine updates the properties of the specified idle state for a processor. The PEP must not call this routine until it has responded to a [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification for this processor.

## See also

[PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)

[UpdateProcessorIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateprocessoridlestate)