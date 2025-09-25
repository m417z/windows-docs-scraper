# IXpsOMSignatureBlockResourceCollection::InsertAt

## Description

Inserts an [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface pointer at a specified location in the collection.

## Parameters

### `index` [in]

The zero-based index in the collection where the interface pointer that is passed in *signatureBlockResource* is to be inserted.

### `signatureBlockResource` [in]

The [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface pointer that is to be inserted at the location specified by *index*.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

At the location specified by *index*, this method inserts the [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface pointer that is passed in *signatureBlockResource*. Prior to the insertion, the pointer in this and all subsequent locations is moved up by one index.

For more information about the collection methods, see [Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85)).

## See also

[IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource)

[IXpsOMSignatureBlockResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresourcecollection)

[Working with XPS OM Collection Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/dd372931(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)