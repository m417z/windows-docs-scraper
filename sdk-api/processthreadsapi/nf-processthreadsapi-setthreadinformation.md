# SetThreadInformation function

## Description

Sets information for the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread. The handle must have THREAD_SET_INFORMATION access right. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `ThreadInformationClass` [in]

The class of information to set. The only supported values are **ThreadMemoryPriority** and **ThreadPowerThrottling**.

### `ThreadInformation`

Pointer to a structure that contains the type of information specified by the *ThreadInformationClass* parameter.

If the *ThreadInformationClass* parameter is **ThreadMemoryPriority**, this parameter must point to a **MEMORY_PRIORITY_INFORMATION** structure.

If the *ThreadInformationClass* parameter is **ThreadPowerThrottling**, this parameter must point to a **THREAD_POWER_THROTTLING_STATE** structure.

### `ThreadInformationSize` [in]

The size in bytes of the structure specified by the *ThreadInformation* parameter.

If the *ThreadInformationClass* parameter is **ThreadMemoryPriority**, this parameter must be `sizeof(MEMORY_PRIORITY_INFORMATION)`.

If the *ThreadInformationClass* parameter is **ThreadPowerThrottling**, this parameter must be `sizeof(THREAD_POWER_THROTTLING_STATE)`.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To help improve system performance, applications should use the **SetThreadInformation** function with **ThreadMemoryPriority** to lower the memory priority of threads that perform background operations or access files and data that are not expected to be accessed again soon. For example, an anti-malware application might lower the priority of threads involved in scanning files.

**Memory priority** helps to determine how long pages remain in the [working set](https://learn.microsoft.com/windows/desktop/Memory/working-set) of a process before they are trimmed. A thread's memory priority determines the minimum priority of the physical pages that are added to the process working set by that thread. When the memory manager trims the working set, it trims lower priority pages before higher priority pages. This improves overall system performance because higher priority pages are less likely to be trimmed from the working set and then trigger a page fault when they are accessed again.

**ThreadPowerThrottling** enables throttling policies on a thread, which can be used to balance out performance and power efficiency in cases where optimal performance is not required. When a thread opts into enabling `THREAD_POWER_THROTTLING_EXECUTION_SPEED`, the thread will be classified as EcoQoS. The system will try to increase power efficiency through strategies such as reducing CPU frequency or using more power efficient cores. EcoQoS should be used when the work is not contributing to the foreground user experience, which provides longer battery life, and reduced heat and fan noise. EcoQoS should not be used for performance critical or foreground user experiences. (Prior to Windows 11, the EcoQoS level did not exist and the process was instead labeled as LowQoS). If an application does not explicitly enable `THREAD_POWER_THROTTLING_EXECUTION_SPEED`, the system will use its own heuristics to automatically infer a Quality of Service level. For more information, see [Quality of Service](https://learn.microsoft.com/windows/win32/procthread/quality-of-service).

#### Examples

The following example shows how to call **SetThreadInformation** with **ThreadMemoryPriority** to set low memory priority on the current thread.

```c
DWORD ErrorCode;
BOOL Success;
MEMORY_PRIORITY_INFORMATION MemPrio;

//
// Set low memory priority on the current thread.
//

ZeroMemory(&MemPrio, sizeof(MemPrio));
MemPrio.MemoryPriority = MEMORY_PRIORITY_LOW;

Success = SetThreadInformation(GetCurrentThread(),
                               ThreadMemoryPriority,
                               &MemPrio,
                               sizeof(MemPrio));

if (!Success) {
    ErrorCode = GetLastError();
    fprintf(stderr, "Set thread memory priority failed: %d\n", ErrorCode);
}
```

The following example shows how to call **SetThreadInformation** with **ThreadPowerThrottling** to control the Quality of Service of a thread.

```c
THREAD_POWER_THROTTLING_STATE PowerThrottling;
ZeroMemory(&PowerThrottling, sizeof(PowerThrottling));
PowerThrottling.Version = THREAD_POWER_THROTTLING_CURRENT_VERSION;

//
// EcoQoS
// Turn EXECUTION_SPEED throttling on.
// ControlMask selects the mechanism and StateMask declares which mechanism should be on or off.
//

PowerThrottling.ControlMask = THREAD_POWER_THROTTLING_EXECUTION_SPEED;
PowerThrottling.StateMask = THREAD_POWER_THROTTLING_EXECUTION_SPEED;

SetThreadInformation(GetCurrentThread(),
                     ThreadPowerThrottling,
                     &PowerThrottling,
                     sizeof(PowerThrottling));

//
// HighQoS
// Turn EXECUTION_SPEED throttling off.
// ControlMask selects the mechanism and StateMask is set to zero as mechanisms should be turned off.
//

PowerThrottling.ControlMask = THREAD_POWER_THROTTLING_EXECUTION_SPEED;
PowerThrottling.StateMask = 0;

SetThreadInformation(GetCurrentThread(),
                     ThreadPowerThrottling,
                     &PowerThrottling,
                     sizeof(PowerThrottling));

//
// Let system manage all power throttling. ControlMask is set to 0 as we don’t want
// to control any mechanisms.
//

PowerThrottling.ControlMask = 0;
PowerThrottling.StateMask = 0;

SetThreadInformation(GetCurrentThread(),
                     ThreadPowerThrottling,
                     &PowerThrottling,
                     sizeof(PowerThrottling));
```

## See also

[GetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreadinformation)

[SetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessinformation)