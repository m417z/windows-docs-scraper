# PWLX_ASSIGN_SHELL_PROTECTION callback function

## Description

[The WlxAssignShellProtection function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to assign protection to the shell program of a newly logged-on user.

**Note** GINA DLLs are ignored in Windows Vista.

The shell process should be created in a suspended state, then the **WlxAssignShellProtection** function should be called to apply the correct protection to the shell process.

This function has been superseded by the Windows API
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function.

## Parameters

### `hWlx` [in]

Specifies the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `hToken` [in]

Specifies the handle to a [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `hProcess` [in]

Specifies the handle to the process to modify. The process must be created in the suspended state, and this should be the handle returned in the
[PROCESS_INFORMATION](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) structure.

### `hThread` [in]

Specifies the handle to the initial thread of the process.

## Return value

The **WlxAssignShellProtection** function returns any errors encountered while trying to assign protection.

## Remarks

The Windows API
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function supersedes **WlxAssignShellProtection**. Call **CreateProcessAsUser** in
[WlxActivateUserShell](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxactivateusershell) to create the shell process and set its protections in a single call.

## See also

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[WlxActivateUserShell](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxactivateusershell)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)