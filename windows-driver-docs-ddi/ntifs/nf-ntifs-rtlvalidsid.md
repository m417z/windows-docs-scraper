# RtlValidSid function

## Description

The **RtlValidSid** routine validates a security identifier (SID) by verifying that the revision number is within a known range and that the number of subauthorities is less than the maximum.

## Parameters

### `Sid` [in]

Pointer to the SID structure to validate.

## Return value

**RtlValidSid** returns **TRUE** if the security descriptor is valid, **FALSE** otherwise.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlEqualPrefixSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalprefixsid)

[RtlEqualSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalsid)

[RtlInitializeSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializesid)

[RtlLengthRequiredSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthrequiredsid)

[RtlLengthSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthsid)

[RtlSubAuthoritySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsubauthoritysid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)