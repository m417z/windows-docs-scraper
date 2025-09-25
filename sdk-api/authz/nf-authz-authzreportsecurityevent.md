# AuthzReportSecurityEvent function

## Description

The **AuthzReportSecurityEvent** function generates a security audit for a registered security event source.

Auditing for the object access event category must be enabled for the **AuthzReportSecurityEvent** function to generate a security audit. The available audit types are defined in the [AUDIT_PARAM_TYPE](https://learn.microsoft.com/windows/desktop/api/adtgen/ne-adtgen-audit_param_type) enumeration.

## Parameters

### `dwFlags` [in]

Flags that specify the type of audit generated. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **APF_AuditFailure**<br><br>0x00000000 | Failure audits are generated. |
| **APF_AuditSuccess**<br><br>0x00000001 | Success audits are generated. |

### `hEventProvider` [in, out]

A handle to the registered security event source to use for the audit.

### `dwAuditId` [in]

The identifier of the audit.

### `pUserSid` [in, optional]

A pointer to the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that will be listed as the source of the audit in the event log.

### `dwCount` [in]

The number of AuditParamFlag type/value pairs that appear in the variable arguments section that follows this parameter.

### `...`

A list of AuditParamFlag type/value pairs that provide additional information about the event.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuthzRegisterSecurityEventSource](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzregistersecurityeventsource)

[AuthzReportSecurityEventFromParams](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzreportsecurityeventfromparams)