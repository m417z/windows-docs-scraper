## Description

The PPHYSICAL_COUNTER_OVERFLOW_HANDLER is implemented by the client driver to handle counter overflows from the counters resources acquired through the [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) routine.

## Parameters

### `OverflowBits`

Provides a bitmap describing which counters overflowed.

### `OwningHandle`

Provides the **HANDLE** corresponding to the resource set the overflowing counters belong to.

## Remarks

Register your implementation of this callback function by calling [**HalAllocateHardwareCounters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) with a structure of type [**PHYSICAL_COUNTER_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_list). In the **PHYSICAL_COUNTER_RESOURCE_LIST**, provide a structure of type [PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_descriptor) that specifies a [**PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_physical_counter_resource_descriptor_type) of **ResourceTypeOverflow**.

Here is an example prototype for an overflow handler:

```cpp
VOID
PmuAwareOverflowHandler (
    _In_ ULONGLONG OverflowStatus,
    _In_ HANDLE OwningHandle
    )

/*++

Routine Description:

    This routine is the PMU Overflow Handler for a sharing driver.

Arguments:

    OverflowStatus - The counters which have overflowed.

    OwningHandle - The handle owning the counters.

Return Value:

    None.

--*/
{
}
```

To register the overflow handler, use code like this:

```cpp
VOID
CreateOverflowDescriptor (
    _Inout_ PPHYSICAL_COUNTER_RESOURCE_LIST CounterResourceList,
    _In_ ULONG DescriptorIndex
    )
{

    CounterResourceList->Descriptors[DescriptorIndex].Type = ResourceTypeOverflow;
    CounterResourceList->Descriptors[DescriptorIndex].u.OverflowHandler = PmuAwareOverflowHandler;
}
```

This callback is called at IRQL = PROFILE_LEVEL. This means it must always be memory-resident. The callback should return as quickly as possible and should not attempt to do any of the following.

- Acquire or release spin locks.

- Access paged pool that is not locked in memory

- Call a pageable routine.

The callback does not need to handle clearing any overflow registers as it will be handled by the HAL.

## See also