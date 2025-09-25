# GetApplicationRestartSettings function

## Description

Retrieves the restart information registered for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have the PROCESS_VM_READ access right.

### `pwzCommandline` [out, optional]

A pointer to a buffer that receives the restart command line specified by the application when it called the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function. The maximum size of the command line, in characters, is RESTART_MAX_CMD_LINE. Can be **NULL** if *pcchSize* is zero.

### `pcchSize` [in, out]

On input, specifies the size of the *pwzCommandLine* buffer, in characters.

If the buffer is not large enough to receive the command line, the function fails with HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) and sets this parameter to the required buffer size, in characters.

On output, specifies the size of the buffer that was used.

To determine the required buffer size, set *pwzCommandLine* to **NULL** and this parameter to zero. The size includes one for the **null**-terminator character. Note that the function returns S_OK, not HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) in this case.

### `pdwFlags` [out, optional]

A pointer to a variable that receives the flags specified by the application when it called the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function.

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more parameters are not valid. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The application did not register for restart. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The *pwzCommandLine* buffer is too small. The function returns the required buffer size in *pcchSize*. Use the required size to reallocate the buffer. |

## Remarks

This information is available only for the current process; you cannot call this function after your program is restarted to get the restart command line. To get the command line after a restart, access the *argv* parameter of your **main** function.

#### Examples

The following example shows how to get the restart settings specified when you called the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function.

```cpp
#include <windows.h>
#include <stdio.h>

void wmain(int argc, WCHAR* argv[])
{
    HRESULT hr = S_OK;
    WCHAR wsCommandLine[RESTART_MAX_CMD_LINE + 1];
    DWORD cchCmdLine = sizeof(wsCommandLine) / sizeof(WCHAR);
    DWORD dwFlags = 0;
    LPWSTR pwsCmdLine = NULL;
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(argc);

    wprintf(L"Registering for restart...\n");
    hr = RegisterApplicationRestart(L"/restart -f .\\filename.ext", 0);
    if (FAILED(hr))
    {
        wprintf(L"RegisterApplicationRestart failed, 0x%x\n", hr);
        goto cleanup;
    }

    wprintf(L"Get restart command line using static buffer...\n");
    hr = GetApplicationRestartSettings(GetCurrentProcess(), wsCommandLine, &cchCmdLine, &dwFlags);
    if (FAILED(hr))
    {
        wprintf(L"GetApplicationRestartSettings failed, 0x%x\n", hr);
        goto cleanup;
    }

    wprintf(L"Command line: %s\n", wsCommandLine);

    wprintf(L"\nGet settings using dynamic buffer...\n");

    cchCmdLine = 0;

    // Returns S_OK instead of ERROR_INSUFFICIENT_BUFFER when pBuffer is NULL and size is 0.
    hr = GetApplicationRestartSettings(GetCurrentProcess(), (PWSTR)pwsCmdLine, &cchCmdLine, &dwFlags);
    if (SUCCEEDED(hr))
    {
        pwsCmdLine = (LPWSTR)malloc(cchCmdLine * sizeof(WCHAR));

        if (pwsCmdLine)
        {
            hr = GetApplicationRestartSettings(GetCurrentProcess(), (PWSTR)pwsCmdLine, &cchCmdLine, &dwFlags);
            if (FAILED(hr))
            {
                wprintf(L"GetApplicationRestartSettings failed with 0x%x\n", hr);
                goto cleanup;
            }

            wprintf(L"Command line: %s\n", pwsCmdLine);
        }
        else
        {
            wprintf(L"Allocating the command-line buffer failed.\n");
        }
    }
    else
    {
        if (hr != HRESULT_FROM_WIN32(ERROR_NOT_FOUND)) // Not a restart.
        {
            wprintf(L"GetApplicationRestartSettings failed with 0x%x\n", hr);
            goto cleanup;
        }
    }

cleanup:

    if (pwsCmdLine)
        free(pwsCmdLine);
}

```

## See also

[RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart)