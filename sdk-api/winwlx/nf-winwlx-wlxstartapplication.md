# WlxStartApplication function

## Description

[The WlxStartApplication function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxStartApplication** function can be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when the system needs an application to be started in the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of the user.

There are two reasons that the system might need an application to start in the context of the user:

* Windows Explorer has quit unexpectedly and needs to be restarted.
* The extended task manager needs to run.

**Note** GINA DLLs are ignored in Windows Vista.

The GINA can override this behavior, if appropriate, by using the **WlxStartApplication** function.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `pszDesktopName` [in]

Specifies the name of the desktop on which to start the application. Pass this string to the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) or
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function through the **lpDesktop** member of the
[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure.

### `pEnvironment` [in]

Specifies the initial environment for the process. Winlogon creates this environment and hands it off to the GINA. The GINA can modify this environment before using it to initialize the shell of the user. When the GINA has finished using this environment, it must free the memory allocated for *pEnvironment* by calling the [VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree) function.

### `pszCmdLine` [in]

The program to execute.

## Return value

If the function successfully starts the application, the function returns **TRUE**.

If the function fails or the application did not start, the function returns **FALSE**.

## Remarks

Before calling **WlxStartApplication**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

If the **WlxStartApplication** function is not exported by the GINA, Winlogon will execute the process.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)