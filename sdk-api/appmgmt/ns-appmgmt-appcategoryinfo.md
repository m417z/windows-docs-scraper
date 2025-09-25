# APPCATEGORYINFO structure

## Description

Provides application category information to Add/Remove Programs in Control Panel. The [APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist) structure is used create a complete list of categories for an application publisher.

## Members

### `Locale`

Type: **LCID**

Unused.

### `pszDescription`

Type: **LPWSTR**

A pointer to a string containing the display name of the category. This string displays in the **Category** list in Add/Remove Programs. This string buffer must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `AppCategoryId`

Type: **GUID**

A GUID identifying the application category.

## See also

[APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist)

[IAppPublisher::GetCategories](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-iapppublisher-getcategories)