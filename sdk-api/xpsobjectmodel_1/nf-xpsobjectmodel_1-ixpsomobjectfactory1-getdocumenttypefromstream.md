# IXpsOMObjectFactory1::GetDocumentTypeFromStream

## Description

Detects the type of XPS document that is stored in the specified stream.

## Parameters

### `xpsDocumentStream`

[in] A stream that contains XPS OM data. The stream must support sequential reading and the read position of the stream must be set to the beginning of the XPS data.

### `documentType`

[out, retval] The document type of the XPS data found in the stream.

## Return value

Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The document type is XPS_DOCUMENT_TYPE_ XPS or XPS_DOCUMENT_TYPE_ OPENXPS.

## Remarks

This method only parses the data enough to detect the document type. It does not validate the content. A return value of S_OK does not, therefore, imply that the stream contains a valid document.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)