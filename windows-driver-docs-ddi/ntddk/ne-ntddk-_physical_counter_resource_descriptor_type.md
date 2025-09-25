# _PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE enumeration

## Description

The **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE** enumeration contains constants that indicate the type of hardware performance counter resource that is described by a [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure.

## Constants

### `ResourceTypeSingle`

A single hardware counter. The counter is described by the **u.CounterIndex** member of the [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure.

### `ResourceTypeRange`

A range of counter indexes. The counter indexes are described by the **u.Range** member of the [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure.

### `ResourceTypeExtendedCounterConfiguration`

An extended counter configuration register address. Specifying this value will result in [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) returning **STATUS_NOT_SUPPORTED**.

### `ResourceTypeOverflow`

A counter overflow interrupt handler. The interrupt handler to be invoked is described by the **u.OverflowHandler** member of the [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure.

### `ResourceTypeEventBuffer`

An event buffer configuration. The configuration of the event buffer threshold, entry size, and overflow handler are described by the **u.EventBufferConfiguration** member of the [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure.

### `ResourceTypeMax`

The maximum value in this enumeration type.

### `ResourceTypeIdenitificationTag`

## Remarks

The **Type** member of a [**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structure uses a **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE** enumeration constant to indicate the type of counter resource that is described by the structure.

## See also

[PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor)

[*PPHYSICAL_COUNTER_OVERFLOW_HANDLER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pphysical_counter_overflow_handler)

[*PHYSICAL_COUNTER_EVENT_BUFFER_OVERFLOW_HANDLER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pphysical_counter_event_buffer_overflow_handler)