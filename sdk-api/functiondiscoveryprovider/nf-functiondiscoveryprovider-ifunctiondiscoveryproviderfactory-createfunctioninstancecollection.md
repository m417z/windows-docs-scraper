# IFunctionDiscoveryProviderFactory::CreateFunctionInstanceCollection

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a function instance collection.

## Parameters

### `ppIFunctionInstanceCollection` [out]

A pointer to an [IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection) interface pointer.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *ppIFunctionInstanceCollection* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

Providers that return results synchronously through the *ppIFunctionInstanceCollection* parameter of the [IFunctionDiscoveryProvider::Query](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-query) method can use this to create a collection to return the results with.

Client programmers can create and use the Function Discovery instance collection object, as it can also be created using **CoCreateInstance**.

## See also

[IFunctionDiscoveryProviderFactory](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderfactory)