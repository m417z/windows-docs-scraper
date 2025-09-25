## Description

The **INSTALLSPEC** structure specifies a group policy application by its user-friendly name and group policy GUID or by its file name extension. The **Spec** member of the [INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata) structure provides this information to the [InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication) function.

## Members

### `AppName`

Structure that contains the following members.

### `AppName.Name`

The user-friendly name of the application as it appears in **Add or Remove Programs** and the [Group Policy Object Editor](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-object-editor). You can obtain the name by calling [GetManagedApplications](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-getmanagedapplications).

### `AppName.GPOId`

The **GUID** for the group policy object in which the application exists. You can obtain the group policy object **GUID** by calling [GetManagedApplications](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-getmanagedapplications).

### `FileExt`

The file name extension, such as .jpg, of the application to be installed.

**Note** [InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication) fails if the **Type** member of [INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata) equals **FILEEXT** and there is no application deployed to the user with this file name extension.

### `ProgId`

This parameter is reserved and should not be used.

### `COMClass`

This parameter is reserved and should not be used.

### `COMClass.Clsid`

This parameter is reserved and should not be used.

### `COMClass.ClsCtx`

This parameter is reserved and should not be used.

## See also

[GetManagedApplications](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-getmanagedapplications)

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)

[INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata)

[InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication)

[UninstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-uninstallapplication)