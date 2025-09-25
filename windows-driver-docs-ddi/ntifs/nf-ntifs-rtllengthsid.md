# RtlLengthSid function

## Description

The **RtlLengthSid** routine returns the length, in bytes, of a valid security identifier (SID).

## Parameters

### `Sid` [in]

Pointer to the SID structure. Must point to a valid SID.

## Return value

If the SID structure is valid, **RtlLengthSid** returns the length, in bytes, of the SID structure.

If the SID structure is not valid, the return value is undefined. Before calling **RtlLengthSid**, pass the SID to [RtlValidSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid) to verify that it is valid.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlEqualPrefixSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalprefixsid)

[RtlEqualSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalsid)

[RtlInitializeSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializesid)

[RtlLengthRequiredSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthrequiredsid)

[RtlSubAuthoritySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsubauthoritysid)

[RtlValidSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)