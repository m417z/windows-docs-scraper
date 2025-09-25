# IMetaDataImport::GetMemberProps

## Description

Gets metadata information, including the name, binary signature, and relative virtual address, of the Type member referenced by the specified metadata token.

## Parameters

### `tkMember` [in]

The token that references the member to get the associated metadata for.

### `ptkTypeDef` [out]

A pointer to the metadata token that represents the class of the member.

### `szMember` [out]

The name of the member.

### `cchMember` [in]

The size in wide characters of the szMember buffer.

### `pchMember` [out]

The size in wide characters of the returned name.

### `pdwAttr` [out]

Any flag values applied to the member.

### `ppvSigBlob` [out]

A pointer to the binary metadata signature of the member.

### `pcbSigBlob` [out]

The size in bytes of *ppvSigBlob*.

### `pulCodeRVA` [out]

A pointer to the relative virtual address of the member.

### `pdwImplFlags` [out]

Any method implementation flags associated with the member.

### `pdwCPlusTypeFlag` [out]

A flag that marks a ValueType.

### `ppValue` [out]

A constant string value returned by this member.

### `pcchValue` [out]

The size in characters of *ppValue*, or zero if *ppValue* does not hold a string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)