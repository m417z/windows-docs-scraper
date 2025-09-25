# IXpsOMDocumentSequence::GetDocuments

## Description

Gets a pointer to the [IXpsOMDocumentCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentcollection) interface, which contains the documents specified in the document sequence.

## Parameters

### `documents` [out, retval]

A pointer to the [IXpsOMDocumentCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentcollection) interface, which contains the documents specified in the document sequence. If the sequence does not have any documents, the **IXpsOMDocumentCollection** interface will be empty.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *documents* is **NULL**. |

## Remarks

If the document sequence does not have any documents, the document collection that is returned in *documents* will be empty. To get the number of documents in the collection, call the collection's [GetCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomdocumentcollection-getcount) method.

## See also

[IXpsOMDocumentSequence](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdocumentsequence)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))