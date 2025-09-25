# DSOBJECTNAMES structure

## Description

The **DSOBJECTNAMES** structure is used to contain directory object data for use by an Active Directory property sheet or context menu extension.

## Members

### `clsidNamespace`

Contains the namespace identifier which indicates the origin of the namespace selection. The **CLSID_DsFolder** value (identical to **CLSID_MicrosoftDS**) is used to identify namespaces implemented by Active Directory Domain Services.

### `cItems`

Contains the number of elements in the **aObjects** array.

### `aObjects`

Contains an array of [DSBOJECT](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobject) structures. Each **DSBOJECT** structure represents a single directory object. The **cItems** member contains the number of elements in the array.

## See also

[DSBOJECT](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-dsobject)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)