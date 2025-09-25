# RtlGetDaclSecurityDescriptor function

## Description

The **RtlGetDaclSecurityDescriptor** routine returns a pointer to the discretionary ACL (DACL) for a security descriptor.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) whose DACL is to be returned.

### `DaclPresent` [out]

Pointer to a Boolean variable that indicates the presence of a DACL in the specified security descriptor. If this variable receives **TRUE**, the security descriptor contains a DACL, and the remaining output parameters receive valid values. If this variable receives **FALSE**, the security descriptor does not contain a DACL, and the remaining output parameters do not receive valid values.

### `Dacl` [out]

Pointer to a variable that receives the address of the DACL for the security descriptor. If the security descriptor does not have a DACL, this variable does not receive a value. If the security descriptor has a **NULL** DACL, this variable receives **NULL**. A **NULL** DACL implicitly allows all access to an object.

### `DaclDefaulted` [out]

Pointer to a Boolean variable that receives the value of the SE_DACL_DEFAULTED flag in the security descriptor's SECURITY_DESCRIPTOR_CONTROL structure. If this flag is **TRUE**, the DACL was retrieved by a default mechanism. If it is **FALSE**, the DACL was explicitly specified by a user. This value is valid only if **Dacl* receives a non-**NULL** value.

## Return value

**RtlGetDaclSecurityDescriptor** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_UNKNOWN_REVISION** | The security descriptor's revision level is unknown or is not supported. This is an error code. |

## Remarks

A value of **TRUE** for **DaclPresent* does not mean that **Dacl* is non-**NULL**. That is, **DaclPresent* can be **TRUE** while **Dacl* is **NULL**, meaning that a **NULL** DACL is in effect. A **NULL** DACL implicitly allows all access to an object and is not the same as an empty DACL. An empty DACL permits no access to an object.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)