# RtlSubAuthoritySid function

## Description

The **RtlSubAuthoritySid** routine returns a pointer to a specified subauthority of a security identifier (SID).

## Parameters

### `Sid` [in]

Pointer to the SID structure. The SID must have been initialized by calling **RtlInitializeSid**.

### `SubAuthority`

Zero-based index indicating which subauthority is being specified. This value is not validated against the number of subauthorities in the SID.

## Return value

If the call to **RtlSubAuthoritySid** succeeds, the return value is a pointer to the specified SID subauthority. The subauthority value is a relative identifier. (The relative identifier, or RID, is the portion of a SID that identifies a user or group in relation to the authority that issued the SID.)

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlInitializeSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializesid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)