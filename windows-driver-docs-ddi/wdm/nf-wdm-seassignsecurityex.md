# SeAssignSecurityEx function

## Description

The
**SeAssignSecurityEx** routine builds a self-relative security descriptor for a new object given the following optional parameters: a security descriptor of the object's parent directory, an explicit security descriptor for the object, and the object type.

## Parameters

### `ParentDescriptor` [in, optional]

Pointer to the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) of the parent object that contains the new object being created. *ParentDescriptor* can be **NULL**, or have a **NULL** system access control list ([SACL](https://learn.microsoft.com/windows-hardware/drivers/)) or a **NULL** discretionary access control list ([DACL](https://learn.microsoft.com/windows-hardware/drivers/)).

### `ExplicitDescriptor` [in, optional]

Pointer to an explicit [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) that is applied to the new object. *ExplicitDescriptor* can be **NULL**, or have a **NULL** SACL or a **NULL** DACL.

### `NewDescriptor` [out]

Receives a pointer to the returned [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor). **SeAssignSecurityEx** allocates the buffer from the paged memory pool.

### `ObjectType` [in, optional]

Pointer to a GUID for the type of object being created. If the object does not have a GUID, *ObjectType* must be set to **NULL**.

### `IsDirectoryObject` [in]

Specifies whether the new object is a directory object. If *IsDirectoryObject* is set to **TRUE**, the new object is a directory object, otherwise the new object is not a directory object.

### `AutoInheritFlags` [in]

Specifies the type of automatic inheritance that is applied to access control entries ([ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)) in the access control lists ([ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)) specified by *ParentDescriptor*. *AutoInheritFlags* also controls privilege checking, owner checking, and setting a default owner and group for *NewDescriptor*. *AutoInheritFlags* must be set to a logical OR of one or more of the following values:

| Value | Meaning |
| --- | --- |
| SEF_DACL_AUTO_INHERIT | ACEs in the DACL of *ParentDescriptor* are inherited by *NewDescripto*r, in addition to explicit ACEs specified by *ExplicitDescriptor*. |
| SEF_SACL_AUTO_INHERIT | ACEs in the SACL of *ParentDescriptor* are inherited by *NewDescriptor*, in addition to explicit ACEs specified by *ExplicitDescriptor*. |
| SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT | *ExplicitDescriptor* is the default descriptor for the object type specified by *ObjectType*. *ExplicitDescriptor* is not used if ACEs are inherited from *ParentDescriptor*. |
| SEF_AVOID_PRIVILEGE_CHECK | Privilege checking is not done. This flag is useful with automatic inheritance because it avoids privilege checking on each child that needs to be updated. |
| SEF_AVOID_OWNER_CHECK | Owner checking is not done. |
| SEF_DEFAULT_OWNER_FROM_PARENT | If an owner is specified by *ExplicitDescriptor*, this flag is not used, and the owner of *NewDescriptor* is set to the owner specified by *ExplictDescriptor*.<br><br>If an owner is not specified by *ExplicitDescriptor*, this flag is used in the following way: If the flag is set, the owner of *NewDescriptor* is set to the owner of *ParentDescriptor*. Otherwise, the owner of *NewDescriptor* is set to the owner specified by the *SubjectContext.* |
| SEF_DEFAULT_GROUP_FROM_PARENT | If a group is specified by *ExplicitDescriptor*, this flag is not used, and the group of *NewDescriptor* is set to the group specified by *ExplictDescriptor*.<br><br>If a group is not specified by *ExplicitDescriptor*, this flag is used in the following way: If the flag is set, the group of *NewDescriptor* is set to the group of *ParentDescriptor*. Otherwise, the group of *NewDescriptor* is set to the group specified by the *SubjectContext.* |

The assignment of system and discretionary ACLs is described in the following table:

|  | Nondefault explicit descriptor(1) | Default explicit descriptor(2) | **NULL** Explicit descriptor |
| --- | --- | --- | --- |
| ACL is inherited from parent descriptor(3). | Assign both inherited and explicit ACLs(5)(6). | Assign inherited ACL. | Assign inherited ACL. |
| ACL is not inherited from parent descriptor(4). | Assign nondefault ACL. | Assign default ACL. | Assign no ACL. |

**Assignment Notes**

1. The SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT flag is not specified.
2. The SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT flag is specified.
3. The auto inherit flag for an ACL is specified (SEF_DACL_AUTO_INHERIT or SEF_SACL_AUTO_INHERIT).
4. The automatic inherit flag for an ACL is not specified.
5. ACEs with the INHERITED_ACE bit set in their **AceFlags** member are not copied to the assigned security descriptor.
6. ACEs that are inherited from the parent descriptor are appended after the ACEs specified by the explicit descriptor.

### `SubjectContext` [in]

Pointer to a security context of the subject that is creating the object. *SubjectContext* is used to retrieve default security information for the new object, including the default owner, the primary group, and discretionary access control.

### `GenericMapping` [in]

Pointer to an array of access mask values that specify the mapping between each generic rights to object-specific rights.

### `PoolType` [in]

This parameter is unused. The buffer to hold the new security descriptor is always allocated from paged pool.

## Return value

**SeAssignSecurityEx** returns one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The assignment was successful. |
| **STATUS_INVALID_OWNER** | The SID provided as the owner of the new security descriptor is not a SID that the caller is authorized to assign as the owner of an object. |
| **STATUS_PRIVILEGE_NOT_HELD** | The caller does not have the privilege (**SeSecurityPrivilege**) necessary to explicitly assign the specified SACL. |

## Remarks

**SeAssignSecurityEx** extends the basic operation of **SeAssignSecurity** in the following ways:

* *ObjectType* optionally specifies an object type. Object-specific inheritance is controlled by the following members of an object-specific ACE: **Flags**, **InheritedObjectType**, and **Header.AceFlags**.
* *AutoInheritFlags* specifies the type of automatic inheritance of ACEs that is used. AutoInheritFlags also controls privilege checking, owner checking, and setting a default owner and group for *NewDescriptor*.

For more information about security and access control, see the documentation on these topics in the Microsoft Windows SDK.

## See also

[GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SeAssignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)

[SeDeassignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-sedeassignsecurity)