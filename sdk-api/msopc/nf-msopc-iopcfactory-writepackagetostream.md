# IOpcFactory::WritePackageToStream

## Description

Serializes a package that is represented by a package object.

## Parameters

### `package` [in]

A pointer to the [IOpcPackage](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpackage) interface of the package object that contains data to be serialized.

### `flags` [in]

The value that describes the encoding method used in serialization.

### `stream` [in]

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the stream where the package object data will be written.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *flags* parameter is not a valid [OPC_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_write_flags) enumeration value. |
| **E_NOTIMPL** | This method is not implemented for this version of Windows. |
| **E_POINTER** | At least one of the *stream* and *package* parameters is **NULL**. |
| ****IStream** interface error** | An **HRESULT** error code from the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. |
| **Package Consumption error** | An **HRESULT** error code from the [Package Consumption Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/package-consumption-error-group). |
| **Part URI error** | An **HRESULT** error code from the [Part URI Error Group](https://learn.microsoft.com/previous-versions/windows/desktop/opc/part-uri-error-group). |

## Remarks

Do not use a stream to serialize package data when the same stream is being used to deserialize a package, because the attempt may result in undefined behavior.

For information about how to use this method to save a package that is represented as a package object, see the [Saving a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/saving-a-package) programming task.

### Support on Previous Versions of Windows

This method is not supported on versions of Windows prior to Windows 7. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

[OPC_WRITE_FLAGS](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_write_flags)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**

[Saving a Package](https://learn.microsoft.com/previous-versions/windows/desktop/opc/saving-a-package)