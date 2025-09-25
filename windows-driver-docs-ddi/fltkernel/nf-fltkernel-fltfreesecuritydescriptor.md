# FltFreeSecurityDescriptor function

## Description

**FltFreeSecurityDescriptor** frees a security descriptor allocated by the [FltBuildDefaultSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltbuilddefaultsecuritydescriptor) routine.

## Parameters

### `SecurityDescriptor` [in]

Opaque pointer to the security descriptor ([SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)) to be freed.

## Return value

None

## Remarks

**FltFreeSecurityDescriptor** should only be used to free a security descriptor that was allocated by a previous call to [FltBuildDefaultSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltbuilddefaultsecuritydescriptor).

## See also

[FltBuildDefaultSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltbuilddefaultsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)