# ITsSbResourcePluginStore::EnumerateEnvironments

## Description

Returns an array that contains the environments present in the resource plug-in store.

## Parameters

### `pdwCount` [in, out]

A pointer to the number of targets retrieved.

### `pVal` [out]

A pointer to an array that contains references to the environments present. When you have finished using the array, release each element and free the array by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment)

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbResourcePluginStoreEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbresourcepluginstoreex)