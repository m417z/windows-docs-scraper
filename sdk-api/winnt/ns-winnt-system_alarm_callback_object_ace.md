# SYSTEM_ALARM_CALLBACK_OBJECT_ACE structure

## Description

Not supported.

The **SYSTEM_ALARM_CALLBACK_OBJECT_ACE** structure is reserved for future use.

## Members

### `Header`

[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of ACE. It contains flags that control inheritance of the ACE by child objects. The structure also contains flags that indicate whether the ACE audits successful access attempts, failed access attempts, or both. The **AceType** member of the **ACE_HEADER** structure should be set to SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE.

### `Mask`

An
[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) that specifies the access rights the system will audit for access attempts by the [trustee](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly).

### `Flags`

A set of bit flags that indicate whether the **ObjectType** and **InheritedObjectType** members contain GUIDs. This parameter can be a combination of the following values. Set all undefined bits to zero.

| Value | Meaning |
| --- | --- |
| **ACE_OBJECT_TYPE_PRESENT** | The **ObjectType** member contains a GUID. |
| **ACE_INHERITED_OBJECT_TYPE_PRESENT** | The **InheritedObjectType** member contains a GUID. |

### `ObjectType`

A
[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that identifies a property set, property, extended right, or type of child object.

This member is valid only if the ACE_OBJECT_TYPE_PRESENT bit is set in the **Flags** member. Otherwise, **ObjectType** is ignored.

The purpose of this GUID depends on the access rights specified in the **Mask** member.

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

### `SidStart`

The first **DWORD** of a trustee's ACE. This ACE can be appended with application data. When the [AuthzAccessCheckCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzaccesscheckcallback) function is called, this ACE is passed as the *pAce* parameter of that function.

## Remarks

If neither the **ObjectType** nor **InheritedObjectType** GUID is specified, the **SYSTEM_ALARM_CALLBACK_OBJECT_ACE** structure has the same semantics as the [SYSTEM_ALARM_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_callback_ace) structure. In that case, use the
**SYSTEM_ALARM_CALLBACK_ACE** structure because it is smaller and more efficient.

An ACL that contains an **SYSTEM_ALARM_CALLBACK_OBJECT_ACE** must specify the ACL_REVISION_DS revision number in its
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure.