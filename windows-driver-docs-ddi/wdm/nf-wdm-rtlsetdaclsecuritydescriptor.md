# RtlSetDaclSecurityDescriptor function

## Description

The **RtlSetDaclSecurityDescriptor** routine sets the DACL information of an absolute-format security descriptor, or if there is already a DACL present in the security descriptor, it is superseded.

## Parameters

### `SecurityDescriptor` [in, out]

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure. This structure is the security descriptor to which the DACL is to be applied.

### `DaclPresent` [in]

Whether to indicate that a DACL is present in the security descriptor. If this parameter is **FALSE**, **RtlSetDaclSecurityDescriptor** sets the SE_DACL_PRESENT control flag in the security descriptor to **FALSE**. In this case, the remaining optional parameters (*Dacl* and *DaclDefaulted*) are ignored. If *DaclPresent* is **TRUE**, the SE_DACL_PRESENT flag in the security descriptor is set to **TRUE** and the remaining optional parameters are not ignored. For more information about the SE_DACL_PRESENT flag, see [SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control).

### `Dacl` [in, optional]

A pointer to the DACL for the security descriptor. If this parameter is **NULL**, the DACL pointer in the security descriptor is set to **NULL**. A **NULL** DACL pointer unconditionally grants all access to an object and is not the same as an empty DACL. An empty DACL denies all access to an object. If *Dacl* is non-**NULL**, the [ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl) structure supplied by the caller is referenced by, but not copied into, the security descriptor. The caller can allocate the **ACL** structure from paged system memory, and can call the [RtlCreateAcl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl) routine to initialize the structure.

❗**WARNING**❗ Setting a **NULL** DACL allows unrestricted access the object and, therefore, should only be used in strategic scenarios where a security evaluation has validated that this is an acceptable outcome. Consider using an ***empty*** DACL, which defaults to all access being denied by default.

### `DaclDefaulted` [in, optional]

Whether the DACL was supplied by some default mechanism, or was explicitly specified by the caller. If this parameter is **TRUE**, the DACL was supplied by a default mechanism. If *DaclDefaulted* is **FALSE**, the caller explicitly specified the DACL. **RtlSetDaclSecurityDescriptor** copies the value specified for this parameter to the SE_DACL_DEFAULTED control flag in the security descriptor. For more information about the SE_DACL_DEFAULTED flag, see [SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control).

## Return value

**RtlSetDaclSecurityDescriptor** can return one of the following status values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call completed successfully. |
| **STATUS_UNKNOWN_REVISION** | The revision of the security descriptor is unknown. |
| **STATUS_INVALID_SECURITY_DESCR** | The security descriptor is not an absolute format security descriptor. |

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateAcl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control)