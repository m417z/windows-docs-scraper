# IXpsOMPageReference::GetStoryFragmentsResource

## Description

Gets a pointer to the [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface of the StoryFragments part resource that is associated with the page.

## Parameters

### `storyFragmentsResource` [out, retval]

A pointer to the [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface of the StoryFragments part resource that is associated with the page. If there is no StoryFragments part, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *storyFragmentsResource* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

After the resource is parsed and loaded into the XPS OM, this method might return an error that applies to another resource. This occurs because when a resource is loaded, all of the relationships are parsed.

The StoryFragments part of a page contains the XML markup that describes the portions of one or more stories that are associated with a single fixed page. Some of the document contents that might be described by the XML markup in a StoryFragments part include the story's tables and paragraphs that are found on the page.

The XML markup in the DocumentStructure and StoryFragments parts is described in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

## See also

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))