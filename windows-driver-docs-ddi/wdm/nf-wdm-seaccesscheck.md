# SeAccessCheck function

## Description

**SeAccessCheck** determines whether the requested access rights can be granted to an object protected by a security descriptor and an object owner.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that describes the security descriptor protecting the object being accessed.

### `SubjectSecurityContext` [in]

Pointer to the opaque [**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that specifies the subject's captured security context.

### `SubjectContextLocked` [in]

Boolean value that indicates whether the user's subject context is locked, so that it does not have to be locked again.

### `DesiredAccess` [in]

Specifies the [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) bitmask for the access rights that the caller is attempting to acquire. If the caller sets the MAXIMUM_ALLOWED bit, the routine performs all DACL checks. However, **SeAccessCheck** does not do any privilege checks unless the caller specifically requests them by setting the ACCESS_SYSTEM_SECURITY or WRITE_OWNER bits.

### `PreviouslyGrantedAccess` [in]

Specifies the [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) bitmask of access rights already granted, such as access rights granted as a result of holding a privilege.

### `Privileges` [out]

Pointer to a caller-supplied variable to be set to the address of the [**PRIVILEGE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_privilege_set) structure that will be used as part of the access validation, or this parameter can be NULL. The returned buffer, if any, must be released by the caller with [**SeFreePrivileges**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefreeprivileges).

### `GenericMapping` [in]

Pointer to the [**GENERIC_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping) structure associated with this object type. This value specifies the specific access rights implied by each GENERIC_*XXX* access right.

### `AccessMode` [in]

Specifies the access mode to be used in the check, either **UserMode** or **KernelMode**.

### `GrantedAccess` [out]

Pointer to a returned access mask indicating the granted access. If the caller specifies MAXIMUM_ALLOWED, and the DACL in **SecurityDescriptor** is NULL, then the routine returns GENERIC_ALL plus any additional access the caller explicitly requests.

### `AccessStatus` [out]

Pointer to the status value indicating why access was denied.

## Return value

If access is allowed, **SeAccessCheck** returns TRUE.

## Remarks

**SeAccessCheck** might perform privilege tests for [**SeTakeOwnershipPrivilege** and **SeSecurityPrivilege**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_se_exports), depending on the accesses being requested. It might perform additional privilege testing in future releases of the operating system.

This routine also might check whether the caller is the owner of the object in order to grant WRITE_DAC or READ_CONTROL access.

If this routine returns FALSE, the caller should use the returned **AccessStatus** as its return value. That is, the caller should avoid hardcoding a return value of STATUS_ACCESS_DENIED or any other specific STATUS_*XXX* value.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Microsoft Windows SDK.

## See also

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**GENERIC_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)

[**IoGetFileObjectGenericMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetfileobjectgenericmapping)

[**PRIVILEGE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_privilege_set)

[**SE_EXPORTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_se_exports)

[**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**SeFreePrivileges**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefreeprivileges)

[**SeValidSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-sevalidsecuritydescriptor)