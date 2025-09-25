# RtlSetOwnerSecurityDescriptor function

## Description

The **RtlSetOwnerSecurityDescriptor** routine sets the owner information of an absolute-format security descriptor. It replaces any owner information that is already present in the security descriptor.

## Parameters

### `SecurityDescriptor` [in, out]

Pointer to the SECURITY_DESCRIPTOR structure whose owner is to be set. **RtlSetOwnerSecurityDescriptor** replaces any existing owner with the new owner.

### `Owner` [in, optional]

Pointer to a security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)) structure for the security descriptor's new primary owner. This pointer, not the SID structure itself, is copied into the security descriptor. If this parameter is **NULL**, **RtlSetOwnerSecurityDescriptor** clears the security descriptor's owner information. This marks the security descriptor as having no owner.

### `OwnerDefaulted` [in, optional]

Set to **TRUE** if the owner information is derived from a default mechanism. If this value is **TRUE**, it is default information. **RtlSetOwnerSecurityDescriptor** sets the SE_OWNER_DEFAULTED flag in the security descriptor's SECURITY_DESCRIPTOR_CONTROL field. If this parameter is **FALSE**, the SE_OWNER_DEFAULTED flag is cleared.

## Return value

**RtlSetOwnerSecurityDescriptor** can return one of the following status codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The owner was successfully set or reset. |
| **STATUS_UNKNOWN_REVISION** | The given security descriptor's version is not recognized by this routine. |
| **STATUS_INVALID_SECURITY_DESCR** | The given security descriptor is not a valid absolute security descriptor. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlCreateSecurityDescriptorRelative](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreatesecuritydescriptorrelative)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_DESCRIPTOR_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-descriptor-control)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SeAssignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)