# IBackgroundCopyJob4::GetOwnerIntegrityLevel

## Description

Gets the integrity level of the token of the owner that created or took ownership of the job.

## Parameters

### `pLevel` [out]

Integrity level of the token of the owner that created or took ownership of the job.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

For details on how the integrity level of the user's token affects a job, see [User Account Control and BITS](https://learn.microsoft.com/windows/desktop/Bits/user-account-control-and-bits).

This method returns the value from the [GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority) function. For possible mandatory integrity RID values, see [Well-known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids) in the Security documentation.

## See also

[IBackgroundCopyJob4](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4)