# QueryLogPolicy function

## Description

The **QueryLogPolicy** function allows you to obtain a policy that is installed for the specified log.

## Parameters

### `hLog` [in]

The handle to the log to query.

### `ePolicyType` [in]

Specifies the type of policy to query for. Policy types are enumerated in [CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type).

### `pPolicyBuffer` [out]

A pointer to a buffer to receive the returned policies.

### `pcbPolicyBuffer` [in, out]

A pointer to the size of *pPolicyBuffer*. If the buffer is not large enough, *pcbPolicyBuffer* receives the size buffer required to successfully retrieve the specified policies.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ns-clfsmgmt-clfs_mgmt_policy)

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type)

[RemoveLogPolicy](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-removelogpolicy)