# AuthzUnregisterSecurityEventSource function

## Description

The **AuthzUnregisterSecurityEventSource** function unregisters a security event source with the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA).

## Parameters

### `dwFlags` [in]

This parameter is reserved for future use. Set this parameter to zero.

### `phEventProvider` [in, out]

A pointer to a handle to the security event source to unregister.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function deallocates any resources and closes any RPC connections associated with a previous call to the [AuthzRegisterSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzregistersecurityeventsource) function.

## See also

[AuthzRegisterSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzregistersecurityeventsource)