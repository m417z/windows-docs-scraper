# PackageFamilyNameFromFullName function

## Description

Gets the package family name for the specified package full name.

## Parameters

### `packageFullName` [in]

Type: **PCWSTR**

The full name of a package.

### `packageFamilyNameLength` [in, out]

Type: **UINT32***

On input, the size of the *packageFamilyName* buffer, in characters. On output, the size of the package family name returned, in characters, including the null terminator.

### `packageFamilyName` [out, optional]

Type: **PWSTR**

The package family name.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
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

int ShowUsage();
void FullNameToFamilyName(__in PCWSTR fullName);

int ShowUsage()
{
    wprintf(L"Usage: PackageFamilyNameFromFullName <fullname> [<fullname>...]\n");
    return 1;
}

int __cdecl wmain(__in int argc, __in_ecount(argc) WCHAR * argv[])
{
    if (argc <= 1)
        return ShowUsage();

    for (int i=1; i<argc; ++i)
        FullNameToFamilyName(argv[i]);

    return 0;
}

void FullNameToFamilyName(__in PCWSTR fullName)
{
    wprintf(L"FullName: %s\n", fullName);
    UINT32 length = 0;
    LONG rc = PackageFamilyNameFromFullName(fullName, &length, NULL);
    if (rc == ERROR_SUCCESS)
    {
        wprintf(L"PackageFamilyNameFromFullName unexpectedly succeeded\n");
        return;
    }
    else if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        wprintf(L"Error %d in PackageFamilyNameFromFullName\n", rc);
        return;
    }

    PWSTR familyName = (PWSTR) malloc(length * sizeof(WCHAR));
    if (familyName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    rc = PackageFamilyNameFromFullName(fullName, &length, familyName);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d converting PackageFamilyName to FullName\n", rc);
    else
        wprintf(L"Package Family Name = %s\n", familyName);

    free(familyName);
}

```

## See also

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefamilyname)

[PackageFamilyNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromid)

[PackageFullNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefullnamefromid)

[PackageIdFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packageidfromfullname)

[PackageNameAndPublisherIdFromFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagenameandpublisheridfromfamilyname)