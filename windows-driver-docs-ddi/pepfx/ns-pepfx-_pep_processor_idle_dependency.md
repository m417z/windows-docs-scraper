# _PEP_PROCESSOR_IDLE_DEPENDENCY structure (pepfx.h)

## Description

The **PEP_PROCESSOR_IDLE_DEPENDENCY** structure specifies the dependencies of a platform idle state on the specified processor.

## Members

### `TargetProcessor`

A **POHANDLE** value that identifies the processor. The platform extension plug-in (PEP) received this handle in a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `ExpectedState`

The index of the processor idle state that this processor must enter to initiate the platform's transition to this platform idle state. If the **IdleStates** array in the [PEP_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) structure contains N elements, the idle states are numbered 0 to N-1 in the order in which they appear in the array.

### `AllowDeeperStates`

Whether a secondary (subordinate) processor can be in a deeper processor idle state than **ExpectedState** and still satisfy the constraints of the transition to the platform idle state. Set this member to **TRUE** if a secondary processor in a deeper idle state can still satisfy the constraints, and to **FALSE** if it cannot. A primary processor (identified by the **TargetProcessor** member) can enter the selected idle state only after its secondary processors have entered their corresponding idle states.

### `LooseDependency`

Whether the platform idle state has a loose dependency on the idle state of this processor. Set this member to **TRUE** to indicate a loose dependency in which a best effort to synchronize the idle state transitions of the platform and processor is sufficient. Set to **FALSE** to indicate a dependency in which the operating system is required to strictly synchronize these transitions. If **LooseDependency** is **FALSE**, the **WakesSpuriously** bit in the [PEP_PROCESSOR_IDLE_STATE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_v2) structure for this processor must be **FALSE**.

## Remarks

The **DependencyArray** member of the [PEP_PPM_IDLE_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_select) structure is a pointer to an array of **PEP_PROCESSOR_IDLE_DEPENDENCY** structures. The **DependencyArray** member of the [PEP_PLATFORM_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_platform_idle_state) structure is the first element in an array of **PEP_PROCESSOR_IDLE_DEPENDENCY** structures.

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_PLATFORM_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_platform_idle_state)

[PEP_PPM_IDLE_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_select)

[PEP_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)

[PEP_PROCESSOR_IDLE_STATE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_v2)