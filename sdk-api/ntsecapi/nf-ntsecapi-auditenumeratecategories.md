# AuditEnumerateCategories function

## Description

The **AuditEnumerateCategories** function enumerates the available audit-policy categories.

## Parameters

### `ppAuditCategoriesArray` [out]

A pointer to a single buffer that contains both an array of pointers to **GUID** structures and the structures themselves. The **GUID** structures specify the audit-policy categories available on the computer.

When you have finished using this buffer, free it by calling the [AuditFree](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditfree) function.

### `pdwCountReturned` [out]

A pointer to the number of elements in the *ppAuditCategoriesArray* array.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuditEnumerateSubCategories](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditenumeratesubcategories)