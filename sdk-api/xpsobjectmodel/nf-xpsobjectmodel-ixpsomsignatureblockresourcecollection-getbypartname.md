# IXpsOMSignatureBlockResourceCollection::GetByPartName

## Description

Gets an [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface pointer from the collection by matching the interface's part name.

## Parameters

### `partName` [in]

The part name of the [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface to be found in the collection.

### `signatureBlockResource` [out, retval]

A pointer to the [IXpsOMSignatureBlockResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresource) interface whose part name matches *partName*. If a matching interface is not found in the collection, a **NULL** pointer is returned.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMSignatureBlockResourceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsignatureblockresourcecollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)