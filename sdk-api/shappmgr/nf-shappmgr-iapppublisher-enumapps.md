# IAppPublisher::EnumApps

## Description

Creates an enumerator for enumerating all applications published by an application publisher for a given category.

## Parameters

### `pAppCategoryId` [in]

Type: **GUID***

A pointer to a GUID that specifies the application category to be enumerated. This must be one of the categories provided through [IAppPublisher::GetCategories](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-iapppublisher-getcategories). If *pAppCategoryID* identifies a category not provided through **IAppPublisher::GetCategories**, creation of the enumerator succeeds with the enumerator returning zero items. If this parameter value is **NULL**, the enumerator returns applications published for all categories.

### `ppepa` [out]

Type: **[IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps)****

The address of a pointer to an [IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps) reference variable that points to a **IEnumPublishedApps** interface. Application publishers must create an enumeration object that supports the **IEnumPublishedApps** interface, and return its pointer value through this parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** [IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps) is not a standard enumeration interface. It does not support a Skip method nor does its Next method support retrieval of multiple items.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)