# GetManagedApplicationCategories function

## Description

The
**GetManagedApplicationCategories** function gets a list of application categories for a domain. The list is the same for all users in the domain.

## Parameters

### `dwReserved` [out]

This parameter is reserved. Its value must be 0.

### `pAppCategory` [out]

A [APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist) structure that contains a list of application categories. This structure must be freed by calling [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) when the list is no longer required.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

The structure returned by **GetManagedApplicationCategories** must be freed by calling [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) when the list is no longer required.

## See also

[APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)