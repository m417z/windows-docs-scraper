# IXpsOMObjectFactory::CreateStoryFragmentsResource

## Description

Creates an [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface that provides access to the content of the resource stream of a page's StoryFragments part.

## Parameters

### `acquiredStream` [in]

The read-only [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface to be associated with this StoryFragments resource.

**Important** Treat this stream as a Single-Threaded Apartment (STA) object; do not re-enter it.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource.

### `storyFragmentsResource` [out, retval]

A pointer to the new [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *acquiredStream*, *partUri*, or *storyFragmentsResource* is **NULL**. |

## Remarks

The StoryFragments part of a page contains the XML markup that describes the structure of the portions of one or more stories that are associated with a single fixed page. Some of the document contents that might be described by the XML markup in a StoryFragments part include the story's tables and paragraphs that are found on the page.

The XML markup in the DocumentStructure and StoryFragments parts is described in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

## See also

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))