# IFunctionDiscoveryProvider::InstancePropertyStoreOpen

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Opens the property store of the provider. This method is called whenever [IFunctionInstance::OpenPropertyStore](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-openpropertystore) is called if the provider did not provide a property store at creation time. The provider can provide the property store at this time, or handle the [IProviderProperties](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderproperties) methods as they are called.

## Parameters

### `pIFunctionInstance` [in]

A pointer to the [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface for the store that is to be opened. Each property store is associated with a function instance.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `dwStgAccess` [in]

The access mode to be assigned to the open stream. For this method, the following modes are supported:

#### STGM_READ

#### STGM_READWRITE

#### STGM_WRITE

### `ppIPropertyStore` [out]

A pointer to an **IPropertyStore** interface pointer.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The provider does not implement an instance property store. |
| **STG_E_ACCESSDENIED** | The method could not open a writable property store because the caller has insufficient access, the discovery provider does not allow write access to its property store, or another property store is already open for this function instance. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)