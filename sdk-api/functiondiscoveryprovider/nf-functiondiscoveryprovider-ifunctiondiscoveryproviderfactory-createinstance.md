# IFunctionDiscoveryProviderFactory::CreateInstance

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a function instance. All function instances should be created using this method. Other implementations that support [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) should not be used.

## Parameters

### `pszSubCategory` [in]

The subcategory string for the function instance. See [Subcategory Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/subcategory-definitions).

### `pszProviderInstanceIdentity` [in]

The provider instance identifier.

Function Discovery uses this identifier to ensure that function instance identifiers returned by [IFunctionInstance::GetID](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-getid) are unique. To that end, Function Discovery attaches a prefix to the identifier passed to *pszProviderInstanceIdentity* to ensure that a given function instance identifier is unique across all providers. Implementers only need to ensure that *pszProviderInstanceIdentity* uniquely identifies the device, resource, or instance within the scope of the provider.

This string is returned to client applications that call [IFunctionInstance::GetProviderInstanceID](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-getproviderinstanceid).

There is no upper limit on the size of this string.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `pIPropertyStore` [in]

A pointer to an **IPropertyStore** interface.

### `pIFunctionDiscoveryProvider` [in]

A pointer to the [IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider) provider instance creating this function instance.

### `ppIFunctionInstance` [out]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The provider should specify the subcategory (may be **NULL**), the instance identifier, a provider-allocated context (if required), and an optional property store.

**CreateInstance** returns an appropriately initialized function instance to the provider.

The context specified by the provider will be passed back to the provider for all subsequent function instance related methods, such as [InstanceReleased](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-instancereleased), [InstancePropertyStoreOpen](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-instancepropertystoreopen), [InstancePropertyStoreFlush](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-instancepropertystoreflush), and [InstanceQueryService](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-instancequeryservice).

The provider must guarantee that the provider reference count does not go to zero, possibly on another thread, while **CreateInstance** is being called.

## See also

[IFunctionDiscoveryProviderFactory](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderfactory)