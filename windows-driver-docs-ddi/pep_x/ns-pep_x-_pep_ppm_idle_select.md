# _PEP_PPM_IDLE_SELECT structure

## Description

The **PEP_PPM_IDLE_SELECT** structure describes the most energy-efficient idle state that the processor can enter and still satisfy the constraints specified by the operating system.

## Members

### `Constraints` [in]

A pointer to a [PEP_PROCESSOR_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_processor_idle_constraints) structure that specifies the constraints that the selected processor idle state must satisfy. The operating system sets the values in this structure. The platform extension plug-in (PEP) must select a processor idle state that satisfies these constraints.

### `AbortTransition` [out]

Whether to cancel the pending transition to a processor idle state. Set this member to TRUE if the PEP requires the operating system to cancel the pending transition, and to FALSE otherwise. The PEP selects this option if it wants to queue work and have the Windows kernel process this work before the processor enters idle.

### `IdleStateIndex` [out]

The index that identifies the idle state that the processor is to enter. This member is ignored if **AbortTransition** = TRUE. If the processor supports N idle states, idle state indexes range from 0 to N–1. The PEP supplied the number of supported idle states for this processor in response to a previous [PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states) notification.

### `DependencyArrayUsed` [out]

The number of array elements that the PEP has actually written to the output buffer pointed to the **DependencyArray** member.

### `DependencyArrayCount` [in]

The maximum number of elements in the array pointed to by the **DependencyArray** member. The **DependencyArrayCount** member value is equal to the **MaximumCoordinatedProcessors** value that the PEP previously supplied in response to the [PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states) notification.

### `DependencyArray` [in]

A pointer to an output buffer to which the PEP writes an array of [PEP_PROCESSOR_IDLE_DEPENDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_dependency) structures. The elements of this array specify processor idle dependencies or wake dependencies that must be met for this idle transition to succeed. The PEP sets the **DependencyArrayUsed** member to the actual number of array elements that the PEP writes to the buffer. The output buffer is allocated by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) and is guaranteed to be large enough to contain the number of array elements specified by the **DependencyArrayCount** member.

### `PlatformIdleStateIndex` [out]

The index of the platform idle state that the platform is to enter when the processor enters the selected processor idle state. The PEP should set this member only if the platform enters an idle state at the same time as the processor. This member is ignored if **AbortTransition** is TRUE.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_IDLE_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_select) notification. The **Constraints**, **DependencyArrayCount**, and **DependencyArray** members of the structure contain input values supplied by PoFx when this notification is sent. The remaining members contain output values that the PEP writes to the structure in response to the notification.

## See also

[PEP_NOTIFY_PPM_IDLE_SELECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_select)

[PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states)

[PEP_PROCESSOR_IDLE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_processor_idle_constraints)

[PEP_PROCESSOR_IDLE_DEPENDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_dependency)