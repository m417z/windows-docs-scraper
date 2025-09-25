# IXpsDocumentPackageTarget::GetXpsOMPackageWriter

## Description

Gets the [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) object for the document package.

## Parameters

### `documentSequencePartName` [in]

The document sequence part name.

### `discardControlPartName` [in]

The control part name.

### `packageWriter` [out, retval]

The [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) object.

## Return value

This method returns an HRESULT value. If the method call fails, it returns the appropriate HRESULT error code.

## See also

[IXpsDocumentPackageTarget](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsdocumentpackagetarget)

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)