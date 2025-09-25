# IMetaDataImport::GetNameFromToken

## Description

Gets the UTF-8 name of the object referenced by the specified metadata token. This method is obsolete.

## Parameters

### `tk` [in]

The token representing the object to return the name for.

### `pszUtf8NamePtr` [out]

A pointer to the UTF-8 object name in the heap.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**GetNameFromToken** is obsolete. As an alternative, call a method to get the properties of the particular type of token required, such as [GetFieldProps](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-getfieldprops) for a field or [GetMethodProps](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-getmethodprops) for a method.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)