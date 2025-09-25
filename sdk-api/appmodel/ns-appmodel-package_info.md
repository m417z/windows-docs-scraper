# PACKAGE_INFO structure

## Description

Represents package identification information that includes the package identifier, full name, and install location.

## Members

### `reserved`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; do not use.

### `flags`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Properties of the package.

### `path`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The location of the package.

### `packageFullName`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The package full name.

### `packageFamilyName`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The package family name.

### `packageId`

Type: **[PACKAGE_ID](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_id)**

The package identifier (ID).

## Remarks

For info about string size limits, see [Identity constants](https://learn.microsoft.com/windows/desktop/appxpkg/identity-constants).

## See also

[GetCurrentPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageinfo)

[GetPackageInfo](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackageinfo)