# _OB_PRE_CREATE_HANDLE_INFORMATION structure

## Description

The **OB_PRE_CREATE_HANDLE_INFORMATION** structure provides information to an [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine about a thread or process handle that is being opened.

## Members

### `DesiredAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the access rights to grant for the handle. By default, this member equals *OriginalDesiredAccess*, but the *ObjectPreCallback* routine can modify this value to restrict the access that is granted.

Drivers can use the following flags for handles to processes:

| Flag | Allowed operations |
| --- | --- |
| PROCESS_CREATE_PROCESS | Create a new child process of the process. |
| PROCESS_CREATE_THREAD | Create a new thread in the context of the process. |
| PROCESS_DUP_HANDLE | Duplicate handles to or from the context of the process, such as by calling the user-mode **DuplicateHandle** routine. |
| PROCESS_SET_QUOTA | Set the working set size for the process, such as by calling the user-mode **SetProcessWorkingSetSize** routine. |
| PROCESS_SET_INFORMATION | Modify process settings, such as by calling the user-mode **SetPriorityClass** routine. |
| PROCESS_SUSPEND_RESUME | Suspend or resume the process. |
| PROCESS_TERMINATE | Terminate the process, such as by calling the user-mode **TerminateProcess** routine.. |
| PROCESS_VM_OPERATION | Modify the address space of the process, such as by calling the user-mode **WriteProcessMemory** and **VirtualProtectEx** routines. |
| PROCESS_VM_WRITE | Write to the address space of the process, such as by calling the user-mode **WriteProcessMemory** routine. |

Drivers can use the following flags for handles to threads:

| Flag | Allowed operations |
| --- | --- |
| THREAD_DIRECT_IMPERSONATION | Enable a server thread to impersonate one of its clients. |
| THREAD_IMPERSONATE | Impersonate the operating system's anonymous logon token, such as by calling the user-mode **ImpersonateAnonymousToken** routine. |
| THREAD_SET_CONTEXT | Modify the thread's execution context, such as by calling the user-mode **SetThreadContext** routine. |
| THREAD_SET_INFORMATION | Modify thread settings, such as by calling the user-mode **SetThreadIdealProcessor** routine. The operations that are permitted by this access right are a superset of those that are permitted by the THREAD_SET_LIMITED_INFORMATION access right. |
| THREAD_SET_LIMITED_INFORMATION | Modify a limited set of thread settings, such as by calling the user-mode **SetThreadAffinityMask** and **SetThreadPriorityBoost** routines. |
| THREAD_SET_THREAD_TOKEN | Modify properties of the thread's impersonation token, such as by calling the user-mode **SetTokenInformation** routine. |
| THREAD_SUSPEND_RESUME | Suspend or resume the thread, such as by calling the user-mode **SuspendThread** and **ResumeThread** routines. |
| THREAD_TERMINATE | Terminate the thread, such as by calling the user-mode **TerminateThread** routine. |

### `OriginalDesiredAccess`

An ACCESS_MASK value that specifies the original access that was requested for the handle.

## Remarks

You can never add access rights beyond what is specified in the **DesiredAccess** member. If the access right is listed as a modifiable flag, the access right can be removed.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)