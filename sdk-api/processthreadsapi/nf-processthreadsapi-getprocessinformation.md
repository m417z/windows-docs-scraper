# GetProcessInformation function

## Description

Retrieves information about the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have at least the **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/win32/procthread/process-security-and-access-rights).

### `ProcessInformationClass` [in]

A member of the [PROCESS_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class) enumeration specifying the kind of information to retrieve.

### `ProcessInformation`

Pointer to an object to receive the type of information specified by the *ProcessInformationClass* parameter.

If the *ProcessInformationClass* parameter is **ProcessMemoryPriority**, this parameter must point to a [MEMORY_PRIORITY_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-memory_priority_information).

If the *ProcessInformationClass* parameter is **ProcessPowerThrottling**, this parameter must point to a [PROCESS_POWER_THROTTLING_STATE structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_power_throttling_state).

If the *ProcessInformationClass* parameter is **ProcessProtectionLevelInfo**, this parameter must point to a [PROCESS_PROTECTION_LEVEL_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_protection_level_information).

If the *ProcessInformationClass* parameter is **ProcessLeapSecondInfo**, this parameter must point to a [PROCESS_LEAP_SECOND_INFO structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_leap_second_info).

If the *ProcessInformationClass* parameter is **ProcessAppMemoryInfo**, this parameter must point to a [APP_MEMORY_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-app_memory_information).

If the *ProcessInformationClass* parameter is **ProcessMaxOverridePrefetchParameter**, this parameter must point to an [OVERRIDE_PREFETCH_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-override_prefetch_parameter).

### `ProcessInformationSize` [in]

The size in bytes of the structure specified by the *ProcessInformation* parameter.

If the *ProcessInformationClass* parameter is **ProcessMemoryPriority**, this parameter must be `sizeof(MEMORY_PRIORITY_INFORMATION)`.

If the *ProcessInformationClass* parameter is **ProcessPowerThrottling**, this parameter must be `sizeof(PROCESS_POWER_THROTTLING_STATE)`.

If the *ProcessInformationClass* parameter is **ProcessProtectionLevelInfo**, this parameter must be `sizeof(PROCESS_PROTECTION_LEVEL_INFORMATION)`.

If the *ProcessInformationClass* parameter is **ProcessLeapSecondInfo**, this parameter must be `sizeof(PROCESS_LEAP_SECOND_INFO)`.

If the *ProcessInformationClass* parameter is **ProcessAppMemoryInfo**, this parameter must be `sizeof(APP_MEMORY_INFORMATION)`.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetThreadInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getthreadinformation), [MEMORY_PRIORITY_INFORMATION structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-memory_priority_information), [SetProcessInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessinformation), [PROCESS_INFORMATION_CLASS enumeration](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class), [OVERRIDE_PREFETCH_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-override_prefetch_parameter)