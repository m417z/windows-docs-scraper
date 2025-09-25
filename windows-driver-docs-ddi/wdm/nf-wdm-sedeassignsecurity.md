# SeDeassignSecurity function

## Description

The
**SeDeassignSecurity** routine deallocates the memory associated with a security descriptor that was assigned using **SeAssignSecurity**.

## Parameters

### `SecurityDescriptor` [in, out]

Pointer to the buffered [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) being released.

## Return value

If the deallocation succeeds, **SeDeassignSecurity** returns STATUS_SUCCESS.

## See also

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SeAssignSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)