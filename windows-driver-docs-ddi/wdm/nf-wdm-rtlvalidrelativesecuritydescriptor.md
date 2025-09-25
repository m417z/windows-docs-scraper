# RtlValidRelativeSecurityDescriptor function

## Description

The **RtlValidRelativeSecurityDescriptor** routine checks the validity of a self-relative security descriptor.

## Parameters

### `SecurityDescriptorInput` [in]

A pointer to the buffer that contains the security descriptor in self-relative format. The buffer must begin with a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure, which is followed by the rest of the security descriptor data.

### `SecurityDescriptorLength` [in]

The size of the *SecurityDescriptorInput* structure.

### `RequiredInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information) value that specifies the information that is required to be contained in the security descriptor.

## Return value

**RtlValidRelativeSecurityDescriptor** returns **TRUE** if the security descriptor is valid and includes the information that the *RequiredInformation* parameter specifies. Otherwise, this routine returns **FALSE**.

## Remarks

To check the validity of a security descriptor in absolute format, use [RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor) instead.

## See also

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)