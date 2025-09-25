# PackageNameAndPublisherIdFromFamilyName function

## Description

Gets the package name and publisher identifier (ID) for the specified package family name.

## Parameters

### `packageFamilyName` [in]

Type: **PCWSTR**

The family name of a package.

### `packageNameLength` [in, out]

Type: **UINT32***

On input, the size of the *packageName* buffer, in characters. On output, the size of the package name returned, in characters, including the null-terminator.

### `packageName` [out, optional]

Type: **PWSTR**

The package name.

### `packagePublisherIdLength` [in, out]

Type: **UINT32***

On input, the size of the *packagePublishId* buffer, in characters. On output, the size of the publisher ID returned, in characters, including the null-terminator.

### `packagePublisherId` [out, optional]

Type: **PWSTR**

The package publisher ID.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | One of the buffers is not large enough to hold the data. The required sizes are specified by *packageNameLength* and *packagePublisherIdLength*. |

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
void FamilyNameToNameAndPublisherId(__in PCWSTR familyName);

int ShowUsage()
{
    wprintf(L"Usage: PackageNameAndPublisherIdFromFamilyName <familyname> [<familyname>...]\n");
    return 1;
}

int __cdecl wmain(__in int argc, __in_ecount(argc) WCHAR * argv[])
{
    if (argc <= 1)
        return ShowUsage();

    for (int i=1; i<argc; ++i)
        FamilyNameToNameAndPublisherId(argv[i]);

    return 0;
}

void FamilyNameToNameAndPublisherId(__in PCWSTR familyName)
{
    wprintf(L"FamilyName: %s\n", familyName);
    UINT32 nameLength = 0;
    UINT32 publisherIdLength = 0;
    LONG rc = PackageNameAndPublisherIdFromFamilyName(familyName, &nameLength, NULL, &publisherIdLength, NULL);
    if (rc == ERROR_SUCCESS)
    {
        wprintf(L"PackageNameAndPublisherIdFromFamilyName unexpectedly succeeded\n");
        return;
    }
    else if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        wprintf(L"Error %d in PackageNameAndPublisherIdFromFamilyName\n", rc);
        return;
    }

    PWSTR name = (PWSTR) malloc(nameLength * sizeof(WCHAR));
    if (name == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    PWSTR publisherId = (PWSTR) malloc(publisherIdLength * sizeof(WCHAR));
    if (publisherId == NULL)
    {
        wprintf(L"Error allocating memory\n");
        free(name);
        return;
    }

    rc = PackageNameAndPublisherIdFromFamilyName(familyName, &nameLength, name, &publisherIdLength, publisherId);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d converting PackageFamilyName to Name and PublisherId\n", rc);
    else
    {
        wprintf(L"        Name = %s\n", name);
        wprintf(L"Publisher Id = %s\n", publisherId);
    }

    free(name);
    free(publisherId);
}

```

## See also

[PackageFamilyNameFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromfullname)

[PackageFamilyNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromid)

[PackageFullNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefullnamefromid)

[PackageIdFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packageidfromfullname)