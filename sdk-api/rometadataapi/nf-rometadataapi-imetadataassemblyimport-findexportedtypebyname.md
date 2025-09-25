# IMetaDataAssemblyImport::FindExportedTypeByName

## Description

Gets a pointer to an exported type, given its name and enclosing type.

## Parameters

### `szName` [in]

The name of the exported type.

### `mdtExportedType` [in]

The metadata token for the enclosing class of the exported type. This value is **mdExportedTypeNil** if the requested exported type is not a nested type.

### `ptkExportedType` [out]

A pointer to the **mdExportedType** token that represents the exported type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method uses the standard rules employed by the common language runtime for resolving references.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)