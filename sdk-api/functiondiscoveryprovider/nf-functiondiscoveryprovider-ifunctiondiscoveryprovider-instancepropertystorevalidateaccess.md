# IFunctionDiscoveryProvider::InstancePropertyStoreValidateAccess

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Verifies that the provider supports the requested access. It is called when [OpenPropertyStore](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-openpropertystore) is called on a function instance to verify that the provider supports the access mode passed by the *dwStgAccess* parameter.

This method is only called when a provider's [Initialize](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-initialize) method returns a *pdwStgAccessCapabilities* parameter value of -1.

## Parameters

### `pIFunctionInstance` [in]

A pointer to the [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface.

### `iProviderInstanceContext` [in]

The context associated with the specific function instance.

### `dwStgAccess` [in]

The access mode to be verified. For this method, the following modes are supported:

#### STGM_READ

#### STGM_READWRITE

#### STGM_WRITE

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The provider does not implement an instance property store. |
| **STG_E_ACCESSDENIED** | The method could not open a writable property store because the caller has insufficient access, the discovery provider does not allow write access to its property store, or another property store is already open for this function instance. |
| **E_INVALIDARG** | The value of *dwStgAccess* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

The precise meaning of the STG_E_ACCESSDENIED return value is implementation-specific. When you implement the **InstancePropertyStoreValidateAccess** method, you can return STG_E_ACCESSDENIED for any supplied *dwStgAccess* mode value on any supplied function instance.

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)