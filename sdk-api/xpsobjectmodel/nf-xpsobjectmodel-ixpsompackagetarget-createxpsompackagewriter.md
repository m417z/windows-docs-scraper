# IXpsOMPackageTarget::CreateXpsOMPackageWriter

## Description

Create an [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface for use with a print job that the [StartXpsPrintJob1](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-startxpsprintjob1) function created.

## Parameters

### `documentSequencePartName` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the document sequence in the new file.

### `documentSequencePrintTicket` [in, optional]

The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the package-level print ticket to be assigned to the new file. Set this parameter to **NULL** if you do not have a package-level print ticket.

### `discardControlPartName` [in, optional]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the discard control part. Set this parameter to **NULL** if you do not have a discard control part.

### `packageWriter` [out, retval]

A pointer to the new [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface that this method created.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *packageWriter* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *documentSequencePrintTicket* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## See also

[IXpsOMPackageTarget](https://learn.microsoft.com/previous-versions/windows/desktop/ff970304(v=vs.85))

[StartXpsPrintJob1](https://learn.microsoft.com/windows/desktop/api/xpsprint/nf-xpsprint-startxpsprintjob1)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)