# IMetaDataImport2::GetMethodSpecProps

## Description

Gets the metadata signature of the method referenced by the specified MethodSpec token.

## Parameters

### `mi` [in]

A **MethodSpec** token that represents the instantiation of the method.

### `tkParent` [out]

A pointer to the **MethodDef** or **MethodRef** token that represents the method definition.

### `ppvSigBlob` [out]

 A pointer to the binary metadata signature of the method.

### `pcbSigBlob` [out]

The size, in bytes, of *ppvSigBlob*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport2)