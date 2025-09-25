# IMetaDataImport::GetModuleRefProps

## Description

Gets the name of the module referenced by the specified metadata token.

## Parameters

### `tkModuleRef` [in]

The ModuleRef metadata token that references the module to get metadata information for.

### `szName` [out]

A buffer to hold the module name.

### `cchName` [in]

The requested size of *szName* in wide characters.

### `pchName` [out]

The returned size of *szName* in wide characters.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)