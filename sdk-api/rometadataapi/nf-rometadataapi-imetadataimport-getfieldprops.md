# IMetaDataImport::GetFieldProps

## Description

Gets metadata associated with the field referenced by the specified FieldDef token.

## Parameters

### `tkFieldDef` [in]

A FieldDef token that represents the field to get associated metadata for.

### `ptkTypeDef` [out]

A pointer to a TypeDef token that represents the type of the class that the field belongs to.

### `szField` [out]

The name of the field.

### `cchField` [in]

The size in wide characters of the buffer for *szField*.

### `pchField` [out]

The actual size of the returned buffer.

### `pdwAttr` [out]

Flags associated with the field's metadata.

### `ppvSigBlob` [out]

A pointer to the binary metadata value that describes the field.

### `pcbSigBlob` [out]

The size in bytes of *ppvSigBlob*.

### `pdwCPlusTypeFlag` [out]

A flag that specifies the value type of the field.

### `ppValue` [out]

A constant value for the field.

### `pcchValue` [out]

The size in chars of *ppValue*, or zero if no string exists.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)