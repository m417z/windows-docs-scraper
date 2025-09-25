# PROCESS_INFORMATION_CLASS enumeration

## Description

Indicates a specific class of process information. Values from this enumeration are passed into the [GetProcessInformation](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessinformation) and [SetProcessInformation](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessinformation) functions to specify the type of process information passed in the void pointer argument of the function call.

## Constants

### `ProcessMemoryPriority`

The process information is represented by a [MEMORY_PRIORITY_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-memory_priority_information) structure. Allows applications to lower the default memory priority of threads that perform background operations or access files and data that are not expected to be accessed again soon.

### `ProcessMemoryExhaustionInfo`

The process information is represented by a [PROCESS_MEMORY_EXHAUSTION_INFO](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_memory_exhaustion_info) structure. Allows applications to configure a process to terminate if an allocation fails to commit memory.

### `ProcessAppMemoryInfo`

The process information is represented by a [APP_MEMORY_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-app_memory_information) structure. Allows applications to query the commit usage and the additional commit available to this process. Does not allow the caller to actually get a commit limit.

### `ProcessInPrivateInfo`

If a process is set to **ProcessInPrivate** mode, and a trace session has set the [EVENT_ENABLE_PROPERTY_EXCLUDE_INPRIVATE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-enable_trace_parameters) flag, then the trace session will drop all events from that process.

### `ProcessPowerThrottling`

The process information is represented by a [PROCESS_POWER_THROTTLING_STATE](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_power_throttling_state) structure. Allows applications to configure how the system should throttle the target process's activity when managing power.

### `ProcessReservedValue1`

Reserved.

### `ProcessTelemetryCoverageInfo`

Reserved.

### `ProcessProtectionLevelInfo`

The process information is represented by a [PROCESS_PROTECTION_LEVEL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-process_protection_level_information) structure.

### `ProcessLeapSecondInfo`

The process information is represented by a [PROCESS_LEAP_SECOND_INFO](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_leap_second_info) structure.

### `ProcessMachineTypeInfo`

The process is represented by a [PROCESS_MACHINE_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_machine_information) structure.

### `ProcessOverrideSubsequentPrefetchParameter`

Can be used in a call to the [SetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessinformation) to set an [OVERRIDE_PREFETCH_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-override_prefetch_parameter) for the application that called it. The prefetch parameter is used to differentiate different file access patterns for the same process name.

### `ProcessMaxOverridePrefetchParameter`

Can be used in a call to the [GetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessinformation) to query the maximum allowable value (inclusive) for an [OVERRIDE_PREFETCH_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-override_prefetch_parameter). (The prefetch parameter is used to differentiate different file access patterns for the same process name.)

### `ProcessInformationClassMax`

The maximum value for this enumeration. This value may change in a future version.

## Remarks

## See also

[GetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessinformation), [SetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessinformation), [APP_MEMORY_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-app_memory_information), [PROCESS_MACHINE_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_machine_information), [PROCESS_MEMORY_EXHAUSTION_INFO structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_memory_exhaustion_info)