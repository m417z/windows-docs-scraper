# ITsSbGlobalStore::EnumerateTargets

## Description

Returns an array that contains the specified targets present in the global store.

## Parameters

### `ProviderName` [in]

The provider name.

### `FarmName` [in]

The farm name.

### `EnvName` [in]

The environment name.

### `pdwCount` [in, out]

The number of targets retrieved.

### `pVal` [out]

Pointer to the retrieved [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) objects.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore)