# AuthzFreeCentralAccessPolicyCallback callback function

The *AuthzFreeCentralAccessPolicyCallback* function is an application-defined function that frees memory allocated by the [*AuthzGetCentralAccessPolicyCallback*](https://learn.microsoft.com/windows/win32/secauthz/authzgetcentralaccesspolicycallback-) function. *AuthzFreeCentralAccessPolicyCallback* is a placeholder for the application-defined function name.

## Parameters

*pCentralAccessPolicy* \[in\]

Pointer to the central access policy to be freed.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function is unable to perform the evaluation, it returns **FALSE**. Use [**SetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to return an error to the access check function.

## See also

[**AUTHZ\_INIT\_INFO**](https://learn.microsoft.com/windows/desktop/api/Authz/ns-authz-authz_init_info)

[*AuthzGetCentralAccessPolicyCallback*](https://learn.microsoft.com/windows/win32/secauthz/authzgetcentralaccesspolicycallback-)

