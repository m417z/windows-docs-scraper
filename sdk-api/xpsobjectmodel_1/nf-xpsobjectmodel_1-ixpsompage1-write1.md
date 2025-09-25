## Description

Writes the page to the specified stream.

## Parameters

### `stream`

The stream that receives the serialized contents of the page.

### `optimizeMarkupSize`

A Boolean value that indicates whether the document markup of the page is to be optimized for size when the page is written to the stream.

| Value | Meaning |
|-------|--------------------------------------------------------------------------------------------------------------|
| TRUE | The package writer will attempt to optimize the markup for minimum size when writing the page to the stream. |
| FALSE | The package writer will not attempt any optimization when writing the page to the stream. |

### `documentType`

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://docs.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
|-------------|-----------------------------|
| S_OK | The method succeeded. |
| E_POINTER | **stream** is **NULL**. |

## Remarks

To examine the XPS markup of a page before it is written to an XPS package, an application can call the **Write** method to write the page's contents to a stream. The application can then read that stream to examine the XPS markup as it would be serialized when it is written to the XPS package.

The XPS markup that is written to the stream by this method contains the page markup but none of the page's resources.

## See also

[ISequentialStream](https://docs.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXpsOMPage](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsompage1)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://docs.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))