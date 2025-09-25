# FreeCredentialsHandle function

## Description

The **FreeCredentialsHandle** function notifies the security system that the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) are no longer needed. An application calls this function to free the credential handle acquired in the call to the
[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function after calling the [DeleteSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritycontext) function to free any context handles associated with the credential. When all references to this credential set have been removed, the credentials themselves can be removed.

Failure to free credentials handles will result in memory leaks.

## Parameters

### `phCredential` [in]

A pointer to the [CredHandle](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-handles) handle obtained by using the
[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns the following error code.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle passed to the function is not valid. |

## See also

[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)