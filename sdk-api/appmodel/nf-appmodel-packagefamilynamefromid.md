# PackageFamilyNameFromId function

## Description

Gets the package family name for the specified package identifier.

## Parameters

### `packageId` [in]

Type: **const [PACKAGE_ID](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_id)***

The package identifier.

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
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int ShowUsage();
bool ParseArchitecture(__in PCWSTR architectureString, __out UINT32 * architecture);
bool ParseVersion(__in PCWSTR versionString, __out PACKAGE_VERSION * version);

int ShowUsage()
{
    wprintf(L"Usage: PackageFamilyNameFromId <name><version> <arch> <resourceid> <publisher>\n");
    return 1;
}

int __cdecl wmain(__in int argc, __in_ecount(argc) WCHAR * argv[])
{
    if (argc <= 5)
        return ShowUsage();

    PACKAGE_ID packageId;
    ZeroMemory(&packageId, sizeof(packageId));
    packageId.name = argv[1];
    if (!ParseVersion(argv[2], &packageId.version))
        return 2;
    if (!ParseArchitecture(argv[3], &packageId.processorArchitecture))
        return 3;
    packageId.resourceId = argv[4];
    packageId.publisher = argv[5];

    UINT32 length = 0;
    LONG rc = PackageFamilyNameFromId(&packageId, &length, NULL);
    if (rc == ERROR_SUCCESS)
    {
        wprintf(L"PackageFamilyNameFromId unexpected succeeded\n");
        return 4;
    }
    else if (rc != ERROR_INSUFFICIENT_BUFFER)
    {
        wprintf(L"Error %d in PackageFamilyNameFromId\n", rc);
        return 5;
    }

    PWSTR familyName = (PWSTR) malloc(length * sizeof(WCHAR));
    if (familyName == NULL)
    {
        wprintf(L"Error allocating memory\n");
        return 6;
    }

    rc = PackageFamilyNameFromId(&packageId, &length, familyName);
    if (rc != ERROR_SUCCESS)
        wprintf(L"Error %d converting Package Id to Family Name\n", rc);
    else
        wprintf(L"Package Family Name = %s\n", familyName);

    free(familyName);

    return rc == ERROR_SUCCESS ? 0 : 7;
}

bool ParseArchitecture(__in PCWSTR architectureString, __out UINT32 * architecture)
{
    if (_wcsicmp(architectureString, L"neutral") == 0)
        *architecture = PROCESSOR_ARCHITECTURE_NEUTRAL;
    else if (_wcsicmp(architectureString, L"x86") == 0)
        *architecture = PROCESSOR_ARCHITECTURE_INTEL;
    else if (_wcsicmp(architectureString, L"x64") == 0)
        *architecture = PROCESSOR_ARCHITECTURE_AMD64;
    else if (_wcsicmp(architectureString, L"arm") == 0)
        *architecture = PROCESSOR_ARCHITECTURE_ARM;
    else
    {
        wprintf(L"Invalid architecture\n");
        return false;
    }
    return true;
}

bool ParseVersion(__in PCWSTR versionString, __out PACKAGE_VERSION * version)
{
    PWSTR s = (PWSTR) versionString;

    ULONG n = wcstoul(s, &s, 10);
    if (((n == 0) || (n > 65535)) && (errno == ERANGE)) {
        wprintf(L"Invalid Version (Major)\n");
        return false;
    }
    version->Major = (USHORT) n;

    if (*s != L'.')
    {
        wprintf(L"Invalid Version\n");
        return false;
    }

    n = wcstoul(++s, &s, 10);
    if (((n == 0) || (n > 65535)) && (errno == ERANGE)) {
        wprintf(L"Invalid Version (Minor)\n");
        return false;
    }
    version->Minor = (USHORT) n;

    if (*s != L'.')
    {
        wprintf(L"Invalid Version\n");
        return false;
    }

    n = wcstoul(++s, &s, 10);
    if (((n == 0) || (n > 65535)) && (errno == ERANGE)) {
        wprintf(L"Invalid Version (Build)\n");
        return false;
    }
    version->Build = (USHORT) n;

    if (*s != L'.')
    {
        wprintf(L"Invalid Version\n");
        return false;
    }

    n = wcstoul(++s, &s, 10);
    if (((n == 0) || (n > 65535)) && (errno == ERANGE)) {
        wprintf(L"Invalid Version (Revision)\n");
        return false;
    }
    version->Revision = (USHORT) n;

    return true;
}

```

## See also

[GetCurrentPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackagefamilyname)

[GetPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefamilyname)

[PackageFamilyNameFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromfullname)

[PackageFullNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefullnamefromid)

[PackageIdFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packageidfromfullname)

[PackageNameAndPublisherIdFromFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagenameandpublisheridfromfamilyname)