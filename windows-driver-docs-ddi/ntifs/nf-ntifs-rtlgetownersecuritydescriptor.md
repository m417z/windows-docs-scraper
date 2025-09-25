# RtlGetOwnerSecurityDescriptor function

## Description

The **RtlGetOwnerSecurityDescriptor** routine returns the owner information for a given security descriptor.

## Parameters

### `SecurityDescriptor` [in]

Pointer to the security descriptor.

### `Owner` [out]

Pointer to an address to receive a pointer to the owner security identifier ([SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)). If the security descriptor does not currently contain an owner SID, *Owner* receives **NULL**.

### `OwnerDefaulted` [out]

Pointer to a Boolean variable that receives **TRUE** if the owner information is derived from a default mechanism, rather than by the original provider of the security descriptor explicitly, **FALSE** otherwise. Valid only if *Owner* receives a non-**NULL** value.

## Return value

**RtlGetOwnerSecurityDescriptor** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_UNKNOWN_REVISION** | The security descriptor's revision level is not known or is not supported. This is an error code. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlCreateSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreatesecuritydescriptor)

[RtlLengthSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtllengthsecuritydescriptor)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[RtlSetOwnerSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsetownersecuritydescriptor)

[RtlValidSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlvalidsecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)