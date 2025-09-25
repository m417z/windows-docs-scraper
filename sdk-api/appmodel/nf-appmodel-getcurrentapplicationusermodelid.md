# GetCurrentApplicationUserModelId function

## Description

Gets the [application user model ID](https://learn.microsoft.com/windows/desktop/appxpkg/appx-packaging-glossary) for the current process.

## Parameters

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
#include <stdio.h>

int __cdecl wmain()
{
    UINT32 length = 0;
    LONG rc = GetCurrentApplicationUserModelId(&length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_APPLICATION)
            wprintf(L"Desktop application\n");
        else
            wprintf(L"Error %d in GetCurrentApplicationUserModelId\n", rc);
        return 1;
    }

    PWSTR fullName = (PWSTR) malloc(length * sizeof(*fullName));
    if (fullName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return 2;
    }

    rc = GetCurrentApplicationUserModelId(&length, fullName);
    if (rc != ERROR_SUCCESS)
    {
        wprintf(L"Error %d retrieving ApplicationUserModelId\n", rc);
        return 3;
    }
    wprintf(L"%s\n", fullName);

    free(fullName);

    return 0;
}

```

## See also

[GetApplicationUserModelId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getapplicationusermodelid)

[GetCurrentPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefullname)