# DsFreePasswordCredentials function

## Description

The **DsFreePasswordCredentials** function frees memory allocated for a credentials structure by the
[DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa) function.

## Parameters

### `AuthIdentity` [in]

Handle of the credential structure to be freed.

## Return value

This function does not return a value.

## Remarks

When the handle in *AuthIdentity* is passed to [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda), [DsUnbind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) must be called before freeing this handle. The normal sequence of events is:

1. Call [DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa) to obtain the credential handle.
2. Call [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda), passing the credential handle.
3. Call [DsUnbind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) when the RPC connection is no longer required.
4. Call **DsFreePasswordCredentials** to free the credential handle.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa)

[DsUnbind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda)