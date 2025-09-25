# AcquireCredentialsHandleW function

## Description

The **AcquireCredentialsHandle (CredSSP)** function acquires a handle to preexisting [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of a [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This handle is required by the
[InitializeSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) and
[AcceptSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) functions. These can be either preexisting *credentials*, which are established through a system logon that is not described here, or the caller can provide alternative credentials.

**Note** This is not a "log on to the network" and does not imply gathering of credentials.

## Parameters

### `pPrincipal`

TBD

### `pPackage`

TBD

### `fCredentialUse` [in]

A flag that indicates how these credentials will be used. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SECPKG_CRED_INBOUND**<br><br>0x1 | Validate an incoming server credential. Inbound credentials might be validated by using an authenticating authority when [InitializeSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) or [AcceptSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) is called. If such an authority is not available, the function will fail and return **SEC_E_NO_AUTHENTICATING_AUTHORITY**. Validation is package specific. |
| **SECPKG_CRED_OUTBOUND**<br><br>0x2 | Allow a local client credential to prepare an outgoing token. |

### `pvLogonId` [in, optional]

A pointer to a [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) that identifies the user. This parameter is provided for file-system processes such as network redirectors. This parameter can be **NULL**.

### `pAuthData` [in, optional]

A pointer to a [CREDSSP_CRED](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-credssp_cred) structure that specifies authentication data for both Schannel and Negotiate packages.

### `pGetKeyFn` [in, optional]

Reserved. This parameter is not used and should be set to **NULL**.

### `pvGetKeyArgument` [in, optional]

Reserved. This parameter must be set to **NULL**.

### `phCredential` [out]

A pointer to the [CredHandle](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-handles) structure that will receive the credential handle.

### `ptsExpiry` [out, optional]

A pointer to a [TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) structure that receives the time at which the returned credentials expire. The structure value received depends on the security package, which must specify the value in local time.

#### - pszPackage [in]

A pointer to a null-terminated string that specifies the name of the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) with which these credentials will be used. This is a security package name returned in the **Name** member of a
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure returned by the
[EnumerateSecurityPackages](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-enumeratesecuritypackagesa) function. After a context is established,
[QueryContextAttributes (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) can be called with *ulAttribute* set to **SECPKG_ATTR_PACKAGE_INFO** to return information on the security package in use.

#### - pszPrincipal [in, optional]

A pointer to a null-terminated string that specifies the name of the principal whose credentials the handle will reference.

**Note** If the process that requests the handle does not have access to the credentials, the function returns an error. A null string indicates that the process requires a handle to the credentials of the user under whose [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) it is executing.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INSUFFICIENT_MEMORY** | There is insufficient memory available to complete the requested action. |
| **SEC_E_INTERNAL_ERROR** | An error occurred that did not map to an SSPI error code. |
| **SEC_E_NO_CREDENTIALS** | No credentials are available in the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **SEC_E_NOT_OWNER** | The caller of the function does not have the necessary credentials. |
| **SEC_E_SECPKG_NOT_FOUND** | The requested security package does not exist. |
| **SEC_E_UNKNOWN_CREDENTIALS** | The credentials supplied to the package were not recognized. |

## Remarks

The **AcquireCredentialsHandle (CredSSP)** function returns a handle to the credentials of a principal, such as a user or client, as used by a specific [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The function can return the handle to either preexisting credentials or newly created credentials and return it. This handle can be used in subsequent calls to the
[AcceptSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) and
[InitializeSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) functions.

In general, **AcquireCredentialsHandle (CredSSP)** does not provide the credentials of other users logged on to the same computer. However, a caller with SE_TCB_NAME [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) can obtain the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of an existing logon session by specifying the [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) of that session. Typically, this is used by kernel-mode modules that must act on behalf of a logged-on user.

A package might call the function in *pGetKeyFn* provided by the RPC run-time transport. If the transport does not support the notion of callback to retrieve credentials, this parameter must be **NULL**.

For kernel mode callers, the following differences must be noted:

* The two string parameters must be [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) strings.
* The buffer values must be allocated in process virtual memory, not from the pool.

When you have finished using the returned credentials, free the memory used by the credentials by calling the
[FreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecredentialshandle) function.

> [!NOTE]
> The sspi.h header defines AcquireCredentialsHandle as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AcceptSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext)

[FreeCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecredentialshandle)

[InitializeSecurityContext (CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)