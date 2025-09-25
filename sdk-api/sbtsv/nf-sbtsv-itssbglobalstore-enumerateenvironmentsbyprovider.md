# ITsSbGlobalStore::EnumerateEnvironmentsByProvider

## Description

Returns an array that contains the environments present on the specified provider.

## Parameters

### `ProviderName` [in]

The name of the provider.

### `pdwCount` [in, out]

A pointer to the number of environments retrieved.

### `ppVal` [out]

A pointer to an array that contains references to the environments present. When you have finished using the array, release each element and free the array by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore)