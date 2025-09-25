# DsBindByInstanceW function

## Description

The **DsBindByInstance** function
explicitly binds to any AD LDS or Active Directory instance.

## Parameters

### `ServerName` [in]

Pointer to a null-terminated string that specifies the name of the instance. This parameter is required to
bind to an AD LDS instance. If this parameter is **NULL** when binding to an Active
Directory instance, then the *DnsDomainName* parameter must contain a value. If this
parameter and the *DnsDomainName* parameter are both **NULL**, the
function fails with the return value **ERROR_INVALID_PARAMETER** (87).

### `Annotation` [in]

Pointer to a null-terminated string that specifies the port number of the AD LDS instance or
**NULL** when binding to an Active Directory instance. For example,
"389".

If this parameter is **NULL** when binding by domain to an Active Directory instance,
then the *DnsDomainName* parameter must be specified. If this parameter is
**NULL** when binding to an AD LDS instance, then the
*InstanceGuid* parameter must be specified.

### `InstanceGuid` [in]

Pointer to a **GUID** value that contains the **GUID** of the AD LDS instance. The **GUID** value is the
**objectGUID** property of the **nTDSDSA** object of the
instance. If this parameter is **NULL** when binding to an AD LDS instance, the
*Annotation* parameter must be specified.

### `DnsDomainName` [in]

Pointer to a null-terminated string that specifies the DNS name of the domain when binding to an Active
Directory instance by domain. Set this parameter to **NULL** to bind to an Active
Directory instance by server or to an AD LDS instance.

### `AuthIdentity` [in, optional]

Handle to the credentials used to start the RPC session. Use the
[DsMakePasswordCredentials](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmakepasswordcredentialsa) function to create
a structure suitable for *AuthIdentity*.

### `ServicePrincipalName` [in, optional]

Pointer to a null-terminated string that specifies the Service Principal Name to assign to the client.
Passing **NULL** in *ServicePrincipalName* is equivalent to a call
to the [DsBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `BindFlags` [in, optional]

Contains a set of flags that define the behavior of this function. This parameter can contain zero or a
combination of one or more of the following values.

#### NTDSAPI_BIND_ALLOW_DELEGATION (1)

Causes the bind to use the delegate impersonation level. This enables operations that require
delegation, such as [DsAddSidHistory](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsaddsidhistorya), to succeed.
Specifying this flag also causes [DsBindWithSpnEx](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspnexa) to
operate similar to [DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna).

If this flag is not specified, the bind will use the impersonate impersonation level. For more
information about impersonation levels, see
[Impersonation Levels](https://learn.microsoft.com/windows/desktop/com/impersonation-levels).

Most operations do not require the delegate impersonation level; this flag should only be
specified if it is required. Binding to a rogue server with the delegate impersonation level enables the
rogue server to connect to a non-rogue server with your credentials and perform unintended operations.

#### NTDSAPI_BIND_FORCE_KERBEROS (4)

**Active Directory Lightweight Directory Services:** If this flag is specified, [DsBindWithSpnEx](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspnexa)
requires Kerberos authentication to be used. If Kerberos authentication cannot be established,
**DsBindWithSpnEx** will not attempt to authenticate
with any other mechanism.

### `phDS` [out]

Address of a **HANDLE** value that receives the bind handle. To close this handle,
call [DsUnBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsunbinda).

##### - BindFlags.NTDSAPI_BIND_ALLOW_DELEGATION (1)

Causes the bind to use the delegate impersonation level. This enables operations that require
delegation, such as [DsAddSidHistory](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsaddsidhistorya), to succeed.
Specifying this flag also causes [DsBindWithSpnEx](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspnexa) to
operate similar to [DsBindWithSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspna).

If this flag is not specified, the bind will use the impersonate impersonation level. For more
information about impersonation levels, see
[Impersonation Levels](https://learn.microsoft.com/windows/desktop/com/impersonation-levels).

Most operations do not require the delegate impersonation level; this flag should only be
specified if it is required. Binding to a rogue server with the delegate impersonation level enables the
rogue server to connect to a non-rogue server with your credentials and perform unintended operations.

##### - BindFlags.NTDSAPI_BIND_FORCE_KERBEROS (4)

**Active Directory Lightweight Directory Services:** If this flag is specified, [DsBindWithSpnEx](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithspnexa)
requires Kerberos authentication to be used. If Kerberos authentication cannot be established,
**DsBindWithSpnEx** will not attempt to authenticate
with any other mechanism.

## Return value

Returns **NO_ERROR** if successful or an RPC or Win32 error otherwise. Possible error codes include those
listed in the following list.

## Remarks

The following list lists the required parameter values for binding to an instance.

| Instance | *ServerName* | *Annotation* | *InstanceGuid* | *DnsDomainName* |
| --- | --- | --- | --- | --- |
| Active Directory by server | Server Name | **NULL** | **NULL** | **NULL** |
| Active Directory by domain | **NULL** | **NULL** | **NULL** | DNS domain name |
| AD LDS by port | DNS Name of the computer with the AD LDS installation. | Port Number | **NULL** | **NULL** |
| AD LDS by **GUID** | DNS Name of the computer with the AD LDS installation. | **NULL** | Instance **GUID** | **NULL** |

**Note** For improved performance when binding to an AD LDS instance on a computer with several instances
of AD LDS, bind by the Instance **GUID** instead of the port number.

> [!NOTE]
> The ntdsapi.h header defines DsBindByInstance as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).