# IXpsOMPackage1::GetDocumentType

## Description

Gets the document type of the data that was used to initialize this package. This method is used to determine whether a document is the XPS or OpenXPS type. For more information, see [XPS Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85)).

## Parameters

### `documentType`

[out, retval] The document type of the source data used to initialize this package. A document type value of XPS_DOCUMENT_TYPE_UNSPECIFIED is returned if the package was created in memory.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, the following values. For information about XPS Document API return values that are not listed in this table, see XPS Document Errors.

S_OK: The method succeeded.

E_POINTER: documentType is **NULL**.

## Remarks

If the [IXpsOMPackage1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1) instance was not loaded from a stream or a file, the document type is unspecified (XPS_DOCUMENT_TYPE_UNSPECIFIED). Otherwise, the document type returned is that of the stream or file used to initialize the **IXpsOMPackage1** instance.

## See also

[IXpsOMPackage1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1)

[XPS Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))