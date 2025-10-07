# AuthzGetCentralAccessPolicyCallback callback function

The *AuthzGetCentralAccessPolicyCallback* function is an application-defined function that retrieves the central access policy. *AuthzGetCentralAccessPolicyCallback* is a placeholder for the application-defined function name.

## Parameters

*hAuthzClientContext* \[in\]

Handle to the client context.

*capid* \[in\]

ID of the central access policy to retrieve.

*pArgs* \[in, optional\]

Optional arguments that were passed to the [**AuthzAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaccesscheck) function through the **OptionalArguments** member of the [**AUTHZ\_ACCESS\_REQUEST**](https://learn.microsoft.com/windows/desktop/api/Authz/ns-authz-authz_access_request) structure.

*pCentralAccessPolicyApplicable* \[out\]

Pointer to a Boolean value that the resource manager uses to indicate whether a central access policy should be used during access evaluation.

*ppCentralAccessPolicy* \[out\]

Pointer to the central access policy (CAP) to be used for evaluating access. If this value is **NULL**, the default CAP is applied.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function is unable to perform the evaluation, it returns **FALSE**. Use [**SetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to return an error to the access check function.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Redistributable<br> | Windows Server 2003 Administration Tools Pack on Windows XP<br> |

## See also

[**AUTHZ\_ACCESS\_REQUEST**](https://learn.microsoft.com/windows/desktop/api/Authz/ns-authz-authz_access_request)

[**AUTHZ\_INIT\_INFO**](https://learn.microsoft.com/windows/desktop/api/Authz/ns-authz-authz_init_info)

[**AuthzAccessCheck**](https://learn.microsoft.com/windows/desktop/api/Authz/nf-authz-authzaccesscheck)

