# _SECURITY_DESCRIPTOR structure

## Description

The SECURITY_DESCRIPTOR structure contains the security information associated with an object. Drivers use this structure to set and query an object's security status.

Because the internal format of a security descriptor can vary, drivers are not to modify the SECURITY_DESCRIPTOR structure directly. For creating and manipulating a security descriptor, use the functions listed in the See Also section.

## Members

### `Revision`

Specifies the revision level of the security descriptor.

### `Sbz1`

Specifies a zero byte of padding that aligns the Revision member on a 16-bit boundary.

### `Control`

The control information of security descriptor. For more information, see [SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control).

### `Owner`

A pointer to an owner security identifier.
> [!NOTE]
> This member might be invalid. You should use **RtlGetOwnerSecurityDescriptor** to get an owner security identifier.

### `Group`

A pointer to a primary group security identifier.
> [!NOTE]
> This member might be invalid. You should use **RtlGetGroupSecurityDescriptor** to get this member.

### `Sacl`

A pointer to a system access control list (SACL).
> [!NOTE]
> This member might be invalid. You should use **RtlGetSaclSecurityDescriptor** to get this member.

### `Dacl`

A pointer to a discretionary access control list (DACL).
> [!NOTE]
> This member might be invalid. You should use **RtlGetDaclSecurityDescriptor** to get this member.

## Remarks

A security descriptor includes information that specifies the following components of an object's security:
* An owner [SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)
* A primary group SID
* A discretionary [ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl) (DACL)
* A system ACL (SACL)

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[ObGetObjectSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obgetobjectsecurity)

[ObReleaseObjectSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreleaseobjectsecurity)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlGetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetdaclsecuritydescriptor)

[RtlGetGroupSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetgroupsecuritydescriptor)

[RtlGetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetownersecuritydescriptor)

[RtlGetSaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetsaclsecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetGroupSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetgroupsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[SeAssignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)

[SeAssignSecurityEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurityex)

[SeDeassignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-sedeassignsecurity)

[SeSetSecurityDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetsecuritydescriptorinfo)

[SeSetSecurityDescriptorInfoEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetsecuritydescriptorinfoex)

[SeValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-sevalidsecuritydescriptor)

[ZwQuerySecurityObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerysecurityobject)

[ZwSetSecurityObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetsecurityobject)