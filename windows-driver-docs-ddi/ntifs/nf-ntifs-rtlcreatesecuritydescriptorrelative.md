# RtlCreateSecurityDescriptorRelative function

## Description

The **RtlCreateSecurityDescriptorRelative** routine initializes a new security descriptor in self-relative format. On return, the security descriptor is initialized with no system ACL (SACL), no discretionary ACL (DACL), no owner, no primary group, and all control flags set to zero.

## Parameters

### `SecurityDescriptor` [out]

Pointer to a caller-allocated buffer, which must be at least **sizeof**(SECURITY_DESCRIPTOR_RELATIVE), to receive the initialized security descriptor.

### `Revision` [in]

Revision level to assign to the security descriptor. This parameter must be SECURITY_DESCRIPTOR_REVISION.

## Return value

**RtlCreateSecurityDescriptorRelative** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call completed successfully. |
| **STATUS_UNKNOWN_REVISION** | The given *Revision* is not known or is not supported. |

## Remarks

In effect, a successful call to this routine initializes a security descriptor without security constraints.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)