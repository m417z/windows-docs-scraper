# IOpcFactory::CreateStreamOnFile

## Description

Creates a stream over a file. This method is a simplified wrapper for a call to the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. **CreateFile** parameters that are not exposed through this method use their default values. For more information, see **CreateFile**.

## Parameters

### `filename` [in]

The name of the file over which the stream is created.

### `ioMode` [in]

The value that describes the read/write status of the stream to be created.

### `securityAttributes` [in]

For information about the [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure in this parameter, see the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `dwFlagsAndAttributes` [in]

The settings and attributes of the file. For most files, **FILE_ATTRIBUTE_NORMAL** can be used.

For more information about this parameter, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `stream` [out, retval]

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *ioMode* parameter is not a valid [OPC_STREAM_IO_MODE](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_stream_io_mode) enumeration value. |
| **E_POINTER** | At least one of the *filename* and *stream* parameters is **NULL**. |
| ****CreateFile** function error** | An **HRESULT** error code from the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. |

## Remarks

Do not use a stream to serialize package data when the same stream is being used to deserialize a package, because the attempt may result in undefined behavior.

For information about using this method when loading or saving a package, see the [Loading a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/loading-a-package) or [Saving a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/saving-a-package) programming task.

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

[Loading a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/loading-a-package)

[OPC_STREAM_IO_MODE](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_stream_io_mode)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Parts Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/parts-overview)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

[RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt)

**Reference**

[Saving a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/saving-a-package)