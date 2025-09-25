# RtlLengthSecurityDescriptor function

## Description

The **RtlLengthSecurityDescriptor** routine returns the size of a given security descriptor.

## Parameters

### `SecurityDescriptor` [in]

Pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor).

## Return value

**RtlLengthSecurityDescriptor** returns the size in bytes of the descriptor.

## See also

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)