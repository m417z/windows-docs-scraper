# SetProcessInformation function

## Description

Sets information for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have the **PROCESS_SET_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `ProcessInformationClass` [in]

A member of the [PROCESS_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class) enumeration specifying the kind of information to set.

### `ProcessInformation`

Pointer to an object that contains the type of information specified by the *ProcessInformationClass* parameter.

If the *ProcessInformationClass* parameter is **ProcessMemoryPriority**, this parameter must point to a [MEMORY_PRIORITY_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-memory_priority_information).

If the *ProcessInformationClass* parameter is **ProcessPowerThrottling**, this parameter must point to a [PROCESS_POWER_THROTTLING_STATE structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_power_throttling_state).

If the *ProcessInformationClass* parameter is **ProcessLeapSecondInfo**, this parameter must point to a [PROCESS_LEAP_SECOND_INFO structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_leap_second_info).

If the *ProcessInformationClass* parameter is **ProcessOverrideSubsequentPrefetchParameter**, this parameter must point to an [OVERRIDE_PREFETCH_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-override_prefetch_parameter).

### `ProcessInformationSize` [in]

The size in bytes of the structure specified by the *ProcessInformation* parameter.

If the *ProcessInformationClass* parameter is **ProcessMemoryPriority**, this parameter must be `sizeof(MEMORY_PRIORITY_INFORMATION)`.

If the *ProcessInformationClass* parameter is **ProcessPowerThrottling**, this parameter must be `sizeof(PROCESS_POWER_THROTTLING_STATE)`.

If the *ProcessInformationClass* parameter is **ProcessLeapSecondInfo**, this parameter must be `sizeof(PROCESS_LEAP_SECOND_INFO)`.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To help improve system performance, applications should use the **SetProcessInformation** function with **ProcessMemoryPriority** to lower the default memory priority of threads that perform background operations or access files and data that are not expected to be accessed again soon. For example, a file indexing application might set a lower default priority for the process that performs the indexing task.

**Memory priority** helps to determine how long pages remain in the [working set](https://learn.microsoft.com/windows/desktop/Memory/working-set) of a process before they are trimmed. A process's memory priority determines the default priority of the physical pages that are added to the process working set by the threads of that process. When the memory manager trims the working set, it trims lower priority pages before higher priority pages. This improves overall system performance because higher priority pages are less likely to be trimmed from the working set and then trigger a page fault when they are accessed again.

**ProcessPowerThrottling** enables throttling policies on a process, which can be used to balance out performance and power efficiency in cases where optimal performance is not required.

When a process opts into enabling `PROCESS_POWER_THROTTLING_EXECUTION_SPEED`, the process will be classified as EcoQoS. The system will try to increase power efficiency through strategies such as reducing CPU frequency or using more power efficient cores. EcoQoS should be used when the work is not contributing to the foreground user experience, which provides longer battery life, and reduced heat and fan noise. EcoQoS should not be used for performance critical or foreground user experiences. (Prior to Windows 11, the EcoQoS level did not exist and the process was labeled as LowQoS). If an application does not explicitly enable `PROCESS_POWER_THROTTLING_EXECUTION_SPEED`, the system will use its own heuristics to automatically infer a Quality of Service level. For more information, see [Quality of Service](https://learn.microsoft.com/windows/win32/procthread/quality-of-service).

When a process opts into enabling `PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION`, any current timer resolution requests made by the process will be ignored. Timers belonging to the process are no longer guaranteed to expire with higher timer resolution, which can improve power efficiency. After explicitly disabling `PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION`, the system remembers and honors any previous timer resolution request by the process. By default in Windows 11 if a window owning process becomes fully occluded, minimized, or otherwise non-visible to the end user, and non-audible, Windows may automatically ignore the timer resolution request and thus does not guarantee a higher resolution than the default system resolution.

### Examples

The following example shows how to call **SetProcessInformation** with **ProcessMemoryPriority** to set low memory priority as the default for the calling process.

``` syntax
    DWORD ErrorCode;
    BOOL Success;
    MEMORY_PRIORITY_INFORMATION MemPrio;

    //
    // Set low memory priority on the current process.
    //

    ZeroMemory(&MemPrio, sizeof(MemPrio));
    MemPrio.MemoryPriority = MEMORY_PRIORITY_LOW;

    Success = SetProcessInformation(GetCurrentProcess(),
                                   ProcessMemoryPriority,
                                   &MemPrio,
                                   sizeof(MemPrio));

    if (!Success) {
        ErrorCode = GetLastError();
        fprintf(stderr, "Set process memory priority failed: %d\n", ErrorCode);
        goto cleanup;
    }
```

The following example shows how to call **SetProcessInformation** with **ProcessPowerThrottling** to control the Quality of Service of a process.

``` syntax
PROCESS_POWER_THROTTLING_STATE PowerThrottling;
RtlZeroMemory(&PowerThrottling, sizeof(PowerThrottling));
PowerThrottling.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;

//
// EcoQoS
// Turn EXECUTION_SPEED throttling on.
// ControlMask selects the mechanism and StateMask declares which mechanism should be on or off.
//

PowerThrottling.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
PowerThrottling.StateMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;

SetProcessInformation(GetCurrentProcess(),
                      ProcessPowerThrottling,
                      &PowerThrottling,
                      sizeof(PowerThrottling));

//
// HighQoS
// Turn EXECUTION_SPEED throttling off.
// ControlMask selects the mechanism and StateMask is set to zero as mechanisms should be turned off.
//

PowerThrottling.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
PowerThrottling.StateMask = 0;

SetProcessInformation(GetCurrentProcess(),
                      ProcessPowerThrottling,
                      &PowerThrottling,
                      sizeof(PowerThrottling));

```

The following example shows how to call **SetProcessInformation** with **ProcessPowerThrottling** to control the Timer Resolution of a process.

``` syntax
PROCESS_POWER_THROTTLING_STATE PowerThrottling;
RtlZeroMemory(&PowerThrottling, sizeof(PowerThrottling));
PowerThrottling.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;

//
// Ignore Timer Resolution Requests.
// Turn IGNORE_TIMER_RESOLUTION throttling on.
// ControlMask selects the mechanism and StateMask declares which mechanism should be on or off.
//

PowerThrottling.ControlMask = PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION;
PowerThrottling.StateMask = PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION;

SetProcessInformation(GetCurrentProcess(),
                      ProcessPowerThrottling,
                      &PowerThrottling,
                      sizeof(PowerThrottling));

//
// Always honor Timer Resolution Requests.
// Turn IGNORE_TIMER_RESOLUTION throttling off.
// ControlMask selects the mechanism and StateMask is set to zero as mechanisms should be turned off.
//

PowerThrottling.ControlMask = PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION;
PowerThrottling.StateMask = 0;

SetProcessInformation(GetCurrentProcess(),
                      ProcessPowerThrottling,
                      &PowerThrottling,
                      sizeof(PowerThrottling));

```

The following example shows how to call **SetProcessInformation** with **ProcessPowerThrottling** to reset to the default system managed behavior.

``` syntax
PROCESS_POWER_THROTTLING_STATE PowerThrottling;
RtlZeroMemory(&PowerThrottling, sizeof(PowerThrottling));
PowerThrottling.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;

//
// Let system manage all power throttling. ControlMask is set to 0 as we don't want
// to control any mechanisms.
//

PowerThrottling.ControlMask = 0;
PowerThrottling.StateMask = 0;

SetProcessInformation(GetCurrentProcess(),
                      ProcessPowerThrottling,
                      &PowerThrottling,
                      sizeof(PowerThrottling));

```

## See also

[GetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessinformation), [SetThreadInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadinformation), [MEMORY_PRIORITY_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-memory_priority_information), [SetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessinformation), [PROCESS_INFORMATION_CLASS enumeration](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class), [OVERRIDE_PREFETCH_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-override_prefetch_parameter)