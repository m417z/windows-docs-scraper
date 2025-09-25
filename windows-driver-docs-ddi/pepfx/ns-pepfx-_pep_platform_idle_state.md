# _PEP_PLATFORM_IDLE_STATE structure (pepfx.h)

## Description

The **PEP_PLATFORM_IDLE_STATE** structure specifies the properties of a platform idle state.

## Members

### `InitiatingProcessor`

A **POHANDLE** value that identifies the processor that initiates the transition to this platform idle state, or **NULL** if any processor can initiate the transition. If non-NULL, this handle represents the registration of the processor (as a device) with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

### `InitiatingState`

The index of the processor idle state that the processor enters to initiate the platform's entry to the specified platform idle state. If the **IdleStates** array in the [PEP_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) structure contains N elements, the idle states are numbered 0 to N-1 in the order in which they appear in the array.

### `Latency`

The worst-case latency, in 100-nanosecond units, that the platform requires to wake from this idle state in response to a wake event.

### `BreakEvenDuration`

The minimum amount of time, specified in 100-nanosecond units, that the platform must spend in this idle state to make a transition to this state worthwhile. PoFx uses this member value as a hint to avoid switching the platform to an idle state unless the platform is likely to remain in this state for at least the amount of time specified by **BreakEvenDuration**.

### `DependencyArrayUsed`

The number of items in **DependencyArray** which were filled in by the PEP.

### `DependencyArrayCount`

The number of elements in the **DependencyArray** array. The array contains one element for each processor in the hardware platform.

### `DependencyArray`

The first element in an array of [PEP_PROCESSOR_IDLE_DEPENDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_dependency) structures. This array specifies the set of dependencies that the platform idle state has on each processor. If the platform contains N processors, the array contains N elements, and processors are numbered 0 to N-1 in the order in which they are represented in the array.

## Remarks

This structure is used in conjunction with the [PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) notification. The **State** member of a [PEP_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state) structure is a **PEP_PLATFORM_IDLE_STATE** structure.

## See also

[PEP_NOTIFY_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state)

[PEP_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)

[PEP_PPM_QUERY_PLATFORM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_platform_state)

[PEP_PROCESSOR_IDLE_DEPENDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_dependency)