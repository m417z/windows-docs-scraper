# IXpsDocumentPackageTarget3D::GetXpsOMPackageWriter3D

## Description

Gets a new [IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d) object for the document package.

## Parameters

### `documentSequencePartName` [in]

The root part of XPS payload.

### `discardControlPartName` [in, optional]

The discard control part for the XPS payload.

### `modelPartName` [in]

Name of the part which will hold the 3D model. The part’s content type is “application/vnd.ms-package.3dmanufacturing-3dmodel+xml”. It is linked from package root with relationship type “http://schemas.microsoft.com/3dmanufacturing/2013/01/3dmodel” .

### `modelData` [in]

A readable stream which holds 3D model description. The model description may be UTF16 encoding of XML document, but for XPS OM and XpsPrint, this is a BLOB passing through. The **GetXpsOMPackageWriter3D** method attempts to move the provided stream’s read pointer to the beginning of the stream, but the method call will not fail if the stream does not support the [Seek](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-seek) method.

### `packageWriter` [out]

 Returns the writer which may be used to send XPS content and textures for the 3D model.

## Return value

Returns the appropriate HRESULT error code.

## See also

[IXpsDocumentPackageTarget3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsdocumentpackagetarget3d)