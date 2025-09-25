# _PEP_PPM_QUERY_DOMAIN_INFO structure (pepfx.h)

## Description

Used in the **PEP_NOTIFY_PPM_QUERY_DOMAIN_INFO** notification that queries for information about a performance domain.

## Members

### `DomainId`

On input, the domain ID of the domain being queried.

### `CoordinationType`

On output, indicates the coordination type of the performance domain. The possible values are:

* PROCESSOR_DOMAIN_COORDIANTION_SW_ALL (0x00)
* PROCESSOR_DOMAIN_COORDIANTION_SW_ANY (0x01)
* PROCESSOR_DOMAIN_COORDIANTION_HW_ALL (0x02)

If this notification is not supported, PROCESSOR_DOMAIN_COORDIANTION_SW_ALL coordination is used.

### `IdleProcessorsDiscounted`

On output, and if HW-ALL coordination is used, this value is TRUE if the platform automatically ignores requests from idle processors as it determines the resolved performance level of the domain, FALSE if requests from idle processors continue to be honored.
If PROCESSOR_DOMAIN_COORDIANTION_HW_ALL coordination is not used: this field is ignored.

### `SchedulerDirectedTransitionsSupported`

On output, this value is TRUE if the PEP supports the requirements of scheduler directed performance transitions for this domain, FALSE otherwise.

### `AffinitizePerfSet`

On output, this value is TRUE if the PEP requires the PEP_NOTIFY_PPM_PERF_SET or PEP_NOTIFY_PPM_PERF_SET_STATE notification to execute on the processor changing frequency, or FALSE if the PEP allows these notifications to execute on any processor.
If PROCESSOR_DOMAIN_COORDIANTION_SW_ANY coordination is used: the PEP_NOTIFY_PPM_PERF_SET or PEP_NOTIFY_PPM_PERF_SET_STATE notification will execute on a processor in the domain.

### `WorstCaseTransitionLatency`

On output, this value indicates the worst case latency for the processor to transition to a new performance state, measured from the time the OS issues the notification to the PEP to transition to a new performance level, to the time the processor is running at the new performance level, in 100ns units.

### `WorstCaseTransitionOverhead`

On output, this value indicates the worst case overhead (PEP code execution time plus time the processor is not executing instructions) measured from the time the OS issues the notification to the PEP to transition to a new performance level, to the time the processor is running at the new performance level, in 100ns units.

## See also

[Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/ppm-notifications)