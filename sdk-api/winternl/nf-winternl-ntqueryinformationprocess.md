# NtQueryInformationProcess function

## Description

[**NtQueryInformationProcess** may be altered or unavailable in future versions of Windows. Applications should use the alternate functions listed in this topic.]

Retrieves information about the specified process.

## Parameters

### `ProcessHandle` [in]

A handle to the process for which information is to be retrieved.

### `ProcessInformationClass` [in]

The type of process information to be retrieved. This parameter can be one of the following values from the **PROCESSINFOCLASS** enumeration.

| Value | Meaning |
| --- | --- |
| **ProcessBasicInformation**<br><br>0 | Retrieves a pointer to a PEB structure that can be used to determine whether the specified process is being debugged, and a unique value used by the system to identify the specified process. <br><br>Use the [CheckRemoteDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent) and [GetProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessid) functions to obtain this information. |
| **ProcessDebugPort**<br><br>7 | Retrieves a **DWORD_PTR** value that is the port number of the debugger for the process. A nonzero value indicates that the process is being run under the control of a ring 3 debugger.<br><br>Use the [CheckRemoteDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent) or [IsDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-isdebuggerpresent) function. |
| **ProcessWow64Information**<br><br>26 | Determines whether the process is running in the WOW64 environment (WOW64 is the x86 emulator that allows Win32-based applications to run on 64-bit Windows).<br><br>Use the [IsWow64Process2](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process2) function to obtain this information. |
| **ProcessImageFileName**<br><br>27 | Retrieves a **UNICODE_STRING** value containing the name of the image file for the process.<br><br>Use the [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamea) or [GetProcessImageFileName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessimagefilenamea) function to obtain this information. |
| **ProcessBreakOnTermination**<br><br>29 | Retrieves a **ULONG** value indicating whether the process is considered critical.<br><br>**Note** This value can be used starting in Windows XP with SP3. Starting in Windows 8.1, [IsProcessCritical](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-isprocesscritical) should be used instead. |
| **ProcessTelemetryIdInformation**<br><br>64 | Retrieves a **[PROCESS_TELEMETRY_ID_INFORMATION_TYPE](https://learn.microsoft.com/windows/win32/devnotes/process_telemetry_id_information_type)** value that contains metadata about a process. |
| **ProcessSubsystemInformation**<br><br>75 | Retrieves a **SUBSYSTEM_INFORMATION_TYPE** value indicating the subsystem type of the process. The buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a single [SUBSYSTEM_INFORMATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/ne-ntddk-_subsystem_information_type) enumeration. |

### `ProcessInformation` [out]

A pointer to a buffer supplied by the calling application into which the function writes the requested information. The size of the information written varies depending on the data type of the *ProcessInformationClass* parameter:

#### PROCESS_BASIC_INFORMATION

When the *ProcessInformationClass* parameter is **ProcessBasicInformation**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a single **PROCESS_BASIC_INFORMATION** structure having the following layout:

``` syntax
typedef struct _PROCESS_BASIC_INFORMATION {
    NTSTATUS ExitStatus;
    PPEB PebBaseAddress;
    ULONG_PTR AffinityMask;
    KPRIORITY BasePriority;
    ULONG_PTR UniqueProcessId;
    ULONG_PTR InheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION;
```

| Field | Meaning |
|-------|---------|
| **ExitStatus** | Contains the same value that [**GetExitCodeProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) returns. However the use of **GetExitCodeProcess** is preferable for clarity and safety. |
| **PebBaseAddress** | Points to a [**PEB**](https://learn.microsoft.com/windows/desktop/api/Winternl/ns-winternl-peb) structure. |
| **AffinityMask** | Can be cast to a **DWORD** and contains the same value that [**GetProcessAffinityMask**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getprocessaffinitymask) returns for the `lpProcessAffinityMask` parameter. |
| **BasePriority** | Contains the process priority as described in [Scheduling Priorities](https://learn.microsoft.com/windows/win32/procthread/scheduling-priorities#base-priority). |
| **UniqueProcessId** | Can be cast to a **DWORD** and contains a unique identifier for this process. We recommend using the [**GetProcessId**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid) function to retrieve this information. |
| **InheritedFromUniqueProcessId** | Can be cast to a **DWORD** and contains a unique identifier for the parent process. |

#### ULONG_PTR

When the *ProcessInformationClass* parameter is **ProcessWow64Information**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a **ULONG_PTR**. If this value is nonzero, the process is running in a WOW64 environment. Otherwise, the process is not running in a WOW64 environment.

Use the [IsWow64Process2](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process2) function to determine whether a process is running in the WOW64 environment.

#### UNICODE_STRING

When the *ProcessInformationClass* parameter is **ProcessImageFileName**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a **UNICODE_STRING** structure as well as the string itself. The string stored in the **Buffer** member is the name of the image file.

If the buffer is too small, the function fails with the STATUS_INFO_LENGTH_MISMATCH error code and the *ReturnLength* parameter is set to the required buffer size.

### `ProcessInformationLength` [in]

The size of the buffer pointed to by the *ProcessInformation* parameter, in bytes.

### `ReturnLength` [out, optional]

A pointer to a variable in which the function returns the size of the requested information. If the function was successful, this is the size of the information written to the buffer pointed to by the *ProcessInformation* parameter (if the buffer was too small, this is the minimum size of buffer needed to receive the information successfully).

## Return value

The function returns an NTSTATUS success or error code.

The forms and significance of NTSTATUS error codes are listed in the Ntstatus.h header file available in the DDK. See [Logging Errors](https://learn.microsoft.com/windows-hardware/drivers/kernel/logging-errors) for more details.

## Remarks

The **NtQueryInformationProcess** function and the structures that it returns are internal to the operating system and subject to change from one release of Windows to another. To maintain the compatibility of your application, it is better to use public functions mentioned in the description of the *ProcessInformationClass* parameter instead.

If you do use **NtQueryInformationProcess**, access the function through [run-time dynamic linking](https://learn.microsoft.com/windows/desktop/Dlls/using-run-time-dynamic-linking). This gives your code an opportunity to respond gracefully if the function has been changed or removed from the operating system. Signature changes, however, may not be detectable.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## See also

[CheckRemoteDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent)

[GetProcessId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessid)

[IsDebuggerPresent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-isdebuggerpresent)

[IsWow64Process](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process)

[IsWow64Process2](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process2)