# GetManagedApplications function

## Description

The
**GetManagedApplications** function gets a list of applications that are displayed in the **Add** pane of **Add/Remove Programs** (ARP) for a specified user context.

## Parameters

### `pCategory` [in]

A pointer to a GUID that specifies the category

of applications to be listed. If *pCategory* is not null, *dwQueryFlags* must contain **MANAGED_APPS_FROMCATEGORY**. If *pCategory* is null, *dwQueryFlags* cannot contain **MANAGED_APPS_FROMCATEGORY**.

### `dwQueryFlags` [in]

This parameter can contain one or more of the following values.

#### MANAGED_APPS_USERAPPLICATIONS

Lists all applications that apply to the user. The parameter *pCategory* must be null.

#### MANAGED_APPS_FROMCATEGORY

Lists only applications in the category specified by *pCategory*. The *pCategory* parameter cannot be null.

### `dwInfoLevel` [in]

This parameter must be **MANAGED_APPS_INFOLEVEL_DEFAULT**.

### `pdwApps` [out]

The count of applications in the list returned by this function.

### `prgManagedApps` [out]

This parameter is a pointer to an array of [MANAGEDAPPLICATION](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-managedapplication) structures. This array contains the list of applications listed in the **Add** pane of **Add/Remove Programs** (ARP). You must call **LocalFree** to free the array when they array is no longer required.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)