# SeSetSecurityDescriptorInfo function

## Description

The **SeSetSecurityDescriptorInfo** routine sets an object's security descriptor.

## Parameters

### `Object` [in, optional]

Pointer to the object whose security descriptor is to be set. This is used to update security quota information.

### `SecurityInformation` [in]

Pointer to a bitmask specifying which security information is to be applied to the object. Can be a combination of one or more of the following values.

| Value | Meaning |
| ----- | ------- |
| DACL_SECURITY_INFORMATION | Indicates the discretionary access control list (DACL) of the object is being set. Requires WRITE_DAC access. |
| GROUP_SECURITY_INFORMATION | Indicates the primary group identifier of the object is being set. Requires WRITE_OWNER access. |
| OWNER_SECURITY_INFORMATION | Indicates the owner identifier of the object is being set. Requires WRITE_OWNER access. |
| SACL_SECURITY_INFORMATION | Indicates the system ACL (SACL) of the object is being set. Requires ACCESS_SYSTEM_SECURITY access. |

### `ModificationDescriptor`

The input security descriptor to be applied to the object. The caller of this routine is expected to probe and capture the passed security descriptor before calling **SeSetSecurityDescriptorInfo**, and to release it afterward.

### `ObjectsSecurityDescriptor` [in, out]

Pointer to a pointer to the object's security descriptor. The security descriptor must be in self-relative format. The caller is responsible for freeing this structure when it is no longer needed.

### `PoolType` [in]

Specifies the pool type to use when allocating a new security descriptor, which can be one of the following:

* **NonPagedPool**
* **PagedPool**
* **NonPagedPoolCacheAligned**
* **PagedPoolCacheAligned**

Usually, a caller specifies **PagedPool**, or else **NonPagedPool** if the buffer will be accessed at IRQL >= DISPATCH_LEVEL or in an arbitrary thread context.

The **NonPagedPoolMustSucceed** and **NonPagedPoolCacheAlignedMustS** pool types are obsolete and should no longer be used.

### `GenericMapping` [in]

Pointer to a GENERIC_MAPPING structure that specifies the mapping of generic to specific and standard access types for the object being accessed. This mapping structure is expected to be safe to access (that is, captured if necessary) prior to be passed to this routine.

## Return value

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The object's security descriptor was successfully modified. |
| STATUS_BAD_DESCRIPTOR_FORMAT | The provided object's security descriptor was not in self-relative format. |
| STATUS_NO_SECURITY_ON_OBJECT | The object does not have a security descriptor.

## Remarks

**SeSetSecurityDescriptorInfo** modifies an object's existing security descriptor. If the object does not have a security descriptor, the call to **SeSetSecurityDescriptorInfo** will fail.

To specify whether the object supports automatic inheritance of access control entries (ACE), use **SeSetSecurityDescriptorInfoEx**.

A security descriptor can be in absolute or self-relative form. In self-relative form, all members of the structure are located contiguously in memory. In absolute form, the structure only contains pointers to the members.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**ACE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**GENERIC_MAPPING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)

[**RtlCreateSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[**RtlCreateSecurityDescriptorRelative**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesecuritydescriptorrelative)

[**RtlLengthSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[**RtlSetDaclSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[**RtlSetOwnerSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[**RtlValidSecurityDescriptor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)

[**SeQuerySecurityDescriptorInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysecuritydescriptorinfo)

[**SeSetAccessStateGenericMapping**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetaccessstategenericmapping)

[**SeSetSecurityDescriptorInfoEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetsecuritydescriptorinfoex)