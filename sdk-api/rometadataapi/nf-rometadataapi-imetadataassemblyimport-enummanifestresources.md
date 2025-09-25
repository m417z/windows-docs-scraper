# IMetaDataAssemblyImport::EnumManifestResources

## Description

Gets a pointer to an enumerator for the resources referenced in the current assembly manifest.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be a null value when the **EnumManifestResources** method is called for the first time.

### `rManifestResources` [out]

The array used to store the **mdManifestResource** metadata tokens.

### `cMax` [in]

The maximum number of **mdManifestResource** tokens that can be placed in *rManifestResources*.

### `pcTokens` [out]

The number of **mdManifestResource** tokens actually placed in *rManifestResources*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumManifestResources** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is set to zero. |

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)