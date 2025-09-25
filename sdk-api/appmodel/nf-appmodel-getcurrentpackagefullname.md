# GetCurrentPackageFullName function

## Description

Gets the package full name for the calling process.

## Parameters

### `packageFullNameLength` [in, out]

Type: **UINT32***

On input, the size of the *packageFullName* buffer, in characters. On output, the size of the package full name returned, in characters, including the null terminator.

### `packageFullName` [out, optional]

Type: **PWSTR**

The package full name.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The process has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *packageFullNameLength*. |

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
    LONG rc = GetCurrentPackageFullName(&length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_PACKAGE)
            wprintf(L"Process has no package identity\n");
        else
            wprintf(L"Error %d in GetCurrentPackageFullName\n", rc);
        return 1;
    }

    PWSTR fullName = (PWSTR) malloc(length * sizeof(*fullName));
    if (fullName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return 2;
    }

    rc = GetCurrentPackageFullName(&length, fullName);
    if (rc != ERROR_SUCCESS)
    {
        wprintf(L"Error %d retrieving PackageFullName\n", rc);
        return 3;
    }
    wprintf(L"%s\n", fullName);

    free(fullName);

    return 0;
}

```

## See also

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetCurrentPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagepath)

[GetPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefullname)

[PackageFullNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefullnamefromid)