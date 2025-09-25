# IMetaDataImport::GetCustomAttributeProps

## Description

Gets the value of the custom attribute, given its metadata token.

## Parameters

### `cv` [in]

A metadata token that represents the custom attribute to be retrieved.

### `ptkObj` [out]

A metadata token representing the object that the custom attribute modifies. This value can be any type of metadata token except **mdCustomAttribute**. See [Metadata Tokens](https://learn.microsoft.com/previous-versions/dotnet/netframework-4.0/ms404456(v=vs.100)) for more information about the token types.

### `ptkType` [out]

An **mdMethodDef** or **mdMemberRef** metadata token representing the Type of the returned custom attribute.

### `ppBlob` [out]

A pointer to an array of data that is the value of the custom attribute.

### `pcbBlob` [out]

The size in bytes of the data returned in *const*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A custom attribute is stored as an array of data, the format of which is understood by the metadata engine.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)