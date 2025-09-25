# GetApplicationUserModelIdFromToken function

## Description

Gets the [application user model ID](https://learn.microsoft.com/windows/desktop/appxpkg/appx-packaging-glossary) for the specified token.

## Parameters

### `token` [in]

A token that contains the application identity. This handle must have the **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more info, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `applicationUserModelIdLength` [in, out]

On input, the size of the *applicationUserModelId* buffer, in wide characters. On success, the size of the buffer used, including the null terminator.

### `applicationUserModelId` [out]

A pointer to a buffer that receives the application user model ID.

## Return value

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_APPLICATION** | The token has no application identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *applicationUserModelIdLength*. |

## Remarks

For info about string size limits, see [Identity constants](https://learn.microsoft.com/windows/desktop/appxpkg/identity-constants).

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
void ShowProcessApplicationUserModelId(__in const UINT32 pid, __in HANDLE token);

int ShowUsage()
{
    wprintf(L"Usage: GetApplicationUserModelIdFromToken <pid> [<pid>...]\n");
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
                    ShowProcessApplicationUserModelId(pid, token);
                    CloseHandle(token);
                }
                CloseHandle(process);
            }
        }
    }
    return 0;
}

void ShowProcessApplicationUserModelId(__in const UINT32 pid, __in HANDLE token)
{
    wprintf(L"Process %u (token=%p)\n", pid, token);

    UINT32 length = 0;
    LONG rc = GetApplicationUserModelIdFromToken(token, &length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_PACKAGE)
            wprintf(L"Token has no package identity\n");
        else
            wprintf(L"Error %d in GetApplicationUserModelIdFromToken\n", rc);
        return;
    }

    PWSTR applicationUserModelId = (PWSTR) malloc(length * sizeof(*applicationUserModelId));
    if (applicationUserModelId == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    rc = GetApplicationUserModelIdFromToken(token, &length, applicationUserModelId);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d retrieving ApplicationUserModelId\n", rc);
    else
        wprintf(L"%s\n", applicationUserModelId);

    free(applicationUserModelId);
}

```