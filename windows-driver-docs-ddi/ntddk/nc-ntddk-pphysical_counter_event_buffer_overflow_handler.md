# PPHYSICAL_COUNTER_EVENT_BUFFER_OVERFLOW_HANDLER callback function

## Description

The PPHYSICAL_COUNTER_OVERFLOW_HANDLER is implemented by the client driver to handle event buffer overflows from the counters resources acquired through the [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) routine.

## Parameters

### `EventBuffer`

Provides a pointer to the event buffer containing the event entries.

### `EntrySize`

Provides the size of an individual event entry.

### `NumberOfEntries`

Provides the number of entries available.

### `OwningHandle`

Provides the **HANDLE** corresponding to the resource set the event buffer belongs to.

## Remarks

Register your implementation of this callback function by calling [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) with a structure of type [**PHYSICAL_COUNTER_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_list). In the **PHYSICAL_COUNTER_RESOURCE_LIST**, provide a structure of type [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) that specifies a [**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_physical_counter_resource_descriptor_type) of **ResourceTypeEventBuffer**.

This callback is called at IRQL = PROFILE_LEVEL. This means it must always be memory-resident. The callback should return as quickly as possible and should not attempt to do any of the following.

* Acquire or release spin locks.

* Access paged pool that is not locked in memory

* Call a pageable routine.

The callback does not need to handle clearing any overflow registers as it will be handled by the HAL.

## See also