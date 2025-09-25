# UpdateProcThreadAttribute function

## Description

Updates the specified attribute in a list of attributes for process and thread creation.

## Parameters

### `lpAttributeList` [in, out]

A pointer to an attribute list created by the [InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist) function.

### `dwFlags` [in]

This parameter is reserved and must be zero.

### `Attribute` [in]

The attribute key to update in the attribute list. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY** | The *lpValue* parameter is a pointer to a [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure that specifies the processor group affinity for the new thread.<br><br>Supported in Windows 7 and newer and Windows Server 2008 R2 and newer. |
| **PROC_THREAD_ATTRIBUTE_HANDLE_LIST** | The *lpValue* parameter is a pointer to a list of handles to be inherited by the child process.<br><br>These handles must be created as inheritable handles and must not include pseudo handles such as those returned by the [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) or [GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) function.<br><br>**Note** if you use this attribute, pass in a value of TRUE for the *bInheritHandles* parameter of the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function. |
| **PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR** | The *lpValue* parameter is a pointer to a [PROCESSOR_NUMBER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_number) structure that specifies the ideal processor for the new thread.<br><br>Supported in Windows 7 and newer and Windows Server 2008 R2 and newer. |
| **PROC_THREAD_ATTRIBUTE_MACHINE_TYPE** | The *lpValue* parameter is a pointer to a **WORD** that specifies the machine architecture of the child process.<br><br>Supported in Windows 11 and newer.<br><br>The **WORD** pointed to by *lpValue* can be a value listed on [IMAGE FILE MACHINE CONSTANTS](https://learn.microsoft.com/windows/win32/sysinfo/image-file-machine-constants). |
| **PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY** | The *lpValue* parameter is a pointer to a **DWORD** or **DWORD64** that specifies the exploit mitigation policy for the child process. Starting in Windows 10, version 1703, this parameter can also be a pointer to a two-element **DWORD64** array.<br><br>The specified policy overrides the policies set for the application and the system and cannot be changed after the child process starts running. <br><br>The **DWORD** or **DWORD64** pointed to by *lpValue* can be one or more of the values listed in the remarks.<br><br>Supported in Windows 7 and newer and Windows Server 2008 R2 and newer. |
| **PROC_THREAD_ATTRIBUTE_PARENT_PROCESS** | The *lpValue* parameter is a pointer to the handle of a process to use (instead of the calling process) as the parent for the process being created. The handle for the process used must have the **PROCESS_CREATE_PROCESS** access right.<br><br>Attributes inherited from the specified process include handles, the device map, processor affinity, priority, quotas, the process token, and job object. (Note that some attributes such as the debug port will come from the creating process, not the process specified by this handle.) |
| **PROC_THREAD_ATTRIBUTE_PREFERRED_NODE** | The *lpValue* parameter is a pointer to the node number of the preferred NUMA node for the new process.<br><br>Supported in Windows 7 and newer and Windows Server 2008 R2 and newer. |
| **PROC_THREAD_ATTRIBUTE_UMS_THREAD** | The *lpValue* parameter is a pointer to a [UMS_CREATE_THREAD_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ums_create_thread_attributes) structure that specifies a user-mode scheduling (UMS) thread context and a UMS completion list to associate with the thread. <br><br>After the UMS thread is created, the system queues it to the specified completion list. The UMS thread runs only when an application's UMS scheduler retrieves the UMS thread from the completion list and selects it to run. For more information, see [User-Mode Scheduling](https://learn.microsoft.com/windows/desktop/ProcThread/user-mode-scheduling).<br><br>Supported in Windows 7 and newer and Windows Server 2008 R2 and newer.<br><br>Not supported in Windows 11 and newer (see [User-Mode Scheduling](https://learn.microsoft.com/windows/win32/procthread/user-mode-scheduling)). |
| **PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES** | The *lpValue* parameter is a pointer to a [SECURITY_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_capabilities) structure that defines the security capabilities of an app container. If this attribute is set the new process will be created as an AppContainer process.<br><br>Supported in Windows 8 and newer and Windows Server 2012 and newer. |
| **PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL** | The *lpValue* parameter is a pointer to a **DWORD** value of **PROTECTION_LEVEL_SAME**. This specifies the protection level of the child process to be the same as the protection level of its parent process.<br><br>Supported in Windows 8.1 and newer and Windows Server 2012 R2 and newer. |
| **PROC_THREAD_ATTRIBUTE_CHILD_PROCESS_POLICY** | The *lpValue* parameter is a pointer to a **DWORD** value that specifies the child process policy. The policy specifies whether to allow a child process to be created.<br><br>For information on the possible values for the **DWORD** to which *lpValue* points, see Remarks.<br><br>Supported in Windows 10 and newer and Windows Server 2016 and newer. |
| **PROC_THREAD_ATTRIBUTE_DESKTOP_APP_POLICY** | This attribute is relevant only to win32 applications that have been converted to UWP packages by using the [Desktop Bridge](https://developer.microsoft.com/windows/bridges/desktop). <br><br>The *lpValue* parameter is a pointer to a **DWORD** value that specifies the desktop app policy. The policy specifies whether descendant processes should continue to run in the desktop environment.<br><br>For information about the possible values for the **DWORD** to which *lpValue* points, see Remarks.<br><br>Supported in Windows 10 Version 1703 and newer and Windows Server Version 1709 and newer. |
| **PROC_THREAD_ATTRIBUTE_JOB_LIST** | The *lpValue* parameter is a pointer to a list of job handles to be assigned to the child process, in the order specified.<br><br>Supported in Windows 10 and newer and Windows Server 2016 and newer. |
| **PROC_THREAD_ATTRIBUTE_ENABLE_OPTIONAL_XSTATE_FEATURES** | The *lpValue* parameter is a pointer to a **DWORD64** value that specifies the set of optional XState features to enable for the new thread.<br><br>Supported in Windows 11 and newer and Windows Server 2022 and newer. |

### `lpValue` [in]

A pointer to the attribute value. **This value must persist until the attribute list is destroyed using the [DeleteProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-deleteprocthreadattributelist) function**.

### `cbSize` [in]

The size of the attribute value specified by the *lpValue* parameter.

### `lpPreviousValue` [out, optional]

This parameter is reserved and must be NULL.

### `lpReturnSize` [in, optional]

This parameter is reserved and must be NULL.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An attribute list is an opaque structure that consists of a series of key/value pairs, one for each attribute. A process can update only the attribute keys described in this topic.

The **DWORD** or **DWORD64** pointed to by *lpValue* can be one or more of the following values when you specify **PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY** for the *Attribute* parameter:

**PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE** (0x00000001)Enables data execution prevention (DEP) for the child process. For more information, see [Data Execution Prevention](https://learn.microsoft.com/windows/desktop/Memory/data-execution-prevention).

**PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE** (0x00000002)Enables DEP-ATL thunk emulation for the child process. DEP-ATL thunk emulation causes the system to intercept NX faults that originate from the Active Template Library (ATL) thunk layer. This value can be specified only with PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE.

**PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE** (0x00000004)Enables structured exception handler overwrite protection (SEHOP) for the child process. SEHOP blocks exploits that use the structured exception handler (SEH) overwrite technique.

**Windows 7, Windows Server 2008 R2, Windows Server 2008 and Windows Vista:** The following values are not supported until Windows 8 and Windows Server 2012.

The force Address Space Layout Randomization (ASLR) policy, if enabled, forcibly rebases images that are not dynamic base compatible by acting as though an image base collision happened at load time. If relocations are required, images that do not have a base relocation section will not be loaded.

The following mitigation options are available for mandatory ASLR policy:

**PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON** (0x00000001 << 8)

**PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF** (0x00000002 << 8)

**PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS** (0x00000003 << 8)

The heap terminate on corruption policy, if enabled, causes the heap to terminate if it becomes corrupt. Note that 'always off' does not override the default opt-in for binaries with current subsystem versions set in the image header. Heap terminate on corruption is user mode enforced.

The following mitigation options are available for heap terminate on corruption policy:

**PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON** (0x00000001 << 12)

**PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF** (0x00000002 << 12)

The bottom-up randomization policy, which includes stack randomization options, causes a random location to be used as the lowest user address.

The following mitigation options are available for the bottom-up randomization policy:

**PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON** (0x00000001 << 16)

**PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF** (0x00000002 << 16)

The high-entropy bottom-up randomization policy, if enabled, causes up to 1TB of bottom-up variance to be used. Note that high-entropy bottom-up randomization is effective if and only if bottom-up ASLR is also enabled; high-entropy bottom-up randomization is only meaningful for native 64-bit processes.

The following mitigation options are available for the high-entropy bottom-up randomization policy:

**PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON** (0x00000001 << 20)

**PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF**  (0x00000002 << 20)

The strict handle checking enforcement policy, if enabled, causes an exception to be raised immediately on a bad handle reference. If this policy is not enabled, a failure status will be returned from the handle reference instead.

The following mitigation options are available for the strict handle checking enforcement policy:

**PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON** (0x00000001 << 24)

**PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF** (0x00000002 << 24)

The Win32k system call disable policy, if enabled, prevents a process from making Win32k calls.

The following mitigation options are available for the Win32k system call disable policy:

**PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON** (0x00000001 << 28)

**PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF** (0x00000002 << 28)

The Extension Point Disable policy, if enabled, prevents certain built-in third party extension points from being used. This policy blocks the following extension points:

* AppInit DLLs
* Winsock Layered Service Providers (LSPs)
* Global Windows Hooks
* Legacy Input Method Editors (IMEs)

Local hooks still work with the Extension Point Disable policy enabled. This behavior is used to prevent legacy extension points from being loaded into a process that does not use them.

The following mitigation options are available for the extension point disable policy:

**PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON** (0x00000001 << 32)

**PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF** (0x00000002 << 32)

The [Control Flow Guard (CFG) policy](https://learn.microsoft.com/windows/desktop/SecBP/control-flow-guard), if turned on, places additional restrictions on indirect calls in code that has been built with CFG enabled.

The following mitigation options are available for controlling the CFG policy:

* **PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_MASK** (0x00000003ui64 << 40)
* **PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_DEFER** (0x00000000ui64 << 40)
* **PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_ON** (0x00000001ui64 << 40)
* **PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_OFF** (0x00000002ui64 << 40)
* **PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_EXPORT_SUPPRESSION** (0x00000003ui64 << 40)

In addition, the following policy can be specified to enforce that EXEs/DLLs must enable CFG. If an attempt is made to load an EXE/DLL that does not enable CFG, the load will fail:

* **PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_MASK** (0x00000003ui64 << 8)
* **PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_DEFER** (0x00000000ui64 << 8)
* **PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_ALWAYS_ON** (0x00000001ui64 << 8)
* **PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_ALWAYS_OFF** (0x00000002ui64 << 8)
* **PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_RESERVED** (0x00000003ui64 << 8)

The dynamic code policy, if turned on, prevents a process from generating dynamic code or modifying executable code.

The following mitigation options are available for the dynamic code policy:

**PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK** (0x00000003ui64 << 36)

**PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER** (0x00000000ui64 << 36)

**PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON** (0x00000001ui64 << 36)

**PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF** (0x00000002ui64 << 36)

**PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON_ALLOW_OPT_OUT** (0x00000003ui64 << 36)

The binary signature policy requires EXEs/DLLs to be properly signed.

The following mitigation options are available for the binary signature policy:

* **PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK** (0x00000003ui64 << 44)
* **PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER** (0x00000000ui64 << 44)
* **PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON** (0x00000001ui64 << 44)
* **PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF** (0x00000002ui64 << 44)
* **PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALLOW_STORE** (0x00000003ui64 << 44)

The font loading prevention policy for the process determines whether non-system fonts can be loaded for a process. When the policy is turned on, the process is prevented from loading non-system fonts.

The following mitigation options are available for the font loading prevention policy:

**PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_MASK** (0x00000003ui64 << 48)

**PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_DEFER** (0x00000000ui64 << 48)

**PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_ALWAYS_ON** (0x00000001ui64 << 48)

**PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_ALWAYS_OFF** (0x00000002ui64 << 48)

**PROCESS_CREATION_MITIGATION_POLICY_AUDIT_NONSYSTEM_FONTS** (0x00000003ui64 << 48)

The image loading policy of the process determines the types of executable images that can be mapped into the process. When the policy is turned on, images cannot be loaded from some locations, such as remove devices or files that have the Low mandatory label.

The following mitigation options are available for the image loading policy:

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_MASK** (0x00000003ui64 << 52)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_DEFER** (0x00000000ui64 << 52)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_ALWAYS_ON** (0x00000001ui64 << 52)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_ALWAYS_OFF** (0x00000002ui64 << 52)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_RESERVED** (0x00000003ui64 << 52)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_MASK** (0x00000003ui64 << 56)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_DEFER** (0x00000000ui64 << 56)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_ALWAYS_ON** (0x00000001ui64 << 56)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_ALWAYS_OFF** (0x00000002ui64 << 56)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_RESERVED** (0x00000003ui64 << 56)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_MASK** (0x00000003ui64 << 60)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_DEFER** (0x00000000ui64 << 60)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_ALWAYS_ON** (0x00000001ui64 << 60)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_ALWAYS_OFF** (0x00000002ui64 << 60)

**PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_RESERVED** (0x00000003ui64 << 60)

**Windows 10, version 1709:** The following value is available only in Windows 10, version 1709 or later and only with the January 2018 Windows security updates and any applicable firmware updates from the OEM device manufacturer. See [Windows Client Guidance for IT Pros to protect against speculative execution side-channel vulnerabilities](https://support.microsoft.com/help/4073119/protect-against-speculative-execution-side-channel-vulnerabilities-in).

**PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_INDIRECT_BRANCH_PREDICTION_ALWAYS_ON**  (0x00000001ui64 << 16)This flag can be used by processes to protect against sibling hardware threads (hyperthreads) from interfering with indirect branch predictions. Processes that have sensitive information in their address space should consider enabling this flag to protect against attacks involving indirect branch prediction (such as CVE-2017-5715).

**Windows 10, version 1809:** The following value is available only in Windows 10, version 1809 or later.

**PROCESS_CREATION_MITIGATION_POLICY2_SPECULATIVE_STORE_BYPASS_DISABLE_ALWAYS_ON**  (0x00000001ui64 << 24)This flag can be used by processes to disable the Speculative Store Bypass (SSB) feature of CPUs that may be vulnerable to speculative execution side channel attacks involving SSB (CVE-2018-3639). This flag is only supported by certain Intel CPUs that have the requisite hardware features. On CPUs that do not support this feature, the flag has no effect.

**Windows 10, version 2004:** The following values are available only in Windows 10, version 2004 or later.

Hardware-enforced Stack Protection (HSP) is a hardware-based security feature where the CPU verifies function return addresses at runtime by employing a shadow stack mechanism.
For user-mode HSP, the default mode is compatibility mode, where only shadow stack violations occurring in modules that are considered compatible with shadow stacks (CETCOMPAT) are fatal.
In strict mode, all shadow stack violations are fatal.

The following mitigation options are available for user-mode Hardware-enforced Stack Protection and related features:

**PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_ALWAYS_ON**  (0x00000001ui64 << 28)

**PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_ALWAYS_OFF**  (0x00000002ui64 << 28)

**PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_STRICT_MODE**  (0x00000003ui64 << 28)

Instruction Pointer validation:

**PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_ALWAYS_ON**  (0x00000001ui64 << 32)

**PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_ALWAYS_OFF**  (0x00000002ui64 << 32)

**PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_RELAXED_MODE**  (0x00000003ui64 << 32)

Blocking the load of non-CETCOMPAT/non-EHCONT binaries:

**PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_ALWAYS_ON**  (0x00000001ui64 << 36)

**PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_ALWAYS_OFF**  (0x00000002ui64 << 36)

**PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_NON_EHCONT**  (0x00000003ui64 << 36)

Restricting certain HSP APIs used to specify security properties of dynamic code to only be callable from outside of the process:

**PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_ALWAYS_ON**  (0x00000001ui64 << 48)

**PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_ALWAYS_OFF**  (0x00000002ui64 << 48)

The FSCTL system call disable policy, if enabled, prevents a process from making NtFsControlFile calls.
The following mitigation options are available for the FSCTL system call disable policy:

**PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_ALWAYS_ON**  (0x00000001ui64 << 56)

**PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_ALWAYS_OFF**  (0x00000002ui64 << 56)

The **DWORD** pointed to by *lpValue* can be one or more of the following values when you specify **PROC_THREAD_ATTRIBUTE_CHILD_PROCESS_POLICY** for the *Attribute* parameter:

**PROCESS_CREATION_CHILD_PROCESS_RESTRICTED** 0x01

The process being created is not allowed to create child processes. This restriction becomes a property of the token as which the process runs. It should be noted that this restriction is only effective in sandboxed applications (such as AppContainer) which ensure privileged process handles are not accessible to the process. For example, if a process restricting child process creation is able to access another process handle with PROCESS_CREATE_PROCESS or PROCESS_VM_WRITE access rights, then it may be possible to bypass the child process restriction.

**PROCESS_CREATION_CHILD_PROCESS_OVERRIDE** 0x02

The process being created is allowed to create a child process, if it would otherwise be restricted. You can only specify this value if the process that is creating the new process is not restricted.

The **DWORD** pointed to by *lpValue* can be one or more of the following values when you specify **PROC_THREAD_ATTRIBUTE_DESKTOP_APP_POLICY** for the *Attribute* parameter:

**PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_ENABLE_PROCESS_TREE** 0x01

The process being created will create any child processes outside of the desktop app runtime environment. This behavior is the default for processes for which no policy has been set.

**PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_DISABLE_PROCESS_TREE** 0x02

The process being created will create any child processes inside of the desktop app runtime environment. This policy is inherited by the descendant processes until it is overridden by creating a process with **PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_ENABLE_PROCESS_TREE**.

**PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_OVERRIDE** 0x04

The process being created will run inside the desktop app runtime environment. This policy applies only to the process being created, not its descendants..

In order to launch the child process with the same protection level as the parent, the parent process must specify the **PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL** attribute for the child process. This can be used for both protected and unprotected processes. For example, when this flag is used by an unprotected process, the system will launch a child process at unprotected level. The **CREATE_PROTECTED_PROCESS** flag must be specified in both cases.

The following example launches a child process with the same protection level as the parent process:

```cpp
DWORD ProtectionLevel = PROTECTION_LEVEL_SAME;
SIZE_T AttributeListSize;

STARTUPINFOEXW StartupInfoEx = { 0 };

StartupInfoEx.StartupInfo.cb = sizeof(StartupInfoEx);

InitializeProcThreadAttributeList(NULL, 1, 0, &AttributeListSize)

StartupInfoEx.lpAttributeList = (LPPROC_THREAD_ATTRIBUTE_LIST) HeapAlloc(
    GetProcessHeap(),
    0,
    AttributeListSize
    );

if (InitializeProcThreadAttributeList(StartupInfoEx.lpAttributeList,
                                      1,
                                      0,
                                      &AttributeListSize) == FALSE)
{
    Result = GetLastError();
    goto exitFunc;
}

if (UpdateProcThreadAttribute(StartupInfoEx.lpAttributeList,
                              0,
                              PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL,
                              &ProtectionLevel,
                              sizeof(ProtectionLevel),
                              NULL,
                              NULL) == FALSE)
{
    Result = GetLastError();
    goto exitFunc;
}

PROCESS_INFORMATION ProcessInformation = { 0 };

if (CreateProcessW(ApplicationName,
                   CommandLine,
                   ProcessAttributes,
                   ThreadAttributes,
                   InheritHandles,
                   EXTENDED_STARTUPINFO_PRESENT | CREATE_PROTECTED_PROCESS,
                   Environment,
                   CurrentDirectory,
                   (LPSTARTUPINFOW)&StartupInfoEx,
                   &ProcessInformation) == FALSE)
{
    Result = GetLastError();
    goto exitFunc;
}
```

## See also

[DeleteProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-deleteprocthreadattributelist)

[InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)