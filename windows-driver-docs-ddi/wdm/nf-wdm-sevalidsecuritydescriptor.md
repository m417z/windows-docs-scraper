# SeValidSecurityDescriptor function

## Description

 The **SeValidSecurityDescriptor** routine returns whether a given security descriptor is structurally valid.

## Parameters

### `Length` [in]

Specifies the size in bytes of the given security descriptor.

### `SecurityDescriptor` [in]

Pointer to the self-relative [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor), which must be buffered somewhere in system space.

## Return value

**SeValidSecurityDescriptor** returns **TRUE** if the buffered security descriptor is structurally valid.

## Remarks

**SeValidSecurityDescriptor** does not enforce policy. It simply checks that the given security descriptor data is formatted correctly. In particular, it checks the revision information, self relativity, owner, alignment, and, if available, SID, group, DACL, ACL, and/or SACL do not overflow the given *Length*. Consequently, callers of **SeValidSecurityDescriptor** cannot assume that a returned **TRUE** implies that the given security descriptor necessarily has valid contents.

If **SeValidSecurityDescriptor** returns **TRUE**, the given security descriptor can be passed on to another kernel-mode component because it is structurally valid. Otherwise, passing a structurally invalid security descriptor to be manipulated by another kernel-mode component can cause undefined results or even a system bug check.

To validate a security descriptor that was passed in from user mode, call **RtlValidSecurityDescriptor** rather than **SeValidSecurityDescriptor**.

## See also

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)