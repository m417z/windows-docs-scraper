# SI_ACCESS structure

## Description

The **SI_ACCESS** structure contains information about an access right or default [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for a securable object. The
[ISecurityInformation::GetAccessRights](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getaccessrights) method uses this structure to specify information that the access control editor uses to initialize its property pages.

## Members

### `pguid`

A pointer to a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object to which the access right or default access mask applies. The GUID can identify a property set or property on the object, or a type of child object that can be contained by the object.

If this member points to GUID_NULL, the access right applies to the object itself.

### `mask`

A bitmask that specifies the access right described by this structure. The mask can contain any combination of standard and specific rights, but should not contain generic rights such as GENERIC_ALL.

### `pszName`

A pointer to a null-terminated [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string containing a display string that describes the access right.

Alternatively, **pszName** can be a string resource identifier returned by the
[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. Use the
[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation) method to identify the module that contains the string resource.

### `dwFlags`

A set of bit flags that indicate where the access right is displayed. This member can be a combination of the following.

| Value | Meaning |
| --- | --- |
| **SI_ACCESS_SPECIFIC** | The access right is displayed on the advanced security pages. |
| **SI_ACCESS_GENERAL** | The access right is displayed on the basic security page. |
| **SI_ACCESS_CONTAINER** | Indicates an access right that applies only to containers. If this flag is set, the access right is displayed on the basic security page only if the [ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation) method specifies the SI_CONTAINER flag. |
| **SI_ACCESS_PROPERTY** | Indicates a property-specific access right. Used with SI_EDIT_PROPERTIES. |

This member can also specify a combination of the following flags to indicate whether other containers or objects can inherit the access right.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | Other containers that are contained by the primary object inherit the entry. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the primary object to which the ACL is attached, but objects contained by the primary object inherit the entry. |
| **OBJECT_INHERIT_ACE** | Noncontainer objects contained by the primary object inherit the entry. |

## See also

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[ISecurityInformation::GetAccessRights](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getaccessrights)

[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation)