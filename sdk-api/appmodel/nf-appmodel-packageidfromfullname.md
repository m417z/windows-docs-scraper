# PackageIdFromFullName function

## Description

Gets the package identifier (ID) for the specified package full name.

## Parameters

### `packageFullName` [in]

Type: **PCWSTR**

The full name of a package.

### `flags` [in]

Type: **const UINT32**

The [package constants](https://learn.microsoft.com/windows/desktop/appxpkg/package-constants) that specify how package information is retrieved. The **PACKAGE_INFORMATION_*** flags are supported.

### `bufferLength` [in, out]

Type: **UINT32***

On input, the size of *buffer*, in bytes. On output, the size of the data returned, in bytes.

### `buffer` [out, optional]

Type: **BYTE***

The package ID, represented as a [PACKAGE_ID](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_id) structure.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *bufferLength*. |
| **ERROR_NOT_FOUND** | The package is not installed for the user. |

## Remarks

If *flags* specifies **PACKAGE_INFORMATION_BASIC**, the following fields are retrieved:

* **name**
* **processorArchitecture**
* **publisherId**
* **resourceId**
* **version**

If *flags* specifies **PACKAGE_INFORMATION_FULL**, the following fields are retrieved:

* **name**
* **processorArchitecture**
* **publisher**
* **publisherId**
* **resourceId**
* **version**

A request for **PACKAGE_INFORMATION_FULL** succeeds only if the package corresponding to *packageFullName* is installed for and accessible to the current user. If the package full name is syntactically correct but does not correspond to a package that is installed for and accessible to the current user, the function returns **ERROR_NOT_FOUND**.

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
void FullNameToId(__in PCWSTR fullName, __in const UINT32 flags);
void ShowPackageId(__in const PACKAGE_ID * packageId);

int ShowUsage()
{
    wprintf(L"Usage: PackageIdFromFullName <[flags]fullname> [<[flags]fullname>...]\n"
            L"flags:\n"
            L"    ? = Basic information (PACKAGE_INFORMATION_BASIC)\n"
            L"    * = Full information (PACKAGE_INFORMATION_FULL)\n"
            L"Default = Basic\n");
    return 1;
}

int __cdecl wmain(__in int argc, __in_ecount(argc) WCHAR * argv[])
{
    if (argc <= 1)
        return ShowUsage();

    for (int i=1; i<argc; ++i)
    {
        PCWSTR fullName = argv[i];
        UINT32 flags = PACKAGE_INFORMATION_BASIC;
        if (*fullName != L'\0')
        {
            if (*fullName == L'?')
            {
                flags = PACKAGE_INFORMATION_BASIC;
                ++fullName;
            }
            else if (*fullName == L'*')
            {
                flags = PACKAGE_INFORMATION_FULL;
                ++fullName;
            }
        }
        FullNameToId(fullName, flags);
    }

    return 0;
}

void FullNameToId(__in PCWSTR fullName, __in const UINT32 flags)
{
    wprintf(L"FullName: %s%s\n", fullName, ((flags & PACKAGE_INFORMATION_FULL) == 0 ? L"  [BASIC]" : L"  [FULL]"));
    UINT32 length = 0;
    LONG rc = PackageIdFromFullName(fullName, flags, &length, NULL);
    if (rc == ERROR_SUCCESS)
    {
        wprintf(L"PackageIdFromFullName unexpected succeeded\n");
        return;
    }
    else if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        wprintf(L"Error %d in PackageIdFromFullName\n", rc);
        return;
    }

    BYTE * buffer = (PBYTE) malloc(length);
    if (buffer == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return;
    }

    rc = PackageIdFromFullName(fullName, flags, &length, buffer);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d converting Package Full Name to Id\n", rc);
    else
    {
        ShowPackageId((PACKAGE_ID *) buffer);
    }

    free(buffer);
}

void ShowPackageId(__in const PACKAGE_ID * packageId)
{
    wprintf(L"    Name        : %s\n", packageId->name);
    if (packageId->publisher != NULL)
        wprintf(L"    Publisher   : %s\n", packageId->publisher);
    if (packageId->publisherId != NULL)
        wprintf(L"    PublisherId : %s\n", packageId->publisherId);
    wprintf(L"    Version     : %hu.%hu.%hu.%hu\n",
            packageId->version.Major,
            packageId->version.Minor,
            packageId->version.Build,
            packageId->version.Revision);
    wprintf(L"    Architecture: %u\n", packageId->processorArchitecture);
    if (packageId->resourceId != NULL)
        wprintf(L"    Resource    : %s\n", packageId->resourceId);
}

```

## See also

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageid)

[PackageFamilyNameFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromfullname)

[PackageFamilyNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromid)

[PackageFullNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefullnamefromid)

[PackageNameAndPublisherIdFromFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagenameandpublisheridfromfamilyname)