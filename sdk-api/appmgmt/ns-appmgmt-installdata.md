# INSTALLDATA structure

## Description

The **INSTALLDATA** structure specifies a group-policy application to be installed by [InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication).

## Members

### `Type`

Defines how **Spec** specifies the application to [InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication). **Type** can be one of the [INSTALLSPECTYPE](https://learn.microsoft.com/windows/desktop/api/appmgmt/ne-appmgmt-installspectype) enumeration values. Set **Type** to APPNAME to install an application specified by its user-friendly name and GPO GUID. Set **Type** to FILEEXT to install an application specified by its file name extension.

### `Spec`

An [INSTALLSPEC](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installspec) structure that specifies the application.

## See also

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)

[INSTALLSPEC](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installspec)

[INSTALLSPECTYPE](https://learn.microsoft.com/windows/desktop/api/appmgmt/ne-appmgmt-installspectype)

[InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication)

[UninstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-uninstallapplication)