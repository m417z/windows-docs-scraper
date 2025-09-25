# RefreshPolicy function

## Description

The
**RefreshPolicy** function causes policy to be applied immediately on the client computer. To apply policy and specify the type of refresh that should occur, you can call the extended function
[RefreshPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-refreshpolicyex).

## Parameters

### `bMachine` [in]

Specifies whether to refresh the computer policy or user policy. If this value is **TRUE**, the system refreshes the computer policy. If this value is **FALSE**, the system refreshes the user policy.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

By default, policy is reapplied every 90 minutes.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[ProcessGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicy)