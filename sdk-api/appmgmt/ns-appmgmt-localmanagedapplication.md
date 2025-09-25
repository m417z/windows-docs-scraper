# LOCALMANAGEDAPPLICATION structure

## Description

The **LOCALMANAGEDAPPLICATION** structure describes a managed application installed for a user or a computer. Returned by the [GetLocalManagedApplications](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-getlocalmanagedapplications) function.

## Members

### `pszDeploymentName`

This is a Unicode string that gives the user friendly name of the application as it appears in the Application Deployment Editor (ADE).

### `pszPolicyName`

This is the user-friendly name of the group policy object (GPO) from which the application originates.

### `pszProductId`

This is a Unicode string that gives the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) product code GUID for the application.

### `dwState`

Indicates the state of the installed application. This parameter can contain one or more of the following values.

#### LOCAL_STATE_ASSIGNED

The application is installed in the assigned state.

#### LOCAL_STATE_PUBLISHED

The application is installed in the published state.

#### LOCAL_STATE_UNINSTALL_UNMANAGED

The installation of this application uninstalled an unmanaged application with a conflicting transform.

#### LOCAL_STATE_POLICYREMOVE_ORPHAN

If the policy from which this application originates is removed, the application is left on the computer.

#### LOCAL_STATE_POLICYREMOVE_UNINSTALL

If the policy from which this application originates is removed, the application is uninstalled from the computer.

## See also

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)