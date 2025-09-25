# IMetaDataDispenserEx::FindAssemblyModule

## Description

Finds the name of the assembly module.

## Parameters

### `szAppBase` [in]

Not used.

### `szPrivateBin` [in]

Not used.

### `szGlobalBin` [in]

Not used.

### `szAssemblyName` [in]

The assembly to be found.

### `szModuleName` [in]

The name of the module.

### `szName` [out]

The simple name of the assembly.

### `cchName` [in]

The size, in bytes, of *szName*.

### `pcName` [out]

The number of characters actually returned in *szName*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataDispenserEx](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenserex)