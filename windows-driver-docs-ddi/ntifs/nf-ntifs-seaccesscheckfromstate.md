## Description

**SeAccessCheckFromState** checks whether the requested access rights can be granted to an object that is protected by a security descriptor and an optional object owner.

## Parameters

### `SecurityDescriptor`

[in] Pointer to a [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure containing the security information protecting the object being accessed.

### `PrimaryTokenInformation`

[in] Pointer to the [**TOKEN_ACCESS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-token_access_information) structure captured from the primary token. This structure provides the token's information needed to perform an access check.

### `ClientTokenInformation`

[in_opt] Optional pointer to the [**TOKEN_ACCESS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-token_access_information) structure captured from the client token.

### `DesiredAccess`

[in] An [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the desired access rights to check.

### `PreviouslyGrantedAccess`

[in] An [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies any accesses that the user has already been granted; for example, as a result of holding a privilege.

### `Privileges`

[out] Pointer to a [**PRIVILEGE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_privilege_set) structure in which a privilege set is returned to indicate any privileges that were used as part of the access validation.

### `GenericMapping`

[in] Pointer to the [**GENERIC_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping) structure associated with this object type.

### `AccessMode`

[in] A KPROCESSOR_MODE value that specifies the processor mode to be used in the check. **AccessMode** can be either **KernelMode** or **UserMode**. Lower-level drivers should specify **KernelMode**.

### `GrantedAccess`

[out] Pointer to a returned [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that indicates the granted access.

### `AccessStatus`

[out] Pointer to an NT status value that can be returned to indicate why access was denied. See Remarks.

## Return value

**SeAccessCheckFromState** returns TRUE if access is allowed; it returns FALSE if access is not allowed.

## Remarks

**SeAccessCheckFromState** might perform tests for the following privileges, depending on the accesses being requested:

* **SeTakeOwnershipPrivilege**
* **SeSecurityPrivilege**

This routine also might check whether the caller is the owner of the object in order to grant WRITE_DAC or READ_CONTROL access.

If this routine returns FALSE, the caller should use the returned **AccessStatus** as its return value. That is, the caller should avoid hardcoding a return value of STATUS_ACCESS_DENIED or any other specific STATUS_*XXX* value.

This routine might be called from DPC level so must not be pageable.

## See also

[**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[**SeAccessCheckFromStateEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seaccesscheckfromstateex)