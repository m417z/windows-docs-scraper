# AuthzRegisterSecurityEventSource function

## Description

The **AuthzRegisterSecurityEventSource** function registers a security event source with the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA).

## Parameters

### `dwFlags` [in]

This parameter is reserved for future use. Set this parameter to zero.

### `szEventSourceName` [in]

A pointer to the name of the security event source to register.

### `phEventProvider` [out]

A pointer to a handle to the registered security event source.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function validates the *szEventSourceName* parameter and sets up the appropriate structures and RPC connections to log events with that source name. The validation is handled by an underlying call to an LSA API.

The LSA API verifies the following:

* The caller has the SeAuditPrivilege access right.
* The event source is not already in use.
* The event source is registered.
* The calling application matches the executable image path in the event source registration, if one exists.

## See also

[AuthzUnregisterSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzunregistersecurityeventsource)