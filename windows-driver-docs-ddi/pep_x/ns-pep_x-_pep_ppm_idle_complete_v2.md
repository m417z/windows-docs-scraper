# _PEP_PPM_IDLE_COMPLETE_V2 structure (pep_x.h)

## Description

The **PEP_PPM_IDLE_COMPLETE_V2** structure describe the idle states from which the processor and hardware platform are waking.

## Members

### `ProcessorState` [in]

An index that identifies the idle state from which the processor is waking. The platform extension plug-in (PEP) previously specified the supported processor idle states in response to a [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification. If the PEP specified N processor idle states, valid processor-idle-state indexes range from 0 to N-1. When the hypervisor is enabled and the platform wakes from an idle state, this member is set to **PEP_PROCESSOR_IDLE_STATE_UNKNOWN** (0xffffffff). For more information, see [PEP_NOTIFY_PPM_IDLE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_complete).

### `PlatformState` [in]

An index that identifies the idle state from which the platform is waking. The PEP previously specified the supported platform idle states in response to a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_states) notification. If the PEP specified M platform idle states, valid platform-idle-state indexes range from 0 to M-1. If the transition from the processor idle state does not involve a transition from a platform idle state, this member will contain the value **PEP_PLATFORM_IDLE_STATE_NONE** (0xffffffff).

### `CoordinatedStateCount`

### `CoordinatedStates`

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_IDLE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_complete) notification. The **ProcessorState** and **PlatformState** members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is sent to the PEP.