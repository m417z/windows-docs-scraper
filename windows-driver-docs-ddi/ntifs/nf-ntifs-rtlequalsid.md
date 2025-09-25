# RtlEqualSid function

## Description

The **RtlEqualSid** routine determines whether two security identifier (SID) values are equal. Two SIDs must match exactly to be considered equal.

## Parameters

### `Sid1` [in]

Pointer to the first SID structure to compare. Must point to a valid SID.

### `Sid2` [in]

Pointer to the second SID structure to compare. Must point to a valid SID.

## Return value

**RtlEqualSid** returns **TRUE** if the SID structures are equal, **FALSE** otherwise. If either SID structure is invalid, the return value is undefined.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlCopySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcopysid)

[RtlEqualPrefixSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalprefixsid)

[RtlValidSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)