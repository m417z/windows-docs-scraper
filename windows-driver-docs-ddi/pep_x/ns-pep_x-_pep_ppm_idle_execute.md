# _PEP_PPM_IDLE_EXECUTE structure (pep_x.h)

## Description

The **PEP_PPM_IDLE_EXECUTE** structure specifies the idle state that the processor is to enter.

## Members

### `Status` [out]

An **NTSTATUS** value that indicates whether the processor idle state transition was successful. The platform extension plug-in (PEP) sets this member to **STATUS_SUCCESSFUL** if the transition succeeded. Otherwise, this member is set to an appropriate error status code.

### `ProcessorState` [in]

The index of the processor idle state that the processor is to enter. The PEP previously specified the supported processor idle states in response to a [PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states) notification. If the PEP specified N processor idle states, valid processor-idle-state indexes range from 0 to N-1.

### `PlatformState` [in]

The index of the platform idle state that the hardware platform will enter when the processor enters the processor idle state specified by **ProcessorState**. The PEP previously specified the supported platform idle states in response to a [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) notification. If the PEP specified M platform idle states, valid platform-idle-state indexes range from 0 to M-1. If no change in platform idle state will occur, this member will contain the value P**EP_PLATFORM_IDLE_STATE_NONE** (0xffffffff).

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_IDLE_EXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_execute) notification. The **ProcessorState** and **PlatformState** members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The **Status** member contains an output value that the PEP writes to this member.

## See also

[PEP_NOTIFY_PPM_IDLE_EXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_execute)

[PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states)

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state)