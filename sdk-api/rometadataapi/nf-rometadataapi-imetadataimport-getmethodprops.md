# IMetaDataImport::GetMethodProps

## Description

Gets the metadata associated with the method referenced by the specified MethodDef token.

## Parameters

### `tkMethodDef` [in]

The MethodDef token that represents the method to return metadata for.

### `ptkClass` [out]

A Pointer to a TypeDef token that represents the type that implements the method.

### `szMethod` [out]

A Pointer to a buffer that has the method's name.

### `cchMethod` [in]

The requested size of *szMethod*.

### `pchMethod` [out]

A pointer to the size in wide characters of *szMethod*, or in the case of truncation, the actual number of wide characters in the method name.

### `pdwAttr` [out]

A pointer to any flags associated with the method.

### `ppvSigBlob` [out]

A pointer to the binary metadata signature of the method.

### `pcbSigBlob` [out]

A pointer to the size in bytes of *ppvSigBlob*.

### `pulCodeRVA` [out]

A pointer to the relative virtual address of the method.

### `pdwImplFlags` [out]

A pointer to any implementation flags for the method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)