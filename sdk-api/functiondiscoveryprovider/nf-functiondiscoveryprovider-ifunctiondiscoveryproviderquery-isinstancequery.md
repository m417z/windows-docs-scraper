# IFunctionDiscoveryProviderQuery::IsInstanceQuery

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines whether a query is for a single function instance or multiple function instances.

## Parameters

### `pisInstanceQuery` [out]

If this parameter is **TRUE**, there is a provider instance identifier constraint in the query constraints collection.

### `ppszConstraintValue` [out]

The value of the provider instance identifier constraint.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFunctionDiscoveryProviderQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderquery)