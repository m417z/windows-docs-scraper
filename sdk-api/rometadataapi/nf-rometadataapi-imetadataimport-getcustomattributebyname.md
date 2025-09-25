# IMetaDataImport::GetCustomAttributeByName

## Description

Gets the custom attribute, given its name and owner.

## Parameters

### `tkObj` [in]

A metadata token representing the object that owns the custom attribute.

### `szName` [in]

The name of the custom attribute.

### `ppData` [out]

A pointer to an array of data that is the value of the custom attribute.

### `pcbData` [out]

The size in bytes of the data returned in *const*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is legal to define multiple custom attributes for the same owner; they may even have the same name. However, **GetCustomAttributeByName** returns only one instance. (**GetCustomAttributeByName** returns the first instance that it encounters.) To find all instances of a custom attribute, call the [EnumCustomAttributes](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-enumcustomattributes) method.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)