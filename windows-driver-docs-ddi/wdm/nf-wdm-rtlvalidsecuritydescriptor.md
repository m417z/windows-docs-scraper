# RtlValidSecurityDescriptor function

## Description

The **RtlValidSecurityDescriptor** routine checks a given security descriptor's validity.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) to be checked.

## Return value

**RtlValidSecurityDescriptor** returns **TRUE** if the given descriptor is valid.

## Remarks

The routine checks the validity of an absolute-format security descriptor. To check the validity of a self-relative security descriptor, use the [RtlValidRelativeSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidrelativesecuritydescriptor) routine instead.

## See also

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlValidRelativeSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidrelativesecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)