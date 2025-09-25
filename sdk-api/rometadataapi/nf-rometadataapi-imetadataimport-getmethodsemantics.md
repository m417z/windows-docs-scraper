# IMetaDataImport::GetMethodSemantics

## Description

Gets flags indicating the relationship between the method referenced by the specified MethodDef token and the paired property and event referenced by the specified EventProp token.

## Parameters

### `tkMethodDef` [in]

A MethodDef token representing the method to get the semantic role information for.

### `tkEventProp` [in]

A token representing the paired property and event for which to get the method's role.

### `pdwSemanticsFlags` [out]

A pointer to the associated semantics flags. This value is a bitmask from the CorMethodSemanticsAttr enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport)