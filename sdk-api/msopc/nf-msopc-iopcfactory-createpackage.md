# IOpcFactory::CreatePackage

## Description

Creates a package object that represents an empty package.

## Parameters

### `package` [out, retval]

A pointer to the [IOpcPackage](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcpackage) interface of the package object that represents an empty package.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | This method is not implemented for this version of Windows. |

## Remarks

### Support on Previous Versions of Windows

This method is not supported on versions of Windows prior to Windows 7. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcfactory)

[Music Bundle Sample](https://learn.microsoft.com/previous-versions/windows/desktop/opc/music-bundle-sample)

**Overviews**

[Packages Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packages-overview)

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**