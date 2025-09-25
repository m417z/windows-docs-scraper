# IMetaDataImport::GetMemberRefProps

## Description

Gets metadata associated with the member referenced by the specified token.

## Parameters

### `tkMemberRef` [in]

The MemberRef token to return associated metadata for.

### `ptk` [out]

A TypeDef or TypeRef, or TypeSpec token that represents the class that declares the member, or a ModuleRef token that represents the module class that declares the member, or a MethodDef that represents the member.

### `szMember` [out]

A string buffer for the member's name.

### `cchMember` [in]

The requested size in wide characters of *szMember*.

### `pchMember` [out]

The returned size in wide characters of *szMember*.

### `ppvSigBlob` [out]

A pointer to the binary metadata signature for the member.

### `pcbSigBlob` [out]

The size in bytes of *ppvSigBlob*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)