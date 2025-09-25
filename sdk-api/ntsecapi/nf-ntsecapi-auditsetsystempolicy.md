# AuditSetSystemPolicy function

## Description

The **AuditSetSystemPolicy** function sets system audit policy for one or more audit-policy subcategories.

## Parameters

### `pAuditPolicy` [in]

A pointer to an array of [AUDIT_POLICY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-audit_policy_information) structures. Each structure specifies system audit policy for one audit-policy subcategory.

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

## Remarks

To successfully call this function, the caller must have **SeSecurityPrivilege** or have **AUDIT_SET_SYSTEM_POLICY** access on the [Audit security object](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## See also

[AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy)

[AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy)

[AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy)