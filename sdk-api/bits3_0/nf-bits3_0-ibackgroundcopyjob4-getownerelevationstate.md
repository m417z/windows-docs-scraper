# IBackgroundCopyJob4::GetOwnerElevationState

## Description

Gets a value that determines if the token of the owner was elevated at the time they created or took ownership of the job.

## Parameters

### `pElevated` [out]

Is **TRUE** if the token of the owner was elevated at the time they created or took ownership of the job; otherwise, **FALSE**.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

For details on elevated tokens, see [User Account Control and BITS](https://learn.microsoft.com/windows/desktop/Bits/user-account-control-and-bits).

Note that if the job was created with an elevated token, all subsequent updates to the job must be done with an elevated token.

## See also

[IBackgroundCopyJob4](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4)