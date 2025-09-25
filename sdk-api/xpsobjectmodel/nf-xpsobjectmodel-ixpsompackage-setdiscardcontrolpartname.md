# IXpsOMPackage::SetDiscardControlPartName

## Description

Sets the name of the discard control part in the XPS package.

## Parameters

### `discardControlPartUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the discard control part to be assigned to the XPS package. A **NULL** pointer releases any previously assigned discard control part.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)