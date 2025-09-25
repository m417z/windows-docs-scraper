# PACKAGE_ID structure

## Description

Represents package identification information, such as name, version, and publisher.

## Members

### `reserved`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; do not use.

### `processorArchitecture`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The processor architecture of the package. This member must be one of the values of the **PROCESSOR_ARCHITECTURE_...** constants that matches the **[ProcessorArchitecture](https://learn.microsoft.com/uwp/api/Windows.System.ProcessorArchitecture)** enumeration values. This includes:

* PROCESSOR_ARCHITECTURE_AMD64
* PROCESSOR_ARCHITECTURE_ARM
* PROCESSOR_ARCHITECTURE_ARM64
* PROCESSOR_ARCHITECTURE_INTEL
* PROCESSOR_ARCHITECTURE_IA32_ON_ARM64
* PROCESSOR_ARCHITECTURE_NEUTRAL
* PROCESSOR_ARCHITECTURE_UNKNOWN

### `version`

Type: **[PACKAGE_VERSION](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_version)**

The version of the package.

### `name`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the package.

### `publisher`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The publisher of the package. If there is no publisher for the package, this member is **NULL**.

### `resourceId`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The resource identifier (ID) of the package. If there is no resource ID for the package, this member is **NULL**.

### `publisherId`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The publisher identifier (ID) of the package. If there is no publisher ID for the package, this member is **NULL**.

## Remarks

For info about string size limits, see [Identity constants](https://learn.microsoft.com/windows/desktop/appxpkg/identity-constants).

## See also

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageid)

[GetPackagePath](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagepath)

[PACKAGE_INFO](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_info)

[PackageFamilyNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefamilynamefromid)

[PackageFullNameFromId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packagefullnamefromid)

[PackageIdFromFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-packageidfromfullname)