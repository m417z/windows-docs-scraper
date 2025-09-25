# AuditComputeEffectivePolicyBySid function

## Description

The **AuditComputeEffectivePolicyBySid** function computes the effective audit policy for one or more subcategories for the specified security principal. The function computes effective audit policy by combining system audit policy with per-user policy.

## Parameters

### `pSid` [in]

A pointer to the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure associated with the principal for which to compute effective audit policy. Per-user policy for group SIDs is not currently supported.

### `pSubCategoryGuids` [in]

A pointer to an array of **GUID** values that specify the subcategories for which to compute effective audit policy. For a list of defined subcategories, see [Auditing Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/auditing-constants).

### `dwPolicyCount` [in]

The number of elements in each of the *pSubCategoryGuids* and *ppAuditPolicy* arrays.

### `ppAuditPolicy` [out]

A pointer to a single buffer that contains both an array of pointers to [AUDIT_POLICY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-audit_policy_information) structures and the structures themselves. The **AUDIT_POLICY_INFORMATION** structures specify the effective audit policy for the subcategories specified by the *pSubCategoryGuids* array.

When you have finished using this buffer, free it by calling the [AuditFree](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditfree) function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes defined in WinError.h.

| Return code/value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED**<br><br>5 | The caller does not have the privilege or access rights necessary to call this function. |
| **ERROR_INVALID_PARAMETER**<br><br>87 (0x57) | One or more parameters are not valid. |
| **ERROR_FILE_NOT_FOUND**<br><br>2 (0x2) | No per-user audit policy exists for the principal specified by the *pSid* parameter. |

## Remarks

To successfully call this function, the caller must have **SeSecurityPrivilege** or have **AUDIT_QUERY_SYSTEM_POLICY** and **AUDIT_QUERY_USER_POLICY** access on the [Audit security object](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).