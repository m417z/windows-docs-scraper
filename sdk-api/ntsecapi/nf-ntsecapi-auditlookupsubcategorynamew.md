# AuditLookupSubCategoryNameW function

## Description

The **AuditLookupSubCategoryName** function retrieves the display name of the specified audit-policy subcategory.

## Parameters

### `pAuditSubCategoryGuid` [in]

A pointer to a **GUID** structure that specifies an audit-policy subcategory.

### `ppszSubCategoryName` [out]

The address of a pointer to a null-terminated string that contains the display name of the audit-policy subcategory specified by the *pAuditSubCategoryGuid* parameter.

When you have finished using this string, free it by calling the [AuditFree](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditfree) function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuditLookupCategoryName](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditlookupcategorynamea)

## Remarks

> [!NOTE]
> The ntsecapi.h header defines AuditLookupSubCategoryName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).