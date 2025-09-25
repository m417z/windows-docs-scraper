# _PEP_PPM_QUERY_IDLE_STATES structure

## Description

The **PEP_PPM_QUERY_IDLE_STATES** structure describes the idle states of a particular processor.

## Members

### `Count` [in]

The number of elements in the **IdleStates** array. This member is set to the **IdleStateCount** value that the PEP previously supplied for this processor in response to the [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities) notification.

### `MaximumCoordinatedProcessors` [out]

The maximum number of secondary processors that are subordinate to this processor for any transitions to idle states. A primary processor can enter the selected idle state only after the secondary processors have entered their corresponding idle states. The PEP must set the **MaximumCoordinatedProcessors** member to a number that is less than the total number of processors in the hardware platform.

### `IdleStates` [in]

The first element in an array of [PEP_PROCESSOR_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_processor_idle_state) structures. Each array element describes one of the idle states of this processor. If the array contains more than one element, the additional elements immediately follow the end of the **PEP_PPM_QUERY_IDLE_STATES** structure. The number of array elements is specified by the **Count** member. The buffer that PoFx allocates to hold this structure is guaranteed to be large enough to contain the **PEP_PPM_QUERY_IDLE_STATES** structure plus any array elements that follow this structure. Each idle state is identified by its array index. If the array contains N elements, idle state indexes range from 0 to N–1.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states) notification. The **Count** member of the structure contains an input value that PoFx supplies when this notification is sent. The other two members contain output values that the PEP writes to the structure in response to the notification.

## See also

[PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities)

[PEP_NOTIFY_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states)

[PEP_PROCESSOR_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_processor_idle_state)