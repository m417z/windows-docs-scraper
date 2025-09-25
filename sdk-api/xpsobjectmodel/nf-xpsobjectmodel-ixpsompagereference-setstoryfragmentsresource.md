# IXpsOMPageReference::SetStoryFragmentsResource

## Description

Sets the [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface pointer of the StoryFragments resource to be assigned to the page.

## Parameters

### `storyFragmentsResource` [in]

A pointer to the [IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource) interface of the StoryFragments part resource to be assigned to the page. If an **IXpsOMStoryFragmentsResource** interface has been set, a **NULL** pointer will release it.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *storyFragmentsResource* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The StoryFragments part of a page contains the XML markup that describes the portions of one or more stories that are associated with a single fixed page. Some of the document contents that might be described by the XML markup in a StoryFragments part include the story's tables and paragraphs that are found on the page.

The XML markup of the DocumentStructure and StoryFragments parts is described in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

## See also

[IXpsOMDocumentStructureResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentstructureresource)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)