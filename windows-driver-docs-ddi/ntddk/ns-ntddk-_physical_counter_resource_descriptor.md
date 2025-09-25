# _PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR structure

## Description

The **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR** structure describes the counter resources available on the platform.

## Members

### `Type`

Indicates the type of counter resource described by the structure. Set this parameter to one of the following [**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_physical_counter_resource_descriptor_type) enumeration constants:

* **ResourceTypeSingle**
* **ResourceTypeRange**
* **ResourceTypeOverflow**
* **ResourceTypeEventBuffer**

### `Flags`

No flags are currently defined. Set this member to zero.

### `u`

A union that can contain a **CounterIndex**, **Range**, **OverflowHandler**, or **EventBufferConfiguration** value.

### `u.CounterIndex`

A physical counter index.

### `u.Range.Begin`

The starting counter index of a block of contiguous counters.

### `u.Range.End`

The ending counter index of a block of contiguous counters.

### `u.Range`

A range of counter indexes.

### `u.OverflowHandler`

A pointer to the driver-supplied [*PPHYSICAL_COUNTER_OVERFLOW_HANDLER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pphysical_counter_overflow_handler) routine that will be called when an associated hardware counter (specified by another **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR**) overflows.

### `u.EventBufferConfiguration`

A configuration for event buffer based sampling (such as Intel's PEBS). The configuration fields are defined by the [PHYSICAL_COUNTER_EVENT_BUFFER_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-physical_counter_event_buffer_configuration) type.

### `u.IdentificationTag`

## Remarks

Most processors have performance monitor units that contain a number of hardware counters for measuring various aspects of system performance. The **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR** structure describes a counter resource, which can be a single hardware counter, a block of contiguous counters, a counter overflow interrupt, or an event buffer configuration. This structure's **Type** member indicates which type of counter resource is described by the structure.

To specify a set of counter resources, a kernel-mode client can provide an array of **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR** structures. A [**PHYSICAL_COUNTER_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_list) structure serves as a header for the array. The client can allocate and free the set of counter resources described by the array as a single unit. To do so, the driver calls [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) and [**HalFreeHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halfreehardwarecounters)

## See also

[**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_physical_counter_resource_descriptor_type)

[**PHYSICAL_COUNTER_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_list)