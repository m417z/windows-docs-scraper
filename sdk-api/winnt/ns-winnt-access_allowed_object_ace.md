# ACCESS_ALLOWED_OBJECT_ACE structure

## Description

The **ACCESS_ALLOWED_OBJECT_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) that controls allowed access to an object, a property set, or property. The ACE contains a set of access rights, a **GUID** that identifies the type of object, and a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) to whom the system will grant access. The ACE also contains a **GUID** and a set of flags that control inheritance of the ACE by child objects.

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure should be set to ACCESS_ALLOWED_OBJECT_ACE_TYPE, and the **AceSize** member should be set to the total number of bytes allocated for the **ACCESS_ALLOWED_OBJECT_ACE** structure.

### `Mask`

An
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) that specifies the access rights the system will allow to the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly).

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

Specifies the first **DWORD** of a SID that identifies the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) to whom the access rights are granted. The remaining bytes of the SID are stored in contiguous memory after the **SidStart** member. This SID can be appended with application data.

The offset of this member can vary. If the **Flags** member is zero, the **SidStart** member starts at the offset specified by the **ObjectType** member. If **Flags** contains only one flag (either ACE_OBJECT_TYPE_PRESENT or ACE_INHERITED_OBJECT_TYPE_PRESENT), the **SidStart** member starts at the offset specified by the **InheritedObjectType** member.

## Remarks

If neither the **ObjectType** nor **InheritedObjectType** [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) is specified, the **ACCESS_ALLOWED_OBJECT_ACE** structure has the same semantics as those used by the [ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace) structure. In that case, use the **ACCESS_ALLOWED_ACE** structure because it is smaller and more efficient.

An ACL that contains an **ACCESS_ALLOWED_OBJECT_ACE** must specify the ACL_REVISION_DS revision number in its
[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) header.

The access rights specified by the **Mask** member are granted to any [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) that possesses an enabled SID that matches the SID stored in the **SidStart** member.

An **ACCESS_ALLOWED_OBJECT_ACE** structure can be created in an [access control list](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACL) by a call to the [AddAccessAllowedObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedobjectace) function. When this function is used, the correct amount of memory needed to accommodate the GUID structures in the **ObjectType** and **InheritedObjectType** members, if one or both of them exists, as well as to accommodate the trustee's SID is automatically allocated. In addition, the values of the **Header.AceType** and **Header.AceSize** members are set automatically. When an **ACCESS_ALLOWED_OBJECT_ACE** structure is created outside an ACL, sufficient memory must be allocated to accommodate the GUID structures in the **ObjectType** and **InheritedObjectType** members, if one or both of them exists, as well as to accommodate the complete SID of the trustee in the **SidStart** member and the contiguous memory following it. In addition, the values of the **Header.AceType** and **Header.AceSize** members must be set explicitly by the application.

## See also

[ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[AddAccessAllowedObjectAce](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-addaccessallowedobjectace)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)