# IXpsOMObjectFactory1::GetDocumentTypeFromFile

## Description

Detects the type of XPS document that is stored in the specified file.

## Parameters

### `filename`

[in] The name of the XPS file from which to get the type.

### `documentType`

 [out, retval] The document type.

## Return value

Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The document type is XPS_DOCUMENT_TYPE_ XPS or XPS_DOCUMENT_TYPE_ OPENXPS.

## Remarks

This method only parses the data enough to detect the document type. It does not validate the content. A return value of S_OK does not, therefore, imply that the file contains a valid document.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)