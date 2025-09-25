# IMetaDataImport::EnumMembers

## Description

Enumerates MemberDef tokens representing members of the specified type.

## Parameters

### `phEnum` [in, out]

A pointer to the enumerator.

### `tkTypeDef` [in]

A TypeDef token representing the type whose members are to be enumerated.

### `rgMembers` [out]

The array used to hold the MemberDef tokens.

### `cMax` [in]

The maximum size of the *rgMembers* array.

### `pcTokens` [out]

The actual number of MemberDef tokens returned in *rgMembers*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **EnumMembers** returned successfully. |
| **S_FALSE** | There are no MemberRef tokens to enumerate. In this case, *pcTokens* is 0 (zero). |

## Remarks

When enumerating collections of members for a class, **EnumMembers** returns only members defined directly on the class. It does not return any members that the class inherits, even if the class provides an implementation for those inherited members. To enumerate inherited members, the caller must explicitly walk the inheritance chain. Note that the rules for the inheritance chain may vary depending on the language or compiler that emitted the original metadata.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)