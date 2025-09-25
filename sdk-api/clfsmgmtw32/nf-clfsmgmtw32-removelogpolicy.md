# RemoveLogPolicy function

## Description

Resets the specified policy to its default behavior.

## Parameters

### `hLog` [in]

Handle to the log to reset the policy for.

### `ePolicyType` [in]

Specifies the policy to reset. Policy types are enumerated in [CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ns-clfsmgmt-clfs_mgmt_policy)

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type)

[QueryLogPolicy](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-querylogpolicy)