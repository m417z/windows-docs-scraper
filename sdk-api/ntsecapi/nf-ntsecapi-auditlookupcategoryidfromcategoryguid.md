# AuditLookupCategoryIdFromCategoryGuid function

## Description

The **AuditLookupCategoryIdFromCategoryGuid** function retrieves an element of the [POLICY_AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_audit_event_type) enumeration that represents the specified audit-policy category.

## Parameters

### `pAuditCategoryGuid` [in]

A pointer to a **GUID** structure that specifies an audit-policy category.

### `pAuditCategoryId` [out]

A pointer to an element of the [POLICY_AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_audit_event_type) enumeration that represents the audit-policy category specified by the *pAuditCategoryGuid* parameter.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuditLookupCategoryGuidFromCategoryId](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditlookupcategoryguidfromcategoryid)