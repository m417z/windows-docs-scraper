# WlxActivateUserShell function

## Description

[The WlxActivateUserShell function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Activates the user shell program.

The **WlxActivateUserShell** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function following a successful logon to request that the GINA activate the shell program of the user.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. This is the context value that the GINA returns when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `pszDesktopName` [in]

A pointer to a null-terminated wide character string that specifies the name of the desktop where the shell will start. Pass this string to the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) or
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function through the **lpDesktop** member of the
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure.

### `pszMprLogonScript` [in]

A pointer to a null-terminated wide character string that specifies any script names returned from the network provider DLLs. Network provider DLLs can return scripts to be executed during logon; however, the GINA may ignore them.

### `pEnvironment` [in]

Specifies the initial environment variables for the process. Winlogon creates a copy of the environment and hands it off to the GINA. The GINA can modify this environment before using it to initialize the user's shell. The GINA should call the [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) function to free the memory allocated for *pEnvironment*.

## Return value

If the function successfully starts a shell process, the function returns **TRUE**.

If the function fails, it returns **FALSE**. When **FALSE** is returned, Winlogon cancels the logon in process.

## Remarks

Before calling **WlxActivateUserShell**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

Always activate the user shell program in **WlxActivateUserShell** rather than
[WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas). This gives Winlogon a chance to update its state, including setting workstation and desktop protections, before any logged-on user processes are allowed to run.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxLoggedOutSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedoutsas)

[WlxLogoff](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxlogoff)