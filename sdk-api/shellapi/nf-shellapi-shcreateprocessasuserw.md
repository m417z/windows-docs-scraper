# SHCreateProcessAsUserW function

## Description

[**SHCreateProcessAsUserW** is not implemented under Windows XP or later systems.]

Creates a new user-mode process and its primary thread to run a specified executable file.

## Parameters

### `pscpi` [in, out]

Type: **PSHCREATEPROCESSINFOW**

A pointer to an [SHCREATEPROCESSINFOW](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shcreateprocessinfow) structure with information on how to create the process.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** if not. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is similar to [ShellExecuteEx](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information) with **runas** as the verb. However, **SHCreateProcessAsUserW** creates a process that runs in the security context of the user represented by the **hUserToken** member of the structure pointed to by *pscpi*. The **lpProcessInformation** member can be used to return a [PROCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-process_information) structure with information on the new process.

The **runas** verb must be supported by the executable file's [file type](https://learn.microsoft.com/windows/desktop/shell/fa-file-types). The .exe file type supports **runas**. Use the [AssocQueryString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-assocquerystringa) function to check whether **runas** is supported by other file types. The following code fragment illustrates the syntax.

```
AssocQueryString(0, ASSOCSTR_COMMAND, pszFile, TEXT("runas"), NULL, &cchVerb)
```

For a discussion of how to use the Shell to launch applications, see [Launching Applications](https://learn.microsoft.com/windows/desktop/shell/launch).

**SHCreateProcessAsUserW** is not supported under Windows XP. Users requiring similar functionality should examine [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa), [CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera), [CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw) and [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa), carefully evaluating each based on required functionality and security. [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) can be used to extract information used with **CreateProcess**, if necessary.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera)

[CreateProcessWithLogonW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createprocesswithlogonw)

[ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa)