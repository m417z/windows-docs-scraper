# NtQuerySystemInformation function

## Description

[**NtQuerySystemInformation** may be altered or unavailable in future versions of Windows. Applications should use the alternate functions listed in this topic.]

Retrieves the specified system information.

## Parameters

### `SystemInformationClass` [in]

One of the values enumerated in SYSTEM_INFORMATION_CLASS, which indicate the
kind of system information to be retrieved. These include the following values.

#### SystemBasicInformation

Returns the number of processors in the system in a
**SYSTEM_BASIC_INFORMATION** structure. Use the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function instead.

#### SystemCodeIntegrityInformation

Returns a **SYSTEM_CODEINTEGRITY_INFORMATION** structure that can be used to determine the options being enforced by Code Integrity on the system.

#### SystemExceptionInformation

Returns an opaque **SYSTEM_EXCEPTION_INFORMATION** structure that can be used
to generate an unpredictable seed for a random number generator. Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom) function
instead.

#### SystemInterruptInformation

Returns an opaque **SYSTEM_INTERRUPT_INFORMATION** structure that can be used
to generate an unpredictable seed for a random number generator. Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom) function
instead.

#### SystemKernelVaShadowInformation

Returns a **SYSTEM_KERNEL_VA_SHADOW_INFORMATION** structure that can be used to determine the speculation control settings for attacks involving rogue data cache loads (such as CVE-2017-5754).

#### SystemLeapSecondInformation

Returns an opaque **SYSTEM_LEAP_SECOND_INFORMATION** structure that can be used to enable or disable leap seconds system-wide. This setting will persist even after a reboot of the system.

#### SystemLookasideInformation

Returns an opaque **SYSTEM_LOOKASIDE_INFORMATION** structure that can be used
to generate an unpredictable seed for a random number generator. Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom) function
instead.

#### SystemPerformanceInformation

Returns an opaque **SYSTEM_PERFORMANCE_INFORMATION** structure that can be
used to generate an unpredictable seed for a random number generator. Use the
[CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom) function instead.

#### SystemPolicyInformation

Returns policy information in a **SYSTEM_POLICY_INFORMATION** structure. Use the [SLGetWindowsInformation](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetwindowsinformation) function instead to obtain policy information.

#### SystemProcessInformation

Returns an array of **SYSTEM_PROCESS_INFORMATION** structures, one for each
process running in the system.

These structures contain information about the
resource usage of each process, including the number of threads and handles used by the
process, the peak page-file usage, and the number of memory pages that the
process has allocated.

> [!NOTE]
> Whenever possible, **SystemBasicProcessInformation** should be used instead as it is faster, consumes less memory, and doesn't need to synchronize timing data (eliminating processor wakes).

#### SystemBasicProcessInformation

**Available as of Windows 11 version 26100.4770**

Returns an array of **SYSTEM_BASICPROCESS_INFORMATION** structures, one for each
process running in the system.

These structures contain basic information about each process, including the process name,
its process id, and a unique sequence number.

> [!NOTE]
> **SYSTEM_BASICPROCESS_INFORMATION** is identical to **SYSTEM_PROCESS_INFORMATION** except for the **SequenceNumber** member, which is a unique value assigned to each process and used to detect **UniqueProcessId** reuse (instead of process **CreateTime**).

``` syntax
typedef struct _SYSTEM_BASICPROCESS_INFORMATION {
    ULONG NextEntryOffset;
    HANDLE UniqueProcessId;
    HANDLE InheritedFromUniqueProcessId;
    ULONG64 SequenceNumber;
    UNICODE_STRING ImageName;
} SYSTEM_BASICPROCESS_INFORMATION, *PSYSTEM_BASICPROCESS_INFORMATION;
```

Its members are identical to the ones in SYSTEM_PROCESS_INFORMATION,
except for SequenceNumber which is a unique number assigned to each
process that can be used to detect UniqueProcessId reuse instead of
process CreateTime.

#### SystemProcessorPerformanceInformation

Returns an array of **SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION** structures,
one for each processor installed in the system.

#### SystemQueryPerformanceCounterInformation

Returns a **SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION** structure that can be used to determine whether the system requires a kernel transition to retrieve the high-resolution performance counter information through a [QueryPerformanceCounter](https://learn.microsoft.com/windows/desktop/api/profileapi/nf-profileapi-queryperformancecounter) function call.

#### SystemRegistryQuotaInformation

Returns a **SYSTEM_REGISTRY_QUOTA_INFORMATION** structure.

#### SystemSpeculationControlInformation

Returns a **SYSTEM_SPECULATION_CONTROL_INFORMATION** structure that can be used to determine the speculation control settings for attacks involving branch target injection (such as CVE-2017-5715).

Each **SYSTEM_SPECULATION_CONTROL_INFORMATION** structure has the following layout:

``` syntax
typedef struct _SYSTEM_SPECULATION_CONTROL_INFORMATION {
    struct {
        ULONG BpbEnabled : 1;
        ULONG BpbDisabledSystemPolicy : 1;
        ULONG BpbDisabledNoHardwareSupport : 1;
        ULONG SpecCtrlEnumerated : 1;
        ULONG SpecCmdEnumerated : 1;
        ULONG IbrsPresent : 1;
        ULONG StibpPresent : 1;
        ULONG SmepPresent : 1;
        ULONG SpeculativeStoreBypassDisableAvailable : 1;
        ULONG SpeculativeStoreBypassDisableSupported : 1;
        ULONG SpeculativeStoreBypassDisabledSystemWide : 1;
        ULONG SpeculativeStoreBypassDisabledKernel : 1;
        ULONG SpeculativeStoreBypassDisableRequired : 1;
        ULONG BpbDisabledKernelToUser : 1;
        ULONG SpecCtrlRetpolineEnabled : 1;
        ULONG SpecCtrlImportOptimizationEnabled : 1;
        ULONG Reserved : 16;
    } SpeculationControlFlags;
} SYSTEM_SPECULATION_CONTROL_INFORMATION, * PSYSTEM_SPECULATION_CONTROL_INFORMATION;

```

|  |  |
| --- | --- |
| **Flag** | **Meaning** |
| BpbEnabled | If TRUE, speculation control features are supported and enabled. |
| BpbDisabledSystemPolicy | If TRUE, speculation control features are disabled due to system policy. |
| BpbDisabledNoHardwareSupport | If TRUE, speculation control features are disabled due to the absence of hardware support. |
| SpecCtrlEnumerated | If TRUE, the i386/AMD64 IA32_SPEC_CTRL MSR is enumerated by hardware. |
| SpecCmdEnumerated | If TRUE, the i386/AMD64 IA32_SPEC_CMD MSR is enumerated by hardware. |
| IbrsPresent | If TRUE, the i386/AMD64 IBRS MSR is treated as being present. |
| StibpPresent | If TRUE, the i386/AMD64 STIBP MSR is present. |
| SmepPresent | If TRUE, the SMEP feature is present and enabled. |
| SpeculativeStoreBypassDisableAvailable | If TRUE, OS support for SSBD exists. |
| SpeculativeStoreBypassDisableSupported | If TRUE, hardware support for SSBD exists. |
| SpeculativeStoreBypassDisabledSystemWide | If TRUE, SSBD is set systemwide. |
| SpeculativeStoreBypassDisabledKernel | If TRUE, SSBD is set in kernel. |
| SpeculativeStoreBypassDisableRequired | If TRUE, SSBD is needed to prevent speculation attack. |
| BpbDisabledKernelToUser | If TRUE, indirect branch prediction is not flushed on every kernel to user transition. |
| SpecCtrlRetpolineEnabled | If TRUE, Retpoline is enabled for compatible drivers. |
| SpecCtrlImportOptimizationEnabled | If TRUE, Import optimization is enabled. |
| Reserved | Reserved flags. |

#### SystemTimeOfDayInformation

Returns an opaque **SYSTEM_TIMEOFDAY_INFORMATION** structure that can be used
to generate an unpredictable seed for a random number generator. Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom) function
instead.

### `SystemInformation` [in, out]

A pointer to a buffer that receives the requested information. The
size and structure of this information varies depending on the value of the
*SystemInformationClass* parameter:

#### SYSTEM_BASIC_INFORMATION

When the *SystemInformationClass* parameter is
**SystemBasicInformation**, the buffer pointed to by
the *SystemInformation* parameter should be large enough
to hold a single **SYSTEM_BASIC_INFORMATION** structure
having the following layout:

``` syntax
typedef struct _SYSTEM_BASIC_INFORMATION {
    BYTE Reserved1[24];
    PVOID Reserved2[4];
    CCHAR NumberOfProcessors;
} SYSTEM_BASIC_INFORMATION;
```

The **NumberOfProcessors** member contains the number of
processors present in the system. Use [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) instead to retrieve this
information.

The other members of the structure are reserved for internal
use by the operating system.

#### SYSTEM_CODEINTEGRITY_INFORMATION

When the *SystemInformationClass* parameter is
**SystemCodeIntegrityInformation**, the buffer pointed to by
the *SystemInformation* parameter should be large enough
to hold a single **SYSTEM_CODEINTEGRITY_INFORMATION** structure
having the following layout:

``` syntax
typedef struct _SYSTEM_CODEINTEGRITY_INFORMATION {
    ULONG  Length;
    ULONG  CodeIntegrityOptions;
} SYSTEM_CODEINTEGRITY_INFORMATION, *PSYSTEM_CODEINTEGRITY_INFORMATION;
```

The **Length** member contains the size of the structure in bytes. This must be set by the caller.

The **CodeIntegrityOptions** member contains a bitmask to identify code integrity options.

|  |  |  |
| --- | --- | --- |
| **Value** |  | **Meaning** |
| 0x01 | CODEINTEGRITY_OPTION_ENABLED | Enforcement of kernel mode Code Integrity is enabled. |
| 0x02 | CODEINTEGRITY_OPTION_TESTSIGN | Test signed content is allowed by Code Integrity. |
| 0x04 | CODEINTEGRITY_OPTION_UMCI_ENABLED | Enforcement of user mode Code Integrity is enabled. |
| 0x08 | CODEINTEGRITY_OPTION_UMCI_AUDITMODE_ENABLED | Enforcement of user mode Code Integrity is enabled in audit mode. Executables will be allowed to run/load; however, audit events will be recorded. |
| 0x10 | CODEINTEGRITY_OPTION_UMCI_EXCLUSIONPATHS_ENABLED | User mode binaries being run from certain paths are allowed to run even if they fail code integrity checks.<br><br>Exclusion paths are listed in the following registry key in REG_MULTI_SZ format:<br><br>* Key: HKLM\SYSTEM\CurrentControlSet\Control\CI\TRSData<br>* Value: TestPath<br><br>Paths added to this key should be in one of two formats:<br><br>* Path (absolute or relative): \Program Files\TestAutomationPath<br>* Binary (specific): \Program Files\TestAutomationPath\mybinary.exe<br><br>The following paths are restricted and cannot be added as an exclusion:<br><br>* \<br>* \Windows<br>* \Windows\System32<br>* \Program Files<br><br>Built-in Path Exclusions: The following paths are excluded by default. You don't need to specifically add these to path exclusions. This only applies on ARM (Windows Runtime).<br><br>* \Program Files\WTT<br>* \Program Files (x86)\WTT<br>* \WTT\JobsWorkingDir<br>* \Program Files\Common Files\Model Design Environment<br>* \TAEF<br>* \$ASITEMP<br>* \ATDEVXCT1\WTTInstall<br>* \ATUEXCT1\WTTInstall<br>* \ATESCCT1\WTTInstall<br>* \ATCORECT1\WTTInstall<br>* \ATStressCT1\WTTInstall<br>* \ATWSCCT1\WTTInstall<br>* \ATFUNCT1\WTTInstall<br>* \ATIDCCT1\WTTInstall<br>* \ATDNTCT1\WTTInstall |
| 0x20 | CODEINTEGRITY_OPTION_TEST_BUILD | The build of Code Integrity is from a test build. |
| 0x40 | CODEINTEGRITY_OPTION_PREPRODUCTION_BUILD | The build of Code Integrity is from a pre-production build. |
| 0x80 | CODEINTEGRITY_OPTION_DEBUGMODE_ENABLED | The kernel debugger is attached and Code Integrity may allow unsigned code to load. |
| 0x100 | CODEINTEGRITY_OPTION_FLIGHT_BUILD | The build of Code Integrity is from a flight build. |
| 0x200 | CODEINTEGRITY_OPTION_FLIGHTING_ENABLED | Flight signed content is allowed by Code Integrity. Flight signed content is content signed by the Microsoft Development Root Certificate Authority 2014. |
| 0x400 | CODEINTEGRITY_OPTION_HVCI_KMCI_ENABLED | Hypervisor enforced Code Integrity is enabled for kernel mode components. |
| 0x800 | CODEINTEGRITY_OPTION_HVCI_KMCI_AUDITMODE_ENABLED | Hypervisor enforced Code Integrity is enabled in audit mode. Audit events will be recorded for kernel mode components that are not compatible with HVCI. This bit can be set whether CODEINTEGRITY_OPTION_HVCI_KMCI_ENABLED is set or not. |
| 0x1000 | CODEINTEGRITY_OPTION_HVCI_KMCI_STRICTMODE_ENABLED | Hypervisor enforced Code Integrity is enabled for kernel mode components, but in strict mode. |
| 0x2000 | CODEINTEGRITY_OPTION_HVCI_IUM_ENABLED | Hypervisor enforced Code Integrity is enabled with enforcement of Isolated User Mode component signing. |

#### SYSTEM_EXCEPTION_INFORMATION

When the *SystemInformationClass* parameter is
**SystemExceptionInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold an opaque **SYSTEM_EXCEPTION_INFORMATION** structure for use in
generating an unpredictable seed for a random number generator. For this
purpose, the structure has the following layout:

``` syntax
typedef struct _SYSTEM_EXCEPTION_INFORMATION {
    BYTE Reserved1[16];
} SYSTEM_EXCEPTION_INFORMATION;
```

Individual members of the structure are reserved for internal
use by the operating system.

Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom)
function instead to generate cryptographically random data.

#### SYSTEM_INTERRUPT_INFORMATION

When the *SystemInformationClass* parameter is
**SystemInterruptInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold an array that contains as many opaque
**SYSTEM_INTERRUPT_INFORMATION** structures as there are
processors (CPUs) installed on the system. Each structure, or the array as a whole,
can be used to generate an unpredictable seed for a random number generator. For this
purpose, the structure has the following layout:

``` syntax
typedef struct _SYSTEM_INTERRUPT_INFORMATION {
    BYTE Reserved1[24];
} SYSTEM_INTERRUPT_INFORMATION;
```

Individual members of the structure are reserved for internal
use by the operating system.

Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom)
function instead to generate cryptographically random data.

#### SYSTEM_KERNEL_VA_SHADOW_INFORMATION

When the *SystemInformationClass* parameter is
**SystemKernelVaShadowInformation**, the buffer pointed to by
the *SystemInformation* parameter should be large
enough to hold a single **SYSTEM_KERNEL_VA_SHADOW_INFORMATION** structure having the following layout:

``` syntax
typedef struct _SYSTEM_KERNEL_VA_SHADOW_INFORMATION {
    struct {
        ULONG KvaShadowEnabled:1;
        ULONG KvaShadowUserGlobal:1;
        ULONG KvaShadowPcid:1;
        ULONG KvaShadowInvpcid:1;
        ULONG KvaShadowRequired:1;
        ULONG KvaShadowRequiredAvailable:1;
        ULONG InvalidPteBit:6;
        ULONG L1DataCacheFlushSupported:1;
        ULONG L1TerminalFaultMitigationPresent:1;
        ULONG Reserved:18;
    } KvaShadowFlags;
} SYSTEM_KERNEL_VA_SHADOW_INFORMATION, * PSYSTEM_KERNEL_VA_SHADOW_INFORMATION;
```

The **KvaShadowEnabled** indicates whether shadowing is enabled.

The **KvaShadowUserGlobal** indicates that user/global is enabled.

The **KvaShadowPcid** indicates whether PCID is enabled.

The **KvaShadowInvpcid** indicates whether PCID is enabled and whether INVPCID is in use.

The **KvaShadowRequired** indicates whether the hardware is known to be susceptible to CVE-2017-5754.

The **KvaShadowRequiredAvailable** indicates whether the **KvaShadowRequired** field is supported by the operating system.

The **InvalidPteBit** indicates the physical address bit that is used for invalid page table entries, or zero if not set.

The **L1DataCacheFlushSupported** indicates whether the hardware supports L1 data cache flushing.

The **L1TerminalFaultMitigationPresent** indicates whether the operating system supports the L1 terminal fault (CVE-2018-3620) operating system mitigation.

The **Reserved** member of the structure is reserved for internal use by the
operating system.

#### SYSTEM_LEAP_SECOND_INFORMATION

When the *SystemInformationClass* parameter is
**SystemLeapSecondInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold an opaque **SYSTEM_LEAP_SECOND_INFORMATION** structure for use in
enabling or disabling leap seconds system-wide. This setting will persist even after a reboot of the system. For this
purpose, the structure has the following layout:

``` syntax
typedef struct _SYSTEM_LEAP_SECOND_INFORMATION {
    BOOLEAN Enabled;
    ULONG Flags;
} SYSTEM_LEAP_SECOND_INFORMATION
```

The **Flags** field is reserved for future use.

#### SYSTEM_LOOKASIDE_INFORMATION

When the *SystemInformationClass* parameter is
**SystemLookasideInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold an opaque **SYSTEM_LOOKASIDE_INFORMATION** structure for use in
generating an unpredictable seed for a random number generator. For this
purpose, the structure has the following layout:

``` syntax
typedef struct _SYSTEM_LOOKASIDE_INFORMATION {
    BYTE Reserved1[32];
} SYSTEM_LOOKASIDE_INFORMATION;
```

Individual members of the structure are reserved for internal
use by the operating system.

Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom)
function instead to generate cryptographically random data.

#### SYSTEM_PERFORMANCE_INFORMATION

When the *SystemInformationClass* parameter is
**SystemPerformanceInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold an opaque **SYSTEM_PERFORMANCE_INFORMATION** structure for use in
generating an unpredictable seed for a random number generator. For this
purpose, the structure has the following layout:

``` syntax
typedef struct _SYSTEM_PERFORMANCE_INFORMATION {
    BYTE Reserved1[312];
} SYSTEM_PERFORMANCE_INFORMATION;
```

Individual members of the structure are reserved for internal
use by the operating system.

Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom)
function instead to generate cryptographically random data.

#### SYSTEM_POLICY_INFORMATION

When the *SystemInformationClass* parameter is
**SystemPolicyInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold a single **SYSTEM_POLICY_INFORMATION** structure having the following layout:

``` syntax
typedef struct _SYSTEM_POLICY_INFORMATION {
    PVOID Reserved1[2];
    ULONG Reserved2[3];
} SYSTEM_POLICY_INFORMATION;
```

Individual members of the structure are reserved for internal
use by the operating system.

Use the [SLGetWindowsInformation](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetwindowsinformation)
function instead to obtain policy information.

#### SYSTEM_PROCESS_INFORMATION

When the *SystemInformationClass* parameter is
**SystemProcessInformation**, the buffer pointed to by
the *SystemInformation* parameter contains a **SYSTEM_PROCESS_INFORMATION** structure for each process. Each of these structures is immediately followed in memory by one or more **SYSTEM_THREAD_INFORMATION** structures that provide info for each thread in the preceding process. For more information about **SYSTEM_THREAD_INFORMATION**, see the section about this structure in this article.

The buffer pointed to by
the *SystemInformation* parameter should be large enough
to hold an array that contains as many **SYSTEM_PROCESS_INFORMATION** and **SYSTEM_THREAD_INFORMATION** structures as
there are processes and threads running in the system. This size is specified by the *ReturnLength* parameter.

Each **SYSTEM_PROCESS_INFORMATION** structure has the following
layout:

``` syntax
typedef struct _SYSTEM_PROCESS_INFORMATION {
    ULONG NextEntryOffset;
    ULONG NumberOfThreads;
    BYTE Reserved1[48];
    UNICODE_STRING ImageName;
    KPRIORITY BasePriority;
    HANDLE UniqueProcessId;
    HANDLE InheritedFromUniqueProcessId;
    ULONG HandleCount;
    ULONG SessionId;
    PVOID Reserved3;
    SIZE_T PeakVirtualSize;
    SIZE_T VirtualSize;
    ULONG Reserved4;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    PVOID Reserved5;
    SIZE_T QuotaPagedPoolUsage;
    PVOID Reserved6;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivatePageCount;
    LARGE_INTEGER Reserved7[6];
} SYSTEM_PROCESS_INFORMATION;
```

The start of the next item in the array is the address of the previous item plus the value in the **NextEntryOffset** member. For the last item in the array, **NextEntryOffset** is 0.

The **NumberOfThreads** member contains the number of threads in the process.

The **ImageName** member contains the process's image name.

The **BasePriority** member contains the base priority of the process, which is the starting priority for threads created within the associated process.

The **UniqueProcessId** member contains the process's unique process ID.

The **InheritedFromUniqueProcessId** member contains the unique process ID of its parent.

The **HandleCount** member contains the total number
of handles being used by the process in question; use [GetProcessHandleCount](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocesshandlecount) to retrieve this information
instead.

The **SessionId** member contains the session identifier of the process session.

The **PeakVirtualSize** member contains the peak size, in bytes, of the virtual memory used by the process.

The **VirtualSize** member contains the current size, in bytes, of virtual memory used by the process.

The **PeakWorkingSetSize** member contains the peak size, in kilobytes, of the working set of the process.

The **QuotaPagedPoolUsage** member contains the current quota charged to the process for paged pool usage.

The **QuotaNonPagedPoolUsage** member contains the current quota charged to the process for nonpaged pool usage.

The **PagefileUsage** member contains the number of bytes of page file storage in use by the process.

The **PeakPagefileUsage** member contains the
maximum number of bytes of page-file storage used by the process.

The **PrivatePageCount** member contains the number of memory
pages allocated for the use of this process.

You can also retrieve the **PeakWorkingSetSize**, **QuotaPagedPoolUsage**, **QuotaNonPagedPoolUsage**, **PagefileUsage**, **PeakPagefileUsage**, and **PrivatePageCount** information using either the [GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo) function or the [Win32_Process](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/win32-process) class.

The other members of the structure are reserved for internal use by the
operating system.

#### SYSTEM_THREAD_INFORMATION

When the *SystemInformationClass* parameter is
**SystemProcessInformation**, the buffer pointed to by
the *SystemInformation* parameter contains a **SYSTEM_PROCESS_INFORMATION** structure for each process. Each of these structures is immediately followed in memory by one or more **SYSTEM_THREAD_INFORMATION** structures that provide info for each thread in the preceding process. For more information about **SYSTEM_PROCESS_INFORMATION**, see the section about this structure in this article. Each **SYSTEM_THREAD_INFORMATION** structure has the following
layout:

``` syntax
typedef struct _SYSTEM_THREAD_INFORMATION {
    LARGE_INTEGER Reserved1[3];
    ULONG Reserved2;
    PVOID StartAddress;
    CLIENT_ID ClientId;
    KPRIORITY Priority;
    LONG BasePriority;
    ULONG Reserved3;
    ULONG ThreadState;
    ULONG WaitReason;
} SYSTEM_THREAD_INFORMATION;
```

The **StartAddress** member contains the start address of the thread.

The **ClientId** member contains the
ID of the thread and the process owning the thread.

The **Priority** member contains the
dynamic thread priority.

The **BasePriority** member contains the
base thread priority.

The **ThreadState** member contains the current thread state.

The **WaitReason** member contains the reason the thread is waiting.

The other members of the structure are reserved for internal use by the
operating system.

#### SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION

When the *SystemInformationClass* parameter is
**SystemProcessorPerformanceInformation**, the buffer
pointed to by the *SystemInformation* parameter should
be large enough to hold an array that contains as many **SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION** structures as there are processors (CPUs) installed in the system. Each
structure has the following layout:

``` syntax
typedef struct
_SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION {
    LARGE_INTEGER IdleTime;
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER Reserved1[2];
    ULONG Reserved2;
} SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;
```

The **IdleTime** member contains the amount of time
that the system has been idle, in 100-nanosecond intervals.

The **KernelTime** member contains the amount of time
that the system has spent executing in Kernel mode (including all threads in all
processes, on all processors), in 100-nanosecond intervals.

The **UserTime** member contains the amount of time
that the system has spent executing in User mode (including all threads in all
processes, on all processors), in 100-nanosecond intervals.

Use [GetSystemTimes](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getsystemtimes) instead to retrieve this information.

#### SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION

When the *SystemInformationClass* parameter is **SystemQueryPerformanceCounterInformation**, the buffer pointed to by the *SystemInformation* parameter should be large
enough to hold a single **SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION** structure having the following layout:

``` syntax
typedef struct _SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION {
    ULONG                           Version;
    QUERY_PERFORMANCE_COUNTER_FLAGS Flags;
    QUERY_PERFORMANCE_COUNTER_FLAGS ValidFlags;
} SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION;

```

The **Flags** and **ValidFlags** members are **QUERY_PERFORMANCE_COUNTER_FLAGS** structures having the following layout:

``` syntax
typedef struct _QUERY_PERFORMANCE_COUNTER_FLAGS {
    union {
        struct {
            ULONG KernelTransition:1;
            ULONG Reserved:31;
        };
        ULONG ul;
    };
} QUERY_PERFORMANCE_COUNTER_FLAGS;
```

The **ValidFlags** member of the **SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION** structure indicates which bits of the **Flags** member contain valid information. If a kernel transition is required, the **KernelTransition** bit is set in both **ValidFlags** and **Flags**. If a kernel transition is not required, the **KernelTransition** bit is set in **ValidFlags** and clear in **Flags**.

#### SYSTEM_REGISTRY_QUOTA_INFORMATION

When the *SystemInformationClass* parameter is
**SystemRegistryQuotaInformation**, the buffer pointed
to by the *SystemInformation* parameter should be large
enough to hold a single **SYSTEM_REGISTRY_QUOTA_INFORMATION** structure having the
following layout:

``` syntax
typedef struct _SYSTEM_REGISTRY_QUOTA_INFORMATION {
    ULONG RegistryQuotaAllowed;
    ULONG RegistryQuotaUsed;
    PVOID Reserved1;
} SYSTEM_REGISTRY_QUOTA_INFORMATION;
```

The **RegistryQuotaAllowed** member contains the
maximum size, in bytes, that the Registry can attain on this system.

The **RegistryQuotaUsed** member contains the current
size of the Registry, in bytes.

Use [GetSystemRegistryQuota](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemregistryquota) instead to retrieve this
information.

The other member of the structure is reserved for internal use by the
operating system.

#### SYSTEM_SPECULATION_CONTROL_INFORMATION

When the *SystemInformationClass* parameter is
**SystemSpeculationControlInformation**, the buffer pointed to by
the *SystemInformation* parameter should be large
enough to hold a single **SYSTEM_SPECULATION_CONTROL_INFORMATION** structure having the following layout:

``` syntax
typedef struct _SYSTEM_SPECULATION_CONTROL_INFORMATION {
    struct {
         ULONG BpbEnabled:1;
         ULONG BpbDisabledSystemPolicy:1;
         ULONG BpbDisabledNoHardwareSupport:1;
         ULONG SpecCtrlEnumerated:1;
         ULONG SpecCmdEnumerated:1;
         ULONG IbrsPresent:1;
         ULONG StibpPresent:1;
         ULONG SmepPresent:1;
         ULONG SpeculativeStoreBypassDisableAvailable:1;
         ULONG SpeculativeStoreBypassDisableSupported:1;
         ULONG SpeculativeStoreBypassDisabledSystemWide:1;
         ULONG SpeculativeStoreBypassDisabledKernel:1;
         ULONG SpeculativeStoreBypassDisableRequired:1;
         ULONG BpbDisabledKernelToUser:1;
         ULONG Reserved:18;
    } SpeculationControlFlags;

} SYSTEM_SPECULATION_CONTROL_INFORMATION, * PSYSTEM_SPECULATION_CONTROL_INFORMATION;
```

The **BpbEnabled** indicates whether speculation control features are supported and enabled.

The **BpbDisabledSystemPolicy** indicates whether speculation control features are disabled due to system
policy.

The **BpbDisabledNoHardwareSupport** whether speculation control features are disabled due to the absence of hardware support.

The **SpecCtrlEnumerated** whether the IA32_SPEC_CTRL MSR is enumerated by hardware.

The **SpecCmdEnumerated** indicates whether the IA32_SPEC_CMD MSR is enumerated by hardware.

The **IbrsPresent** indicates whether the IBRS MSR is treated as being present.

The **StibpPresent** indicates whether the STIBP MSR is present.

The **SmepPresent** indicates whether the SMEP feature is present and enabled.

The **SpeculativeStoreBypassDisableAvailable** indicates whether the other speculative store bypass disable (SSBD) fields in this data structure are supported by the operating system.

The **SpeculativeStoreBypassDisableSupported** indicates whether hardware support for SSBD is present.

The **SpeculativeStoreBypassDisabledSystemWide** indicates whether SSBD has been enabled system-wide.

The **SpeculativeStoreBypassDisabledKernel** indicates whether SSBD has been disabled for kernel-mode.

The **SpeculativeStoreBypassDisableRequired** indicates whether the hardware is known to be susceptible to speculative store bypass.

The **BpbDisabledKernelToUser** indicates whether indirect branch prediction is flushed on every to kernel to user transition.

The **Reserved** member of the structure is reserved for internal use by the
operating system.

#### SYSTEM_TIMEOFDAY_INFORMATION

When the *SystemInformationClass* parameter is
**SystemTimeOfDayInformation**, the buffer pointed to
by the *SystemInformation* parameter should be large
enough to hold an opaque **SYSTEM_TIMEOFDAY_INFORMATION** structure for use in
generating an unpredictable seed for a random number generator. For this
purpose, the structure has the following layout:

``` syntax
typedef struct _SYSTEM_TIMEOFDAY_INFORMATION {
    BYTE Reserved1[48];
} SYSTEM_TIMEOFDAY_INFORMATION;
```

Individual members of the structure are reserved for internal
use by the operating system.

Use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom)
function instead to generate cryptographically random data.

### `SystemInformationLength` [in]

The size of the buffer pointed to by the *SystemInformation* parameter, in bytes.

### `ReturnLength` [out, optional]

An optional pointer to a location where the function writes the actual size
of the information requested. If that size is less than or equal to the
*SystemInformationLength* parameter, the function copies the information
into the *SystemInformation* buffer; otherwise, it returns an NTSTATUS
error code and returns in *ReturnLength* the size of
buffer required to receive the requested information.

## Return value

Returns an NTSTATUS success or error code.

The
forms and significance of NTSTATUS error codes are listed in the
Ntstatus.h header file available in the DDK, and are described in the DDK documentation.

## Remarks

The **NtQuerySystemInformation** function and the structures
that it returns are internal to the operating system and subject to change from
one release of Windows to another. To maintain the compatibility of your
application, it is better to use the alternate functions previously mentioned instead.

If you do use **NtQuerySystemInformation**, access the function through
[run-time dynamic
linking](https://learn.microsoft.com/windows/desktop/Dlls/using-run-time-dynamic-linking). This gives your code an
opportunity to respond gracefully if the function has been changed or removed
from the operating system. Signature changes, however, may not be
detectable.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## See also

[GetProcessHandleCount](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocesshandlecount)

[GetProcessMemoryInfo](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessmemoryinfo)

[GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[GetSystemRegistryQuota](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemregistryquota)

[GetSystemTimes](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getsystemtimes)