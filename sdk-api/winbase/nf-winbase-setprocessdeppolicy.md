# SetProcessDEPPolicy function

## Description

Changes data execution prevention (DEP) and DEP-ATL thunk emulation settings for a 32-bit process.

## Parameters

### `dwFlags` [in]

A **DWORD** that can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| 0 | If the DEP system policy is OptIn or OptOut and DEP is enabled for the process, setting *dwFlags* to 0 disables DEP for the process. |
| **PROCESS_DEP_ENABLE**<br><br>0x00000001 | Enables DEP permanently on the current process. After DEP has been enabled for the process by setting **PROCESS_DEP_ENABLE**, it cannot be disabled for the life of the process. |
| **PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION**<br><br>0x00000002 | Disables DEP-ATL thunk emulation for the current process, which prevents the system from intercepting NX faults that originate from the Active Template Library (ATL) thunk layer. For more information, see the Remarks section. This flag can be specified only with **PROCESS_DEP_ENABLE**. |

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To retrieve error values defined for this function, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetProcessDEPPolicy** function overrides the system DEP policy for the current process unless its DEP policy was specified at process creation. The system DEP policy setting must be OptIn or OptOut. If the system DEP policy is AlwaysOff or AlwaysOn, **SetProcessDEPPolicy** returns an error. After DEP is enabled for a process, subsequent calls to **SetProcessDEPPolicy** are ignored.

DEP policy specified at process creation with the [PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) attribute cannot be changed for the life of the process. In this case, calls to **SetProcessDEPPolicy** fail with **ERROR_ACCESS_DENIED**.

**SetProcessDEPPolicy** is supported for 32-bit processes only. If this function is called on a 64-bit process, it fails with **ERROR_NOT_SUPPORTED**.

Applications written to ATL 7.1 and earlier can attempt to execute code on pages marked as non-executable, which triggers an NX fault and terminates the application. DEP-ATL thunk emulation allows an application that would otherwise trigger an NX fault to run with DEP enabled. For information about ATL versions, see [ATL and MFC Version Numbers](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2008/3z02ch3k(v=vs.90)).

If DEP-ATL thunk emulation is enabled, the system intercepts NX faults, emulates the instructions, and handles the exceptions so the application can continue to run. If DEP-ATL thunk emulation is disabled by setting **PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION** for the process, NX faults are not intercepted, which is useful when testing applications for compatibility with DEP.

The following table summarizes the interactions between system DEP policy, DEP-ATL thunk emulation, and **SetProcessDEPPolicy**.
To get the system DEP policy setting, use the [GetSystemDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemdeppolicy) function.

| System DEP policy | DEP behavior | DEP_ATL thunk emulation behavior | **SetProcessDEPPolicy** behavior |
| --- | --- | --- | --- |
| AlwaysOff<br><br>0 | Disabled for the operating system and all processes. | Not applicable. | Returns an error. |
| AlwaysOn<br><br>1 | Enabled for the operating system and all processes. | Disabled. | Returns an error. |
| OptIn<br><br>2<br><br>Default configuration for Windows client versions. | Enabled for the operating system and disabled for nonsystem processes. Administrators can explicitly enable DEP for selected executable files. | Not applicable. | DEP can be enabled for the current process.<br><br>If DEP is enabled for the current process, DEP-ATL thunk emulation can be disabled for that process. |
| OptOut<br><br>3<br><br>Default configuration for Windows Server versions. | Enabled for the operating system and all processes. Administrators can explicitly disable DEP for selected executable files. | Enabled. | DEP can be disabled for the current process.<br><br>If DEP is disabled for the current process, DEP-ATL thunk emulation is automatically disabled for that process. |

To compile an application that calls this function, define **_WIN32_WINNT** as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Data Execution Prevention](https://learn.microsoft.com/windows/desktop/Memory/data-execution-prevention)

[GetProcessDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessdeppolicy)

[GetSystemDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemdeppolicy)