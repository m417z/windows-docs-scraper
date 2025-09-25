# IMetaDataImport::FindMemberRef

## Description

Gets a pointer to the MemberRef token for the member reference that is enclosed by the specified Type and that has the specified name and metadata signature.

## Parameters

### `tkTypeRef` [in]

The TypeRef token for the class or interface that encloses the member reference to search for. If this value is **mdTokenNil**, the lookup is done for a global variable or a global-function reference.

### `szName` [in]

The name of the member reference to search for.

### `pvSigBlob` [in]

A pointer to the binary metadata signature of the member reference.

### `cbSigBlob` [in]

The size in bytes of *pvSigBlob*.

### `pMemberRef` [out]

A pointer to the matching MemberRef token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You specify the member using its enclosing class or interface (*tkTypeRef*), its name (*szName*), and optionally its signature (*pvSigBlob*).

The signature passed to **FindMemberRef** must have been generated in the current scope, because signatures are bound to a particular scope. A signature can embed a token that identifies the enclosing class or value type. The token is an index into the local TypeDef table. You cannot build a run-time signature outside the context of the current scope and use that signature as input to **FindMemberRef**.

**FindMemberRef** finds only member references that were defined directly in the class or interface; it does not find inherited member references.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)