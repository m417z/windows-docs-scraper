# MANAGEDAPPLICATION structure

## Description

The **MANAGEDAPPLICATION** structure contains information about an application. The function [GetManagedApplications](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-getmanagedapplications) returns an array of **MANAGEDAPPLICATION** structures.

## Members

### `pszPackageName`

The user-friendly name of the application.

### `pszPublisher`

The name of the application's publisher.

### `dwVersionHi`

The major version number of the application.

### `dwVersionLo`

The minor version number of the application.

### `dwRevision`

The version number of the deployment. The version changes each time an application gets patched.

### `GpoId`

The GUID of the GPO from which this application is deployed.

### `pszPolicyName`

The user-friendly name for the GPO from which this application is deployed.

### `ProductId`

If this application is installed by [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal), this member is the ProductId GUID.

### `Language`

The numeric language identifier that indicates the language version of the application. For a list of language numeric identifiers, see the [Language Identifier Constants and Strings](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings) topic.

### `pszOwner`

This member is unused.

### `pszCompany`

This member is unused.

### `pszComments`

This member is unused.

### `pszContact`

This member is unused.

### `pszSupportUrl`

This member is unused.

### `dwPathType`

Indicates the type of package used to install the application. This member can have one of the following values.

#### MANAGED_APPTYPE_WINDOWSINSTALLER

The application is installed using the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal).

#### MANAGED_APPTYPE_SETUPEXE

The application is installed using a legacy setup application.

#### MANAGED_APPTYPE_UNSUPPORTED

The application is installed by an unsupported setup application.

### `bInstalled`

This parameter is **TRUE** if the application is currently installed and is **FALSE** otherwise.

## See also

[GetManagedApplications](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-getmanagedapplications)

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)