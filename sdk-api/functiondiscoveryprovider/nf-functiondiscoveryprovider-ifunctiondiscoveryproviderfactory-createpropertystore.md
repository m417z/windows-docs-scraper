# IFunctionDiscoveryProviderFactory::CreatePropertyStore

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Enables providers to reuse the in-memory property store implementation.

## Parameters

### `ppIPropertyStore` [out]

A pointer to an **IPropertyStore** interface pointer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If providers wish to cache properties, either when the function instance is created or when the property store is first opened, the provider can use this method to create an in memory property store, set properties as necessary, and then either assign it to the function instance at creation time using [CreateInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryproviderfactory-createinstance) or when the property store is first opened using [InstancePropertyStoreOpen](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-instancepropertystoreopen).

## See also

[IFunctionDiscoveryProviderFactory](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderfactory)