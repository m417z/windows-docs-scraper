# IFunctionDiscoveryProviderQuery::GetQueryConstraints

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves the current query constraints.

## Parameters

### `ppIProviderQueryConstraints` [out]

A pointer to an [IProviderQueryConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderqueryconstraintcollection) interface pointer that receives the collection of query constraints.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Providers are expected to apply all query constraints when returning results. Providers should ignore any query constraints they do not recognize.

The provider should examine all constraints to determine the query to perform.

## See also

[IFunctionDiscoveryProviderQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderquery)