# RtlLengthRequiredSid function

## Description

The **RtlLengthRequiredSid** routine returns the length, in bytes, of the buffer required to store a security identifier (SID) with a specified number of subauthorities.

## Parameters

### `SubAuthorityCount` [in]

The number of subauthorities to be stored in the SID.

## Return value

**RtlLengthRequiredSid** returns the length, in bytes, of the buffer required to store the SID structure.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlEqualPrefixSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalprefixsid)

[RtlEqualSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalsid)

[RtlInitializeSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializesid)

[RtlLengthSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthsid)

[RtlSubAuthoritySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsubauthoritysid)

[RtlValidSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)