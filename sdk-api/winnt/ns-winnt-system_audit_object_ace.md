# SYSTEM_AUDIT_OBJECT_ACE structure

## Description

The **SYSTEM_AUDIT_OBJECT_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL). The ACE can audit access to an object or subobjects such as property sets or properties. The ACE contains a set of access rights, a GUID that identifies the type of object or subobject, and a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) for whom the system will audit access. The ACE also contains a GUID and a set of flags that control inheritance of the ACE by child objects.

## Members

### `Header`

An
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It contains flags that control inheritance of the ACE by child objects. The structure also contains flags that indicate whether the ACE audits successful access attempts, failed access attempts, or both. The **AceType** member of the **ACE_HEADER** structure should be set to SYSTEM_AUDIT_OBJECT_ACE_TYPE, and the **AceSize** member should be set to the total number of bytes allocated for the **SYSTEM_AUDIT_OBJECT_ACE** structure.

### `Mask`

An
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) that specifies the access rights the system will audit for access attempts by the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly).

### `Flags`

A set of bit flags that indicate whether the **ObjectType** and **InheritedObjectType** members contain GUIDs. This member can be a combination of the following values. Set all undefined bits to zero.

| Value | Meaning |
| --- | --- |
| **ACE_OBJECT_TYPE_PRESENT** | The **ObjectType** member contains a GUID. |
| **ACE_INHERITED_OBJECT_TYPE_PRESENT** | The **InheritedObjectType** member contains a GUID. |

### `ObjectType`

A
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies a property set, property, extended right, or type of child object.

This member is valid only if the ACE_OBJECT_TYPE_PRESENT bit is set in the **Flags** member. Otherwise, **ObjectType** is ignored.

The purpose of this GUID depends on the access rights specified in the **Mask** member.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ADS_RIGHT_DS_READ_PROP and/or ADS_RIGHT_DS_WRITE_PROP** | The **ObjectType** GUID identifies a property set or property of the object. The ACE controls auditing of the trustee's attempts to read or write the property or property set. |
| **ADS_RIGHT_DS_CONTROL_ACCESS** | The **ObjectType** GUID identifies an extended access right. |
| **ADS_RIGHT_DS_CREATE_CHILD** | The **ObjectType** GUID identifies a type of child object. The ACE controls auditing of the trustee's attempts to create this type of child object. |
| **ADS_RIGHT_DS_SELF** | The **ObjectType** GUID identifies a validated write. |

### `InheritedObjectType`

A [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies the type of child object that can inherit the ACE.

This member is valid only if the ACE_INHERITED_OBJECT_TYPE_PRESENT bit is set in the **Flags** member. If that bit is not set, **InheritedObjectType** is ignored and all types of child objects can inherit the ACE. In either case, inheritance is also controlled by the inheritance flags in the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header), as well as by any protection against inheritance placed on the child objects.

The offset of this member can vary. If the **Flags** member does not contain the ACE_OBJECT_TYPE_PRESENT flag, the **InheritedObjectType** member starts at the offset specified by the **ObjectType** member.

### `SidStart`

Specifies the first **DWORD** of a SID that identifies the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) for whom the access attempts are audited. The remaining bytes of the SID are stored in contiguous memory after the **SidStart** member. This SID can be appended with application data.

The offset of this member can vary. If the **Flags** member is zero, the **SidStart** member starts at the offset specified by the **ObjectType** member. If **Flags** contains only one flag (either ACE_OBJECT_TYPE_PRESENT or ACE_INHERITED_OBJECT_TYPE_PRESENT), the **SidStart** member starts at the offset specified by the **InheritedObjectType** member.

## Remarks

If neither the **ObjectType** nor **InheritedObjectType** GUID is specified, the **SYSTEM_AUDIT_OBJECT_ACE** structure has the same semantics as the [SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structure. In that case, use the
**SYSTEM_AUDIT_ACE** structure because it is smaller and more efficient.

An ACL that contains an **SYSTEM_AUDIT_OBJECT_ACE** must specify the ACL_REVISION_DS revision number in its
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure.

When a **SYSTEM_AUDIT_OBJECT_ACE** structure is created, sufficient memory must be allocated to accommodate the GUID structures in **ObjectType** and **InheritedObjectType** members, if one or both of them exists, as well as to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory that follows it.

An **SYSTEM_AUDIT_OBJECT_ACE** structure can be created in an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) by a call to the [AddAuditAccessObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessobjectace) function. When this function is used, the correct amount of memory needed to accommodate the GUID structures in the **ObjectType** and **InheritedObjectType** members, if one or both of them exists, as well as to accommodate the trustee's SID is automatically allocated. In addition, the values of the **Header.AceType** and **Header.AceSize** members are set automatically. When an **SYSTEM_AUDIT_OBJECT_ACE** structure is created outside an ACL, sufficient memory must be allocated to accommodate the GUID structures in the **ObjectType** and **InheritedObjectType** members, if one or both of them exists, as well as to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory following it. In addition, the values of the **Header.AceType** and **Header.AceSize** members must be set explicitly by the application.

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAuditAccessObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addauditaccessobjectace)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)