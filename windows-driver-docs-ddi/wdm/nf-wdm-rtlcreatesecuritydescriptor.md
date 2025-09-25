# RtlCreateSecurityDescriptor function

## Description

The **RtlCreateSecurityDescriptor** routine initializes a new absolute-format security descriptor. On return, the security descriptor is initialized with no system ACL, no discretionary ACL, no owner, no primary group, and all control flags set to zero.

## Parameters

### `SecurityDescriptor` [out]

Pointer to the buffer for the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) to be initialized.

### `Revision` [in]

Specifies the revision level to assign to the security descriptor. Set this parameter to SECURITY_DESCRIPTOR_REVISION.

## Return value

**RtlCreateSecurityDescriptor** can return one of the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The call completed successfully. |
| **STATUS_UNKNOWN_REVISION** | The caller specified an unsupported value for *Revision*. |

## Remarks

A successful call to this routine initializes a security descriptor. The fields in this descriptor are set to initial values that indicate that there are no security constraints.

## See also

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)