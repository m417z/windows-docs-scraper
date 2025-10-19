# IXpsOMObjectFactory::CreatePackageWriterOnStream

## Description

Opens a stream for writing the contents of an XPS OM to an XPS package.

## Parameters

### `outputStream` [in]

The stream to be used for writing.

### `optimizeMarkupSize` [in]

A Boolean value that indicates whether the document markup will be optimized for size when the document is written to the stream.

| Value | Meaning |
| --- | --- |
| **TRUE** | When writing to the stream, the package writer will attempt to optimize the markup for minimum size. |
| **FALSE** | When writing to the package, the package writer will not attempt any optimization. |

### `interleaving` [in]

Specifies whether the content of the XPS OM will be interleaved when it is written to the stream.

### `documentSequencePartName` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the document sequence in the new file.

### `coreProperties` [in]

The [IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties) interface that contains the core document properties to be given to the new file. This parameter can be set to **NULL**.

### `packageThumbnail` [in]

The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the thumbnail image to be assigned to the new file. This parameter can be set to **NULL**.

### `documentSequencePrintTicket` [in]

The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the package-level print ticket to be assigned to the new file. This parameter can be set to **NULL**.

### `discardControlPartName` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the discard control part. This parameter can be set to **NULL**.

### `packageWriter` [out, retval]

A pointer to the new [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface created by this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *outputStream*, *documentSequencePartName*, or *packageWriter* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *coreProperties*, *documentSequencePrintTicket* or *packageThumbnail* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

The stream is opened and initialized, and then the returned [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface is used to write content types, package relationships, core properties, document sequence resources, and document sequence relationships.

If *documentSequencePrintTicket* is set to **NULL** and the value of *interleaving* is **XPS_INTERLEAVING_ON**, this method creates a blank job-level print ticket and adds a relationship to the blank print ticket. This is done to provide more efficient streaming consumption of the package.

If *documentSequencePrintTicket* is set to **NULL** and the value of *interleaving* is **XPS_INTERLEAVING_OFF**, no blank print ticket is created.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[ISequentialStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter)

[IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))