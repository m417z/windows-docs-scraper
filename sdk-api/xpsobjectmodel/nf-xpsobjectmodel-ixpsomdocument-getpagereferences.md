# IXpsOMDocument::GetPageReferences

## Description

Gets the [IXpsOMPageReferenceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereferencecollection) interface of the document, which allows virtualized access to its pages.

## Parameters

### `pageReferences` [out, retval]

A pointer to the [IXpsOMPageReferenceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereferencecollection) interface that contains a collection of page references for each page of the document. If there are no page references, the **IXpsOMPageReferenceCollection** returned in *pageReferences* will be empty and will have no elements.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pageReferences* is **NULL**. |

## Remarks

To get the pages of a document, first get the list of [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interfaces by calling **GetPageReferences**. Then, for each **IXpsOMPageReference** interface, load a page by calling [GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage).

If the document does not have any pages, the page reference collection returned in *pageReferences* will be empty. To get the number of page references in the collection, call its [GetCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereferencecollection-getcount) method.

For an example of how this method can be used in a program, see [Navigate the XPS OM](https://learn.microsoft.com/previous-versions/windows/desktop/dd372917(v=vs.85)).

## See also

[IXpsOMDocument](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocument)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMPageReferenceCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereferencecollection)

[Navigate the XPS OM](https://learn.microsoft.com/previous-versions/windows/desktop/dd372917(v=vs.85))

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))