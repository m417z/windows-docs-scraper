# IXpsOMPackage1::WriteToStream1

## Description

Writes an XPS OM to a stream as an XPS package of a specified type.

## Parameters

### `outputStream`

 [in] The stream that receives the serialized contents of the package. This parameter must not be **NULL**.

### `optimizeMarkupSize`

[in] A Boolean value that indicates whether the document markup will be optimized for size when the contents of the XPS OM are written to the XPS package.

TRUE: The package writer will try to optimize the markup for minimum size.

FALSE: The package writer will not try to perform any optimization.

### `documentType`

[in] The XPS data format to write to outputStream. The value of this parameter cannot be XPS_DOCUMENT_TYPE_UNSPECIFIED.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, the following values. For information about XPS Document API return values that are not listed in this table, see XPS Document Errors.

S_OK: The method succeeded.

E_POINTER: documentType is **NULL**.

E_INVALIDARG: documentType was set to XPS_DOCUMENT_TYPE_UNSPECIFIED.

XPS_E_INVALID_CONTENT_TYPE: An image resource in the package is of a type that is not supported by the document type specified in documentType.

## See also

[IXpsOMPackage1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1)