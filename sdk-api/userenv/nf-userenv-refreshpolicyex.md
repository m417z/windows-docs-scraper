# RefreshPolicyEx function

## Description

The
**RefreshPolicyEx** function causes policy to be applied immediately on the computer. The extended function allows you to specify the type of policy refresh to apply.

## Parameters

### `bMachine` [in]

Specifies whether to refresh the computer policy or user policy. If this value is **TRUE**, the system refreshes the computer policy. If this value is **FALSE**, the system refreshes the user policy.

### `dwOptions` [in]

Specifies the type of policy refresh to apply. This parameter can be the following value.

#### RP_FORCE

Reapply all policies even if no policy change was detected.

Note that if there are any client-side extensions that can be applied at boot or logon time, (for example, an application installation extension), the extensions are re-applied at the next boot or logon, even if no policy change is detected.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you do not need to specify the *dwOptions* parameter, you can call the
[RefreshPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-refreshpolicy) function instead.

By default, policy is reapplied every 90 minutes.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[ProcessGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicy)

[ProcessGroupPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicyex)

[RefreshPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-refreshpolicy)