# GetPackageFullNameFromToken function

## Description

Gets the package full name for the specified token.

## Parameters

### `token` [in]

A token that contains the package identity.

### `packageFullNameLength` [in, out]

On input, the size of the *packageFullName* buffer, in characters. On output, the
size of the package full name returned, in characters, including the null terminator.

### `packageFullName` [out, optional]

The package full name.

## Return value

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function
returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The token has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *packageFullNameLength*. |

## Remarks

For info about string size limits, see
[Identity constants](https://learn.microsoft.com/windows/desktop/appxpkg/identity-constants).

#### Examples

```cpp
/***************************************************
*                                                  *
*   Copyright (C) Microsoft. All rights reserved.  *
*                                                  *
***************************************************/

#define _UNICODE 1
#define UNICODE 1

#include <Windows.h>
#include <appmodel.h>
#include <appmodelp.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int ShowUsage();
void ShowProcessPackageFullName(__in const UINT32 pid, __in HANDLE token);

int ShowUsage()
{
    wprintf(L"Usage: GetPackageFullNameFromToken <pid> [<pid>...]\n");
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
                HANDLE token;
                if (!OpenProcessToken(process, TOKEN_QUERY, &token))
                    wprintf(L"Error %d in OpenProcessToken (pid=%u)\n", GetLastError(), pid);
                else
                {
                    ShowProcessPackageFullName(pid, token);
                    CloseHandle(token);
                }
                CloseHandle(process);
            }
        }
    }
    return 0;
}

void ShowProcessPackageFullName(__in const UINT32 pid, __in HANDLE token)
{
    wprintf(L"Process %u (token=%p)\n", pid, token);

    UINT32 length = 0;
    LONG rc = GetPackageFullNameFromToken(token, &length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_PACKAGE)
            wprintf(L"Token has no package identity\n");
        else
            wprintf(L"Error %d in GetPackageFullNameFromToken\n", rc);
        return;
    }

    PWSTR fullName = (PWSTR) malloc(length * sizeof(*fullName));
    if (fullName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    rc = GetPackageFullNameFromToken(token, &length, fullName);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d retrieving PackageFullName\n", rc);
    else
        wprintf(L"%s\n", fullName);

    free(fullName);
}
```