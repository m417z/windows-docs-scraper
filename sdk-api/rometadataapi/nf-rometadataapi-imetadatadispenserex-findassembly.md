# IMetaDataDispenserEx::FindAssembly

## Description

Gets the name of the assembly.

## Parameters

### `szAppBase` [in]

Not used.

### `szPrivateBin` [in]

Not used.

### `szGlobalBin` [in]

Not used.

### `szAssemblyName` [in]

The name of the assembly to find.

### `szName` [out]

The simple name of the assembly.

### `cchName` [in]

The size, in bytes, of *szName*.

### `pchName` [out]

The number of characters actually returned in *szName*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataDispenserEx](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenserex)