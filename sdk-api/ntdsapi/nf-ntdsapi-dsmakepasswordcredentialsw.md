# DsMakePasswordCredentialsW function

## Description

The **DsMakePasswordCredentials** function constructs a credential handle suitable for use with the
[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

## Parameters

### `User` [in]

Pointer to a null-terminated string that contains the user name to use for the credentials.

### `Domain` [in]

Pointer to a null-terminated string that contains the domain that the user is a member of.

### `Password` [in]

Pointer to a null-terminated string that contains the password to use for the credentials.

### `pAuthIdentity` [out]

Pointer to an [RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle) value that receives the credential handle. This handle is used in a subsequent call to [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda). This handle must be freed with the
[DsFreePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreepasswordcredentials) function when it is no longer required.

## Return value

Returns a Windows error code, including the following.

## Remarks

A null, default credential handle is created if *User*, *Domain* and *Password* are all **NULL**. Otherwise, *User* must be present. The *Domain* parameter may be **NULL** when *User* is fully qualified, such as a user in UPN format; for example, "someone@fabrikam.com".

When the handle returned in *pAuthIdentity* is passed to [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda), [DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) must be called before freeing the handle with [DsFreePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreepasswordcredentials). The normal sequence is:

1. Call **DsMakePasswordCredentials** to obtain the credential handle.
2. Call [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda), and pass the credential handle.
3. Call [DsUnbind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda) when the binding is no longer required.
4. Call [DsFreePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreepasswordcredentials) to free the credential handle.

> [!NOTE]
> The ntdsapi.h header defines DsMakePasswordCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[DsFreePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreepasswordcredentials)

[DsUnbind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda)

[RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle)