# IXpsOMDocumentStructureResource::GetOwner

## Description

Gets a pointer to the [IXpsOMDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocument) interface that contains the resource.

## Parameters

### `owner` [out, retval]

A pointer to the [IXpsOMDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocument) interface that contains the resource. If the resource is not part of a document, a **NULL** pointer is returned.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IXpsOMDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocument)

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)