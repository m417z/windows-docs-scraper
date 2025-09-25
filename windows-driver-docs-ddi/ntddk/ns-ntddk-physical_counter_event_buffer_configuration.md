# PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION structure

## Description

The **PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION** structure describes the configuration for event buffers on the platform.

## Members

### `OverflowHandler`

A pointer to the driver-supplied [*PPHYSICAL_COUNTER_EVENT_BUFFER_OVERFLOW_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pphysical_counter_event_buffer_overflow_handler) routine that will be called when the event buffer entries reach a threshold in the event buffer.

### `CustomEventBufferEntrySize`

The size of the event buffer entries, for custom event buffer sizes. Set to zero.

### `EventThreshold`

The number of events to be recorded before the OverflowHandler callback routine is invoked. This value is used as a maximum threshold. The actual number of events will depend on the number of actors using event buffer profiling.

## Remarks

Most processors have performance monitor units that contain a number of hardware counters for measuring various aspects of system performance. The **PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION** structure is used within the [**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure to describe the configuration for event buffer resources.

## See also

[**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_physical_counter_resource_descriptor_type)

[PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor)