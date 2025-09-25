# DsBindWithSpnA function

## Description

The **DsBindWithSpn** function binds to a domain controller using the specified credentials and a specific service principal name (SPN) for mutual authentication.

This function is provided for where complete control is required for mutual authentication. Do not use this function if you expect [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) to find a server for you, because SPNs are computer-specific, and it is unlikely that the SPN you provide will match the server that **DsBind** finds for you. Providing a **NULL***ServicePrincipalName* argument results in behavior that is identical to [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda).

## Parameters

### `DomainControllerName` [in, optional]

Pointer to a null-terminated string that contains the fully qualified DNS name of the domain to bind to. For more information, see the *DomainControllerName* description in the [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) topic.

### `DnsDomainName` [in, optional]

Pointer to a null-terminated string that contains the fully qualified DNS name of the domain to bind to. For more information, see the *DnsDomainName* description in the [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) topic.

### `AuthIdentity` [in, optional]

Contains an [RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle) value that represents the credentials to be used for the bind. The
[DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa) function is used to obtain this value. If this parameter is **NULL**,
the credentials of the calling thread are used.

[DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) must be called before freeing this handle with the [DsFreePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreepasswordcredentials) function.

### `ServicePrincipalName` [in, optional]

Pointer to a null-terminated string that specifies the Service Principal Name to assign to the client. Passing **NULL** in *ServicePrincipalName* is equivalent to a call to the [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `phDS` [out]

Address of a **HANDLE** value that receives the binding handle. To close this handle, pass it to the [DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) function.

## Return value

Returns **ERROR_SUCCESS** if successful or a Windows or RPC error code otherwise. The following are the most common error codes.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsBindWithSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).