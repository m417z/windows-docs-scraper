# IXpsOMObjectFactory1::CreatePackageFromFile1

## Description

Opens an XPS package file and returns an instantiated XPS document object tree. This method will read a file that contains an XPS document that is of type XPS_DOCUMENT_TYPE_ XPS or XPS_DOCUMENT_TYPE_ OPENXPS

## Parameters

### `filename`

[in, string] The name of the XPS package file.

### `reuseObjects`

[in] The Boolean value that indicates that the software is to attempt to optimize the document object tree by sharing objects that are identical in all properties and children.

TRUE: The software will attempt to optimize the object tree.

FALSE: The software will not attempt to optimize the object tree.

### `package`

[out, retval] A pointer to the new IXpsOMPackage1 interface that contains the XPS document object tree that was read from filename.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The method succeeded.

XPS_E_UNEXPECTED_NAMESPACE: The package markup uses a namespace that is not supported by the document type

XPS_E_ABSOLUTE_REFERENCE: The OpenXPS document contains XML elements that use absolute URIs to reference other parts in the document.

## Remarks

Use this method to read a file that contains an XPS document that could be of type XPS_DOCUMENT_TYPE_ XPS or XPS_DOCUMENT_TYPE_ OPENXPS. [CreatePackageFromFile](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomobjectfactory-createpackagefromfile), released in Windows 7, only opens files that contain an XPS document of type XPS_DOCUMENT_TYPE_ XPS.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)