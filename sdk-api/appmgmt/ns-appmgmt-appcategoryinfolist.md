# APPCATEGORYINFOLIST structure

## Description

Provides a list of supported application categories from an application publisher to Add/Remove Programs in Control Panel.

## Members

### `cCategory`

Type: **DWORD**

A value of type **DWORD** that specifies the count of [APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo) elements in the array pointed to by **pCategoryInfo**.

### `pCategoryInfo`

Type: **[APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo)***

A pointer to an array of [APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo) structures. This array contains all the categories an application publisher supports and must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pCategoryInfo.size_is`

### `pCategoryInfo.size_is.cCategory`

## See also

[APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo)

[IAppPublisher::GetCategories](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-iapppublisher-getcategories)