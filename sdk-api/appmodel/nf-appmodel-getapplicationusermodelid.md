# GetApplicationUserModelId function

## Description

Gets the [application user model ID](https://learn.microsoft.com/windows/desktop/appxpkg/appx-packaging-glossary) for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have the **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more info, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `applicationUserModelIdLength` [in, out]

On input, the size of the *applicationUserModelId* buffer, in wide characters. On success, the size of the buffer used, including the null terminator.

### `applicationUserModelId` [out]

A pointer to a buffer that receives the application user model ID.

## Return value

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_APPLICATION** | The process has no application identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *applicationUserModelIdLength*. |

## Remarks

For info about string size limits, see [Identity constants](https://learn.microsoft.com/windows/desktop/appxpkg/identity-constants).

#### Examples

```cpp
#define _UNICODE 1
#define UNICODE 1

#include <Windows.h>
#include <appmodel.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int ShowUsage();
void ShowProcessApplicationUserModelId(__in const UINT32 pid, __in HANDLE process);

int ShowUsage()
{
    wprintf(L"Usage: GetApplicationUserModelId <pid> [<pid>...]\n");
    return 1;
}

int __cdecl wmain(__in int argc, __in_ecount(argc) WCHAR * argv[])
{
    if (argc <= 1)
        return ShowUsage();

    for (int i=1; i<argc; ++i)
    {
        UINT32 pid = wcstoul(argv[i], NULL, 10);
        if (pid > 0)
        {
            HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
            if (process == NULL)
                wprintf(L"Error %d in OpenProcess (pid=%u)\n", GetLastError(), pid);
            else
            {
                ShowProcessApplicationUserModelId(pid, process);
                CloseHandle(process);
            }
        }
    }
    return 0;
}

void ShowProcessApplicationUserModelId(__in const UINT32 pid, __in HANDLE process)
{
    wprintf(L"Process %u (handle=%p)\n", pid, process);

    UINT32 length = 0;
    LONG rc = GetApplicationUserModelId(process, &length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_APPLICATION)
            wprintf(L"Desktop application\n");
        else
            wprintf(L"Error %d in GetApplicationUserModelId\n", rc);
        return;
    }

    PWSTR fullName = (PWSTR) malloc(length * sizeof(*fullName));
    if (fullName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    rc = GetApplicationUserModelId(process, &length, fullName);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d retrieving ApplicationUserModelId\n", rc);
    else
        wprintf(L"%s\n", fullName);

    free(fullName);
}

```

## See also

[GetCurrentApplicationUserModelId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentapplicationusermodelid)

[GetPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefamilyname)

[GetPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageid)

[GetPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageinfo)

[GetPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagepath)