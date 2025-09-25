# SI_INHERIT_TYPE structure

## Description

The **SI_INHERIT_TYPE** structure contains information about how [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) can be inherited by child objects. The
[ISecurityInformation::GetInheritTypes](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getinherittypes) method uses this structure to specify display strings that the access control editor uses to initialize its property pages.

## Members

### `pguid`

A pointer to a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of child object. This member can be a pointer to GUID_NULL. The GUID corresponds to the **InheritedObjectType** member of an object-specific ACE.

### `dwFlags`

A set of inheritance flags that indicate the types of ACEs that can be inherited by the **pguid** object type. These flags correspond to the **AceFlags** member of an
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | The specified object type can inherit ACEs that have the CONTAINER_INHERIT_ACE flag set. |
| **INHERIT_ONLY_ACE** | The specified object type can inherit ACEs that have the INHERIT_ONLY_ACE flag set. |
| **OBJECT_INHERIT_ACE** | The specified object type can inherit ACEs that have the OBJECT_INHERIT_ACE flag set. |

### `pszName`

A pointer to a null-terminated [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string containing a display string that describes the child object.

Alternatively, **pszName** can be a string resource identifier returned by the
[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. Use the
[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation) method to identify the module that contains the string resource.

## See also

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[ISecurityInformation::GetInheritTypes](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getinherittypes)

[ISecurityInformation::GetObjectInformation](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation-getobjectinformation)