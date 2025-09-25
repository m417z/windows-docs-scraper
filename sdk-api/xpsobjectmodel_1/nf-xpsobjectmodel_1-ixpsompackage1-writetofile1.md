# IXpsOMPackage1::WriteToFile1

## Description

Writes an XPS OM to a file as an XPS package of a specified type.

## Parameters

### `fileName`

[in, string] The name of the file to be created. This parameter must not be **NULL**.

### `securityAttributes`

[in, unique] The SECURITY_ATTRIBUTES structure, which contains two distinct but related data members:

lpSecurityDescriptor: an optional security descriptor

bInheritHandle: a Boolean value that determines whether the returned handle can be inherited by child processes

If lpSecurityDescriptor is **NULL**, the file or device that is associated with the returned handle will be assigned a default security descriptor.

For more information about the securityAttributes parameter, refer to CreateFile.

### `flagsAndAttributes`

[in] Specifies the settings and attributes of the file to be created. For most files, a value of FILE_ATTRIBUTE_NORMAL can be used.

For more information about the flagsAndAttributes parameter, refer to CreateFile.

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

E_INVALIDARG: The document type was specified as XPS_DOCUMENT_TYPE_UNSPECIFIED.

XPS_E_INVALID_CONTENT_TYPE: An image resource in the package is of a type that is not supported by the document type specified in documentType.

## Remarks

The caller must ensure that all image resources in the package are supported by the package type. For example, JpegXR images cannot be used in an MSXPS document type because they are incompatible.

## See also

[IXpsOMPackage1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompackage1)