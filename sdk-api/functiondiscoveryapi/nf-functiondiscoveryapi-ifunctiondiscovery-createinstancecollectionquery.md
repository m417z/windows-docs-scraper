# IFunctionDiscovery::CreateInstanceCollectionQuery

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a query for a collection of specific function instances.

## Parameters

### `pszCategory` [in]

The category for the query. See [Category Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/category-definitions).

### `pszSubCategory` [in]

The subcategory for the query. See [Subcategory Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/subcategory-definitions). This parameter can be **NULL**.

Subcategory queries are only supported for layered categories and some provider categories. The [Registry Provider](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/registry-provider), the PnP-X association provider, and the publication provider support subcategory queries. Custom providers can be explicitly designed to support subcategory queries. This means the *pszSubCategory* parameter should be set to a non-**NULL** value only when the *pszCategory* parameter is set to **FCTN_CATEGORY_REGISTRY**, **FCTN_CATEGORY_PUBLICATION**, **FCTN_CATEGORY_PNPXASSOCIATION**, or a custom category value defined for either a layered category or a custom provider supporting subcategory queries.

### `fIncludeAllSubCategories` [in]

If **TRUE**, this method recursively creates a query for all the subcategories of the category specified in *pszCategory*, returning a collection containing function instances from all the subcategories of *pszCategory*.

If **FALSE**, this method restricts the created query to returning function instances in the category specified by *pszCategory* and the subcategory specified by *pszSubCategory*.

### `pIFunctionDiscoveryNotification` [in]

A pointer to the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface implemented by the calling application. This parameter can be **NULL**. This pointer is valid until the returned query object is released.

### `pfdqcQueryContext` [in, out]

A pointer to the context in which the query was created. The type **FDQUERYCONTEXT** is defined as a DWORDLONG.

### `ppIFunctionInstanceCollectionQuery` [out]

A pointer to the [IFunctionInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollectionquery) interface pointer.

## Return value

Possible return values include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *pszCategory* or *pIID* is invalid. The value returned in *ppIFunctionInstanceCollectionQuery* parameter is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)**<br><br>0x80070002 | The value of *pszCategory* or *pszSubCategory* is unknown. |

## Remarks

If *pIFunctionDiscoveryNotification* is specified, it enables the Function Discovery change notification process. This parameter can be **NULL**. However, it is required for network providers since they do not return synchronous results. Function Discovery network providers only return instances through the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface.

This method only initializes the query call. The [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) method of the [IFunctionInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollectionquery) interface returned in *ppIFunctionInstanceCollectionQuery* must be called to perform the query and return any data.

## See also

[Function Discovery Queries](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-queries)

[IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery)