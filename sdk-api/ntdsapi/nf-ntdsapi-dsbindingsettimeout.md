# DsBindingSetTimeout function

## Description

The **DsBindingSetTimeout** function sets the timeout value
that is honored by all RPC calls that use the specified binding
handle. RPC calls that required more time than the timeout value are canceled.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `cTimeoutSecs` [in]

Contains the new timeout value, in seconds.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error code otherwise. The following is a possible error code.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)