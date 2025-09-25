# GetThreadInformation function

## Description

Retrieves information about the specified thread.

## Parameters

### `hThread` [in]

A handle to the thread. The handle must have THREAD_QUERY_INFORMATION access rights. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `ThreadInformationClass` [in]

The class of information to retrieve. This value can be **ThreadMemoryPriority**, **ThreadAbsoluteCpuPriority** or **ThreadDynamicCodePolicy**.

> [!NOTE]
> **ThreadDynamicCodePolicy** is supported in Windows Server 2016 and newer, Windows 10 LTSB 2016 and newer, and Windows 10 version 1607 and newer.

### `ThreadInformation`

Pointer to a structure to receive the type of information specified by the *ThreadInformationClass* parameter.

If the *ThreadInformationClass* parameter is **ThreadMemoryPriority**, this parameter must point to a **MEMORY_PRIORITY_INFORMATION** structure.

If the *ThreadInformationClass* parameter is **ThreadAbsoluteCpuPriority**, this parameter must point to a **LONG**.

If the *ThreadInformationClass* parameter is **ThreadDynamicCodePolicy**, this parameter must point to a **DWORD**.

### `ThreadInformationSize` [in]

The size in bytes of the structure specified by the *ThreadInformation* parameter.

If the *ThreadInformationClass* parameter is **ThreadMemoryPriority**, this parameter must be `sizeof(MEMORY_PRIORITY_INFORMATION)`.

If the *ThreadInformationClass* parameter is **ThreadAbsoluteCpuPriority**, this parameter must be `sizeof(LONG)`.

If the *ThreadInformationClass* parameter is **ThreadDynamicCodePolicy**, this parameter must be `sizeof(DWORD)`.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessinformation), [SetThreadInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadinformation)