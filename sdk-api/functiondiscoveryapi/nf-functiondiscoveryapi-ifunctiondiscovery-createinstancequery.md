# IFunctionDiscovery::CreateInstanceQuery

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a query for a specific function instance.

## Parameters

### `pszFunctionInstanceIdentity` [in]

The identifier of the function instance.

### `pIFunctionDiscoveryNotification` [in]

A pointer to the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface implemented by the calling application. If specified, it enables the Function Discovery change notification process. This parameter can be **NULL**; however it is required for network providers.

### `pfdqcQueryContext` [in, out]

A pointer to the context in which the query was created. The type **FDQUERYCONTEXT** is defined as a DWORDLONG.

### `ppIFunctionInstanceQuery` [out]

A pointer to an [IFunctionInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancequery) interface pointer used to return the generated query.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ppIFunctionInstanceQuery* is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

Function Discovery Network providers only return instances through the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface.

This method only initializes the query call. The [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancequery-execute) method of the [IFunctionInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancequery) interface returned in *ppIFunctionInstanceQuery* must be called to perform the query and return any data.

## See also

[Function Discovery Queries](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-queries)

[IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery)