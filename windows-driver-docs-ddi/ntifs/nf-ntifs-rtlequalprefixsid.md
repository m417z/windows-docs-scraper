# RtlEqualPrefixSid function

## Description

The **RtlEqualPrefixSid** routine determines whether two security-identifier (SID) prefixes are equal. An SID prefix is the entire SID except for the last subauthority value.

## Parameters

### `Sid1` [in]

Pointer to the first SID structure to compare. Must point to a valid SID.

### `Sid2` [in]

Pointer to the second SID structure to compare. Must point to a valid SID.

## Return value

**RtlEqualPrefixSid** returns **TRUE** if the SID prefixes are equal, **FALSE** otherwise. If either SID structure is invalid, the return value is undefined.

## Remarks

**RtlEqualPrefixSid** enables a server in one domain to verify an attempt by a user to log on to another domain. For example, if a user attempts to log on to RemoteDomain from a workstation in LocalDomain, the server for LocalDomain can request the SIDs for the user and the user's groups from RemoteDomain. The domain controller for RemoteDomain responds with the relevant SIDs.

All SIDs for a specified domain necessarily have the same prefix. When the server receives the user's SIDs, it can call **RtlEqualPrefixSid** for each SID, comparing the user or group SID against the SID for RemoteDomain. If any of the SID prefixes are not equal, the server refuses the logon attempt.

It is advisable to modify the SID for a domain before comparing it with a group or user SID. If the SID for RemoteDomain is S-1-1234-8, each group or user SID for that domain will have S-1-1234-8 as its prefix. To compare the SIDs by using **RtlEqualPrefixSid**, the caller copies the domain SID and adds any subauthority relative identifier value to the copy, thereby creating an SID in the form S-1-1234-8-0. (The relative identifier, or RID, is the portion of a SID that identifies a user or group in relation to the authority that issued the SID.) The caller then uses the modified domain SID as a template against which the group and user SIDs are compared.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlCopySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcopysid)

[RtlEqualSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalsid)

[RtlValidSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)