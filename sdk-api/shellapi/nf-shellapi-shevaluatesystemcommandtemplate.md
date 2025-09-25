# SHEvaluateSystemCommandTemplate function

## Description

Enforces strict validation of parameters used in a call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) or [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea).

## Parameters

### `pszCmdTemplate` [in]

Type: **PCWSTR**

A command line, which may or may not include parameters. If the parameters are substitution parameters, then **SHEvaluateSystemCommandTemplate** should be called before parameters have been replaced.

### `ppszApplication` [out]

Type: **PWSTR***

A pointer to the verified path to the application. This value should be passed as the *lpApplication* parameter in a call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) or as the *lpFile* parameter in a call to [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea). This resource is allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and it is the responsibility of the caller to free the resource when it is no longer needed by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `ppszCommandLine` [out, optional]

Type: **PWSTR***

A pointer to a command-line string template to be used in a call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa). Command-line parameters should be specified based on this template, and then passed as the *lpCommandLine* parameter to **CreateProcess**. It is guaranteed to be of a form that [PathGetArgs](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathgetargsa) can always read correctly. This resource is allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and it is the responsibility of the caller to free the resource when it is no longer needed by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

This parameter can be **NULL** if this function is not being used in association with a call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

### `ppszParameters` [out, optional]

Type: **PWSTR***

A pointer to a command-line string template to be used in a call to [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea). Command-line parameters should be specified based on this template, and then passed as the *lpParameters* parameter to **ShellExecute**. This parameter is identical to calling [PathGetArgs](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathgetargsa). This resource is allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and it is the responsibility of the caller to free the resource when it is no longer needed by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

This parameter can be **NULL** if this function is not being used in association with a call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is used when a calling process needs the deterministic behavior from a command template, regardless of execution context. It ignores the current process state, such as the `%PATH%`, [GetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrentdirectory), and parent process directory.

This function is used when the command is hard-coded.

This function is used by [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) when handling file associations from HKEY_CLASSES_ROOT. The purpose of this function is to reduce [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) command-line exploits. It is not designed for processing user input and if used for that purpose can generate unexpected failures.