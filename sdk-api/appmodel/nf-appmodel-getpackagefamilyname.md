# GetPackageFamilyName function

## Description

Gets the package family name for the specified process.

## Parameters

### `hProcess` [in]

Type: **HANDLE**

A handle to the process that has the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `packageFamilyNameLength` [in, out]

Type: **UINT32***

On input, the size of the *packageFamilyName* buffer, in characters. On output, the size of the package family name returned, in characters, including the null-terminator.

### `packageFamilyName` [out, optional]

Type: **PWSTR**

The package family name.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The process has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *packageFamilyNameLength*. |

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
void ShowProcessPackageFamilyName(__in const UINT32 pid, __in HANDLE process);

int ShowUsage()
{
    wprintf(L"Usage: GetPackageFamilyName <pid> [<pid>...]\n");
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
                ShowProcessPackageFamilyName(pid, process);
                CloseHandle(process);
            }
        }
    }
    return 0;
}

void ShowProcessPackageFamilyName(__in const UINT32 pid, __in HANDLE process)
{
    wprintf(L"Process %u (handle=%p)\n", pid, process);

    UINT32 length = 0;
    LONG rc = GetPackageFamilyName(process, &length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_PACKAGE)
            wprintf(L"Process has no package identity\n");
        else
            wprintf(L"Error %d in GetPackageFamilyName\n", rc);
        return;
    }

    PWSTR familyName = (PWSTR) malloc(length * sizeof(*familyName));
    if (familyName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    rc = GetPackageFamilyName(process, &length, familyName);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d retrieving PackageFamilyName\n", rc);
    else
        wprintf(L"%s\n", familyName);

    free(familyName);
}

```

## See also

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefullname)

[GetPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageid)

[PackageFamilyNameFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromfullname)

[PackageFamilyNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromid)