# IFunctionInstance::GetProviderInstanceID

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the identifier string for the provider instance. This string is the unique identifier for the provider instance.

## Parameters

### `ppszCoMemProviderInstanceIdentity` [out]

The provider instance identifier string. For root devices, this string has the same value as PKEY_PNPX_GlobalIdentity.

Be sure to free this buffer using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *ppszCoMemProviderInstanceID* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## See also

[IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance)