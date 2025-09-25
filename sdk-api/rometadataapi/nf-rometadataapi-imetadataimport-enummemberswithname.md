# IMetaDataImport::EnumMembersWithName

## Description

Enumerates MemberDef tokens representing members of the specified type with the specified name.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tkTypeDef` [in]

A TypeDef token representing the type with members to enumerate.

### `szName` [in]

The member name that limits the scope of the enumerator.

### `rgMembers` [out]

The array used to store the MemberDef tokens.

### `cMax` [in]

The maximum size of the *rgMembers* array.

### `pcTokens` [out]

The actual number of MemberDef tokens returned in *rgMembers*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMembersWithName** returned successfully. |
| **S_FALSE** | There are no MemberRef tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## Remarks

This method enumerates fields and methods, but not properties or events. Unlike [EnumMembers](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadataimport-enummembers), **EnumMembersWithName** discards all field and member tokens that do not have the specified name.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)