# IMetaDataImport::EnumMemberRefs

## Description

Enumerates MemberRef tokens representing members of the specified type.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tkParent` [in]

A TypeDef, TypeRef, MethodDef, or ModuleRef token for the type whose members are to be enumerated.

### `rgMemberRefs` [out]

The array used to store MemberRef tokens.

### `cMax` [in]

The maximum size of the *rgMemberRefs* array.

### `pcTokens` [out]

The actual number of MemberRef tokens returned in *rgMemberRefs*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMemberRefs** returned successfully. |
| **S_FALSE** | There are no MemberRef tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)