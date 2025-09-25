# IFunctionDiscoveryProviderQuery::IsSubcategoryQuery

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines whether a query is for function instances in a specific subcategory.

## Parameters

### `pisSubcategoryQuery` [out]

If this parameter is **TRUE**, there is a subcategory constraint in the query constraints collection.

### `ppszConstraintValue` [out]

The value of the subcategory constraint.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the provider does not support subcategories, the provider should return an [IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection) with 0 instances in response to the query.

## See also

[IFunctionDiscoveryProviderQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderquery)