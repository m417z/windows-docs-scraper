# IFunctionDiscoveryProvider::InstancePropertyStoreFlush

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Provides a mechanism for the provider to persist properties without having to implement [IProviderProperties](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderproperties). This method is called whenever [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) is called by the client on the function instance property store.

## Parameters

### `pIFunctionInstance` [in]

 A pointer to the [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The provider does not implement an instance property store. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

If the provider keeps the new values that are passed through [SetValue](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-iproviderproperties-setvalue) cached in memory, this method should implement the code to persist the updated values to the underlying API/store.

If you implement this method, you should call [OpenPropertyStore](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-openpropertystore) to return the current property store before persisting the data.

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)