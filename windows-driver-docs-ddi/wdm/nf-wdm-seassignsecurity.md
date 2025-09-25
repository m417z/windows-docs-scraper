# SeAssignSecurity function

## Description

The
**SeAssignSecurity** routine builds a self-relative security descriptor for a new object, given the security descriptor of its parent directory and any originally requested security for the object.

## Parameters

### `ParentDescriptor` [in, optional]

Pointer to a buffer containing the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) for the parent directory, if any, containing the new object being created. *ParentDescriptor* can be **NULL**, or have a **NULL** system access control list ([SACL](https://learn.microsoft.com/windows-hardware/drivers/)) or a **NULL** discretionary access control list ([DACL](https://learn.microsoft.com/windows-hardware/drivers/)).

### `ExplicitDescriptor` [in, optional]

Pointer to a buffer containing the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) specified by the user that is applied to the new object. *ExplicitDescriptor* can be **NULL**, or have a **NULL** SACL or a **NULL** DACL.

### `NewDescriptor` [out]

Receives a pointer to the returned [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor). **SeAssignSecurity** allocates the buffer from the paged memory pool.

### `IsDirectoryObject` [in]

Specifies whether the new object is a directory object. **TRUE** indicates the object contains other objects.

### `SubjectContext` [in]

Pointer to a buffer containing the security context of the subject creating the object. This is used to retrieve default security information for the new object, such as the default owner, the primary group, and discretionary access control.

### `GenericMapping` [in]

Pointer to the [GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping) structure that describes the mapping from each generic right to the implied nongeneric rights.

### `PoolType` [in]

This parameter is unused. The buffer to hold the new security descriptor is always allocated from paged pool.

## Return value

**SeAssignSecurity** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The assignment was successful. |
| **STATUS_INVALID_OWNER** | The SID provided for the owner of the target security descriptor is not one the caller is authorized to assign as the owner of an object. |
| **STATUS_PRIVILEGE_NOT_HELD** | The caller does not have the privilege (**SeSecurityPrivilege**) necessary to explicitly assign the specified system ACL. |

## Remarks

The final security descriptor returned to the caller may contain a mix of information, some explicitly provided from the new object's parent.

**SeAssignSecurity** assumes privilege checking has not been performed. This routine performs privilege checking.

The assignment of system and discretionary ACLs is governed by the logic illustrated in the following table:

|  | Explicit (nondefault) ACL specified | Explicit default ACL specified | No ACL specified |
| --- | --- | --- | --- |
| **Inheritable ACL from parent** | Assign specified ACL | Assign inherited ACL | Assign inherited ACL |
| **No inheritable ACL from parent** | Assign specified ACL | Assign default ACL | Assign no ACL |

An explicitly specified ACL, whether a default ACL or not, can be empty or null. The caller must be a kernel-mode client or be appropriately privileged to explicitly assign a default or nondefault system ACL.

The assignment of the new object's owner and group is governed by the following logic:

* If the passed security descriptor includes an owner, it is assigned as the new object's owner. Otherwise, the caller's token is considered to determine the owner. Within the token, the default owner, if any, is assigned. Otherwise, the caller's user ID is assigned.
* If the passed security descriptor includes a group, it is assigned as the new object's group. Otherwise, the caller's token is considered to determine the group. Within the token, the default group, if any, is assigned. Otherwise, the caller's primary group ID is assigned.

## See also

[GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)

[IoGetFileObjectGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetfileobjectgenericmapping)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SeDeassignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-sedeassignsecurity)