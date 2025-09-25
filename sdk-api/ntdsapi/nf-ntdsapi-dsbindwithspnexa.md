# DsBindWithSpnExA function

## Description

The **DsBindWithSpnEx** function binds to a domain controller using the specified credentials and a specific service principal name (SPN) for mutual authentication. This function is similar to the [DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna) function except this function allows more binding options with the *BindFlags* parameter.

This function is provided where complete control is required over mutual authentication. Do not use this function if you expect [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) to find a server for you, because SPNs are computer-specific, and it is unlikely that the SPN you provide will match the server that **DsBind** finds for you. Providing a **NULL***ServicePrincipalName* argument results in behavior that is identical to [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda).

## Parameters

### `DomainControllerName` [in, optional]

Pointer to a null-terminated string that contains the fully qualified DNS name of the domain to bind. For more information, see the *DomainControllerName* description in the [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) topic.

### `DnsDomainName` [in, optional]

Pointer to a null-terminated string that contains the fully qualified DNS name of the domain to bind. For more information, see the *DnsDomainName* description in the [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) topic.

### `AuthIdentity` [in, optional]

Contains an [RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle) value that represents the credentials to be used for the bind. The
[DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa) function is used to obtain this value. If this parameter is **NULL**,
the credentials of the calling thread are used.

[DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) must be called before freeing this handle with the [DsFreePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreepasswordcredentials) function.

### `ServicePrincipalName` [in, optional]

Pointer to a null-terminated string that specifies the Service Principal Name to assign to the client. Passing **NULL** in *ServicePrincipalName* is equivalent to a call to the [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `BindFlags` [in, optional]

Contains a set of flags that define the behavior of this function. This parameter can contain zero or a combination of the values listed in the following list.

#### NTDSAPI_BIND_ALLOW_DELEGATION (1)

Causes the bind to use the delegate impersonation level. This allows operations that require delegation, such as
[DsAddSidHistory](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsaddsidhistorya), to succeed. Specifying this flag also causes **DsBindWithSpnEx** to operate like [DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna).

If this flag is not specified, the bind will use the impersonate impersonation level. For more information, see [Impersonation Levels](https://learn.microsoft.com/windows/desktop/com/impersonation-levels).

Most operations do
not require the delegate impersonation level, so this flag should only be specified
if absolutely required. Binding to a rogue server with the delegate impersonation level will allow the rogue server to connect to a non-rogue server with your credentials and perform
unintended operations.

#### NTDSAPI_BIND_FIND_BINDING (2)

Reserved.

#### NTDSAPI_BIND_FORCE_KERBEROS (4)

**Active Directory Lightweight Directory Services:** If this flag is specified, **DsBindWithSpnEx** forces Kerberos authentication to be used. If Kerberos authentication cannot be established, **DsBindWithSpnEx** will not attempt to authenticate with any other method.

### `phDS` [out]

Address of a **HANDLE** value that receives the binding handle. To close this handle, pass it to the [DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) function.

## Return value

Returns **ERROR_SUCCESS** if successful or a Windows or RPC error code otherwise. The following list lists common error codes.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna)

[DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda)

[Impersonation Levels](https://learn.microsoft.com/windows/desktop/com/impersonation-levels)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsBindWithSpnEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).