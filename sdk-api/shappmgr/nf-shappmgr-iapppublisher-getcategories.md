# IAppPublisher::GetCategories

## Description

Retrieves a structure listing the categories provided by an application publisher.

## Parameters

### `pAppCategoryList` [out]

Type: **[APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist)***

A pointer to an [APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist) structure. This structure's **cCategory** member returns the count of supported categories. The **pCategoryInfo** member returns a pointer to an array of [APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo) structures. This array contains all the categories an application publisher supports and must be allocated using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Add/Remove Programs Control Panel Application passes the ID returned for a category to the [IAppPublisher::EnumApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-iapppublisher-enumapps) method to identify which category is to be enumerated.

#### Examples

The following example shows how to calculate the size of the array of [APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo) structures that is returned by **IAppPublisher::GetCategories**.

```cpp
size_t CategoryListArraySize = sizeof(APPCATEGORYINFO) * pInfoList->cCategory;
```

## See also

[APPCATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfo)

[APPCATEGORYINFOLIST](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-appcategoryinfolist)

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)