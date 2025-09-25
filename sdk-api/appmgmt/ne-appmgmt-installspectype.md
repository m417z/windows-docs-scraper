# INSTALLSPECTYPE enumeration

## Description

The **INSTALLSPECTYPE** enumeration values define the ways a group policy application can be specified to the [InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication) function. The values are used in the **Type** member of [INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata).

## Constants

### `APPNAME`

This constant equals 1. The application is specified by its display name and group policy GUID.

### `FILEEXT`

The application is specified by its file name extension, for example, .jpg.

### `PROGID`

### `COMCLASS`

## See also

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)

[INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata)

[InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication)

[UninstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-uninstallapplication)