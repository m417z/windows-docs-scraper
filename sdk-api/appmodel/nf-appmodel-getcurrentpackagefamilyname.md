# GetCurrentPackageFamilyName function

## Description

Gets the package family name for the calling process.

## Parameters

### `packageFamilyNameLength` [in, out]

Type: **UINT32***

On input, the size of the *packageFamilyName* buffer, in characters, including the null terminator. On output, the size of the package family name returned, in characters, including the null terminator.

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
#include <stdio.h>

int __cdecl wmain()
{
    UINT32 length = 0;
    LONG rc = GetCurrentPackageFamilyName(&length, NULL);
    if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        if (rc == APPMODEL_ERROR_NO_PACKAGE)
            wprintf(L"Process has no package identity\n");
        else
            wprintf(L"Error %d in GetCurrentPackageFamilyName\n", rc);
        return 1;
    }

    PWSTR familyName = (PWSTR) malloc(length * sizeof(*familyName));
    if (familyName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return 2;
    }

    rc = GetCurrentPackageFamilyName(&length, familyName);
    if (rc != ERROR_SUCCESS)
    {
        wprintf(L"Error %d retrieving PackageFamilyName\n", rc);
        return 3;
    }
    wprintf(L"%s\n", familyName);

    free(familyName);

    return 0;
}

```

## See also

[GetCurrentPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefullname)

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetCurrentPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagepath)

[GetPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefamilyname)

[PackageFamilyNameFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromfullname)

[PackageFamilyNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromid)