# AuthzReportSecurityEventFromParams function

## Description

The **AuthzReportSecurityEventFromParams** function generates a security audit for a registered security event source by using the specified array of audit parameters.

## Parameters

### `dwFlags` [in]

Reserved for future use.

### `hEventProvider` [in]

A handle to the registered security event source to use for the audit.

### `dwAuditId` [in]

The identifier of the audit.

### `pUserSid` [in, optional]

A pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that will be listed as the source of the audit in the event log.

### `pParams` [in]

An array of audit parameters.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuthzRegisterSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzregistersecurityeventsource)

[AuthzReportSecurityEvent](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzreportsecurityevent)