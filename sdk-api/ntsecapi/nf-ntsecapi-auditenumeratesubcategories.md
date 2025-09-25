# AuditEnumerateSubCategories function

## Description

The **AuditEnumerateSubCategories** function enumerates the available audit-policy subcategories.

## Parameters

### `pAuditCategoryGuid` [in]

The **GUID** of an audit-policy category for which subcategories are enumerated. If the value of the *bRetrieveAllSubCategories* parameter is **TRUE**, this parameter is ignored.

### `bRetrieveAllSubCategories` [in]

**TRUE** to enumerate all audit-policy subcategories; **FALSE** to enumerate only the subcategories of the audit-policy category specified by the *pAuditCategoryGuid* parameter.

### `ppAuditSubCategoriesArray` [out]

A pointer to a single buffer that contains both an array of pointers to **GUID** structures and the structures themselves. The **GUID** structures specify the audit-policy subcategories available on the computer.

When you have finished using this buffer, free it by calling the [AuditFree](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditfree) function.

### `pdwCountReturned` [out]

A pointer to the number of audit-policy subcategories returned in the *ppAuditSubCategoriesArray* array.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuditEnumerateCategories](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditenumeratecategories)