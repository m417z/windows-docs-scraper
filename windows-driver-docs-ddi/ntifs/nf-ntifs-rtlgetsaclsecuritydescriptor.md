# RtlGetSaclSecurityDescriptor function

## Description

The **RtlGetSaclSecurityDescriptor** routine returns a pointer to the system ACL (SACL) for a security descriptor.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) whose SACL is to be returned.

### `SaclPresent` [out]

Pointer to a Boolean variable that indicates the presence of a SACL in the specified security descriptor. If this variable receives **TRUE**, the security descriptor contains a SACL, and the remaining output parameters receive valid values. If this variable receives **FALSE**, the security descriptor does not contain a SACL, and the remaining output parameters do not receive valid values.

### `Sacl` [out]

Pointer to a variable that receives the address of the SACL for the security descriptor. If the security descriptor does not have a SACL, this variable does not receive a value. If the security descriptor has a **NULL** SACL, this variable receives **NULL**.

### `SaclDefaulted` [out]

Pointer to a Boolean variable that receives the value of the SE_SACL_DEFAULTED flag in the security descriptor's SECURITY_DESCRIPTOR_CONTROL structure if a SACL exists for the security descriptor.

## Return value

**RtlGetSaclSecurityDescriptor** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_UNKNOWN_REVISION** | The security descriptor's revision level is unknown or is not supported. This is an error code. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlGetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetdaclsecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)