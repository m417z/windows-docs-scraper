## Description

The **KeSetHardwareCounterConfiguration** routine specifies a list of hardware counters to use for thread profiling.

## Parameters

### `CounterArray` [in]

A pointer to a [**HARDWARE_COUNTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_hardware_counter) array that describes the hardware counter configuration to use for thread profiling. Each array element is a structure that describes a hardware counter. Before the routine returns, it copies the contents of this array into its internal data structures.

### `Count` [in]

Specifies the number of elements in the array that is pointed to by the *CounterArray* parameter.

## Return value

**KeSetHardwareCounterConfiguration** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
|--|--|
| **STATUS_INVALID_PARAMETER** | The value of the *Count* parameter exceeds the maximum number of counters that is specified by the MAX_HW_COUNTERS constant, which is defined in the Ntddk.h header file. |
| **STATUS_WMI_ALREADY_ENABLED** | One or more of the counters that are specified in the *CounterArray* array are already enabled. |
| **STATUS_NOT_IMPLEMENTED** | This routine is not implemented for the processor architecture that the caller is running on. |

## Remarks

In Windows 7, this routine is implemented only for the x86-based, x64-based, and Itanium-based architectures. If a caller is running on a processor architecture that is not supported, the routine returns STATUS_NOT_IMPLEMENTED.

This routine tells the operating system which hardware counters to use for thread profiling. Call this routine only when thread profiling is disabled. If the *CounterArray* array specifies any hardware counters that are currently being used, the routine fails and returns STATUS_WMI_ALREADY_ENABLED.

An application thread can enable thread profiling to obtain a set of performance measurements from the hardware counters in the performance monitoring unit (PMU) of the local processor. The operating system supports only one profiling application at a time. Concurrent instances of a thread-profiling application are not supported. A thread can enable thread profiling for itself but not for other threads.

When thread profiling is enabled, the operating system uses the hardware counters that were specified in the last call to **KeSetHardwareCounterConfiguration**. Each successful **KeSetHardwareCounterConfiguration** call replaces any hardware counter configuration that might have been set in a previous **KeSetHardwareCounterConfiguration** call.

Set *Count* = 0 to specify an empty hardware counter configuration. This configuration effectively prevents the use of hardware counters for thread profiling. The default hardware counter configuration that exists after system startup and before the initial **KeSetHardwareCounterConfiguration** call is an empty configuration.

The effect of a successful **KeSetHardwareCounterConfiguration** call is global. If a thread in any process is profiled, the profiler uses the hardware counter configuration that was set by the last call to **KeSetHardwareCounterConfiguration**. In a multiprocessor system, a **KeSetHardwareCounterConfiguration** call sets the hardware counter configuration to use for thread profiling across all processors in the system, although each processor uses its own set of hardware counters.

To avoid resource conflicts, all drivers that use counter resources should use the [HalAllocateHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters) and [HalFreeHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halfreehardwarecounters) routines to coordinate their sharing of these resources.

To determine if thread profiling is enabled for a given thread, call the [**QueryThreadProfiling**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-querythreadprofiling) function.

To query the operating system for the hardware counter configuration that is currently in effect for thread profiling, call the [KeQueryHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhardwarecounterconfiguration) routine.

Virtualization software typically does not virtualize hardware performance counters. Thus, hardware performance counters are unlikely to be available in a virtual machine.

## See also

[Hardware Counter Profiling Reference](https://learn.microsoft.com/previous-versions/windows/desktop/hcp/hcp-reference)

[**HARDWARE_COUNTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_hardware_counter)

[HalAllocateHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halallocatehardwarecounters)

[HalFreeHardwareCounters](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-halfreehardwarecounters)

[KeQueryHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryhardwarecounterconfiguration)