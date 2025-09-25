# SI_PAGE_TYPE enumeration

## Description

The **SI_PAGE_TYPE** enumeration contains values that indicate the types of property pages in an access control editor property sheet.

## Constants

### `SI_PAGE_PERM`

The
[basic security property page](https://learn.microsoft.com/windows/desktop/SecAuthZ/basic-security-property-page) for editing the object's DACL.

### `SI_PAGE_ADVPERM`

The
[Permissions](https://learn.microsoft.com/windows/desktop/SecAuthZ/permissions-property-page) tab for advanced editing of the object's DACL, such as editing object-specific ACEs.

### `SI_PAGE_AUDIT`

The
[Auditing](https://learn.microsoft.com/windows/desktop/SecAuthZ/auditing-property-page) tab for editing the object's SACL.

### `SI_PAGE_OWNER`

The
[Owner](https://learn.microsoft.com/windows/desktop/SecAuthZ/owner-property-page) tab for editing the object's owner.

### `SI_PAGE_EFFECTIVE`

The **Effective Permission** tab that displays the effective permissions granted to a specified user or group for access to the object.

### `SI_PAGE_TAKEOWNERSHIP`

A dialog box for changing the owner of the object.

### `SI_PAGE_SHARE`

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[ISecurityInformation::PropertySheetPageCallback](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-propertysheetpagecallback)