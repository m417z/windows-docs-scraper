# AddAccessDeniedObjectAce function

## Description

The **AddAccessDeniedObjectAce** function adds an access-denied [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to the end of a [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL). The new ACE can deny access to an object, or to a property set or property on an object. You can also use **AddAccessDeniedObjectAce** to add an ACE that only a specified type of child object can inherit.

## Parameters

### `pAcl` [in, out]

A pointer to a DACL. The **AddAccessDeniedObjectAce** function adds an access-denied ACE to the end of this DACL. The ACE is in the form of an
[ACCESS_DENIED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_object_ace) structure.

### `dwAceRevision` [in]

Specifies the revision level of the DACL being modified. This value must be ACL_REVISION_DS. If the DACL's revision level is lower than ACL_REVISION_DS, the function changes it to ACL_REVISION_DS.

### `AceFlags` [in]

A set of bit flags that control ACE inheritance. The function sets these flags in the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure of the new ACE. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | The ACE is inherited by container objects. |
| **INHERIT_ONLY_ACE** | The ACE does not apply to the object to which the [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) is assigned, but it can be inherited by child objects. |
| **INHERITED_ACE** | Indicates an inherited ACE. This flag allows operations that change the security on a tree of objects to modify inherited ACEs, while not changing ACEs that were directly applied to the object. |
| **NO_PROPAGATE_INHERIT_ACE** | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE bits are not propagated to an inherited ACE. |
| **OBJECT_INHERIT_ACE** | The ACE is inherited by noncontainer objects. |

### `AccessMask` [in]

A set of bit flags that use the
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) format to specify the access rights that the new ACE denies to the specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

### `ObjectTypeGuid` [in, optional]

A pointer to a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object, property set, or property protected by the new ACE. If this parameter is **NULL**, the new ACE protects the object to which the ACL is assigned.

### `InheritedObjectTypeGuid` [in, optional]

A pointer to a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of object that can inherit the new ACE. If this parameter is non-**NULL**, only the specified object type can inherit the ACE. If **NULL**, any type of child object can inherit the ACE. In either case, inheritance is also controlled by the value of the *AceFlags* parameter, as well as by any protection against inheritance placed on the child objects.

### `pSid` [in]

A pointer to a
SID that identifies the user, group, or [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) to which the new ACE allows access.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code | Description |
| --- | --- |
| **ERROR_ALLOTTED_SPACE_EXCEEDED** | The new ACE does not fit into the ACL. A larger ACL buffer is required. |
| **ERROR_INVALID_ACL** | The specified ACL is not properly formed. |
| **ERROR_INVALID_FLAGS** | The *AceFlags* parameter is not valid. |
| **ERROR_INVALID_SID** | The specified SID is not structurally valid. |
| **ERROR_REVISION_MISMATCH** | The specified revision is not known or is incompatible with that of the ACL. |
| **ERROR_SUCCESS** | The ACE was successfully added. |

## Remarks

If both *ObjectTypeGuid* and *InheritedObjectTypeGuid* are **NULL**, use the
[AddAccessDeniedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedaceex) function rather than **AddAccessDeniedObjectAce**. This is suggested because an
[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace) is smaller and more efficient than an
[ACCESS_DENIED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_object_ace).

Although the **AddAccessDeniedObjectAce** function adds the new ACE to the end of the ACL, access-denied ACEs should appear at the beginning of an ACL. The caller must ensure that ACEs are added to the DACL in the correct order. For more information, see
[Order of ACEs in a DACL](https://learn.microsoft.com/windows/desktop/SecAuthZ/order-of-aces-in-a-dacl).

## See also

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACCESS_DENIED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_object_ace)

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header)

[AddAccessAllowedObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedobjectace)

[AddAccessDeniedAceEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessdeniedaceex)

[AddAuditAccessObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessobjectace)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[Low-level Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/low-level-access-control)

[Low-level Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)