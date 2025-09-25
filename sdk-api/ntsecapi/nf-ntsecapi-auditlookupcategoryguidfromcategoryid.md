# AuditLookupCategoryGuidFromCategoryId function

## Description

The **AuditLookupCategoryGuidFromCategoryId** function retrieves a **GUID** structure that represents the specified audit-policy category.

## Parameters

### `AuditCategoryId` [in]

An element of the [POLICY_AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_audit_event_type) enumeration that specifies an audit-policy category.

### `pAuditCategoryGuid` [out]

A pointer to a **GUID** structure that represents the audit-policy category specified by the *AuditCategoryId*

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuditLookupCategoryIdFromCategoryGuid](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditlookupcategoryidfromcategoryguid)