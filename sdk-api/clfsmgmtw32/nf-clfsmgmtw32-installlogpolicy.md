# InstallLogPolicy function

## Description

Installs (sets) a policy for a log.

## Parameters

### `hLog` [in]

A handle to a log.

### `pPolicy` [in]

A pointer to a [CLFS_MGMT_POLICY](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ns-clfsmgmt-clfs_mgmt_policy) structure that represents the desired policy to install.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Installing a log policy does not trigger an immediate change in behavior.

#### Examples

For an example that uses this function, see [Creating a Log File](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/creating-a-log-file).

## See also

[CLFS_MGMT_POLICY](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ns-clfsmgmt-clfs_mgmt_policy)

[CLFS_MGMT_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/clfsmgmt/ne-clfsmgmt-clfs_mgmt_policy_type)

[SetLogFileSizeWithPolicy](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-setlogfilesizewithpolicy)