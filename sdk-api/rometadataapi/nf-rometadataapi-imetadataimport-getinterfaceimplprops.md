# IMetaDataImport::GetInterfaceImplProps

## Description

Gets a pointer to the metadata tokens for the Type that implements the specified method, and for the interface that declares that method.

## Parameters

### `tkInterfaceImpl` [in]

The metadata token representing the method to return the class and interface tokens for.

### `ptkClass` [out]

The metadata token representing the class that implements the method.

### `ptkIface` [out]

The metadata token representing the interface that defines the implemented method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)