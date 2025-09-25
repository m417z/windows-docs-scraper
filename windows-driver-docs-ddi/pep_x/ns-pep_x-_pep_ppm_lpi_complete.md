# _PEP_PPM_LPI_COMPLETE structure

## Description

The **PEP_PPM_LPI_COMPLETE** structure describes the processor performance counters that the platform extension plug-in (PEP) supports for a particular processor.

## Members

### `CoordinatedStateCount`

The number of coordinated idle states being exited by this transition.

### `CoordinatedStates`

Pointer to an array of coordinated idle states that are being exited by this transition.

## Remarks

This structure is used by the **PEP_NOTIFY_PPM_LPI_COMPLETE** notification. The notification is sent to the PEP to notify it that current processor is waking up from a completed platform idle transition. The first processor to wake indicates the platform idle states being exited. The first processor to wake from a platform idle state may not be the processor that entered the platform idle state.

This notification is only sent when using the ACPI LPI interface. Windows doesn't inform the PEP of processor idle state transitions or coordinated idle transitions except those listed below:

Windows 10, version 1703: This notification is only sent when a platform idle state associated with the root processor container (if one exists) is exited, and only includes the platform idle state associated with the root processor container.

Windows 10, version 1709: This notification is sent for all platform idle states. For example, all coordinated idle states associated with a processor container which directly or indirectly contains all processors in the system.

This notification is sent with interrupts disabled. This notification is always executed on the target processor.

## See also

- [PEP_NOTIFY_PPM_QUERY_FEEDBACK_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_feedback_counters)
- [PEP_PROCESSOR_FEEDBACK_COUNTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_feedback_counter)