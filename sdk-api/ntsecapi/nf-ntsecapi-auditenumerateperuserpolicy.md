# AuditEnumeratePerUserPolicy function

## Description

The **AuditEnumeratePerUserPolicy** function enumerates users for whom per-user auditing policy is specified.

## Parameters

### `ppAuditSidArray` [out]

A pointer to a single buffer that contains both an array of pointers to [POLICY_AUDIT_SID_ARRAY](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_audit_sid_array) structures and the structures themselves. The **POLICY_AUDIT_SID_ARRAY** structures specify the users for whom per-user audit policy is specified.

When you have finished using this buffer, free it by calling the [AuditFree](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditfree) function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes defined in WinError.h.

| Return code/value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED**<br><br>5 | The caller does not have the privilege or access rights necessary to call this function. |
| **ERROR_INVALID_PARAMETER**<br><br>87 | One or more parameters are invalid. |

## Remarks

To successfully call this function, the caller must have **SeSecurityPrivilege** or have **AUDIT_ENUMERATE_USERS** access on the [Audit security object](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).