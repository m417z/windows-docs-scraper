# _PHYSICAL_COUNTER_RESOURCE_LIST structure

## Description

The **PHYSICAL_COUNTER_RESOURCE_LIST** structure describes an array of [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) structures.

## Members

### `Count`

The number of elements in the **Descriptors** array.

### `Descriptors`

The first element in an array of **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR** structures. If the array contains more than one element, the remaining elements immediately follow the first element.

## Remarks

This structure describes a set of counter resources. Most processors have performance monitor units (PMUs) that contain a number of hardware counters to measure various aspects of system performance. A counter resource is a single hardware counter, a block of contiguous counters, or a counter overflow interrupt in a PMU.

The buffer allocated to contain a **PHYSICAL_COUNTER_RESOURCE_LIST** structure must be large enough to contain the structure plus any **PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR** array elements that follow the structure.

The [HalAllocateHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) routine's *ResourceList* parameter is a pointer to a **PHYSICAL_COUNTER_RESOURCE_LIST** structure. In Windows 7, this parameter is unused and must be set to **NULL**.

## See also

[HalAllocateHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters)

[PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor)