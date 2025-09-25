# IFunctionDiscoveryProviderQuery::GetPropertyConstraints

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves the current property constraints.

## Parameters

### `ppIProviderPropertyConstraints` [out]

A pointer to an [IProviderPropertyConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderpropertyconstraintcollection) interface pointer that receives the collection of property constraints.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Function Discovery will apply all property constraints to the results returned by the provider, but it is more efficient if the provider can apply the property constraints to the results.

 The provider should examine all constraints to determine the query to perform.

## See also

[IFunctionDiscoveryProviderQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderquery)