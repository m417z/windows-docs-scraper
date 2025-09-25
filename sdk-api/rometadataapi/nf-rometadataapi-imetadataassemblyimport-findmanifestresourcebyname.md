# IMetaDataAssemblyImport::FindManifestResourceByName

## Description

Gets a pointer to the manifest resource with the specified name.

## Parameters

### `szName` [in]

The name of the resource.

### `ptkManifestResource` [out]

The array used to store the **mdManifestResource** metadata tokens, each of which represents a manifest resource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method uses the standard rules employed by the common language runtime for resolving references.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)