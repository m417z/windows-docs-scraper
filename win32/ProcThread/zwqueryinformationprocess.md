# ZwQueryInformationProcess function

\[**ZwQueryInformationProcess** may be altered or unavailable in future versions of Windows. Applications should use the alternate functions listed in this topic.\]

Retrieves information about the specified process.

## Parameters

*ProcessHandle* \[in\]

A handle to the process for which information is to be retrieved.

*ProcessInformationClass* \[in\]

The type of process information to be retrieved. This parameter can be one of the following values from the **PROCESSINFOCLASS** enumeration.

| Value | Meaning |
|-------|---------|
|

**ProcessBasicInformation**

0

| Retrieves a pointer to a PEB structure that can be used to determine whether the specified process is being debugged, and a unique value used by the system to identify the specified process. <br> It is best to use the [**CheckRemoteDebuggerPresent**](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent) and [**GetProcessId**](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessid) functions to obtain this information.<br> |
|

**ProcessDebugPort**

7

| Retrieves a **DWORD_PTR** value that is the port number of the debugger for the process. A nonzero value indicates that the process is being run under the control of a ring 3 debugger.<br> It is best to use the [**CheckRemoteDebuggerPresent**](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-checkremotedebuggerpresent) or [**IsDebuggerPresent**](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-isdebuggerpresent) function.<br> |
|

**ProcessWow64Information**

26

| Determines whether the process is running in the WOW64 environment (WOW64 is the x86 emulator that allows Win32-based applications to run on 64-bit Windows).<br> It is best to use the [**IsWow64Process**](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process) function to obtain this information.<br> |
|

**ProcessImageFileName**

27

| Retrieves a **UNICODE_STRING** value containing the name of the image file for the process.<br> |
| **ProcessBreakOnTermination**<br>29<br> | Retrieves a **ULONG** value indicating whether the process is considered critical.<br> **Note:** This value can be used starting in Windows XP with SP3. Starting in Windows 8.1, [**IsProcessCritical**](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-isprocesscritical) should be used instead.<br> |
|

**ProcessProtectionInformation**

61

| Retrieves a BYTE value indicating the type of protected process and the protected process signer.<br>
*ProcessInformation* \[out\]

A pointer to a buffer supplied by the calling application into which the function writes the requested information. The size of the information written varies depending on the value of the *ProcessInformationClass* parameter:

PROCESS\_BASIC\_INFORMATION

When the *ProcessInformationClass* parameter is **ProcessBasicInformation**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a single **PROCESS\_BASIC\_INFORMATION** structure having the following layout:

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
| **ExitStatus** | Contains the same value that [**GetExitCodeProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) would return. However the use of **GetExitCodeProcess** is preferable for clarity and safety. |
| **PebBaseAddress** | Points to a [**PEB**](https://learn.microsoft.com/windows/desktop/api/Winternl/ns-winternl-peb) structure. |
| **AffinityMask** | Can be cast to a **DWORD** and contains the same value that [**GetProcessAffinityMask**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getprocessaffinitymask) would return for the `lpProcessAffinityMask` parameter. |
| **BasePriority** | Contains the process priority as described in [Scheduling Priorities](https://learn.microsoft.com/windows/win32/procthread/scheduling-priorities#base-priority). |
| **UniqueProcessId** | Can be cast to a **DWORD** and contains a unique identifier for this process. It is best to use the [**GetProcessId**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid) function to retrieve this information. |
| **InheritedFromUniqueProcessId** | Can be cast to a **DWORD** and contains a unique identifier for the parent process. |

ULONG\_PTR

When the *ProcessInformationClass* parameter is **ProcessWow64Information**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a **ULONG\_PTR**. If this value is nonzero, the process is running in a WOW64 environment; otherwise, if the value is equal to zero, the process is not running in a WOW64 environment.

It is best to use the [**IsWow64Process**](https://learn.microsoft.com/windows/win32/api/wow64apiset/nf-wow64apiset-iswow64process) function to determine whether a process is running in the WOW64 environment.

UNICODE\_STRING

When the *ProcessInformationClass* parameter is **ProcessImageFileName**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a **UNICODE\_STRING** structure as well as the string itself. The string stored in the **Buffer** member is the name of the image file.

If the buffer is too small, the function fails with the STATUS\_INFO\_LENGTH\_MISMATCH error code and the *ReturnLength* parameter is set to the required buffer size.

PS_PROTECTION

When the *ProcessInformationClass* parameter is **ProcessProtectionInformation**, the buffer pointed to by the *ProcessInformation* parameter should be large enough to hold a single **PS_PROTECTION** structure having the following layout:

``` syntax
typedef struct _PS_PROTECTION {
    union {
        UCHAR Level;
        struct {
            UCHAR Type   : 3;
            UCHAR Audit  : 1;                  // Reserved
            UCHAR Signer : 4;
        };
    };
} PS_PROTECTION, *PPS_PROTECTION;
```

The first 3 bits contain the type of protected process:

``` syntax
typedef enum _PS_PROTECTED_TYPE {
    PsProtectedTypeNone = 0,
    PsProtectedTypeProtectedLight = 1,
    PsProtectedTypeProtected = 2
} PS_PROTECTED_TYPE, *PPS_PROTECTED_TYPE;
```

The top 4 bits contain the protected process signer:

``` syntax
typedef enum _PS_PROTECTED_SIGNER {
    PsProtectedSignerNone = 0,
    PsProtectedSignerAuthenticode,
    PsProtectedSignerCodeGen,
    PsProtectedSignerAntimalware,
    PsProtectedSignerLsa,
    PsProtectedSignerWindows,
    PsProtectedSignerWinTcb,
    PsProtectedSignerWinSystem,
    PsProtectedSignerApp,
    PsProtectedSignerMax
} PS_PROTECTED_SIGNER, *PPS_PROTECTED_SIGNER;
```

*ProcessInformationLength* \[in\]

The size of the buffer pointed to by the *ProcessInformation* parameter, in bytes.

*ReturnLength* \[out, optional\]

A pointer to a variable in which the function returns the size of the requested information. If the function was successful, this is the size of the information written to the buffer pointed to by the *ProcessInformation* parameter, but if the buffer was too small, this is the minimum size of buffer needed to receive the information successfully.

## Return value

Returns an NTSTATUS success or error code.

The forms and significance of NTSTATUS error codes are listed in the Ntstatus.h header file available in the DDK, and are described in the DDK documentation under Kernel-Mode Driver Architecture / Design Guide / Driver Programming Techniques / Logging Errors.

## Remarks

The **ZwQueryInformationProcess** function and the structures that it returns are internal to the operating system and subject to change from one release of Windows to another. To maintain the compatibility of your application, it is better to use public functions mentioned in the description of the *ProcessInformationClass* parameter instead.

If you do use **ZwQueryInformationProcess**, access the function through [run-time dynamic linking](https://learn.microsoft.com/windows/win32/dlls/using-run-time-dynamic-linking). This gives your code an opportunity to respond gracefully if the function has been changed or removed from the operating system. Signature changes, however, may not be detectable.

This function has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client\