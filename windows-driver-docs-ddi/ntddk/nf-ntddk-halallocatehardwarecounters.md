## Description

The **HalAllocateHardwareCounters** routine allocates a set of hardware performance counter resources.

## Parameters

### `GroupAffinty`

A pointer to a set of **GROUP_AFFINITY** structures indicating which processors' counter resources the consumer requests. If this parameter is **NULL**, then the request indicates an allocation across all processors in the system.

### `GroupCount` [in]

Supplies the number of **GROUP_AFFINITY** structures provided by the *GroupAffinty* parameter, or zero if *GroupAffinity* is **NULL**.

### `ResourceList` [in]

A pointer to a **PHYSICAL_COUNTER_RESOURCE_LIST** containing the resources required by the consumer. If this parameter is **NULL**, then the consumer is requesting exclusive ownership of the performance monitoring unit.

### `CounterSetHandle` [out]

A pointer to a location into which the routine writes a handle to the allocated counter resources. To release these resources later, the caller must pass this handle to the [HalFreeHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halfreehardwarecounters) routine. If the requested counter resources are unavailable, **HalAllocateHardwareCounters** sets **CounterSetHandle* = **NULL** and returns STATUS_INSUFFICIENT_RESOURCES.

## Return value

**HalAllocateHardwareCounters** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| **STATUS_INSUFFICIENT_RESOURCES** | The requested counter resources are currently unavailable. |
| **STATUS_INVALID_PARAMETER** | The caller specified an invalid parameter value. |
| **STATUS_NOT_SUPPORTED** | The caller supplied resources in the resource list that are currently not supported. |

## Remarks

Most processors have performance monitor units (PMUs) that contain a number of hardware counters. Software tools use these counters to monitor various aspects of system performance. Typically, such a tool consists of a custom kernel-mode driver to program the counters and a user-mode application that communicates with the driver.

If more than one such tool is installed on a computer, the associated drivers must avoid trying to use the same hardware counters simultaneously. To avoid such resource conflicts, all drivers that use counter resources should use the **HalAllocateHardwareCounters** and **HalFreeHardwareCounters** routines to coordinate their sharing of these resources.

A counter resource is a single hardware counter, a block of contiguous counters, a counter overflow interrupt, or an event buffer configuration in a PMU.

Before configuring the counters, a driver can call the **HalAllocateHardwareCounters** routine to acquire exclusive access to a set of counter resources. After the driver no longer needs these resources, it must free the resources by calling the **HalFreeHardwareCounters** routine.

In versions of Windows before Windows 10 version 1903, a successful call to **HalAllocateHardwareCounters** grants the caller exclusive access to all counter resources in the performance monitor unit of a single-processor system. In a multiprocessor system, a successful call grants the caller exclusive access to all counter resources in all processors in the system. GroupAffinity and ResourceList must be **NULL** and GroupCount must be zero.

Starting in Windows 10 version 1903, counter resources can be allocated based on the resource list and group affinities provided.

Virtualization software typically does not virtualize hardware performance counters. Thus, these counters might not be available in a virtual machine, regardless of whether **HalAllocateHardwareCounters** returns a status code of STATUS_SUCCESS. For example, hardware performance counters are not available in a Hyper-V virtual machine, but **HalAllocateHardwareCounters** might still return STATUS_SUCCESS.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[HalFreeHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halfreehardwarecounters)

[**PHYSICAL_COUNTER_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_physical_counter_resource_list)