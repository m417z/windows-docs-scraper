# IXpsOMPackage::WriteToStream

## Description

Writes the XPS package to a specified stream.

## Parameters

### `stream` [in]

The stream that receives the serialized contents of the package. This parameter must not be **NULL**.

### `optimizeMarkupSize` [in]

A Boolean value that indicates whether the document markup is to be optimized for size when it is written to the stream.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The package writer will attempt to optimize the markup for minimum size. |
| ****FALSE**** | The package writer will not attempt any optimization. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *stream* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

The *optimizeMarkupSize* value determines whether the markup inside the individual document parts is to be optimized. It has no effect on how the parts are interleaved.

**Note** Writing an XPS OM to a stream does not automatically create a thumbnail for the XPS document. To create a thumbnail of the XPS document, use the [IXpsOMThumbnailGenerator](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomthumbnailgenerator) interface.

## See also

[ISequentialStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))