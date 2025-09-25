# ACCESS_DENIED_CALLBACK_OBJECT_ACE structure

## Description

The **ACCESS_DENIED_CALLBACK_OBJECT_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) that controls denied access to an object, a property set, or property. The ACE contains a set of access rights, a **GUID** that identifies the type of object, and a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) to whom the system will deny access. The ACE also contains a **GUID** and a set of flags that control inheritance of the ACE by child objects.

When the [AuthzAccessCheck](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzaccesscheck) function is called, each **ACCESS_DENIED_CALLBACK_OBJECT_ACE** structure contained in the DACL of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure passed through a pointer to the **AuthzAccessCheck** function invokes a call to the application–defined [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) function, in which a pointer to the **ACCESS_DENIED_CALLBACK_OBJECT_ACE** structure found is passed in the *pAce* parameter.

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure should be set to ACCESS_DENIED_CALLBACK_ACE_TYPE, and the **AceSize** member should be set to the total number of bytes allocated for the **ACCESS_DENIED_CALLBACK_OBJECT_ACE** structure.

### `Mask`

An
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) that specifies the access rights the system will deny to the trustee.

### `Flags`

A set of bit flags that indicate whether the **ObjectType** and **InheritedObjectType** members are present. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Neither **ObjectType** nor **InheritedObjectType** are present. The **SidStart** member follows immediately after the **Flags** member. |
| **ACE_OBJECT_TYPE_PRESENT** | **ObjectType** is present and contains a **GUID**. <br><br>If this value is not specified, the **InheritedObjectType** member follows immediately after the **Flags** member. |
| **ACE_INHERITED_OBJECT_TYPE_PRESENT** | **InheritedObjectType** is present and contains a **GUID**. <br><br>If this value is not specified, all types of child objects can inherit the ACE. |

### `ObjectType`

This member exists only if the ACE_OBJECT_TYPE_PRESENT bit is set in the **Flags** member. Otherwise, the **InheritedObjectType** member follows immediately after the **Flags** member.

If this member exists, it is a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies a property set, property, extended right, or type of child object. The purpose of this **GUID** depends on the access rights specified in the **Mask** member.

| Value | Meaning |
| --- | --- |
| **ADS_RIGHT_DS_CONTROL_ACCESS** | The **ObjectType** **GUID** identifies an extended access right. |
| **ADS_RIGHT_DS_CREATE_CHILD** | The **ObjectType** **GUID** identifies a type of child object. The ACE controls the trustee's right to create this type of child object. |
| **ADS_RIGHT_DS_READ_PROP** | The **ObjectType** **GUID** identifies a property set or property of the object. The ACE controls the trustee's right to read the property or property set. |
| **ADS_RIGHT_DS_WRITE_PROP** | The **ObjectType** **GUID** identifies a property set or property of the object. The ACE controls the trustee's right to write the property or property set. |
| **ADS_RIGHT_DS_SELF** | The **ObjectType** **GUID** identifies a validated write. |

### `InheritedObjectType`

This member exists only if the ACE_INHERITED_OBJECT_TYPE_PRESENT bit is set in the **Flags** member.

If this member exists, it is a
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of child object that can inherit the ACE. Inheritance is also controlled by the inheritance flags in the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header), as well as by any protection against inheritance placed on the child objects.

The offset of this member can vary. If the **Flags** member does not contain the ACE_OBJECT_TYPE_PRESENT flag, the **InheritedObjectType** member starts at the offset specified by the **ObjectType** member.

### `SidStart`

The first **DWORD** of a trustee's SID.
The remaining bytes of the SID are stored in contiguous memory after the **SidStart** member. This SID can be appended with application data.

## Remarks

If neither the **ObjectType** nor **InheritedObjectType** **GUID** is specified, the **ACCESS_DENIED_CALLBACK_OBJECT_ACE** structure has the same semantics as those used by the [ACCESS_DENIED_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_callback_ace) structure. In that case, use the
**ACCESS_DENIED_CALLBACK_ACE** structure because it is smaller and more efficient.

An ACL that contains an **ACCESS_DENIED_CALLBACK_OBJECT_ACE** must specify the ACL_REVISION_DS revision number in its
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) header.

The access rights specified by the **Mask** member are denied to any [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) that possesses an enabled SID that matches the SID stored in the **SidStart** member.

When an **ACCESS_DENIED_CALLBACK_OBJECT_ACE** structure is created, sufficient memory must be allocated to accommodate the GUID structures in the **ObjectType** and **InheritedObjectType** members, if one or both of them exists, as well as to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory that follows it.

## See also

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAuditAccessObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessobjectace)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)