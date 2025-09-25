# IMetaDataAssemblyImport::EnumFiles

## Description

Enumerates the files referenced in the current assembly manifest.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator. This must be a null value for the first call of this method.

### `rFiles` [out]

The array used to store the **mdFile** metadata tokens.

### `cMax` [in]

The maximum number of **mdFile** tokens that can be placed in *rFiles*.

### `pcTokens` [out]

The number of **mdFile** tokens actually placed in *rFiles*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumFiles** returned successfully. |
| **S_FALSE** | There are no tokens to enumerate. In this case, *pcTokens* is set to zero. |

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)