# QueryThreadCycleTime function

## Description

Retrieves the cycle time for the specified thread.

## Parameters

### `ThreadHandle` [in]

A handle to the thread. The handle must have the THREAD_QUERY_INFORMATION or THREAD_QUERY_LIMITED_INFORMATION access right. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/win32/procthread/thread-security-and-access-rights).

### `CycleTime` [out]

The number of CPU clock cycles used by the thread. This value includes cycles spent in both user mode and kernel mode.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To enumerate the threads of the process, use the [Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first) and [Thread32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32next) functions. To get the thread handle for a thread identifier, use the
[OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function.

Do not attempt to convert the CPU clock cycles returned by **QueryThreadCycleTime** to elapsed time. This function uses timer services provided by the CPU, which can vary in implementation. For example, some CPUs will vary the frequency of the timer when changing the frequency at which the CPU runs and others will leave it at a fixed rate. The behavior of each CPU is described in the documentation provided by the CPU vendor.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later.

## See also

[QueryIdleProcessorCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryidleprocessorcycletime)

[QueryProcessCycleTime](https://learn.microsoft.com/windows/desktop/api/realtimeapiset/nf-realtimeapiset-queryprocesscycletime)