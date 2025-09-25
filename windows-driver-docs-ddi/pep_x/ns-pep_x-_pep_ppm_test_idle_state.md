# _PEP_PPM_TEST_IDLE_STATE structure (pep_x.h)

## Description

The **PEP_PPM_TEST_IDLE_STATE** structure contains information about whether the processor can immediately enter a processor idle state.

## Members

### `ProcessorState`

(input) The index of the processor idle state that is to be entered. The platform extension plug-in (PEP) previously specified the supported processor idle states in response to a [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification. If the PEP specified N processor idle states, valid processor-idle-state indexes range from 0 to N-1.

### `PlatformState` [in]

The index of the platform idle state that the hardware platform will enter when the processor enters the processor idle state specified by **ProcessorState**. The PEP previously specified the supported platform idle states in response to a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) notification. If the PEP specified M platform idle states, valid platform-idle-state indexes range from 0 to M-1. If no change in platform idle state will occur, this member will contain the value **PEP_PLATFORM_IDLE_STATE_NONE** (0xffffffff).

### `VetoReason` [out]

The nonzero index value that identifies reason the PEP needs to veto this idle state transition, or **PEP_IDLE_VETO_NONE** (0) if the PEP is prepared to immediately make this transition. If the PEP supports N veto reasons, valid veto reason indexes range from 1 to N. The PEP previously specified the number of supported veto reasons in response to a [PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason) notification.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_TEST_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_test_idle_state) notification. The **ProcessorState** and **PlatformState** members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The PEP writes an output value to the **VetoReason** member of this structure.

## See also

[PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state)

[PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason)

[PEP_NOTIFY_PPM_TEST_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_test_idle_state)