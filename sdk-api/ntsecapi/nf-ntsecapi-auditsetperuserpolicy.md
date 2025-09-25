# AuditSetPerUserPolicy function

## Description

The **AuditSetPerUserPolicy** function sets per-user audit policy in one or more audit subcategories for the specified principal.

## Parameters

### `pSid` [in]

A pointer to the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure associated with the principal for which to set audit policy. Per-user policy for group SIDs is not currently supported.

### `pAuditPolicy` [in]

A pointer to an array of [AUDIT_POLICY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-audit_policy_information) structures. Each structure specifies per-user audit policy for one audit subcategory.

The **AuditCategoryGuid** member of these structures is ignored.

### `dwPolicyCount` [in]

The number of elements in the *pAuditPolicy* array.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes defined in WinError.h.

| Return code/value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED**<br><br>5 | The caller does not have the privilege or access rights necessary to call this function. |
| **ERROR_INVALID_PARAMETER**<br><br>87 | One or more parameters are invalid. |
| **ERROR_NO_SUCH_USER**<br><br>1317 | The [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure specified by the *pSID* parameter is not associated with an existing user. |

## Remarks

To successfully call this function, the caller must have **SeSecurityPrivilege** or have **AUDIT_SET_USER_POLICY** access on the [Audit security object](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## See also

[AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy)

[AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy)

[AuditSetSystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetsystempolicy)