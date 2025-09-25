# IMetaDataAssemblyImport::EnumExportedTypes

## Description

Enumerates the exported types referenced in the assembly manifest in the current metadata scope.

## Parameters

### `phEnum` [in, out]

 A pointer to the enumerator. This must be a null value when the **EnumExportedTypes** method is called for the first time.

### `rExportedTypes` [out]

The enumeration of **mdExportedType** metadata tokens.

### `cMax` [in]

The maximum number of **mdExportedType** tokens that can be placed in the *rExportedTypes* array.

### `pcTokens` [out]

The number of **mdExportedType** tokens actually placed in *rExportedTypes*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumExportedTypes** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is set to zero. |

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)