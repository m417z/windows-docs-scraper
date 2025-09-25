# IXpsOMObjectFactory1::CreatePackageWriterOnStream1

## Description

Opens a stream for writing the contents of an XPS OM to an XPS package of a specified type.

## Parameters

### `outputStream`

[in] The stream to be used for writing.

### `optimizeMarkupSize`

A Boolean value that indicates whether the document markup will be optimized for size when the document is written to the stream.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | When writing to the stream, the package writer will attempt to optimize the markup for minimum size. |
| ****FALSE**** | When writing to the package, the package writer will not attempt any optimization. |

### `interleaving`

[in] Specifies whether the content of the XPS OM will be interleaved when it is written to the stream.

### `documentSequencePartName`

[in] The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name of the document sequence in the new file.

### `coreProperties`

[in] The [IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties) interface that contains the core document properties to be given to the new file. This parameter can be set to **NULL**.

### `packageThumbnail`

[in] The [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface that contains the thumbnail image to be assigned to the new file. This parameter can be set to **NULL**.

### `documentSequencePrintTicket`

[in] The [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface that contains the package-level print ticket to be assigned to the new file. This parameter can be set to **NULL**.

### `discardControlPartName`

[in] The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the name of the discard control part. This parameter can be set to **NULL**.

### `documentType`

[in] The document type of the package writer. The value of this parameter cannot be XPS_DOCUMENT_TYPE_UNSPECIFIED.

### `packageWriter`

[out, retval] A pointer to the new [IXpsOMPackageWriter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackagewriter) interface created by this method.

## Return value

Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The method succeeded and packageWriter was set correctly.

E_INVALIDARG: The document type was not a valid XPS document format.

## Remarks

Use this method to produce a package writer for either an MSXPS document or an OpenXPS document. [CreatePackageWriterOnStream](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomobjectfactory-createpackagewriteronstream), released in Windows 7, only creates XPS document files in the MSXPS format.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)