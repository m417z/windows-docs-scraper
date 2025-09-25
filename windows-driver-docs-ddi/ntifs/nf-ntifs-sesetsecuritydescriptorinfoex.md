# SeSetSecurityDescriptorInfoEx function

## Description

The **SeSetSecurityDescriptorInfoEx** routine modifies an object's security descriptor and specifies whether the object supports automatic inheritance of access control entries (ACE).

## Parameters

### `Object` [in, optional]

Pointer to the object whose security descriptor is to be modified. This is used to update security quota information.

### `SecurityInformation` [in]

Pointer to a value specifying which security information is to be set. Can be a combination of one or more of the following.

| Value | Meaning |
| ----- | ------- |
| DACL_SECURITY_INFORMATION | Indicates the discretionary access control list (DACL) of the object is being set. Requires WRITE_DAC access. |
| GROUP_SECURITY_INFORMATION | Indicates the primary group identifier of the object is being set. Requires WRITE_OWNER access. |
| OWNER_SECURITY_INFORMATION | Indicates the owner identifier of the object is being set. Requires WRITE_OWNER access. |
| SACL_SECURITY_INFORMATION | Indicates the system ACL (SACL) of the object is being set. Requires ACCESS_SYSTEM_SECURITY access. |

### `ModificationDescriptor`

The input security descriptor to be applied to the object. The caller of this routine is expected to probe and capture the passed security descriptor before calling, and to release it after calling.

### `ObjectsSecurityDescriptor` [in, out]

Pointer to a pointer to the object's security descriptor. The security descriptor must be in self-relative format. This structure must be deallocated by the caller.

### `AutoInheritFlags` [in]

Bitmask that controls automatic inheritance of ACEs. Set to the logical OR of one or more of the following bit flags:

| Security Information Flags | Meaning |
| -------------------------- | ------- |
| SEF_DACL_AUTO_INHERIT | If this flag is set, the DACL is treated as an auto-inherit DACL and is processed as described in the following Remarks section. This bit is ignored if DACL_SECURITY_INFORMATION is not set in the **SecurityInformation** parameter.|
| SEF_SACL_AUTO_INHERIT | If this flag is set, the SACL is treated as an auto-inherit SACL and is processed as described in the following Remarks section. This bit is ignored if SACL_SECURITY_INFORMATION is not set in the **SecurityInformation** parameter.

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
| STATUS_NO_SECURITY_ON_OBJECT | The object does not have a security descriptor. |

## Remarks

If the **AutoInheritFlags** parameter is zero, the effect of calling **SeSetSecurityDescriptorInfoEx** is the same as that of calling **SeSetSecurityDescriptorInfo**.

If **AutoInheritFlags** specifies the SEF_DACL_AUTO_INHERIT bit, **SeSetSecurityDescriptorInfoEx** applies the following rules to the DACL to create the new security descriptor from the current descriptor:

* If the SE_DACL_PROTECTED flag is not set in the control bits of the either the current security descriptor or the input **SecurityDescriptor**, **SeSetSecurityDescriptorInfoEx** constructs the output security descriptor from the inherited ACEs of the current security descriptor and noninherited ACEs of **SecurityDescriptor**. That is, it is impossible to change an inherited ACE by changing the ACL on an object. This behavior preserves the inherited ACEs as they were inherited from the parent container.

* If SE_DACL_PROTECTED is set in the input **SecurityDescriptor**, the current security descriptor is ignored. The output security descriptor is built as a copy of the input **SecurityDescriptor** with any INHERITED_ACE bits turned off.

Ideally an ACL editor should turn off the INHERITED_ACE bits indicating to its caller that the ACEs inherited from the object's parent are now being explicitly set on the object.

* If SE_DACL_PROTECTED is set in the current security descriptor and not in the **SecurityDescriptor**, the current security descriptor is ignored. The output security descriptor is built as a copy of the **SecurityDescriptor**. It is the caller's responsibility to ensure that the correct ACEs have the INHERITED_ACE bit turned on.

If **AutoInheritFlags** specifies the SEF_SACL_AUTO_INHERIT bit, **SeSetSecurityDescriptorInfoEx** applies similar rules to the new SACL.

For more information about access control and ACE inheritance, see the Security section of the Microsoft Windows SDK documentation.

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

[**SeSetSecurityDescriptorInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetsecuritydescriptorinfo)