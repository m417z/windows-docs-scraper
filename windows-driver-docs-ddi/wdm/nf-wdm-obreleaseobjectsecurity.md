# ObReleaseObjectSecurity function

## Description

The **ObReleaseObjectSecurity** routine is the reciprocal to **ObGetObjectSecurity**.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the buffered [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) to be released. The caller obtained this parameter from **ObGetObjectSecurity**

### `MemoryAllocated` [in]

Specifies the value also obtained from **ObGetObjectSecurity**.

## Remarks

After a successful call to [ObGetObjectSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obgetobjectsecurity), a driver must call **ObReleaseObjectSecurity** eventually.

**ObReleaseObjectSecurity** releases any resources that were allocated by **ObGetObjectSecurity**. It also decrements the reference count on the given security descriptor.

## See also

[ObGetObjectSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obgetobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)