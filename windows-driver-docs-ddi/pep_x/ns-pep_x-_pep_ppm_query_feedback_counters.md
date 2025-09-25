# _PEP_PPM_QUERY_FEEDBACK_COUNTERS structure (pep_x.h)

## Description

The **PEP_PPM_QUERY_FEEDBACK_COUNTERS** structure describes all the processor performance counters that the platform extension plug-in (PEP) supports for a particular processor.

## Members

### `Count` [in]

The number of processor performance feedback counters supported by the PEP. The PEP previously supplied this count in response to a [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities) notification.

### `Counters` [out]

The first element in an array of [PEP_PROCESSOR_FEEDBACK_COUNTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_feedback_counter) structures. If this array contains more than one element, the additional elements immediately follow the end of the **PEP_PPM_QUERY_FEEDBACK_COUNTERS** structure. The **Count** member specifies the number of elements in this array. For more information, see Remarks.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_FEEDBACK_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_feedback_counters) notification. The **Count** member of the structure contains an input value that PoFx supplies when this notification is sent. The **Counters** member contains an output value that the PEP writes in response to the notification. The PEP writes any additional **Counters** array elements to the output buffer area that follows the **PEP_PPM_QUERY_FEEDBACK_COUNTERS** structure. The buffer that PoFx allocated for this structure is guaranteed to be large enough to contain any array elements that follow the structure.

## See also

[PEP_NOTIFY_PPM_QUERY_FEEDBACK_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_feedback_counters)

[PEP_PROCESSOR_FEEDBACK_COUNTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_feedback_counter)