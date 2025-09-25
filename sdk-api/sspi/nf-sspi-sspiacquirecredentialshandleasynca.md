# SspiAcquireCredentialsHandleAsyncA function

## Description

The **SspiAcquireCredentialsHandleAsyncA** function asynchronously acquires a handle to preexisting [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of a [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

This handle is required by the
[SspiInitializeSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca) and
[SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync) functions. These can be either preexisting *credentials*, which are established through a system logon that is not described here, or the caller can provide alternative credentials.
> [!NOTE]
> This function serves as the asynchronous counterpart to [AcquireCredentialsHandle](https://learn.microsoft.com/windows/win32/secauthn/acquirecredentialshandle--general).

## Parameters

### `AsyncContext`

The async call context.

### `pszPrincipal`

A pointer to a null-terminated string that specifies the name of the principal whose credentials the handle will reference asynchronously.

### `pszPackage`

A pointer to a null-terminated string that specifies the name of the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) with which these credentials will be used.

See [AcquireCredentialsHandleA: pszPackage](https://learn.microsoft.com/windows/win32/secauthn/acquirecredentialshandle--general#parameters)

### `fCredentialUse`

A flag that indicates how these credentials will be used. This parameter can be one of the following values:

|

Value

|

Meaning

|
|---|---|
| **SECPKG_CRED_INBOUND** | Validate an incoming server credential. Inbound credentials might be validated by using an authenticating authority when [SspiInitializeSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca) or [SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync) is called. If such an authority is not available, the function will fail and return **SEC_E_NO_AUTHENTICATING_AUTHORITY**. Validation is package specific.|
| **SECPKG_CRED_OUTBOUND** | Allow a local client credential to prepare an outgoing token.|

### `pvLogonId`

A pointer to a [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) that identifies the user. This parameter is provided for file-system processes such as network redirectors. This parameter can be **NULL**.

### `pAuthData`

A pointer to a [CREDSSP_CRED](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-credssp_cred) structure that specifies authentication data for both Schannel and Negotiate packages.

### `pGetKeyFn`

Pointer to the GetKey() function.

### `pvGetKeyArgument`

Pass to GetKey().

### `phCredential`

A pointer to the [CredHandle](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-handles) structure that will receive the credential handle.

### `ptsExpiry`

*optional* A pointer to a [TimeStamp](https://learn.microsoft.com/windows/desktop/SecAuthN/timestamp) structure that receives the time at which the returned credentials expire. The structure value received depends on the security package, which must specify the value in local time.

## Return value

Returns **SEC_E_OK** if the async request to acquire a credential handle was successfully queued for execution. Otherwise, it returns the error generated attempting to queue it. To retrieve the status of the operation, use [SspiGetAsyncCallStatus](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspigetasynccallstatus).

If the handle was acquired, SspiGetAsyncCallStatus returns **SEC_E_OK**. Otherwise, it may return *SEC_I_ASYNC_CALL_PENDING* if the call is still in progress, or any of the following fatal error codes in the table below.

|

Return code

|

Description

|
|---|---|
| **SEC_E_INSUFFICIENT_MEMORY** | There is insufficient memory available to complete the requested action. |
| **SEC_E_INTERNAL_ERROR** | An error occurred that did not map to an SSPI error code. |
| **SEC_E_NO_CREDENTIALS** | No credentials are available in the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) |
| **SEC_E_NOT_OWNER** | The caller of the function does not have the necessary credentials. |
| **SEC_E_SECPKG_NOT_FOUND** | The requested security package does not exist.|
| **SEC_E_UNKNOWN_CREDENTIALS** | The credentials supplied to the package were not recognized. |

## Remarks

The **SspiAcquireCredentialsHandleAsyncA** function returns a handle to the credentials of a principal, such as a user or client, as used by a specific [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The function can return the handle to either preexisting credentials or newly created credentials and return it. This handle can be used in subsequent calls to the
[SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync) and
[SspiInitializeSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca) functions.

In general, **SspiAcquireCredentialsHandleAsyncA** does not provide the credentials of other users logged on to the same computer. However, a caller with SE_TCB_NAME [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) can obtain the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) of an existing logon session by specifying the [logon identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) of that session. Typically, this is used by kernel-mode modules that must act on behalf of a logged-on user.

A package might call the function in *pGetKeyFn* provided by the RPC run-time transport. If the transport does not support the notion of callback to retrieve credentials, this parameter must be **NULL**.

For kernel mode callers, the following differences must be noted:

- The two string parameters must be [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) strings.
- The buffer values must be allocated in process virtual memory, not from the pool.

When you have finished using the returned credentials, free the memory used by the credentials by calling the
[SspiFreeCredentialsHandleAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreecredentialshandleasync) function.

## See also

[AcquireCredentialsHandle](https://learn.microsoft.com/windows/win32/secauthn/acquirecredentialshandle--general)

[SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync)

[SspiFreeCredentialsHandleAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreecredentialshandleasync)

[SspiInitializeSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)