# IXpsOMObjectFactory::CreateReadOnlyStreamOnFile

## Description

Creates a read-only [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) over the specified file.

## Parameters

### `filename` [in]

The name of the file to be opened.

### `stream` [out, retval]

A stream over the specified file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *filename* or *stream* is **NULL**. |

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

**CreateReadOnlyStreamOnFile** is a wrapper method for [IOpcFactory::CreateStreamOnFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-createstreamonfile). It has the same effect as calling the following:

```cpp
    hr = opcFactory->CreateStreamOnFile (
        fileName,
        OPC_STREAM_IO_READ,
        NULL,
        FILE_ATTRIBUTE_NORMAL,
        &stream);

```

## See also

[IOpcFactory::CreateStreamOnFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-createstreamonfile)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))