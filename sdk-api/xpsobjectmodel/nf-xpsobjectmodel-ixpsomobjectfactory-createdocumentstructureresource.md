# IXpsOMObjectFactory::CreateDocumentStructureResource

## Description

Creates an [IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource) interface, which provides access to the document structure resource stream.

## Parameters

### `acquiredStream` [in]

The read-only [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface to be associated with this resource. This parameter must not be **NULL**.

**Important** Treat this stream as a Single-Threaded Apartment (STA) object; do not re-enter it.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource. This parameter must not be **NULL**.

### `documentStructureResource` [out, retval]

A pointer to the new [IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *acquiredStream*, *partUri*, or *documentStructureResource* is **NULL**. |

## Remarks

The DocumentStructure part of an XPS document contains the document outline, which, with the StoryFragments parts, defines the reading order of every element that appears in the fixed pages of the document. This interface enables a program to read the XML contents of the DocumentStructure part and also to replace the XML contents of the DocumentStructure part.

The DocumentStructure part contains the document framework and the outline that describes the overall reading order of the document. The reading order is organized into semantic blocks called stories. Stories are logical units of the document in the same way as articles are units in a magazine. Stories are made up of one or more StoryFragments parts.

The StoryFragments parts contain content structure markup that defines the story's semantic blocks, such as the paragraphs and tables that make up the story's content.

The content of the DocumentStructure and StoryFragments parts is described in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))