# IOpcFactory::ReadPackageFromStream

## Description

Deserializes package data from a stream and creates a package object to represent the package being read. While a Packaging API object obtained from the package object, or the package object itself, is still in use, the stream may be used to access package data.

## Parameters

### `stream` [in]

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the stream.

The stream must be readable, seekable, have size, and must contain package data. Additionally, if the stream is not cloneable, it will be buffered and read sequentially, incurring overhead.

### `flags` [in]

The value that specifies the read settings for caching package components and validating them against *OPC* conformance requirements.

### `package` [out, retval]

A pointer to the [IOpcPackage](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpackage) interface of the package object that represents the package being read through the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *flags* parameter is not a valid [OPC_READ_FLAGS](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_read_flags) enumeration value. |
| **E_NOTIMPL** | This method is not implemented for this version of Windows. |
| **E_POINTER** | At least one of the *stream* and *package* parameters is **NULL**. |
| **IStream interface error** | An **HRESULT** error code from the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

Do not use a stream to serialize package data when the same stream is being used to deserialize a package, because the attempt may result in undefined behavior.

The Packaging APIs can interact with packages that map a ZIP archive as specified in the OPC, and that are based on either Zip32 (ZIP 2.0) or Zip64 (ZIP 4.5) encoding.

For information about how to use this method to load a package, see the [Loading a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/loading-a-package) programming task.

### Support on Previous Versions of Windows

This method is not supported on versions of Windows prior to Windows 7. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

[Loading a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/loading-a-package)

[OPC_READ_FLAGS](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_read_flags)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**